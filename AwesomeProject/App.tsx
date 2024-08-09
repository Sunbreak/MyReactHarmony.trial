
import React, { useRef, useEffect, useState } from 'react'
import {Text, View, StyleSheet, Pressable} from 'react-native';//注入组件
import { captureRef } from "react-native-view-shot";

const App = (): React.Node => {
  const viewRef = useRef();
  const [url, setUrl] = useState('')

  useEffect(() => {
    // on mount
    // @ts-ignore
    // ref.current?.captureRef?.().then(uri => {
    //   console.log("do something with ", uri);
    //   setUrl(uri)
    // });
    captureRef(viewRef, {
      format: "jpg",
      quality: 0.8,
      width: 100,
      height: 100
    }).then(
      (uri) => {
        console.log("Image saved to", uri)
        setUrl(uri)
      },
      (error) => console.error("Oops, snapshot failed", error)
    );
  }, []);

  return (
    <View>
      <Text ref={viewRef} style={{marginTop: 100, marginBottom: 50}}>...Something to rasterize...</Text>
      <Text>截图存储地址：{url}</Text>
    </View>
  );
};

export default App;
const styles = StyleSheet.create({//创建样式
 textContainer: {
   backgroundColor: 'white',
   height: 400,
   justifyContent: 'center',
   padding: 20,
 },
 title:{
   fontWeight: 'bold',
   textAlign: 'left',
   fontSize:40
 },
 content:{
   marginTop: 10,
   fontSize: 16,
   textAlign: 'left'
 }
});
