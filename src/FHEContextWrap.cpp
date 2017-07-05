#include "FHEContextWrap.h"

using namespace v8;

Nan::Persistent<Function> FHEContextWrap::ctor;

void FHEContextWrap::setup(v8::Handle<v8::Object> exports) {
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("FHEContext").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    exports->Set(Nan::New("FHEContext").ToLocalChecked(), tpl->GetFunction());
    ctor.Reset(tpl->GetFunction());
}

NAN_METHOD(FHEContextWrap::New) {
    unsigned long m = info[0]->Uint32Value();
    unsigned long p = info[1]->Uint32Value();
    unsigned long r = info[2]->Uint32Value();

    vector<long> gens, ords;

    Local<Array> gensArr = Local<Array>::Cast(info[3]);
    for (uint32_t i = 0; i < gensArr->Length(); i++) {
        gens.push_back(gensArr->Get(i)->Int32Value());
    }

    Local<Array> ordsArr = Local<Array>::Cast(info[4]);
    for (uint32_t i = 0; i < ordsArr->Length(); i++) {
        gens.push_back(ordsArr->Get(i)->Int32Value());
    }

    FHEContextWrap* paw = new FHEContextWrap(m, p, r, gens, ords);
    paw->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
}

FHEContextWrap::FHEContextWrap(unsigned long m, unsigned long p, unsigned long r, const vector<long>& gens, const vector<long>& ords)
: context(m, p, r, gens, ords) {

}