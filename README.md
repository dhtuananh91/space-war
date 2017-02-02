Overview
-------------

The **SpaceWar** example is a tribute to to the homonymous game developed in the 60s, one of the earliest computer games in history! The purpose of this example is to showcase the capabilities of SmartFoxServer 2X **MMO Rooms** in a realtime game featuring flying starships, weapon shots, collisions... with the possibility of having thousands of them in the same Room.

This example is a porting of its Flash counterpart. The two versions of the game share the same server-side Extension, which contains the core logic of the game, and a similar approach in client development. Also, the game flow and basic concepts like clients synchronization and Room configuration (but not only) are the same for the two versions. For this reason I strongly recommend that you read the in-depth **Flash tutorial** to learn the multiplayer programming techniques used in the **cocos2d-x** game too.

----------


Dependencies
-------------
- [Cocos2dx v3.13.1](https://github.com/cocos2d/cocos2d-x/archive/cocos2d-x-3.13.1.zip)
- [Android NDK R10e](https://dl.google.com/android/repository/android-ndk-r10e-darwin-x86_64.zip)
- [Apache Ant v1.9.7](http://archive.apache.org/dist/ant/binaries/apache-ant-1.9.7-bin.zip)
- **Boost C++ Library v1.59** (included in external folder)
- **OpenSSL v1.0.2j** (included in external folder)


----------


Environment
-------------
- **Windows 10**
- **macOS Sierra 10.12.1**

----------


Platform
-------------
- **Android** with version >= 15
- **iOS** with version >= 8.0
- **Windows**

----------


Build
-------------
#### <i class="icon-folder"></i> Build on iOS

 1. Open the project at **client/SpaceWar/proj.ios_mac**
 2. Change the bundle identifier into which one you want
 3. Press build
 4. Run on device

> **Note:**
> - Boost C++ Libraries was built without i386 so the project **cannot** run on iOS emulator

#### <i class="icon-folder"></i> Build on Android

 1. Follow an instruction of **How to start a new game** from [Cocos2d-x](https://github.com/cocos2d/cocos2d-x#how-to-start-a-new-game) with v3.13.1. After setup, you should see **ANT_ROOT**, **NDK_ROOT**, **ANDROID_SDK_ROOT** in your environment variables. Make sure these variables point to right **Apache Ant** version and **Android NDK** version as mentioned above 
 2. Navigate to **client/SpaceWar**
 3. Run ```$cocos run -p android```

----------


Project Specification
-------------
> **Structure**
> - **Client**: Space War client source code with cocos2d-x v3.13.1 source code 
> - **external**: Boost C++ Library for Android & iOS
> - **sfs-api**: SmartfoxClient API source code v1.6.4 with some modified

----------


Author
--------
[Dang Hoang Tuan Anh](mailto:dh.tuananh.91@gmail.com)