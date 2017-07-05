#include "FHESecKeyWrap.h"

#include "CtxtWrap.h"

using namespace v8;

Nan::Persistent<Function> CtxtWrap::ctor;

void CtxtWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Ctxt").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    exports->Set(Nan::New("Ctxt").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(CtxtWrap::New) {
    FHEPubKeyWrap *pw = Nan::ObjectWrap::Unwrap<FHEPubKeyWrap>(info[0]->ToObject());

    CtxtWrap* paw = new CtxtWrap(pw->key);
    paw->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

CtxtWrap::CtxtWrap(const FHEPubKey& pubKey)
: ctxt(pubKey) {

}