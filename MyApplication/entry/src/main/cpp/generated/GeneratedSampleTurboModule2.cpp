
#include "GeneratedSampleTurboModule2.h"

// This file was generated.

namespace rnoh {
using namespace facebook;

GeneratedSampleTurboModule2::GeneratedSampleTurboModule2(const ArkTSTurboModule::Context ctx, const std::string name) : ArkTSTurboModule(ctx, name) {
    methodMap_ = {
        ARK_METHOD_METADATA(voidFunc, 0),
        ARK_ASYNC_METHOD_METADATA(emitEventFromArkTS2Cpp, 1),
        ARK_METHOD_METADATA(setNativeResponderBlocked, 3),
    };
}

} // namespace rnoh
