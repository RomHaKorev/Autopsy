#include "lexerview.h"

#include <QQuickTextDocument>
#include <QTextCursor>
#include <QDebug>
#include <QTextBlock>
#include <QTextDocumentFragment>

#include <lexer.h>
#include <tokens/token.h>

LexerView::LexerView(QObject *parent) : QObject(parent)
{

}


QQuickTextDocument* LexerView::document() const
{
	return textDocument;
}

void LexerView::setTextDocument(QQuickTextDocument* document)
{
	textDocument = document;
}

void LexerView::apply()
{
	if (lexer == nullptr)
		return;

	for (Token const& token: lexer->tokens())
	{

	}
	/*auto* doc = textDocument->textDocument();
	QTextCursor cursor(doc);
	cursor.movePosition(QTextCursor::MoveOperation::Start, QTextCursor::MoveAnchor);
	cursor.movePosition(QTextCursor::MoveOperation::Right, QTextCursor::MoveAnchor, 3);
	cursor.movePosition(QTextCursor::MoveOperation::Right, QTextCursor::KeepAnchor, 3);

	QTextCharFormat f;
	f.setBackground(Qt::red);

	cursor.setCharFormat(f);*/
}

void LexerView::reset()
{
	auto* doc = textDocument->textDocument();
	QTextCursor cursor(doc);
	cursor.movePosition(QTextCursor::MoveOperation::Start, QTextCursor::MoveAnchor);
	cursor.movePosition(QTextCursor::MoveOperation::End, QTextCursor::KeepAnchor);

	cursor.setCharFormat(QTextCharFormat());
}
