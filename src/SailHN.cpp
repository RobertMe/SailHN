#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

#include "topstories.h"
#include "hnlimitmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication *application = SailfishApp::application(argc, argv);

    TopStories topStories;

    qmlRegisterType<HnLimitModel>("harbour.sailhn", 1, 0, "HnLimitModel");
    qmlRegisterUncreatableType<QAbstractItemModel>("harbour.sailhn", 1, 0, "AbstractItemModel", "used to support sourceModel property of HnFilterModel");

    QQuickView *view = SailfishApp::createView();
    view->engine()->rootContext()->setContextProperty("topStories", &topStories);
    view->setSource(SailfishApp::pathTo("qml/SailHN.qml"));
    view->show();

    return application->exec();
}
