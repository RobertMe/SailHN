import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sailhn 1.0

CoverBackground {
    SilicaListView {
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        spacing: Theme.paddingSmall

        model: HnLimitModel {
            sourceModel: topStories
            limit: 3
        }

        delegate: Label {
            id: titleLabel
            width: parent.width
            text: title

            font.pixelSize: Theme.fontSizeExtraSmall
            truncationMode: TruncationMode.Elide
            wrapMode: Text.Wrap
            maximumLineCount: 3
        }
    }

    CoverActionList {
        id: coverAction

        CoverAction {
            iconSource: "image://theme/icon-cover-refresh"
            onTriggered: topStories.refresh()
        }
    }
}
