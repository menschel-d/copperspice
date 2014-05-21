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

#ifndef QPROXYMODEL_H
#define QPROXYMODEL_H

#include <QtCore/qabstractitemmodel.h>


QT_BEGIN_NAMESPACE

#ifndef QT_NO_PROXYMODEL

class QProxyModelPrivate;

class Q_GUI_EXPORT QProxyModel : public QAbstractItemModel
{
    CS_OBJECT(QProxyModel)

public:
    explicit QProxyModel(QObject *parent = 0);
    ~QProxyModel();

    virtual void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;

    // implementing model interface

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value,
                       int role = Qt::EditRole);

    QStringList mimeTypes() const;
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                      int row, int column, const QModelIndex &parent);
    Qt::DropActions supportedDropActions() const;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());

    void fetchMore(const QModelIndex &parent);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

    QModelIndexList match(const QModelIndex &start, int role, const QVariant &value,
                          int hits = 1, Qt::MatchFlags flags =
                          Qt::MatchFlags(Qt::MatchStartsWith|Qt::MatchWrap)) const;

    QSize span(const QModelIndex &index) const;

    bool submit();
    void revert();

    using QObject::parent;


protected:
    QProxyModel(QProxyModelPrivate &, QObject *parent = 0);

    QModelIndex setProxyModel(const QModelIndex &source_index) const;
    QModelIndex setSourceModel(const QModelIndex &proxy_index) const;

    void connectToModel(const QAbstractItemModel *model) const;
    void disconnectFromModel(const QAbstractItemModel *model) const;

private:
    Q_DECLARE_PRIVATE(QProxyModel)
    Q_DISABLE_COPY(QProxyModel)

    GUI_CS_SLOT_1(Private, void _q_sourceDataChanged(const QModelIndex & un_named_arg1,const QModelIndex & un_named_arg2))
    GUI_CS_SLOT_2(_q_sourceDataChanged)

    GUI_CS_SLOT_1(Private, void _q_sourceRowsAboutToBeInserted(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceRowsAboutToBeInserted)

    GUI_CS_SLOT_1(Private, void _q_sourceRowsInserted(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceRowsInserted)

    GUI_CS_SLOT_1(Private, void _q_sourceRowsAboutToBeRemoved(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceRowsAboutToBeRemoved)

    GUI_CS_SLOT_1(Private, void _q_sourceRowsRemoved(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceRowsRemoved)

    GUI_CS_SLOT_1(Private, void _q_sourceColumnsAboutToBeInserted(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceColumnsAboutToBeInserted)

    GUI_CS_SLOT_1(Private, void _q_sourceColumnsInserted(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceColumnsInserted)

    GUI_CS_SLOT_1(Private, void _q_sourceColumnsAboutToBeRemoved(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceColumnsAboutToBeRemoved)

    GUI_CS_SLOT_1(Private, void _q_sourceColumnsRemoved(const QModelIndex & un_named_arg1,int un_named_arg2,int un_named_arg3))
    GUI_CS_SLOT_2(_q_sourceColumnsRemoved)

};

#endif // QT_NO_PROXYMODEL

QT_END_NAMESPACE

#endif // QPROXYMODEL_H
