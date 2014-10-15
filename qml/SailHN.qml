import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
    initialPage: Component { TopStoriesPage { } }
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
}
