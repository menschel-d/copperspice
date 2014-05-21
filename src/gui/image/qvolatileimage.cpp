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

#include "qvolatileimage_p.h"
#include "qvolatileimagedata_p.h"
#include <QtGui/private/qpaintengine_raster_p.h>
#include <QtGui/private/qpixmapdata_p.h>

QT_BEGIN_NAMESPACE

class QVolatileImagePaintEnginePrivate : public QRasterPaintEnginePrivate
{
public:
    QVolatileImagePaintEnginePrivate() { }
    QVolatileImage *img;
};

class QVolatileImagePaintEngine : public QRasterPaintEngine
{
    Q_DECLARE_PRIVATE(QVolatileImagePaintEngine)

public:
    QVolatileImagePaintEngine(QPaintDevice *device, QVolatileImage *img);
    bool begin(QPaintDevice *device);
    bool end();
    void drawPixmap(const QPointF &p, const QPixmap &pm);
    void drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr);
};

QVolatileImage::QVolatileImage()
    : d(new QVolatileImageData)
{
}

QVolatileImage::QVolatileImage(int w, int h, QImage::Format format)
    : d(new QVolatileImageData(w, h, format))
{
}

QVolatileImage::QVolatileImage(const QImage &sourceImage)
    : d(new QVolatileImageData(sourceImage))
{
}

QVolatileImage::QVolatileImage(void *nativeImage, void *nativeMask)
    : d(new QVolatileImageData(nativeImage, nativeMask))
{
}

// Need non-inline, non-autogenerated copy ctor, dtor, op= to keep the
// fwd declared QSharedData working.

QVolatileImage::QVolatileImage(const QVolatileImage &other)
    : d(other.d)
{
}

QVolatileImage::~QVolatileImage()
{
}

QVolatileImage &QVolatileImage::operator=(const QVolatileImage &rhs)
{
    d = rhs.d;
    return *this;
}

bool QVolatileImage::paintingActive() const
{
    return d->pengine && d->pengine->isActive();
}

bool QVolatileImage::isNull() const
{
    return d->image.isNull();
}

QImage::Format QVolatileImage::format() const
{
    return d->image.format();
}

int QVolatileImage::width() const
{
    return d->image.width();
}

int QVolatileImage::height() const
{
    return d->image.height();
}

int QVolatileImage::bytesPerLine() const
{
    return d->image.bytesPerLine();
}

int QVolatileImage::byteCount() const
{
    return d->image.byteCount();
}

int QVolatileImage::depth() const
{
    return d->image.depth();
}

bool QVolatileImage::hasAlphaChannel() const
{
    return d->image.hasAlphaChannel();
}

void QVolatileImage::beginDataAccess() const
{
    d->beginDataAccess();
}

void QVolatileImage::endDataAccess(bool readOnly) const
{
    d->endDataAccess(readOnly);
}

/*!
  Access to pixel data via bits() or constBits() should be guarded by
  begin/endDataAccess().
 */
uchar *QVolatileImage::bits()
{
    return d->image.bits();
}

const uchar *QVolatileImage::constBits() const
{
    return d->image.constBits();
}

bool QVolatileImage::ensureFormat(QImage::Format format)
{
    return d->ensureFormat(format);
}

/*!
  This will always perform a copy of the pixel data.
 */
QImage QVolatileImage::toImage() const
{
    d->beginDataAccess();
    QImage newImage = d->image.copy(); // no sharing allowed
    d->endDataAccess(true);
    return newImage;
}

/*!
  Returns a reference to the image that is potentially using some native
  buffer internally. Access to the image's pixel data should be guarded by
  begin/endDataAccess(). Use it when there is a need for QImage APIs not provided
  by this class. The returned QImage must never be shared or assigned to.
  */
QImage &QVolatileImage::imageRef() // non-const, in order to cause a detach
{
    d->ensureImage();
    return d->image;
}

/*!
  Non-detaching version, for read-only access only.
  Must be guarded by begin/endDataAccess().
 */
const QImage &QVolatileImage::constImageRef() const
{
    const_cast<QVolatileImageData *>(d.data())->ensureImage();
    return d->image;
}

void *QVolatileImage::duplicateNativeImage() const
{
    return d->duplicateNativeImage();
}

void QVolatileImage::setAlphaChannel(const QPixmap &alphaChannel)
{
    ensureFormat(QImage::Format_ARGB32_Premultiplied);
    beginDataAccess();
    imageRef().setAlphaChannel(alphaChannel.toImage());
    endDataAccess();
    d->ensureImage();
}

void QVolatileImage::fill(uint pixelValue)
{
    beginDataAccess();
    imageRef().fill(pixelValue);
    endDataAccess();
    d->ensureImage();
}

void QVolatileImage::copyFrom(QVolatileImage *source, const QRect &rect)
{
    if (source->isNull()) {
        return;
    }
    QRect r = rect;
    if (rect.isNull()) {
        r = QRect(0, 0, source->width(), source->height());
    }
    source->beginDataAccess();
    QImage &srcImgRef(source->imageRef());
    int srcbpl = srcImgRef.bytesPerLine();
    int srcbpp = srcImgRef.depth() / 8;
    const uchar *sptr = srcImgRef.constBits() + r.y() * srcbpl;
    beginDataAccess();
    QImage &dstImgRef(imageRef());
    if (!dstImgRef.isNull()) {
        int dstbpl = dstImgRef.bytesPerLine();
        uchar *dptr = dstImgRef.bits();
        for (int y = 0; y < r.height(); ++y) {
            memcpy(dptr, sptr + r.x() * srcbpp, r.width() * srcbpp);
            sptr += srcbpl;
            dptr += dstbpl;
        }
    }
    endDataAccess();
    source->endDataAccess(true);
}

/*!
    To be called from the PixmapData's paintEngine().
  */
QPaintEngine *QVolatileImage::paintEngine()
{
    if (!d->pengine) {
        d->pengine = new QVolatileImagePaintEngine(&imageRef(), this);
    }
    return d->pengine;
}

QVolatileImagePaintEngine::QVolatileImagePaintEngine(QPaintDevice *device,
                                                             QVolatileImage *img)
    : QRasterPaintEngine(*(new QVolatileImagePaintEnginePrivate), device)
{
    Q_D(QVolatileImagePaintEngine);
    d->img = img;
}

bool QVolatileImagePaintEngine::begin(QPaintDevice *device)
{
    Q_D(QVolatileImagePaintEngine);
    d->img->beginDataAccess();
    return QRasterPaintEngine::begin(device);
}

bool QVolatileImagePaintEngine::end()
{
    Q_D(QVolatileImagePaintEngine);
    bool ret = QRasterPaintEngine::end();
    d->img->endDataAccess();
    return ret;
}

// For non-RasterClass pixmaps drawPixmap() would call toImage() which is slow in
// our case. Therefore drawPixmap() is rerouted to drawImage().

void QVolatileImagePaintEngine::drawPixmap(const QPointF &p, const QPixmap &pm)
{
    QRasterPaintEngine::drawPixmap(p, pm);
}

void QVolatileImagePaintEngine::drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr)
{
    QRasterPaintEngine::drawPixmap(r, pm, sr);
}

QT_END_NAMESPACE
