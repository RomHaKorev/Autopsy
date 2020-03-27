import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import App 1.0

ApplicationWindow  {
	visible: true
	width: 640
	height: 480
	title: qsTr("Hello World")

	background: Rectangle {
		color: "#202020"
	}

	Compiler {
		id: compiler
	}

	RowLayout {
		anchors.fill: parent
		spacing: 1
		Rectangle {
			color: "#404244"
			Layout.preferredWidth: 100
			Layout.fillHeight: true
			Item {
				width: parent.width
				ColumnLayout {
					anchors.fill: parent
					Layout.alignment: Qt.AlignTop
					Button {
						text: "Reset"
						onClicked: {
							codeEditor.reset();
							lexer.reset();
						}
					}
					Button {
						text: "Lexical"
						onClicked: lexer.apply();
					}
					Button {
						text: "Syntaxic"
					}
				}
			}
		}

		TextArea {

			function reset() {
				text = raw;
			}

			property string raw: ""
			id: codeEditor
			Layout.fillHeight: true
			Layout.preferredWidth: parent.width - 100
			text: "12 == 13"
			color: "white"
			background: Rectangle {
				anchors.fill: parent
				color: "#2e2f30"
			}

			onTextChanged: raw = text

			SyntaxHighlighter {
				document: codeEditor.textDocument
			}
			LexerView {
				document: codeEditor.textDocument
				id: lexer
				lexer: compiler.lexer
			}
		}
	}
}
