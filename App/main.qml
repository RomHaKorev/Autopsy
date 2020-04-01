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
        onLexerChanged: {
            highlighter.enabled = false;
            codeEditor.readOnly = true;
            lexerView.apply();
        }
        onError: {
            buttonSyntax.enabled = false;
            logger.addError(message)
        }
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
                    spacing: 24
                    ImageButton {
                        id: buttonReset
                        Layout.fillWidth: true
                        height: 50
                        source: "/resources/reset.png"
                        label: "Reset"
                        onClicked: {
                            buttonSyntax.enabled = false;
                            highlighter.enabled = true;
                            codeEditor.readOnly = false;
                            codeEditor.reset();
                            lexerView.reset();
                            logger.clear();
                        }
                    }
                    ImageButton {
                        id: buttonLexical
                        Layout.fillWidth: true
                        height: 50
                        source: "/resources/lexical.png"
                        label: "Lexical Analysis"
                        onClicked: {
                            logger.clear();
                            buttonSyntax.enabled = true;
                            compiler.tokenize(codeEditor.text);

                        }
                    }
                    ImageButton {
                        id: buttonSyntax
                        enabled: false;
                        Layout.fillWidth: true
                        height: 50
                        label: "Syntax Analysis"
                        source: "/resources/syntaxic.png"
                        onClicked: {
                            buttonInterpret.enabled = true;
                            compiler.parse();
                        }
                    }
                    ImageButton {
                        id: buttonInterpret
                        enabled: false;
                        Layout.fillWidth: true
                        height: 50
                        label: "Interpret"
                        source: "/resources/interpret.png"
                        onClicked: {
                        }
                    }
                }
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width - 100
            TextArea {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: logger.top

                function reset() {
                    text = raw;
                }

                property string raw: ""
                id: codeEditor
                text: "12 == 13"
                color: "white"
                background: Rectangle {
                    anchors.fill: parent
                    color: "#2e2f30"
                }

                onTextChanged: raw = text

                SyntaxHighlighter {
                    id: highlighter
                    document: codeEditor.textDocument
                }
                LexerView {
                    document: codeEditor.textDocument
                    id: lexerView
                    lexer: compiler.lexer
                }
            }

            TextArea {
                id: logger
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 200

                textFormat: TextArea.RichText

                function addError(message) {
                    logger.append("<font color=\"#CC0000\">" + message + "</font>")
                }
            }
        }
    }
}
