import { RNPackageContext, RNPackage } from '@rnoh/react-native-openharmony/ts';
import { WebViewPackage } from 'rnoh-webview/ts';
import { SafeAreaViewPackage } from 'rnoh-safe-area/ts';
import { AsyncStoragePackage } from 'rnoh-async-storage/ts';
import { NetInfoPackage } from 'rnoh-netinfo/ts';
import { GestureHandlerPackage } from 'rnoh-gesture-handler/ts';
import { ImagePickerViewPackage } from 'rnoh-image-picker/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [
    new WebViewPackage(ctx),
    new SafeAreaViewPackage(ctx),
    new AsyncStoragePackage(ctx),
    new NetInfoPackage(ctx),
    new GestureHandlerPackage(ctx),
    new ImagePickerViewPackage(ctx),
  ];
}
