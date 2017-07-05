#pragma once

#include <nan.h>
#include <FHEContext.h>

class FHEContextWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> ctor;

    void static setup(v8::Handle<v8::Object> exports);
    static NAN_METHOD(New);

public:
    FHEContextWrap(
        unsigned long m, unsigned long p, unsigned long r,
        const vector<long>& gens = vector<long>(), 
        const vector<long>& ords = vector<long>()
    );

public:
    FHEcontext context;
};