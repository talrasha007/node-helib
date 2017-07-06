#include "FHESecKeyWrap.h"

#include "CtxtWrap.h"

using namespace v8;

const char * const CtxtWrap::CLASS_NAME = "Ctxt";

void CtxtWrap::setupMember(v8::Handle<v8::FunctionTemplate> &tpl) {
    Serializable::setupMember<CtxtWrap>(tpl);
    Nan::SetPrototypeMethod(tpl, "add", wrapFunction<&CtxtWrap::add>);
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

NAN_METHOD(CtxtWrap::add) {
    CtxtWrap *o = Nan::ObjectWrap::Unwrap<CtxtWrap>(info[0]->ToObject());
    ctxt += o->ctxt;

    info.GetReturnValue().Set(info.This());
}

void CtxtWrap::read(std::istream& is) {
    is >> ctxt;
}

void CtxtWrap::write(std::ostream& os) {
    os << ctxt;
}