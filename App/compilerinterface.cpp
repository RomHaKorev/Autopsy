#include "compilerinterface.h"

#include <QDebug>
#include "exceptions/illegalcharacterexception.h"
#include "exceptions/unexpectedtokenexception.h"

CompilerInterface::CompilerInterface(QObject *parent) : QObject(parent)
{

}


void CompilerInterface::tokenize(const QString &content)
{
	try {
		lexer << content.toStdString();
		emit lexerChanged();
		emit lexerSuccess();
	} catch(IllegalCharacterException exception)
	{
		qDebug() << exception.what();
		emit error(exception.what());
	}
}

void CompilerInterface::parse()
{
	try {
		parser.process(lexer.tokens());
		emit parserSuccess();
	} catch(UnexpectedTokenException exception)
	{
		qDebug() << exception.what();
		emit error(exception.what());
	}
}
