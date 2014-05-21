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

#ifndef QGESTUREMANAGER_P_H
#define QGESTUREMANAGER_P_H

#include "qobject.h"
#include "qbasictimer.h"
#include "qwidget_p.h"
#include "qgesturerecognizer.h"

#ifndef QT_NO_GESTURES

QT_BEGIN_NAMESPACE

class QBasicTimer;
class QGraphicsObject;
class QGestureManager : public QObject
{
    CS_OBJECT(QGestureManager)
public:
    QGestureManager(QObject *parent);
    ~QGestureManager();

    Qt::GestureType registerGestureRecognizer(QGestureRecognizer *recognizer);
    void unregisterGestureRecognizer(Qt::GestureType type);

    bool filterEvent(QWidget *receiver, QEvent *event);
    bool filterEvent(QObject *receiver, QEvent *event);
#ifndef QT_NO_GRAPHICSVIEW
    bool filterEvent(QGraphicsObject *receiver, QEvent *event);
#endif //QT_NO_GRAPHICSVIEW

    static QGestureManager* instance(); // declared in qapplication.cpp

    void cleanupCachedGestures(QObject *target, Qt::GestureType type);

    void recycle(QGesture *gesture);

protected:
    bool filterEventThroughContexts(const QMultiMap<QObject *, Qt::GestureType> &contexts,
                                    QEvent *event);

private:
    QMultiMap<Qt::GestureType, QGestureRecognizer *> m_recognizers;

    QSet<QGesture *> m_activeGestures;
    QSet<QGesture *> m_maybeGestures;

    enum State {
        Gesture,
        NotGesture,
        MaybeGesture // this means timers are up and waiting for some
                     // more events, and input events are handled by
                     // gesture recognizer explicitly
    } state;

    struct ObjectGesture
    {
        QObject* object;
        Qt::GestureType gesture;

        ObjectGesture(QObject *o, const Qt::GestureType &g) : object(o), gesture(g) { }
        inline bool operator<(const ObjectGesture &rhs) const
        {
            if (object < rhs.object)
                return true;
            if (object == rhs.object)
                return gesture < rhs.gesture;
            return false;
        }
    };

    QMap<ObjectGesture, QList<QGesture *> > m_objectGestures;
    QHash<QGesture *, QGestureRecognizer *> m_gestureToRecognizer;
    QHash<QGesture *, QObject *> m_gestureOwners;

    QHash<QGesture *, QWidget *> m_gestureTargets;

    int m_lastCustomGestureId;

    QHash<QGestureRecognizer *, QSet<QGesture *> > m_obsoleteGestures;
    QHash<QGesture *, QGestureRecognizer *> m_deletedRecognizers;
    QSet<QGesture *> m_gesturesToDelete;
    void cleanupGesturesForRemovedRecognizer(QGesture *gesture);

    QGesture *getState(QObject *widget, QGestureRecognizer *recognizer,
                       Qt::GestureType gesture);
    void deliverEvents(const QSet<QGesture *> &gestures,
                       QSet<QGesture *> *undeliveredGestures);
    void getGestureTargets(const QSet<QGesture*> &gestures,
                           QMap<QWidget *, QList<QGesture *> > *conflicts,
                           QMap<QWidget *, QList<QGesture *> > *normal);

    void cancelGesturesForChildren(QGesture *originatingGesture);
};

QT_END_NAMESPACE

#endif // QT_NO_GESTURES

#endif // QGESTUREMANAGER_P_H
