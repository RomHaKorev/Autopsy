#include "lexerview.h"

#include <QQuickTextDocument>
#include <QTextCursor>
#include <QDebug>
#include <QTextBlock>
#include <QTextDocumentFragment>

#include <lexer.h>
#include <tokens/token.h>


static QColor colorFor(Type type)
{
	switch(type)
	{
	case Type::Number:
		return QColor(42, 128, 151);
	case Type::String:
		return QColor(245, 104, 60);
	case Type::Operator:
		return QColor(42, 152, 232);
	}
	return QColor(80, 80, 80);
}

LexerView::LexerView(QObject *parent) : QObject(parent)
{}


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

	auto* doc = textDocument->textDocument();
	QTextCursor cursor(doc);

	for (Token const& token: lexer->tokens())
	{
		QTextCursor cursor(doc);
		cursor.movePosition(QTextCursor::MoveOperation::Start, QTextCursor::MoveAnchor);
		cursor.movePosition(QTextCursor::MoveOperation::Down, QTextCursor::MoveAnchor, token.position.line);
		cursor.movePosition(QTextCursor::MoveOperation::NextCharacter, QTextCursor::MoveAnchor, token.position.column);
		cursor.movePosition(QTextCursor::MoveOperation::NextCharacter, QTextCursor::KeepAnchor, token.value.size());
		QTextCharFormat f;
		f.setBackground(colorFor(token.type));
		cursor.setCharFormat(f);
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
