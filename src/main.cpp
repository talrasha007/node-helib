#include <nan.h>

using namespace v8;
using namespace node;

NAN_MODULE_INIT(InitAll) {
    
}

NODE_MODULE(node_microbench, InitAll);