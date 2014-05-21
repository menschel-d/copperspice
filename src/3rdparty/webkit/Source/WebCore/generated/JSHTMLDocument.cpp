/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSHTMLDocument.h"

#include "Element.h"
#include "ExceptionCode.h"
#include "HTMLCollection.h"
#include "HTMLDocument.h"
#include "JSDOMBinding.h"
#include "JSElement.h"
#include "JSHTMLCollection.h"
#include "KURL.h"
#include "wtf/text/AtomicString.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLDocument);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDocumentTableValues[17] =
{
    { "embeds", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentEmbeds), (intptr_t)0 THUNK_GENERATOR(0) },
    { "plugins", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentPlugins), (intptr_t)0 THUNK_GENERATOR(0) },
    { "scripts", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentScripts), (intptr_t)0 THUNK_GENERATOR(0) },
    { "all", 0, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentAll), (intptr_t)setJSHTMLDocumentAll THUNK_GENERATOR(0) },
    { "width", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentWidth), (intptr_t)0 THUNK_GENERATOR(0) },
    { "height", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentHeight), (intptr_t)0 THUNK_GENERATOR(0) },
    { "dir", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentDir), (intptr_t)setJSHTMLDocumentDir THUNK_GENERATOR(0) },
    { "designMode", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentDesignMode), (intptr_t)setJSHTMLDocumentDesignMode THUNK_GENERATOR(0) },
    { "compatMode", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentCompatMode), (intptr_t)0 THUNK_GENERATOR(0) },
    { "activeElement", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentActiveElement), (intptr_t)0 THUNK_GENERATOR(0) },
    { "bgColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentBgColor), (intptr_t)setJSHTMLDocumentBgColor THUNK_GENERATOR(0) },
    { "fgColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentFgColor), (intptr_t)setJSHTMLDocumentFgColor THUNK_GENERATOR(0) },
    { "alinkColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentAlinkColor), (intptr_t)setJSHTMLDocumentAlinkColor THUNK_GENERATOR(0) },
    { "linkColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentLinkColor), (intptr_t)setJSHTMLDocumentLinkColor THUNK_GENERATOR(0) },
    { "vlinkColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentVlinkColor), (intptr_t)setJSHTMLDocumentVlinkColor THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLDocumentConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDocumentTable = { 36, 31, JSHTMLDocumentTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDocumentConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDocumentConstructorTable = { 1, 0, JSHTMLDocumentConstructorTableValues, 0 };
class JSHTMLDocumentConstructor : public DOMConstructorObject {
public:
    JSHTMLDocumentConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLDocumentConstructor::s_info = { "HTMLDocumentConstructor", &DOMConstructorObject::s_info, &JSHTMLDocumentConstructorTable, 0 };

JSHTMLDocumentConstructor::JSHTMLDocumentConstructor(ExecState* exec, Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSHTMLDocumentPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSHTMLDocumentConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLDocumentConstructor, JSDOMWrapper>(exec, &JSHTMLDocumentConstructorTable, this, propertyName, slot);
}

bool JSHTMLDocumentConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLDocumentConstructor, JSDOMWrapper>(exec, &JSHTMLDocumentConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLDocumentPrototypeTableValues[9] =
{
    { "open", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionOpen), (intptr_t)0 THUNK_GENERATOR(0) },
    { "close", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionClose), (intptr_t)0 THUNK_GENERATOR(0) },
    { "write", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionWrite), (intptr_t)1 THUNK_GENERATOR(0) },
    { "writeln", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionWriteln), (intptr_t)1 THUNK_GENERATOR(0) },
    { "clear", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionClear), (intptr_t)0 THUNK_GENERATOR(0) },
    { "captureEvents", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionCaptureEvents), (intptr_t)0 THUNK_GENERATOR(0) },
    { "releaseEvents", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionReleaseEvents), (intptr_t)0 THUNK_GENERATOR(0) },
    { "hasFocus", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLDocumentPrototypeFunctionHasFocus), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLDocumentPrototypeTable = { 17, 15, JSHTMLDocumentPrototypeTableValues, 0 };
const ClassInfo JSHTMLDocumentPrototype::s_info = { "HTMLDocumentPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSHTMLDocumentPrototypeTable, 0 };

JSObject* JSHTMLDocumentPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLDocument>(exec, globalObject);
}

bool JSHTMLDocumentPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLDocumentPrototypeTable, this, propertyName, slot);
}

