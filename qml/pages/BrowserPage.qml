import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    property variant item

    SilicaWebView {
        anchors.fill: parent
        url: item.url

        header: PageHeader {
            id: header
            title: item.title
        }
    }
}
