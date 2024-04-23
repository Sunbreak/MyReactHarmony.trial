
import {
  SampleComponent,
} from 'react-native-harmony-sample-package';
import {useState} from 'react';
import React from 'react';
import { Button, View, Text, StyleSheet } from 'react-native';

export function CustomNativeComponentTest() {
  return (
      <View style={{ width: '100%', height: 300, backgroundColor: 'white' }}>
        <Text style={{ fontSize: 40, fontWeight: 'bold', margin: 20 }}>SamplePackage</Text>
        <View style={{ flexDirection: 'row', justifyContent: 'space-evenly' }}>
          <SampleComponent backgroundColor="red" size={64} />
          <SampleComponent backgroundColor="red" size={64}>
            <SampleComponent backgroundColor="green" size={32} />
          </SampleComponent>
          <SampleComponent backgroundColor="red" size={64}>
            <Blinker>
              <SampleComponent backgroundColor="blue" size={32} />
            </Blinker>
          </SampleComponent>
        </View>
      </View>
  );
}

function Blinker({children}: any) {
  const [isVisible, setIsVisible] = useState(true);

  return (
    <React.Fragment>
      <Button
        title="Run"
        onPress={() => {
          setIsVisible(prev => !prev);
        }}
      />
      {isVisible && children}
    </React.Fragment>
  );
}

const styles = StyleSheet.create({//创建样式
  sampleStyle:{
    margin: 20,
  }
 });