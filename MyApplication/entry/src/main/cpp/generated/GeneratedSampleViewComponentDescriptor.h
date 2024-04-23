
#pragma once

// This file was generated.

#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/components/view/ViewShadowNode.h>

namespace facebook {
namespace react {

extern const char GeneratedSampleViewComponentName[] = "GeneratedSampleView";

class GeneratedSampleViewProps : public ViewProps {
  public:
    GeneratedSampleViewProps() = default;

    GeneratedSampleViewProps(const PropsParserContext &context, const GeneratedSampleViewProps &sourceProps, const RawProps &rawProps)
        : ViewProps(context, sourceProps, rawProps) {}
};

using GeneratedSampleViewShadowNode = ConcreteViewShadowNode<
    GeneratedSampleViewComponentName,
    GeneratedSampleViewProps,
    ViewEventEmitter>;

class GeneratedSampleViewComponentDescriptor final
    : public ConcreteComponentDescriptor<GeneratedSampleViewShadowNode> {
  public:
    GeneratedSampleViewComponentDescriptor(ComponentDescriptorParameters const &parameters)
        : ConcreteComponentDescriptor(parameters) {}
};

} // namespace react
} // namespace facebook
