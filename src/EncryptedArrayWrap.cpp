#include "FHEContextWrap.h"

#include "EncryptedArrayWrap.h"

using namespace v8;

const char * const EncryptedArrayWrap::CLASS_NAME = "EncryptedArray";

void EncryptedArrayWrap::setupMember(v8::Handle<v8::FunctionTemplate> tpl) {

}

NAN_METHOD(EncryptedArrayWrap::ctor) {
    FHEContextWrap *cw = Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());

    EncryptedArrayWrap* eaw = new EncryptedArrayWrap(cw->context);
    eaw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

EncryptedArrayWrap::EncryptedArrayWrap(const FHEcontext& context)
: ea(context) {

}

const char * const PlaintextArrayWrap::CLASS_NAME = "PlaintextArray";

void PlaintextArrayWrap::setupMember(v8::Handle<v8::FunctionTemplate> tpl) {

}

NAN_METHOD(PlaintextArrayWrap::ctor) {
    EncryptedArrayWrap *eaw = Nan::ObjectWrap::Unwrap<EncryptedArrayWrap>(info[0]->ToObject());

    PlaintextArrayWrap* paw = new PlaintextArrayWrap(eaw->ea);
    paw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

PlaintextArrayWrap::PlaintextArrayWrap(const EncryptedArray& ea)
: pa(ea) {

}