import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "DMX Controller Demo"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "DMX Intensity: " + viewModel.intensity
            font.pixelSize: 18
        }

        Slider {
            from: 0
            to: 255
            value: viewModel.intensity
            onValueChanged: viewModel.setIntensity(value)
            width: 300
        }
    }
}
