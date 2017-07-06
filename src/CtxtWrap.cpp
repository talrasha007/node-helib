#include "FHESecKeyWrap.h"

#include "CtxtWrap.h"

using namespace v8;

const char * const CtxtWrap::CLASS_NAME = "Ctxt";

void CtxtWrap::setupMember(v8::Handle<v8::FunctionTemplate> tpl) {

}

NAN_METHOD(CtxtWrap::ctor) {
    FHEPubKeyWrap *pw = Nan::ObjectWrap::Unwrap<FHEPubKeyWrap>(info[0]->ToObject());

    CtxtWrap* paw = new CtxtWrap(pw->key);
    paw->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

CtxtWrap::CtxtWrap(const FHEPubKey& pubKey)
: ctxt(pubKey) {

}