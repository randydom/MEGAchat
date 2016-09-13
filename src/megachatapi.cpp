/**
 * @file megachatapi.cpp
 * @brief Intermediate layer for the MEGA Chat C++ SDK.
 *
 * (c) 2013-2016 by Mega Limited, Auckland, New Zealand
 *
 * This file is part of the MEGA SDK - Client Access Engine.
 *
 * Applications using the MEGA API must present a valid application key
 * and comply with the the rules set forth in the Terms of Service.
 *
 * The MEGA SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @copyright Simplified (2-clause) BSD License.
 *
 * You should have received a copy of the license along with this
 * program.
 */


#include <megaapi_impl.h>
#include <megaapi.h>
#include "megachatapi.h"
#include "megachatapi_impl.h"

#include <chatClient.h>
#include <karereCommon.h>

// define the weak symbol for Logger to know where to create the log file
namespace karere
{
    APP_ALWAYS_EXPORT std::string getAppDir() { return karere::createAppDir(); }
}

using namespace mega;
using namespace megachat;

MegaChatCall::~MegaChatCall()
{
}

MegaChatCall *MegaChatCall::copy()
{
    return NULL;
}

int MegaChatCall::getStatus() const
{
    return 0;
}

int MegaChatCall::getTag() const
{
    return 0;
}

MegaChatHandle MegaChatCall::getContactHandle() const
{
    return INVALID_HANDLE;
}

MegaChatApi::MegaChatApi(MegaApi *megaApi)
{
    this->pImpl = new MegaChatApiImpl(this, megaApi);
}

MegaChatApi::~MegaChatApi()
{
    delete pImpl;
}

void MegaChatApi::init(MegaChatRequestListener *listener)
{
    pImpl->init(listener);
}

void MegaChatApi::connect(MegaChatRequestListener *listener)
{
    pImpl->connect(listener);
}

//MegaChatApi::MegaChatApi(const char *appKey, const char *appDir)
//{
//    this->pImpl = new MegaChatApiImpl(this, appKey, appDir);
//}

void MegaChatApi::setOnlineStatus(int status, MegaChatRequestListener *listener)
{
    pImpl->setOnlineStatus(status, listener);
}

MegaChatRoomList *MegaChatApi::getChatRooms()
{
    return pImpl->getChatRooms();
}

void MegaChatApi::createChat(bool group, MegaChatPeerList *peers, MegaChatRequestListener *listener)
{
    pImpl->createChat(group, peers, listener);
}

void MegaChatApi::inviteToChat(MegaChatHandle chatid, MegaChatHandle uh, int privilege, MegaChatRequestListener *listener)
{
    pImpl->inviteToChat(chatid, uh, privilege, listener);
}

void MegaChatApi::removeFromChat(MegaChatHandle chatid, MegaChatHandle uh, MegaChatRequestListener *listener)
{
    pImpl->removeFromChat(chatid, uh, listener);
}

void MegaChatApi::updateChatPermissions(MegaChatHandle chatid, MegaChatHandle uh, int privilege, MegaChatRequestListener *listener)
{
    pImpl->updateChatPermissions(chatid, uh, privilege, listener);
}

void MegaChatApi::truncateChat(MegaChatHandle chatid, MegaChatHandle messageid, MegaChatRequestListener *listener)
{
    pImpl->truncateChat(chatid, messageid, listener);
}

void MegaChatApi::setChatTitle(MegaChatHandle chatid, const char *title, MegaChatRequestListener *listener)
{
    pImpl->setChatTitle(chatid, title, listener);
}

MegaStringList *MegaChatApi::getChatAudioInDevices()
{
    return pImpl->getChatAudioInDevices();
}

MegaStringList *MegaChatApi::getChatVideoInDevices()
{
    return pImpl->getChatVideoInDevices();
}

bool MegaChatApi::setChatAudioInDevice(const char *device)
{
    return pImpl->setChatAudioInDevice(device);
}

bool MegaChatApi::setChatVideoInDevice(const char *device)
{
    return pImpl->setChatVideoInDevice(device);
}

void MegaChatApi::startChatCall(MegaUser *peer, bool enableVideo, MegaChatRequestListener *listener)
{
    pImpl->startChatCall(peer, enableVideo, listener);
}

void MegaChatApi::answerChatCall(MegaChatCall *call, bool accept, MegaChatRequestListener *listener)
{
    pImpl->answerChatCall(call, accept, listener);
}

void MegaChatApi::hangAllChatCalls()
{
    pImpl->hangAllChatCalls();
}

void MegaChatApi::addChatCallListener(MegaChatCallListener *listener)
{
    pImpl->addChatCallListener(listener);
}

void MegaChatApi::removeChatCallListener(MegaChatCallListener *listener)
{
    pImpl->removeChatCallListener(listener);
}

void MegaChatApi::addChatLocalVideoListener(MegaChatVideoListener *listener)
{
    pImpl->addChatLocalVideoListener(listener);
}

void MegaChatApi::removeChatLocalVideoListener(MegaChatVideoListener *listener)
{
    pImpl->removeChatLocalVideoListener(listener);
}

void MegaChatApi::addChatRemoteVideoListener(MegaChatVideoListener *listener)
{
    pImpl->addChatRemoteVideoListener(listener);
}

void MegaChatApi::removeChatRemoteVideoListener(MegaChatVideoListener *listener)
{
    pImpl->removeChatRemoteVideoListener(listener);
}

void MegaChatApi::addChatListener(MegaChatListener *listener)
{
    pImpl->addChatListener(listener);
}

