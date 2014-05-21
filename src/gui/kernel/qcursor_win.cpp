/***********************************************************************
*
* Copyright (c) 2012-2014 Barbara Geller
* Copyright (c) 2012-2014 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see 
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#include <private/qcursor_p.h>
#include <qbitmap.h>
#include <qcursor.h>

#ifndef QT_NO_CURSOR

#include <qimage.h>
#include <qt_windows.h>
#include <private/qapplication_p.h>

QT_BEGIN_NAMESPACE

/*****************************************************************************
  Internal QCursorData class
 *****************************************************************************/

QCursorData::QCursorData(Qt::CursorShape s)
  : cshape(s), bm(0), bmm(0), hx(0), hy(0), hcurs(0)
{
    ref = 1;
}

QCursorData::~QCursorData()
{
    delete bm;
    delete bmm;

#if defined(GWES_ICONCURS)
    if (hcurs)
        DestroyCursor(hcurs);
#endif
}


QCursorData *QCursorData::setBitmap(const QBitmap &bitmap, const QBitmap &mask, int hotX, int hotY)
{
    if (!QCursorData::initialized)
        QCursorData::initialize();
    if (bitmap.depth() != 1 || mask.depth() != 1 || bitmap.size() != mask.size()) {
        qWarning("QCursor: Cannot create bitmap cursor; invalid bitmap(s)");
        QCursorData *c = qt_cursorTable[0];
        c->ref.ref();
        return c;
    }
    QCursorData *d = new QCursorData;
    d->bm  = new QBitmap(bitmap);
    d->bmm = new QBitmap(mask);
    d->hcurs = 0;
    d->cshape = Qt::BitmapCursor;
    d->hx = hotX >= 0 ? hotX : bitmap.width()/2;
    d->hy = hotY >= 0 ? hotY : bitmap.height()/2;
    return d;
}

HCURSOR QCursor::handle() const
{
    if (!QCursorData::initialized)
        QCursorData::initialize();
    if (!d->hcurs)
        d->update();
    return d->hcurs;
}

QCursor::QCursor(HCURSOR handle)
{
    d = new QCursorData(Qt::CustomCursor);
    d->hcurs = handle;
}

#endif //QT_NO_CURSOR

QPoint QCursor::pos()
{
    POINT p;
    GetCursorPos(&p);
    return QPoint(p.x, p.y);
}

void QCursor::setPos(int x, int y)
{
    SetCursorPos(x, y);
}

#ifndef QT_NO_CURSOR

extern HBITMAP qt_createIconMask(const QBitmap &bitmap);

static HCURSOR create32BitCursor(const QPixmap &pixmap, int hx, int hy)
{
    HCURSOR cur = 0;

    QBitmap mask = pixmap.mask();
    if (mask.isNull()) {
        mask = QBitmap(pixmap.size());
        mask.fill(Qt::color1);
    }

    HBITMAP ic = pixmap.toWinHBITMAP(QPixmap::Alpha);
    HBITMAP im = qt_createIconMask(mask);

    ICONINFO ii;
    ii.fIcon     = 0;
    ii.xHotspot  = hx;
    ii.yHotspot  = hy;
    ii.hbmMask   = im;
    ii.hbmColor  = ic;

    cur = CreateIconIndirect(&ii);

    DeleteObject(ic);
    DeleteObject(im);

    return cur;
}

