#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "mediaplayer.h"

int main(int ac, char **av)
{
    QGuiApplication a(ac, av);
    QQmlApplicationEngine engine;
    qmlRegisterType<MediaPlayer>("MediaPlayer", 1, 0, "MediaPlayer");
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    return a.exec();
}
