#ifndef COMPILERINTERFACE_H
#define COMPILERINTERFACE_H

#include <QObject>

#include <lexer.h>

class CompilerInterface : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Lexer const* lexer READ getLexer);
public:
	explicit CompilerInterface(QObject *parent = nullptr);

	Q_INVOKABLE void parse(QString const& content);

	Q_INVOKABLE Lexer const*  getLexer() const { return &lexer; }
private:
	Lexer lexer;
};

#endif // COMPILERINTERFACE_H
