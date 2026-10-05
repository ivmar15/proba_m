/*
 * Sailfish OS port of Maximus
 */
#include <sailfishapp.h>
#include <QtQuick>
#include <QScopedPointer>

#include "plugin/serverconnection.h"
#include "plugin/usersession.h"
#include "models/chatmessagesmodel.h"
#include "models/chatslistmodel.h"
#include "api/chatmessage.h"
#include "api/chatmessagereactions.h"
#include "api/chat.h"
#include "emojimodel.h"
#include "webpimageprovider.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(SailfishApp::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.neochapay"));
    application->setApplicationName(QStringLiteral("maximus"));

    qmlRegisterType<ServerConnection>("ru.neochapay.maximus", 1, 0, "ServerConnection");
    qmlRegisterType<UserSession>("ru.neochapay.maximus", 1, 0, "UserSession");
    qmlRegisterType<ChatsListModel>("ru.neochapay.maximus", 1, 0, "ChatsListModel");
    qmlRegisterType<ChatMessagesModel>("ru.neochapay.maximus", 1, 0, "ChatMessagesModel");
    qmlRegisterType<ChatMessage>("ru.neochapay.maximus", 1, 0, "ChatMessage");
    qmlRegisterType<ChatMessageReactions>("ru.neochapay.maximus", 1, 0, "ChatMessageReactions");
    qmlRegisterType<Chat>("ru.neochapay.maximus", 1, 0, "Chat");
    qmlRegisterType<EmojiModel>("EmojiModel", 1, 0, "EmojiModel");

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->engine()->addImageProvider("qwebp", new WebpImageProvider);
    view->rootContext()->setContextProperty("version", QStringLiteral("0.0.11-3"));
    view->setSource(SailfishApp::pathTo(QStringLiteral("qml/Maximus.qml")));
    view->show();

    return application->exec();
}
