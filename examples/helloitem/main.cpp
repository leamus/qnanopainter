#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "helloitem.h"

int main(int argc, char *argv[])
{
    // load res from libqnanopainter
    Q_INIT_RESOURCE(libqnanopainterdata);

#ifdef Q_OS_WIN
    // Select between OpenGL and OpenGL ES (Angle)
    //QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
#endif
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

#if (QT_VERSION >= 0x060000)
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
#endif

    QQmlApplicationEngine engine;
    qmlRegisterType<HelloItem>("HelloItem", 1, 0, "HelloItem");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
