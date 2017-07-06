#pragma once

#include <nnu.h>
#include <FHE.h>

class FHEPubKeyWrap : public nnu::ClassWrap<FHEPubKeyWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    FHEPubKeyWrap(const FHEcontext& context);
    FHEPubKeyWrap(const FHEPubKey& pubKey);

public:
    FHEPubKey key;
};

class FHESecKeyWrap : public nnu::ClassWrap<FHESecKeyWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    FHESecKeyWrap(const FHEcontext& context);

public:
    FHESecKey key;
};