
import {
  AnyJSBundleProvider,
  ComponentBuilderContext,
  FileJSBundleProvider,
  MetroJSBundleProvider,
  ResourceJSBundleProvider,
  RNApp,
  RNOHErrorDialog,
  RNOHLogger,
  TraceJSBundleProviderDecorator,
  RNOHCoreContext
} from '@rnoh/react-native-openharmony'
import { createRNPackages } from '../RNPackagesFactory'
import { RNLinearGradient, LINEAR_GRADIENT_TYPE } from "rnoh-linear-gradient"
import { WebView, WEB_VIEW } from "rnoh-webview"
import { SafeAreaProvider, SAFE_AREA_PROVIDER_TYPE, SafeAreaView, SAFE_AREA_VIEW_TYPE } from "rnoh-safe-area"
import { RNGestureHandlerRootView } from "rnoh-gesture-handler"
import { RNDateTimePicker, DATETIME_PICKER_VIEW_TYPE } from "rnoh-datetime-picker"
import { RNAutoLayoutView, FLASH_LIST_TYPE, RNCellContainer, CELL_CONTAINER_TYPE } from "rnoh-flash-list"
import { SVGView, SVG_VIEW_TYPE_NAME } from "rnoh-svg"
import { LottieAnimationView, LOTTIE_TYPE } from "rnoh-lottie"

@Builder
export function buildCustomRNComponent(ctx: ComponentBuilderContext) {
  if (ctx.componentName === LINEAR_GRADIENT_TYPE) {
    RNLinearGradient({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === WEB_VIEW) {
    WebView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      // buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === SAFE_AREA_PROVIDER_TYPE) {
    SafeAreaProvider({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === SAFE_AREA_VIEW_TYPE) {
    SafeAreaView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === RNGestureHandlerRootView.NAME) {
    RNGestureHandlerRootView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === DATETIME_PICKER_VIEW_TYPE) {
    RNDateTimePicker({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      // buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === FLASH_LIST_TYPE) {
    RNAutoLayoutView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === CELL_CONTAINER_TYPE) {
    RNCellContainer({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === SVG_VIEW_TYPE_NAME) {
    SVGView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      // buildCustomComponent: buildCustomRNComponent
    })
  } else if (ctx.componentName === LOTTIE_TYPE) {
    LottieAnimationView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      // buildCustomComponent: buildCustomRNComponent
    })
  }
}
const wrappedCustomRNComponentBuilder = wrapBuilder(buildCustomRNComponent)
@Entry
@Component
struct Index {
  @StorageLink('RNOHCoreContext') private rnohCoreContext: RNOHCoreContext | undefined = undefined
  @State shouldShow: boolean = false
  private logger!: RNOHLogger

  aboutToAppear() {
    this.logger = this.rnohCoreContext!.logger.clone("Index")
    const stopTracing = this.logger.clone("aboutToAppear").startTracing()
    this.shouldShow = true
    stopTracing()
  }

  onBackPress(): boolean | undefined {
    // NOTE: this is required since `Ability`'s `onBackPressed` function always
    // terminates or puts the app in the background, but we want Ark to ignore it completely
    // when handled by RN
    this.rnohCoreContext!.dispatchBackPress()
    return  true

  }

  build() {
    Column() {
      if (this.rnohCoreContext && this.shouldShow) {
        if (this.rnohCoreContext?.isDebugModeEnabled) {
          RNOHErrorDialog({ ctx: this.rnohCoreContext })
        }
        RNApp({
          rnInstanceConfig: {
            createRNPackages,
            enableNDKTextMeasuring: true,
            enableBackgroundExecutor: false,
          },
          initialProps: { "foo": "bar" } as Record<string, string>,
          appKey: "app_name",
          wrappedCustomRNComponentBuilder: wrappedCustomRNComponentBuilder,
          onSetUp: (rnInstance) => {
            rnInstance.enableFeatureFlag("ENABLE_RN_INSTANCE_CLEAN_UP")
          },
          jsBundleProvider: new TraceJSBundleProviderDecorator(
            new AnyJSBundleProvider([
              new MetroJSBundleProvider(),
              // NOTE: to load the bundle from file, place it in
              // `/data/app/el2/100/base/com.rnoh.tester/files/bundle.harmony.js`
              // on your device. The path mismatch is due to app sandboxing on HarmonyOS
              new FileJSBundleProvider('/data/storage/el2/base/files/bundle.harmony.js'),
              new ResourceJSBundleProvider(this.rnohCoreContext.uiAbilityContext.resourceManager, 'hermes_bundle.hbc'),
              new ResourceJSBundleProvider(this.rnohCoreContext.uiAbilityContext.resourceManager, 'bundle.harmony.js')
            ]),
            this.rnohCoreContext.logger),
        })
      }
    }
    .height('100%')
    .width('100%')
  }
}
