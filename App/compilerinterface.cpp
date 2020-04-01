#include "compilerinterface.h"

#include <QDebug>
#include "exceptions/illegalcharacterexception.h"

CompilerInterface::CompilerInterface(QObject *parent) : QObject(parent)
{

}


void CompilerInterface::tokenize(const QString &content)
{
	try {
		lexer << content.toStdString();
		emit lexerChanged();
	} catch(IllegalCharacterException exception)
	{
		emit error(exception.what());
	}
}

void CompilerInterface::parse()
{
	try {

	} catch(std::exception exception)
	{
		emit error(exception.what());
	}
}
