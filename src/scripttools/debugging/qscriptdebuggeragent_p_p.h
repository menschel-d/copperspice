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

#ifndef QSCRIPTDEBUGGERAGENT_P_P_H
#define QSCRIPTDEBUGGERAGENT_P_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtScript/qscriptvalue.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qhash.h>
#include <QtCore/qmap.h>
#include <QtCore/qlist.h>

#include "qscriptscriptdata_p.h"
#include "qscriptbreakpointdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerAgent;
class QScriptDebuggerAgentPrivate
{
public:
    enum State {
        NoState,
        SteppingIntoState,
        SteppedIntoState,
        SteppingOverState,
        SteppedOverState,
        SteppingOutState,
        SteppedOutState,
        RunningToLocationState,
        ReachedLocationState,
        InterruptingState,
        InterruptedState,
        BreakpointState,
        ReturningByForceState,
        ReturnedByForceState
    };

    QScriptDebuggerAgentPrivate();
    ~QScriptDebuggerAgentPrivate();

    static QScriptDebuggerAgentPrivate *get(QScriptDebuggerAgent *);

    State state;
    int stepDepth;
    int stepCount;
    int targetScriptId;
    QString targetFileName;
    int targetLineNumber;
    QScriptValue stepResult;
    int returnCounter;
    QScriptValue returnValue;

    int nextBreakpointId;
    QHash<qint64, QList<int> > resolvedBreakpoints;
    QHash<QString, QList<int> > unresolvedBreakpoints;
    QScriptBreakpointMap breakpoints;
    int hitBreakpointId;

    QScriptScriptMap scripts;
    QScriptScriptMap checkpointScripts;
    QScriptScriptMap previousCheckpointScripts;
    QList<QList<qint64> > scriptIdStack;

    QList<qint64> contextIdStack;
    QList<qint64> checkpointContextIdStack;
    qint64 nextContextId;

    QTime processEventsTimer;
    int statementCounter;

    QScriptDebuggerBackendPrivate *backend;
};

QT_END_NAMESPACE

#endif