bool JSHTMLDocumentPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLDocumentPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLDocument::s_info = { "HTMLDocument", &JSDocument::s_info, &JSHTMLDocumentTable, 0 };

JSHTMLDocument::JSHTMLDocument(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLDocument> impl)
    : JSDocument(structure, globalObject, impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSHTMLDocument::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLDocumentPrototype(exec->globalData(), globalObject, JSHTMLDocumentPrototype::createStructure(exec->globalData(), JSDocumentPrototype::self(exec, globalObject)));
}

bool JSHTMLDocument::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    if (canGetItemsForName(exec, static_cast<HTMLDocument*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return getStaticValueSlot<JSHTMLDocument, Base>(exec, &JSHTMLDocumentTable, this, propertyName, slot);
}

bool JSHTMLDocument::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    if (canGetItemsForName(exec, static_cast<HTMLDocument*>(impl()), propertyName)) {
        PropertySlot slot;
        slot.setCustom(this, nameGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), ReadOnly | DontDelete | DontEnum);
        return true;
    }
    return getStaticValueDescriptor<JSHTMLDocument, Base>(exec, &JSHTMLDocumentTable, this, propertyName, descriptor);
}

JSValue jsHTMLDocumentEmbeds(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->embeds()));
    return result;
}


JSValue jsHTMLDocumentPlugins(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->plugins()));
    return result;
}


JSValue jsHTMLDocumentScripts(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->scripts()));
    return result;
}


JSValue jsHTMLDocumentAll(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    return castedThis->all(exec);
}


JSValue jsHTMLDocumentWidth(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsNumber(imp->width());
    return result;
}


JSValue jsHTMLDocumentHeight(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsNumber(imp->height());
    return result;
}


JSValue jsHTMLDocumentDir(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->dir());
    return result;
}


JSValue jsHTMLDocumentDesignMode(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->designMode());
    return result;
}


JSValue jsHTMLDocumentCompatMode(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->compatMode());
    return result;
}


JSValue jsHTMLDocumentActiveElement(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->activeElement()));
    return result;
}


JSValue jsHTMLDocumentBgColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->bgColor());
    return result;
}


JSValue jsHTMLDocumentFgColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->fgColor());
    return result;
}


JSValue jsHTMLDocumentAlinkColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->alinkColor());
    return result;
}


JSValue jsHTMLDocumentLinkColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->linkColor());
    return result;
}


JSValue jsHTMLDocumentVlinkColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    JSValue result = jsString(exec, imp->vlinkColor());
    return result;
}


JSValue jsHTMLDocumentConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLDocument* domObject = static_cast<JSHTMLDocument*>(asObject(slotBase));
    return JSHTMLDocument::getConstructor(exec, domObject->globalObject());
}

void JSHTMLDocument::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLDocument, Base>(exec, propertyName, value, &JSHTMLDocumentTable, this, slot);
}

void setJSHTMLDocumentAll(ExecState* exec, JSObject* thisObject, JSValue value)
{
    static_cast<JSHTMLDocument*>(thisObject)->setAll(exec, value);
}


void setJSHTMLDocumentDir(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setDir(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentDesignMode(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setDesignMode(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentBgColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setBgColor(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentFgColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setFgColor(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentAlinkColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setAlinkColor(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentLinkColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setLinkColor(valueToStringWithNullCheck(exec, value));
}


void setJSHTMLDocumentVlinkColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(thisObject);
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());
    imp->setVlinkColor(valueToStringWithNullCheck(exec, value));
}


JSValue JSHTMLDocument::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLDocumentConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionOpen(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    return JSValue::encode(castedThis->open(exec));
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionClose(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());

    imp->close();
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionWrite(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    return JSValue::encode(castedThis->write(exec));
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionWriteln(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    return JSValue::encode(castedThis->writeln(exec));
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionClear(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());

    imp->clear();
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionCaptureEvents(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());

    imp->captureEvents();
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionReleaseEvents(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());

    imp->releaseEvents();
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsHTMLDocumentPrototypeFunctionHasFocus(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLDocument::s_info))
        return throwVMTypeError(exec);
    JSHTMLDocument* castedThis = static_cast<JSHTMLDocument*>(asObject(thisValue));
    HTMLDocument* imp = static_cast<HTMLDocument*>(castedThis->impl());


    JSC::JSValue result = jsBoolean(imp->hasFocus());
    return JSValue::encode(result);
}


}