void MegaChatApi::removeChatListener(MegaChatListener *listener)
{
    pImpl->removeChatListener(listener);
}

void MegaChatApi::addChatRequestListener(MegaChatRequestListener *listener)
{
    pImpl->addChatRequestListener(listener);
}

void MegaChatApi::removeChatRequestListener(MegaChatRequestListener *listener)
{
    pImpl->removeChatRequestListener(listener);
}

MegaChatRequest::~MegaChatRequest() { }
MegaChatRequest *MegaChatRequest::copy()
{
    return NULL;
}

int MegaChatRequest::getType() const
{
    return 0;
}

const char *MegaChatRequest::getRequestString() const
{
    return NULL;
}

const char *MegaChatRequest::toString() const
{
    return NULL;
}

int MegaChatRequest::getTag() const
{
    return 0;
}

long long MegaChatRequest::getNumber() const
{
    return 0;
}

int MegaChatRequest::getNumRetry() const
{
    return 0;
}

bool MegaChatRequest::getFlag() const
{
    return false;
}

MegaChatPeerList *MegaChatRequest::getMegaChatPeerList()
{
    return NULL;
}

MegaHandle MegaChatRequest::getChatHandle()
{
    return INVALID_HANDLE;
}

MegaHandle MegaChatRequest::getUserHandle()
{
    return INVALID_HANDLE;
}

int MegaChatRequest::getPrivilege()
{
    return MegaChatPeerList::PRIV_UNKNOWN;
}

const char *MegaChatRequest::getText() const
{
    return NULL;
}

MegaChatRoomList *MegaChatRoomList::copy() const
{
    return NULL;
}

const MegaChatRoom *MegaChatRoomList::get(unsigned int i) const
{
    return NULL;
}

unsigned int MegaChatRoomList::size() const
{
    return 0;
}

//Request callbacks
void MegaChatRequestListener::onRequestStart(MegaChatApi *, MegaChatRequest *)
{ }
void MegaChatRequestListener::onRequestFinish(MegaChatApi *, MegaChatRequest *, MegaChatError *)
{ }
void MegaChatRequestListener::onRequestUpdate(MegaChatApi *, MegaChatRequest *)
{ }
void MegaChatRequestListener::onRequestTemporaryError(MegaChatApi *, MegaChatRequest *, MegaChatError *)
{ }
MegaChatRequestListener::~MegaChatRequestListener() {}


MegaChatHandle MegaChatRoom::getHandle() const
{
    return INVALID_HANDLE;
}

int MegaChatRoom::getOwnPrivilege() const
{
    return PRIV_UNKNOWN;
}

int MegaChatRoom::getPeerPrivilegeByHandle(MegaChatHandle userhandle) const
{
    return PRIV_UNKNOWN;
}

unsigned int MegaChatRoom::getPeerCount() const
{
    return 0;
}

MegaChatHandle MegaChatRoom::getPeerHandle(unsigned int i) const
{
    return INVALID_HANDLE;
}

int MegaChatRoom::getPeerPrivilege(unsigned int i) const
{
    return PRIV_UNKNOWN;
}

bool MegaChatRoom::isGroup() const
{
    return false;
}

const char *MegaChatRoom::getTitle() const
{
    return NULL;
}

MegaChatPeerList * MegaChatPeerList::createInstance()
{
    return new MegaChatPeerListPrivate();
}

MegaChatPeerList::MegaChatPeerList()
{

}

MegaChatPeerList::~MegaChatPeerList()
{

}

MegaChatPeerList *MegaChatPeerList::copy() const
{
    return NULL;
}

void MegaChatPeerList::addPeer(MegaChatHandle, int)
{
}

MegaChatHandle MegaChatPeerList::getPeerHandle(int) const
{
    return INVALID_HANDLE;
}

int MegaChatPeerList::getPeerPrivilege(int) const
{
    return PRIV_UNKNOWN;
}

int MegaChatPeerList::size() const
{
    return 0;
}


void MegaChatVideoListener::onChatVideoData(MegaChatApi *api, MegaChatCall *chatCall, int width, int height, char *buffer)
{

}


void MegaChatCallListener::onChatCallStart(MegaChatApi *api, MegaChatCall *call)
{

}

void MegaChatCallListener::onChatCallStateChange(MegaChatApi *api, MegaChatCall *call)
{

}

void MegaChatCallListener::onChatCallTemporaryError(MegaChatApi *api, MegaChatCall *call, MegaChatError *error)
{

}

void MegaChatCallListener::onChatCallFinish(MegaChatApi *api, MegaChatCall *call, MegaChatError *error)
{

}


void MegaChatListener::onChatListItemUpdate(MegaChatApi *api, MegaChatListItem *item)
{

}

void MegaChatListener::onChatRoomUpdate(MegaChatApi *api, MegaChatRoomList *chats)
{

}


MegaChatListItem::MegaChatListItem()
{

}

MegaChatListItem::~MegaChatListItem()
{

}

int MegaChatListItem::getChanges() const
{
    return 0;
}

bool MegaChatListItem::hasChanged(int changeType) const
{
    return 0;
}

MegaChatHandle MegaChatListItem::getChatId() const
{
    return INVALID_HANDLE;
}

const char *MegaChatListItem::getTitle() const
{
    return NULL;
}

int MegaChatListItem::getVisibility() const
{
    return mega::VISIBILITY_UNKNOWN;
}

int MegaChatListItem::getUnreadCount() const
{
    return 0;
}

MegaChatApi::Status MegaChatListItem::getOnlineStatus() const
{
    return MegaChatApi::STATUS_OFFLINE;
}
