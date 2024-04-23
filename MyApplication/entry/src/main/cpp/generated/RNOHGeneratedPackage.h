#pragma once

// This file was generated.

#include "RNOH/Package.h"
#include "RNOH/ArkTSTurboModule.h"

namespace rnoh {

class RNOHGeneratedPackageTurboModuleFactoryDelegate : public TurboModuleFactoryDelegate {
  public:
    SharedTurboModule createTurboModule(Context ctx, const std::string &name) const override {
        return nullptr;
    };
};

class GeneratedEventEmitRequestHandler : public EventEmitRequestHandler {
  public:
    void handleEvent(Context const &ctx) override {
        auto eventEmitter = ctx.shadowViewRegistry->getEventEmitter<facebook::react::EventEmitter>(ctx.tag);
        if (eventEmitter == nullptr) {
            return;
        }

        std::vector<std::string> supportedEventNames = {
        };
        if (std::find(supportedEventNames.begin(), supportedEventNames.end(), ctx.eventName) != supportedEventNames.end()) {
            eventEmitter->dispatchEvent(ctx.eventName, ArkJS(ctx.env).getDynamic(ctx.payload));
        }    
    }
};

class RNOHGeneratedPackage : public Package {
  public:
    RNOHGeneratedPackage(Package::Context ctx) : Package(ctx){};

    std::unique_ptr<TurboModuleFactoryDelegate> createTurboModuleFactoryDelegate() override {
        return std::make_unique<RNOHGeneratedPackageTurboModuleFactoryDelegate>();
    }

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        return {
        };
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        return {
        };
    };

    EventEmitRequestHandlers createEventEmitRequestHandlers() override {
        return {
            std::make_shared<GeneratedEventEmitRequestHandler>(),
        };
    }
};

} // namespace rnoh
