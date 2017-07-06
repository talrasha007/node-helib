#pragma once

#include <nnu.h>
#include <EncryptedArray.h>

class EncryptedArrayWrap : public nnu::ClassWrap<EncryptedArrayWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    EncryptedArrayWrap(const FHEcontext& context);

public:
    EncryptedArray ea;
};

class PlaintextArrayWrap : public nnu::ClassWrap<PlaintextArrayWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    PlaintextArrayWrap(const EncryptedArray& ea);

public:
    NewPlaintextArray pa;
};