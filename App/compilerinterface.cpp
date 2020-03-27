#include "compilerinterface.h"

CompilerInterface::CompilerInterface(QObject *parent) : QObject(parent)
{

}


void CompilerInterface::parse(const QString &content)
{
	lexer << content.toStdString();
}
