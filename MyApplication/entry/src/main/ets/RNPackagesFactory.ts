import { RNPackageContext, RNPackage } from '@rnoh/react-native-openharmony/ts';
import { SamplePackage } from 'rnoh-sample-package/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [new SamplePackage(ctx)];
}
