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

#ifndef QToolBarSeparator_P_H
#define QToolBarSeparator_P_H

#include "QtGui/qwidget.h"

QT_BEGIN_NAMESPACE

#ifndef QT_NO_TOOLBAR

class QStyleOption;
class QToolBar;

class QToolBarSeparator : public QWidget
{
    CS_OBJECT(QToolBarSeparator)
    Qt::Orientation orient;

public:
    explicit QToolBarSeparator(QToolBar *parent);

    Qt::Orientation orientation() const;

    QSize sizeHint() const;

    void paintEvent(QPaintEvent *);
    void initStyleOption(QStyleOption *option) const;

    GUI_CS_SLOT_1(Public, void setOrientation(Qt::Orientation orientation))
    GUI_CS_SLOT_2(setOrientation) 
};

#endif // QT_NO_TOOLBAR

QT_END_NAMESPACE

#endif // QDYNAMICTOOLBARSEPARATOR_P_H
