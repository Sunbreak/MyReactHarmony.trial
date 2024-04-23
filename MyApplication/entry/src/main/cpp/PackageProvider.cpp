#include "RNOH/PackageProvider.h"
#include "generated/RNOHGeneratedPackage.h"
#include "LinearGradientPackage.h"
#include "WebViewPackage.h"
#include "SafeAreaViewPackage.h"
#include "AsyncStoragePackage.h"
#include "RNCNetInfoPackage.h"
#include "GestureHandlerPackage.h"
#include "RNImagePickerPackage.h"
#include "DateTimePickerPackage.h"
#include "FlashListPackage.h"
#include "SVGPackage.h"
#include "LottieAnimationViewPackage.h"

using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {
        std::make_shared<RNOHGeneratedPackage>(ctx), 
        std::make_shared<LinearGradientPackage>(ctx),
        std::make_shared<WebViewPackage>(ctx),
        std::make_shared<SafeAreaViewPackage>(ctx),
        std::make_shared<AsyncStoragePackage>(ctx),
        std::make_shared<RNCNetInfoPackage>(ctx),
        std::make_shared<GestureHandlerPackage>(ctx),
        std::make_shared<RNImagePickerPackage>(ctx),
        std::make_shared<DateTimePickerPackage>(ctx),
        std::make_shared<FlashListPackage>(ctx),
        std::make_shared<SVGPackage>(ctx),
        std::make_shared<LottieAnimationViewPackage>(ctx),
    };
}