void QCursorData::update()
{
    if (!QCursorData::initialized)
        QCursorData::initialize();

    if (hcurs)
        return;

    if (cshape == Qt::BitmapCursor && !pixmap.isNull()) {
        hcurs = create32BitCursor(pixmap, hx, hy);
        if (hcurs)
            return;
    }

    // Non-standard Windows cursors are created from bitmaps

    static const uchar vsplit_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0xe0, 0x03, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00,
        0x00, 0xc0, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    static const uchar vsplitm_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0xc0, 0x01, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0xf0, 0x07, 0x00,
        0x00, 0xf8, 0x0f, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0xc0, 0x01, 0x00,
        0x00, 0xc0, 0x01, 0x00, 0x80, 0xff, 0xff, 0x00, 0x80, 0xff, 0xff, 0x00,
        0x80, 0xff, 0xff, 0x00, 0x80, 0xff, 0xff, 0x00, 0x80, 0xff, 0xff, 0x00,
        0x80, 0xff, 0xff, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0xc0, 0x01, 0x00,
        0x00, 0xc0, 0x01, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0xf0, 0x07, 0x00,
        0x00, 0xe0, 0x03, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    static const uchar hsplit_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00,
        0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00,
        0x00, 0x41, 0x82, 0x00, 0x80, 0x41, 0x82, 0x01, 0xc0, 0x7f, 0xfe, 0x03,
        0x80, 0x41, 0x82, 0x01, 0x00, 0x41, 0x82, 0x00, 0x00, 0x40, 0x02, 0x00,
        0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00,
        0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    static const uchar hsplitm_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xe0, 0x07, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0xe0, 0x07, 0x00,
        0x00, 0xe0, 0x07, 0x00, 0x00, 0xe2, 0x47, 0x00, 0x00, 0xe3, 0xc7, 0x00,
        0x80, 0xe3, 0xc7, 0x01, 0xc0, 0xff, 0xff, 0x03, 0xe0, 0xff, 0xff, 0x07,
        0xc0, 0xff, 0xff, 0x03, 0x80, 0xe3, 0xc7, 0x01, 0x00, 0xe3, 0xc7, 0x00,
        0x00, 0xe2, 0x47, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0xe0, 0x07, 0x00,
        0x00, 0xe0, 0x07, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    static const uchar phand_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00,
        0x80, 0x04, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00,
        0x80, 0x1c, 0x00, 0x00, 0x80, 0xe4, 0x00, 0x00, 0x80, 0x24, 0x03, 0x00,
        0x80, 0x24, 0x05, 0x00, 0xb8, 0x24, 0x09, 0x00, 0xc8, 0x00, 0x09, 0x00,
        0x88, 0x00, 0x08, 0x00, 0x90, 0x00, 0x08, 0x00, 0xa0, 0x00, 0x08, 0x00,
        0x20, 0x00, 0x08, 0x00, 0x40, 0x00, 0x08, 0x00, 0x40, 0x00, 0x04, 0x00,
        0x80, 0x00, 0x04, 0x00, 0x80, 0x00, 0x04, 0x00, 0x00, 0x01, 0x02, 0x00,
        0x00, 0x01, 0x02, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

   static const uchar phandm_bits[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
        0x80, 0x07, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
        0x80, 0x1f, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x80, 0xff, 0x03, 0x00,
        0x80, 0xff, 0x07, 0x00, 0xb8, 0xff, 0x0f, 0x00, 0xf8, 0xff, 0x0f, 0x00,
        0xf8, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0xe0, 0xff, 0x0f, 0x00,
        0xe0, 0xff, 0x0f, 0x00, 0xc0, 0xff, 0x0f, 0x00, 0xc0, 0xff, 0x07, 0x00,
        0x80, 0xff, 0x07, 0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0xff, 0x03, 0x00,
        0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

   static const uchar openhand_bits[] = {
        0x80,0x01,0x58,0x0e,0x64,0x12,0x64,0x52,0x48,0xb2,0x48,0x92,
        0x16,0x90,0x19,0x80,0x11,0x40,0x02,0x40,0x04,0x40,0x04,0x20,
        0x08,0x20,0x10,0x10,0x20,0x10,0x00,0x00};
    static const uchar openhandm_bits[] = {
       0x80,0x01,0xd8,0x0f,0xfc,0x1f,0xfc,0x5f,0xf8,0xff,0xf8,0xff,
       0xf6,0xff,0xff,0xff,0xff,0x7f,0xfe,0x7f,0xfc,0x7f,0xfc,0x3f,
       0xf8,0x3f,0xf0,0x1f,0xe0,0x1f,0x00,0x00};
    static const uchar closedhand_bits[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0xb0,0x0d,0x48,0x32,0x08,0x50,
        0x10,0x40,0x18,0x40,0x04,0x40,0x04,0x20,0x08,0x20,0x10,0x10,
        0x20,0x10,0x20,0x10,0x00,0x00,0x00,0x00};
    static const uchar closedhandm_bits[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0xb0,0x0d,0xf8,0x3f,0xf8,0x7f,
        0xf0,0x7f,0xf8,0x7f,0xfc,0x7f,0xfc,0x3f,0xf8,0x3f,0xf0,0x1f,
        0xe0,0x1f,0xe0,0x1f,0x00,0x00,0x00,0x00};

    static const uchar * const cursor_bits32[] = {
        vsplit_bits, vsplitm_bits, hsplit_bits, hsplitm_bits,
        phand_bits, phandm_bits
    };

    wchar_t *sh = 0;
    switch (cshape) {                        // map to windows cursor
    case Qt::ArrowCursor:
        sh = IDC_ARROW;
        break;
    case Qt::UpArrowCursor:
        sh = IDC_UPARROW;
        break;
    case Qt::CrossCursor:
        sh = IDC_CROSS;
        break;
    case Qt::WaitCursor:
        sh = IDC_WAIT;
        break;
    case Qt::IBeamCursor:
        sh = IDC_IBEAM;
        break;
    case Qt::SizeVerCursor:
        sh = IDC_SIZENS;
        break;
    case Qt::SizeHorCursor:
        sh = IDC_SIZEWE;
        break;
    case Qt::SizeBDiagCursor:
        sh = IDC_SIZENESW;
        break;
    case Qt::SizeFDiagCursor:
        sh = IDC_SIZENWSE;
        break;
    case Qt::SizeAllCursor:
        sh = IDC_SIZEALL;
        break;
    case Qt::ForbiddenCursor:
        sh = IDC_NO;
        break;
    case Qt::WhatsThisCursor:
        sh = IDC_HELP;
        break;
    case Qt::BusyCursor:
        sh = IDC_APPSTARTING;
        break;
    case Qt::PointingHandCursor:
        sh = IDC_HAND;
        break;
    case Qt::BlankCursor:
    case Qt::SplitVCursor:
    case Qt::SplitHCursor:
    case Qt::OpenHandCursor:
    case Qt::ClosedHandCursor:
    case Qt::BitmapCursor: {
        QImage bbits, mbits;
        bool invb, invm;
        if (cshape == Qt::BlankCursor) {
            bbits = QImage(32, 32, QImage::Format_Mono);
            bbits.fill(0);                // ignore color table
            mbits = bbits.copy();
            hx = hy = 16;
            invb = invm = false;
        } else if (cshape == Qt::OpenHandCursor || cshape == Qt::ClosedHandCursor) {
            bool open = cshape == Qt::OpenHandCursor;
            QBitmap cb = QBitmap::fromData(QSize(16, 16), open ? openhand_bits : closedhand_bits);
            QBitmap cm = QBitmap::fromData(QSize(16, 16), open ? openhandm_bits : closedhandm_bits);
            bbits = cb.toImage().convertToFormat(QImage::Format_Mono);
            mbits = cm.toImage().convertToFormat(QImage::Format_Mono);
            hx = hy = 8;
            invb = invm = false;
        } else if (cshape != Qt::BitmapCursor) {
            int i = cshape - Qt::SplitVCursor;
            QBitmap cb = QBitmap::fromData(QSize(32, 32), cursor_bits32[i * 2]);
            QBitmap cm = QBitmap::fromData(QSize(32, 32), cursor_bits32[i * 2 + 1]);
            bbits = cb.toImage().convertToFormat(QImage::Format_Mono);
            mbits = cm.toImage().convertToFormat(QImage::Format_Mono);
            if (cshape == Qt::PointingHandCursor) {
                hx = 7;
                hy = 0;
            } else
                hx = hy = 16;
            invb = invm = false;
        } else {
            bbits = bm->toImage().convertToFormat(QImage::Format_Mono);
            mbits = bmm->toImage().convertToFormat(QImage::Format_Mono);
            invb = bbits.colorCount() > 1 && qGray(bbits.color(0)) < qGray(bbits.color(1));
            invm = mbits.colorCount() > 1 && qGray(mbits.color(0)) < qGray(mbits.color(1));
        }
        int n = qMax(1, bbits.width() / 8);
        int h = bbits.height();

        uchar* xBits = new uchar[h * n];
        uchar* xMask = new uchar[h * n];
        int x = 0;
        for (int i = 0; i < h; ++i) {
            uchar *bits = bbits.scanLine(i);
            uchar *mask = mbits.scanLine(i);
            for (int j = 0; j < n; ++j) {
                uchar b = bits[j];
                uchar m = mask[j];
                if (invb)
                    b ^= 0xff;
                if (invm)
                    m ^= 0xff;
                xBits[x] = ~m;
                xMask[x] = b ^ m;
                ++x;
            }
        }
        hcurs = CreateCursor(qWinAppInst(), hx, hy, bbits.width(), bbits.height(),
                                   xBits, xMask);
        delete [] xBits;
        delete [] xMask;

        return;
    }

    case Qt::DragCopyCursor:
    case Qt::DragMoveCursor:
    case Qt::DragLinkCursor: {
        QPixmap pixmap = QApplicationPrivate::instance()->getPixmapCursor(cshape);
        hcurs = create32BitCursor(pixmap, hx, hy);
    }
        return;
    default:
        qWarning("QCursor::update: Invalid cursor shape %d", cshape);
        return;
    }

    hcurs = (HCURSOR)LoadImage(0, sh, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

}

QT_END_NAMESPACE
#endif // QT_NO_CURSOR
