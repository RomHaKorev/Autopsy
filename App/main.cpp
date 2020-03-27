#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <lexer.h>

#include "syntaxhighlighter.h"
#include "lexerview.h"
#include "compilerinterface.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	qmlRegisterType<SyntaxHighlighter>("App", 1, 0, "SyntaxHighlighter");
	qmlRegisterType<LexerView>("App", 1, 0, "LexerView");
	qmlRegisterType<CompilerInterface>("App", 1, 0, "Compiler");

	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
