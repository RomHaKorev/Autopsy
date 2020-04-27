#ifndef COMPILERINTERFACE_H
#define COMPILERINTERFACE_H

#include <QObject>

#include <lexical/lexer.h>
#include <syntaxic/parser.h>

class CompilerInterface : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Lexer const* lexer READ getLexer NOTIFY lexerChanged)
public:
	explicit CompilerInterface(QObject *parent = nullptr);

	Q_INVOKABLE void tokenize(QString const& content);
	Q_INVOKABLE void parse();

	Q_INVOKABLE Lexer const*  getLexer() const { return &lexer; }
private:
	Lexer lexer;
	Parser parser;
signals:
	void lexerChanged();
	void error(QString const& message);

	void lexerSuccess();
	void parserSuccess();
};



#endif // COMPILERINTERFACE_H
