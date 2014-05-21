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

#ifndef QT7_BACKEND_H
#define QT7_BACKEND_H

#include <QtCore/QList>
#include <QtCore/QPointer>
#include <QtCore/QStringList>
#include <phonon/backendinterface.h>

QT_BEGIN_NAMESPACE

namespace Phonon
{
namespace QT7
{
    class Backend : public QObject, public BackendInterface
    {
        CS_OBJECT(Backend)
        CS_INTERFACES(Phonon::BackendInterface)

        public:
            Backend();
            Backend(QObject *parent, const QStringList &args);
            virtual ~Backend();

            QObject *createObject(BackendInterface::Class, QObject *parent, const QList<QVariant> &args);
            QStringList availableMimeTypes() const;
            QList<int> objectDescriptionIndexes(ObjectDescriptionType type) const;
            QHash<QByteArray, QVariant> objectDescriptionProperties(ObjectDescriptionType type, int index) const;

            bool startConnectionChange(QSet<QObject *> nodes);
            bool connectNodes(QObject *source, QObject *sink);
            bool disconnectNodes(QObject *source, QObject *sink);
            bool endConnectionChange(QSet<QObject *> nodes);
        
            QT7_CS_SIGNAL_1(Public, void objectDescriptionChanged(ObjectDescriptionType un_named_arg1))
            QT7_CS_SIGNAL_2(objectDescriptionChanged,un_named_arg1) 

        private:
            bool quickTime7Available();
    };
}} // namespace Phonon::QT7

QT_END_NAMESPACE
#endif 
