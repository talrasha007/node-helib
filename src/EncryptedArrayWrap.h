#pragma once

#include <nan.h>
#include <EncryptedArray.h>

class EncryptedArrayWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    EncryptedArrayWrap(const FHEcontext& context);

public:
    EncryptedArray ea;
};

class PlaintextArrayWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    PlaintextArrayWrap(const EncryptedArray& ea);

public:
    NewPlaintextArray pa;
};