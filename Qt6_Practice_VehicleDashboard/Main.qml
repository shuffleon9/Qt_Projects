import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt6_Practice_VehicleDashboard 1.0

ApplicationWindow {
    visible: true
    width: 1024
    height: 600
    title: "Vehicle Dashboard"
    color: "#1E1E1E"

    GridLayout {
        anchors.fill: parent
        columns: 3
        rowSpacing: 20
        columnSpacing: 20

        // RPM
        Canvas {
            id: rpm
            Layout.preferredWidth: 300
            Layout.preferredHeight: 300
            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0, 0, width, height);

                // Outer Circle
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 90, 0, 2 * Math.PI);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#444444"; // Subtle gray for outer circle
                ctx.stroke();

                // RPM Arc
                var startAngle = Math.PI; // Start at 180 degrees
                var endAngle = Math.PI + (mockDataSource.rpm / 7000) * Math.PI;
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 80, startAngle, endAngle);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#00bcd4"; // Cyan highlight for rpm arc
                ctx.stroke();

                // RPM Text
                ctx.fillStyle = "#e0e0e0"; // Light gray text for readability
                ctx.font = "20px Arial";
                ctx.textAlign = "center";
                ctx.fillText(mockDataSource.rpm + " rpm", width / 2, height / 2 + 10);
            }
            Connections {
                target: mockDataSource
                onSpeedChanged: rpm.requestPaint()
            }
        }

        // Speedometer
        Canvas {
            id: speedometer
            Layout.preferredWidth: 300
            Layout.preferredHeight: 300
            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0, 0, width, height);

                // Outer Circle
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 140, 0, 2 * Math.PI);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#444444"; // Subtle gray for outer circle
                ctx.stroke();

                // Speed Arc
                var startAngle = Math.PI; // Start at 180 degrees
                var endAngle = Math.PI + (mockDataSource.speed / 240) * Math.PI;
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 130, startAngle, endAngle);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#00bcd4"; // Cyan highlight for speed arc
                ctx.stroke();

                // Speed Text
                ctx.fillStyle = "#e0e0e0"; // Light gray text for readability
                ctx.font = "20px Arial";
                ctx.textAlign = "center";
                ctx.fillText(mockDataSource.speed + " km/h", width / 2, height / 2 + 10);
            }
            Connections {
                target: mockDataSource
                onSpeedChanged: speedometer.requestPaint()
            }
        }

        // Fuel
        Canvas {
            id: fuel
            Layout.preferredWidth: 300
            Layout.preferredHeight: 300
            onPaint: {
                var ctx = getContext("2d");
                ctx.clearRect(0, 0, width, height);

                // Outer Circle
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 90, 0, 2 * Math.PI);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#444444"; // Subtle gray for outer circle
                ctx.stroke();

                // Fuel Arc
                var endAngle = 2 * Math.PI; // Start at 180 degrees
                var startAngle = 2 * Math.PI - (mockDataSource.fuel / 100) * Math.PI;
                ctx.beginPath();
                ctx.arc(width / 2, height / 2, 80, startAngle, endAngle);
                ctx.lineWidth = 10;
                ctx.strokeStyle = "#00bcd4"; // Cyan highlight for fuel arc
                ctx.stroke();

                // Fuel Text
                ctx.fillStyle = "#e0e0e0"; // Light gray text for readability
                ctx.font = "20px Arial";
                ctx.textAlign = "center";
                ctx.fillText(mockDataSource.fuel + "%", width / 2, height / 2 + 10);
            }
            Connections {
                target: mockDataSource
                onSpeedChanged: fuel.requestPaint()
            }
        }

        // Climate Control
        RowLayout {
            Layout.columnSpan: 3
            Layout.alignment: Qt.AlignHCenter
            spacing: 30

            Text {
                text: "Temperature: " + mockDataSource.temperature + "°C"
                color: "#FFFFFF"
                font.pixelSize: 24
            }

            Slider {
                id: temperatureSlider
                from: 16; to: 30; stepSize: 0.5
                value: mockDataSource.temperature
                width: 300
                onValueChanged: console.log("Temperature Set: " + value + "°C")
            }

            Button {
                text: mockDataSource.acOn ? "Turn Off AC" : "Turn On AC"
                onClicked: mockDataSource.acOn = !mockDataSource.acOn
                Layout.alignment: Qt.AlignVCenter
                font.pixelSize: 16
                background: Rectangle {
                    color: mockDataSource.acOn ? "#FF5722" : "#4CAF50"
                    radius: 8
                }
            }
        }

        // Multimedia Controls - Modern Layout
        RowLayout {
            Layout.columnSpan: 3
            Layout.alignment: Qt.AlignLeft
            Layout.margins: 20
            spacing: 30

            Image {
                source: mockDataSource.albumArt
                Layout.preferredWidth: 100
                Layout.preferredHeight: 100
                fillMode: Image.PreserveAspectFit
                smooth: true // Improves quality when scaling
            }

            ColumnLayout {
                spacing: 10

                Text {
                    text: mockDataSource.track
                    color: "#CCCCCC"
                    font.pixelSize: 20
                    font.bold: true
                }

                Text {
                    text: mockDataSource.artist
                    color: "#AAAAAA"
                    font.pixelSize: 16
                }

                RowLayout {
                    spacing: 15

                    Button {
                        text: "Prev"
                        onClicked: console.log("Previous track")
                        width: 60
                        height: 60
                        background: Rectangle {
                            color: "#CCCCCC"
                            radius: 5
                        }
                    }

                    Button {
                        text: "Play/Pause"
                        onClicked: console.log("Play or pause track")
                        width: 60
                        height: 60
                        background: Rectangle {
                            color: "#CCCCCC"
                            radius: 5
                        }
                    }

                    Button {
                        text: "Next"
                        onClicked: console.log("Next track")
                        width: 60
                        height: 60
                        background: Rectangle {
                            color: "#CCCCCC"
                            radius: 5
                        }
                    }
                }
            }
        }
    }
}
