#pragma once

#include <nan.h>
#include <FHE.h>

class FHEPubKeyWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    FHEPubKeyWrap(const FHEcontext& context);
    FHEPubKeyWrap(const FHEPubKey& pubKey);

public:
    FHEPubKey key;
};

class FHESecKeyWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    FHESecKeyWrap(const FHEcontext& context);

public:
    FHESecKey key;
};