#pragma once

// This file was generated.

#include "RNOHCorePackage/ComponentBinders/ViewComponentJSIBinder.h"

namespace rnoh {
class GeneratedSampleViewJSIBinder : public ViewComponentJSIBinder {
  protected:
    facebook::jsi::Object createNativeProps(facebook::jsi::Runtime &rt) override {
        auto object = ViewComponentJSIBinder::createNativeProps(rt);
        object.setProperty(rt, "intTest", true);
        object.setProperty(rt, "intWithDefault", true);
        object.setProperty(rt, "floatTest", true);
        object.setProperty(rt, "floatWithDefaultTest", true);
        object.setProperty(rt, "doubleTest", true);
        object.setProperty(rt, "doubleWithDefaultTest", true);
        object.setProperty(rt, "stringTest", true);
        object.setProperty(rt, "stringWithDefaultTest", true);
        object.setProperty(rt, "booleanTest", true);
        object.setProperty(rt, "booleanWithDefaultTest", true);
        object.setProperty(rt, "objectTest", "Object");
        object.setProperty(rt, "arrayTest", true);
        object.setProperty(rt, "stringEnumTest", true);
        object.setProperty(rt, "intEnumTest", true);
        object.setProperty(rt, "readOnlyArrayTest", true);
        object.setProperty(rt, "colorTest", true);
        return object;
    }

    facebook::jsi::Object createBubblingEventTypes(facebook::jsi::Runtime &rt) override {
        facebook::jsi::Object events(rt);
        events.setProperty(rt, "topBubblingEvent", createBubblingCapturedEvent(rt, "onBubblingEvent"));
        return events;
    }

    facebook::jsi::Object createDirectEventTypes(facebook::jsi::Runtime &rt) override {
        facebook::jsi::Object events(rt);
        events.setProperty(rt, "topDirectEvent", createDirectEvent(rt, "onDirectEvent"));
        return events;
    }
};
} // namespace rnoh
