#include "FHEContextWrap.h"

#include "FHESecKeyWrap.h"

using namespace v8;

const char * const FHEPubKeyWrap::CLASS_NAME = "FHEPubKey";

void FHEPubKeyWrap::setupMember(v8::Handle<v8::FunctionTemplate> tpl) {

}

NAN_METHOD(FHEPubKeyWrap::ctor) {
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

const char * const FHESecKeyWrap::CLASS_NAME = "FHESecKey";

void FHESecKeyWrap::setupMember(v8::Handle<v8::FunctionTemplate> tpl) {

}

NAN_METHOD(FHESecKeyWrap::ctor) {
    FHEContextWrap *cw = Nan::ObjectWrap::Unwrap<FHEContextWrap>(info[0]->ToObject());

    FHESecKeyWrap* paw = new FHESecKeyWrap(cw->context);
    paw->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

FHESecKeyWrap::FHESecKeyWrap(const FHEcontext& context)
: key(context) {

}