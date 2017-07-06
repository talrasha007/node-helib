#pragma once

#include <nnu.h>
#include <FHEContext.h>

class FHEContextWrap : public nnu::ClassWrap<FHEContextWrap> {
public:
    static const char * const CLASS_NAME;

    void static setupMember(v8::Handle<v8::FunctionTemplate> tpl);
    static NAN_METHOD(ctor);

public:
    FHEContextWrap(
        unsigned long m, unsigned long p, unsigned long r,
        const vector<long>& gens = vector<long>(), 
        const vector<long>& ords = vector<long>()
    );

public:
    FHEcontext context;
};