import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    property variant model: topStories

    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: qsTr("Refresh")
                onClicked: page.model.refresh()
            }
        }

        header: PageHeader {
            title: qsTr("Top Stories")
        }
        model: page.model

        delegate: ListItem {
            width: parent.width
            contentHeight: column.height + (Theme.paddingSmall * 2)

            onClicked: {
                var item = page.model.get(index);
                if (item.url) {
                    pageStack.push(Qt.resolvedUrl("BrowserPage.qml"), {item: item});
                }
            }

            Column {
                id: column
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: Theme.paddingLarge
                anchors.right: parent.right
                anchors.rightMargin: Theme.paddingLarge

                Label {
                    text: title
                    width: parent.width
                    font.pixelSize: Theme.fontSizeMedium
                    truncationMode: TruncationMode.Elide
                    wrapMode: Text.Wrap
                    maximumLineCount: 2
                }

                Row {
                    spacing: Theme.paddingSmall

                    Label {
                        text: score + " " + qsTr("points")
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }

                    Label {
                        text: qsTr("by: ") + by;
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }

                    Label {
                        text: Qt.formatDateTime(time)
                        font.pixelSize: Theme.fontSizeSmall
                        color: Theme.secondaryColor
                    }
                }
            }
        }
    }
}
