
#include "GeneratedSampleTurboModule.h"

// This file was generated.

namespace rnoh {
using namespace facebook;

GeneratedSampleTurboModule::GeneratedSampleTurboModule(const ArkTSTurboModule::Context ctx, const std::string name) : ArkTSTurboModule(ctx, name) {
    methodMap_ = {
        ARK_METHOD_METADATA(voidFunc, 0),
        ARK_METHOD_METADATA(getBool, 1),
        ARK_METHOD_METADATA(getString, 1),
        ARK_METHOD_METADATA(getObject, 1),
        ARK_METHOD_METADATA(registerFunction, 1),
        ARK_ASYNC_METHOD_METADATA(doAsyncJob, 1),
        ARK_ASYNC_METHOD_METADATA(getPromisedArray, 0),
        ARK_METHOD_METADATA(getUnionValue, 1),
        ARK_METHOD_METADATA(getEnum, 3),
        ARK_METHOD_METADATA(getUnknown, 1),
        ARK_METHOD_METADATA(getRootTag, 1),
    };
}

} // namespace rnoh
