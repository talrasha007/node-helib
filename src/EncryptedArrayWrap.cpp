#include "FHEContextWrap.h"

#include "EncryptedArrayWrap.h"

using namespace v8;

Nan::Persistent<Function> EncryptedArrayWrap::ctor;

void EncryptedArrayWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);

    exports->Set(Nan::New("EncryptedArray").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(EncryptedArrayWrap::New) {
    FHEContextWrap *cw = Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());

    EncryptedArrayWrap* eaw = new EncryptedArrayWrap(cw->context);
    eaw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

EncryptedArrayWrap::EncryptedArrayWrap(const FHEcontext& context)
: ea(context) {

}

Nan::Persistent<Function> PlaintextArrayWrap::ctor;

void PlaintextArrayWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);

    exports->Set(Nan::New("PlaintextArray").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(PlaintextArrayWrap::New) {
    EncryptedArrayWrap *eaw = Nan::ObjectWrap::Unwrap<EncryptedArrayWrap>(info[0]->ToObject());

    PlaintextArrayWrap* paw = new PlaintextArrayWrap(eaw->ea);
    paw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

PlaintextArrayWrap::PlaintextArrayWrap(const EncryptedArray& ea)
: pa(ea) {

}