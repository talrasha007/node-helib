#include "FHEContextWrap.h"

#include "FHESecKeyWrap.h"

using namespace v8;

Nan::Persistent<Function> FHEPubKeyWrap::ctor;

void FHEPubKeyWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("FHEPubKey").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    exports->Set(Nan::New("FHEPubKey").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(FHEPubKeyWrap::New) {
    FHEContextWrap *cw = !info[0]->BooleanValue() ? nullptr : Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());
    FHESecKeyWrap *kw = !info[1]->BooleanValue() ? nullptr : Nan::ObjectWrap::Unwrap<FHESecKeyWrap>(info[1]->ToObject());

    FHEPubKeyWrap* paw = kw ?
        new FHEPubKeyWrap(kw->key) :
        new FHEPubKeyWrap(cw->context);

    paw->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

FHEPubKeyWrap::FHEPubKeyWrap(const FHEcontext& context)
: key(context) {

}

FHEPubKeyWrap::FHEPubKeyWrap(const FHEPubKey& pubKey)
: key(pubKey) {
    
}

Nan::Persistent<Function> FHESecKeyWrap::ctor;

void FHESecKeyWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("FHESecKey").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    exports->Set(Nan::New("FHESecKey").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(FHESecKeyWrap::New) {
    FHEContextWrap *cw = Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());

    FHESecKeyWrap* paw = new FHESecKeyWrap(cw->context);
    paw->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

FHESecKeyWrap::FHESecKeyWrap(const FHEcontext& context)
: key(context) {

}