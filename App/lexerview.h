#ifndef LEXERVIEW_H
#define LEXERVIEW_H

#include <QObject>

#include "tokens/token.h"

class QQuickTextDocument;
class Lexer;

class LexerView : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QQuickTextDocument* document READ document WRITE setTextDocument)
	Q_PROPERTY(Lexer const* lexer READ getLexer WRITE setLexer)
public:
	explicit LexerView(QObject *parent = nullptr);
	QQuickTextDocument* document() const;
	void setTextDocument(QQuickTextDocument* document);

	Q_INVOKABLE void apply();
	Q_INVOKABLE void reset();

	Q_INVOKABLE Lexer const* getLexer() const { return lexer; }
	Q_INVOKABLE void setLexer(Lexer const* lexer) { this->lexer = lexer; }
private:
	QQuickTextDocument* textDocument;
	Lexer const* lexer;
};

#endif // LEXERVIEW_H
