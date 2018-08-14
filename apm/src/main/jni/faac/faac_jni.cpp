//
// Created by xzl on 2018/7/17.
//

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>
#include <functional>
#include "AACEncoder.h"

using namespace std;
using namespace ZL::Codec;

#ifdef __cplusplus
extern "C" {
#endif


#define JNI_API(retType, funName, ...) extern "C"  JNIEXPORT retType Java_com_google_webrtc_apm_Faac_##funName(JNIEnv* env, jclass cls,__VA_ARGS__)
#define JNI_API1(retType, funName) extern "C"  JNIEXPORT retType Java_com_google_webrtc_apm_Faac_##funName(JNIEnv* env, jclass cls)


JNI_API(jlong,aac_1encoder_1create,jint iSampleRate, jint iAudioChannel,jint quality){
    AACEncoder *encoder = new AACEncoder;
    if(!encoder->init(iSampleRate,iAudioChannel,16,quality)){
        delete encoder;
        return 0;
    }
    return (jlong)encoder;
}

JNI_API(void ,aac_1encoder_1destory,jlong ctx){
    delete ((AACEncoder *)ctx);
}

JNI_API(jbyteArray ,aac_1encoder_1input,
        jlong ctx,
        jshortArray in_arr){
    jshort *in_ptr = env->GetShortArrayElements(in_arr,0);
    auto in_len = env->GetArrayLength(in_arr);
    AACEncoder *encoder = (AACEncoder *)ctx;
    uint8_t *out_ptr = nullptr;
    int out_len = encoder->inputData((char *)in_ptr,in_len * 2,&out_ptr);
    if(out_len <= 0 || !out_ptr){
        env->ReleaseShortArrayElements(in_arr,in_ptr,0);
        return nullptr;
    }
    env->ReleaseShortArrayElements(in_arr,in_ptr,0);
    auto out_arr = env->NewByteArray(out_len);
    env->SetByteArrayRegion(out_arr,0,out_len,(jbyte *)out_ptr);
    return out_arr;
}


#ifdef __cplusplus
}
#endif
