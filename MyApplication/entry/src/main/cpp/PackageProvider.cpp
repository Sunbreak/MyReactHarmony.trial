#include "RNOH/PackageProvider.h"
#include "SamplePackage.h"
#include "ViewShotPackage.h"
#include "generated/RNOHGeneratedPackage.h"

using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {
        std::make_shared<RNOHGeneratedPackage>(ctx), 
        std::make_shared<SamplePackage>(ctx),
        std::make_shared<ViewShotPackage>(ctx),
    };
}