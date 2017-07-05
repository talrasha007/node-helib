#pragma once

#include <nan.h>
#include <Ctxt.h>

class CtxtWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    CtxtWrap(const FHEPubKey& pubKey);

public:
    Ctxt ctxt;
};