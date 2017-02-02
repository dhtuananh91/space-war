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

 1. Follow an instruction of **How to start a new game** from [Cocos2d-x](https://github.com/cocos2d/cocos2d-x#how-to-start-a-new-game) with v3.13.1. After setup, you should see **ANT_ROOT**, **NDK_ROOT**, **ANDROID_SDK_ROOT ** in your environment variables. Make sure these variables point to right **Apache Ant** version and **Android NDK** version as mentioned above 
 2. Navigate to **client/SpaceWar**
 3. Run ```$cocos run -p android```

----------


Project Specification
-------------
- **Structure**
> - **Client**: Space War client source code with cocos2d-x v3.13.1 source code 
> - **external**: Boost C++ Library for Android & iOS
> - **sfs-api**: SmartfoxClient API source code v1.6.4 with some modified

Highlights
----------
- Sprite
> All game objects in **space war** game uses **Sprite** class for presentation. If this is new for you, please read [Sprite Concept](http://cocos2d-x.org/docs/programmers-guide/sprites). In our project we created a template function in **GameItem.cpp** named 
```c++
template <class T> 
T* createGameItem(const std::string& filename) {
		T *sprite = new (std::nothrow) T();
		if (sprite && sprite->initWithFile(filename)) {
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return NULL;
}
```
> **Starship.cpp** use this function for creating starship with specific type
```c++
Starship* Starship::createShip(std::string type) {
	if (!strcmp(type.c_str(), "Astro"))
		return createGameItem<Starship>("ship_astro_0001.png");
	if (!strcmp(type.c_str(), "Raptor"))
		return createGameItem<Starship>("ship_raptor_0001.png");
	if (!strcmp(type.c_str(), "Viking"))
		return createGameItem<Starship>("ship_viking_0001.png");
}
```
- Animation
> We used animation for bullet's explosion event. If this is new for you, please read Sprite Animation concept at [Animation](http://www.cocos2d-x.org/wiki/Sprite_Sheet_Animation)
> For optimization, we will use **AnimationCache** for caching and reuse **Animation**. These following code in **GameScene.cpp** will do that thing in **init** function
```c++
if (!AnimationCache::getInstance()->getAnimation("exp")) {
	char* str = new char[100];
	Vector<SpriteFrame*> animFrames(11);
	for (int i = 1; i < 12; i++) {
		if (i < 10) sprintf(str, "explosion_000%d.png", i);
		else sprintf(str, "explosion_00%d.png", i);
		animFrames.pushBack(Sprite::create(str)->getSpriteFrame());
	}
	delete[]str;
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.45f / 11);
	AnimationCache::getInstance()->addAnimation(animation, "exp");
}
```
> After cache animation in **AnimationCache**, you can get it and use it later at **WeaponShot** class
```c++
Animation* animation = AnimationCache::getInstance()->getAnimation("exp");
runAction(Sequence::createWithTwoActions(Animate::create(animation), RemoveSelf::create()));
```
> **We used RemoveSelf class for removing bullet after it finished explosion animation**
- Input
> - On mobile, we need enable multi-touch feature in cocos2d-x, please read [this article](http://www.cocos2d-x.org/wiki/How_to_Enable_Multi-Touch) to understand how to do it.
> - On Windows player can use **LEFT_ARROW**, **RIGHT_ARROW** for rotating, **UP_ARROW** for thrusting and **SPACE** for shooting
> - On mobile, we will add some UI buttons help player do the same thing as Windows version does
> - We add these code in **GameScene.h** for separate this feature for each platform
```c++
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	#define SHOW_BUTTONS
#endif
```
> Please follow this definition to know how different these platform handle user's input. On Windows, we need **EventListenerKeyboard** class for receiving user's input. It's implemented in **GameScene.cpp**'s **init** function
```c++
auto listener = EventListenerKeyboard::create();
listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
```
> On mobile platform, we will add some UI buttons for user's input, these code will show how to add an UI Button in **cocos2d-x**
```c++
leftBtn = cocos2d::ui::Button::create("Left_Button_Normal.png", "Left_Button_Pressed.png", "Left_Button_Pressed.png");
leftBtn->setTitleText("");
leftBtn->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
leftBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
	switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			isLeftBtnPressed = true;
			break;
		case ui::Widget::TouchEventType::ENDED:
		case ui::Widget::TouchEventType::CANCELED:
			isLeftBtnPressed = false;
			break;
	}
});
leftBtn->setPosition(Vec2(149, 150));
addChild(leftBtn);
```
----------


Author
--------
[Dang Hoang Tuan Anh](dh.tuananh.91@gmail.com)