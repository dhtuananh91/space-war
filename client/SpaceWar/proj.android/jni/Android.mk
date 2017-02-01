LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_CFLAGS 	:= -DSMARTFOXCLIENTAPI_EXPORTS \
					-DBOOST_THREAD_PROVIDES_FUTURE

LOCAL_SRC_FILES := 	hellocpp/main.cpp \
					../../Classes/AppDelegate.cpp \
					../../Classes/ServerConnector.cpp \
					../../Classes/GameObjects/GameItem.cpp \
					../../Classes/GameObjects/Starship.cpp \
					../../Classes/Scenes/BaseScene.cpp \
					../../Classes/Scenes/GameScene.cpp \
					../../Classes/Scenes/LoginScene.cpp \
					../../Classes/Scenes/ShipScene.cpp \
					../../../../sfs-api/Bitswarm/BaseController.cpp \
					../../../../sfs-api/Bitswarm/BBox/BBClient.cpp \
					../../../../sfs-api/Bitswarm/BBox/BBEvent.cpp \
					../../../../sfs-api/Bitswarm/BitSwarmClient.cpp \
					../../../../sfs-api/Bitswarm/BitSwarmEvent.cpp \
					../../../../sfs-api/Bitswarm/ConnectionModes.cpp \
					../../../../sfs-api/Bitswarm/Message.cpp \
					../../../../sfs-api/Bitswarm/PendingPacket.cpp \
					../../../../sfs-api/Bitswarm/UDPManager.cpp \
					../../../../sfs-api/Controllers/ExtensionController.cpp \
					../../../../sfs-api/Controllers/SystemController.cpp \
					../../../../sfs-api/Core/BaseEvent.cpp \
					../../../../sfs-api/Core/DefaultPacketEncrypter.cpp \
					../../../../sfs-api/Core/PacketHeader.cpp \
					../../../../sfs-api/Core/SFSBuddyEvent.cpp \
					../../../../sfs-api/Core/SFSEvent.cpp \
					../../../../sfs-api/Core/SFSIOHandler.cpp \
					../../../../sfs-api/Core/SFSProtocolCodec.cpp \
					../../../../sfs-api/Core/Sockets/IPAddress.cpp \
					../../../../sfs-api/Core/Sockets/TCPClient.cpp \
					../../../../sfs-api/Core/Sockets/TCPClientSSL.cpp \
					../../../../sfs-api/Core/Sockets/TCPSocketLayer.cpp \
					../../../../sfs-api/Core/Sockets/UDPClient.cpp \
					../../../../sfs-api/Core/Sockets/UDPSocketLayer.cpp \
					../../../../sfs-api/Core/ThreadManager.cpp \
					../../../../sfs-api/Entities/Data/SFSArray.cpp \
					../../../../sfs-api/Entities/Data/SFSDataWrapper.cpp \
					../../../../sfs-api/Entities/Data/SFSObject.cpp \
					../../../../sfs-api/Entities/Data/Vec3D.cpp \
					../../../../sfs-api/Entities/Invitation/SFSInvitation.cpp \
					../../../../sfs-api/Entities/Managers/SFSBuddyManager.cpp \
					../../../../sfs-api/Entities/Managers/SFSGlobalUserManager.cpp \
					../../../../sfs-api/Entities/Managers/SFSRoomManager.cpp \
					../../../../sfs-api/Entities/Managers/SFSUserManager.cpp \
					../../../../sfs-api/Entities/Match/BoolMatch.cpp \
					../../../../sfs-api/Entities/Match/LogicOperator.cpp \
					../../../../sfs-api/Entities/Match/MatchExpression.cpp \
					../../../../sfs-api/Entities/Match/NumberMatch.cpp \
					../../../../sfs-api/Entities/Match/RoomProperties.cpp \
					../../../../sfs-api/Entities/Match/StringMatch.cpp \
					../../../../sfs-api/Entities/Match/UserProperties.cpp \
					../../../../sfs-api/Entities/MMOItem.cpp \
					../../../../sfs-api/Entities/MMORoom.cpp \
					../../../../sfs-api/Entities/SFSBuddy.cpp \
					../../../../sfs-api/Entities/SFSConstants.cpp \
					../../../../sfs-api/Entities/SFSRoom.cpp \
					../../../../sfs-api/Entities/SFSUser.cpp \
					../../../../sfs-api/Entities/Variables/MMOItemVariable.cpp \
					../../../../sfs-api/Entities/Variables/ReservedBuddyVariables.cpp \
					../../../../sfs-api/Entities/Variables/ReservedRoomVariables.cpp \
					../../../../sfs-api/Entities/Variables/SFSBuddyVariable.cpp \
					../../../../sfs-api/Entities/Variables/SFSRoomVariable.cpp \
					../../../../sfs-api/Entities/Variables/SFSUserVariable.cpp \
					../../../../sfs-api/Exceptions/SFSCodecError.cpp \
					../../../../sfs-api/Exceptions/SFSError.cpp \
					../../../../sfs-api/Exceptions/SFSValidationError.cpp \
					../../../../sfs-api/FSM/FiniteStateMachine.cpp \
					../../../../sfs-api/FSM/FSMState.cpp \
					../../../../sfs-api/Http/SFSWebClient.cpp \
					../../../../sfs-api/Logging/Logger.cpp \
					../../../../sfs-api/Logging/LoggerEvent.cpp \
					../../../../sfs-api/Protocol/Serialization/DefaultObjectDumpFormatter.cpp \
					../../../../sfs-api/Protocol/Serialization/DefaultSFSDataSerializer.cpp \
					../../../../sfs-api/Requests/AdminMessageRequest.cpp \
					../../../../sfs-api/Requests/BanUserRequest.cpp \
					../../../../sfs-api/Requests/BaseRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/AddBuddyRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/BlockBuddyRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/BuddyMessageRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/GoOnlineRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/InitBuddyListRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/RemoveBuddyRequest.cpp \
					../../../../sfs-api/Requests/Buddylist/SetBuddyVariablesRequest.cpp \
					../../../../sfs-api/Requests/ChangeRoomCapacityRequest.cpp \
					../../../../sfs-api/Requests/ChangeRoomNameRequest.cpp \
					../../../../sfs-api/Requests/ChangeRoomPasswordStateRequest.cpp \
					../../../../sfs-api/Requests/CreateRoomRequest.cpp \
					../../../../sfs-api/Requests/ExtensionRequest.cpp \
					../../../../sfs-api/Requests/FindRoomsRequest.cpp \
					../../../../sfs-api/Requests/FindUsersRequest.cpp \
					../../../../sfs-api/Requests/Game/CreateSFSGameRequest.cpp \
					../../../../sfs-api/Requests/Game/InvitationReplyRequest.cpp \
					../../../../sfs-api/Requests/Game/InviteUsersRequest.cpp \
					../../../../sfs-api/Requests/Game/QuickJoinGameRequest.cpp \
					../../../../sfs-api/Requests/Game/SFSGameSettings.cpp \
					../../../../sfs-api/Requests/GenericMessageRequest.cpp \
					../../../../sfs-api/Requests/HandshakeRequest.cpp \
					../../../../sfs-api/Requests/JoinRoomRequest.cpp \
					../../../../sfs-api/Requests/KickUserRequest.cpp \
					../../../../sfs-api/Requests/LeaveRoomRequest.cpp \
					../../../../sfs-api/Requests/LoginRequest.cpp \
					../../../../sfs-api/Requests/LogoutRequest.cpp \
					../../../../sfs-api/Requests/ManualDisconnectionRequest.cpp \
					../../../../sfs-api/Requests/MessageRecipientMode.cpp \
					../../../../sfs-api/Requests/MMO/MapLimits.cpp \
					../../../../sfs-api/Requests/MMO/MMORoomSettings.cpp \
					../../../../sfs-api/Requests/MMO/SetMMOItemVariables.cpp \
					../../../../sfs-api/Requests/MMO/SetUserPositionRequest.cpp \
					../../../../sfs-api/Requests/ModeratorMessageRequest.cpp \
					../../../../sfs-api/Requests/ObjectMessageRequest.cpp \
					../../../../sfs-api/Requests/PingPongRequest.cpp \
					../../../../sfs-api/Requests/PlayerToSpectatorRequest.cpp \
					../../../../sfs-api/Requests/PrivateMessageRequest.cpp \
					../../../../sfs-api/Requests/PublicMessageRequest.cpp \
					../../../../sfs-api/Requests/RoomEvents.cpp \
					../../../../sfs-api/Requests/RoomExtension.cpp \
					../../../../sfs-api/Requests/RoomPermissions.cpp \
					../../../../sfs-api/Requests/RoomSettings.cpp \
					../../../../sfs-api/Requests/SetRoomVariablesRequest.cpp \
					../../../../sfs-api/Requests/SetUserVariablesRequest.cpp \
					../../../../sfs-api/Requests/SpectatorToPlayerRequest.cpp \
					../../../../sfs-api/Requests/SubscribeRoomGroupRequest.cpp \
					../../../../sfs-api/Requests/UnsubscribeRoomGroupRequest.cpp \
					../../../../sfs-api/SmartFox.cpp \
					../../../../sfs-api/Util/md5/md5.c \
					../../../../sfs-api/Util/ByteArray.cpp \
					../../../../sfs-api/Util/ClientDisconnectionReason.cpp \
					../../../../sfs-api/Util/ConfigData.cpp \
					../../../../sfs-api/Util/ConfigLoader.cpp \
					../../../../sfs-api/Util/CryptoInitializer.cpp \
					../../../../sfs-api/Util/CryptoKey.cpp \
					../../../../sfs-api/Util/EventDispatcher.cpp \
					../../../../sfs-api/Util/LagMonitor.cpp \
					../../../../sfs-api/Util/PasswordUtil.cpp \
					../../../../sfs-api/Util/SFSErrorCodes.cpp \
					../../../../sfs-api/Util/XMLParser/XMLNode.cpp \
					../../../../sfs-api/Util/XMLParser/XMLNodeList.cpp \
					../../../../sfs-api/Util/XMLParser/XMLNodeValue.cpp \
					../../../../sfs-api/Util/XMLParser/XMLObject.cpp \
					../../../../sfs-api/Util/XMLParser/XMLParser.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../../../sfs-api \
					$(LOCAL_PATH)/../../../../external/boost/android/include \
					$(LOCAL_PATH)/../../../../external/openssl-1.0.2j/include

LOCAL_LDLIBS	:= -L$(LOCAL_PATH)/../../../../external/boost/android/lib/ -lboost_system -lboost_thread

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += cocos_ssl_static
LOCAL_STATIC_LIBRARIES += cocos_crypto_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
