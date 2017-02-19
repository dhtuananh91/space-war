LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := boost_system_static
LOCAL_MODULE_FILENAME := boost_system
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libboost_system.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../include
LOCAL_STATIC_LIBRARIES := cocos_ssl_static
LOCAL_STATIC_LIBRARIES += cocos_crypto_static
include $(PREBUILT_STATIC_LIBRARY)

LOCAL_MODULE := boost_thread_static
LOCAL_MODULE_FILENAME := boost_thread
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libboost_thread.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../include
LOCAL_STATIC_LIBRARIES := cocos_ssl_static
LOCAL_STATIC_LIBRARIES += cocos_crypto_static
include $(PREBUILT_STATIC_LIBRARY)