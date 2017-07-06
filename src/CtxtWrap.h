#pragma once

#include <nnu.h>
#include <Ctxt.h>

class CtxtWrap : public nnu::ClassWrap<CtxtWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    CtxtWrap(const FHEPubKey& pubKey);

public:
    Ctxt ctxt;
};