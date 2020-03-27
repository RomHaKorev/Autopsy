#include "syntaxhighlighter.h"

#include <QRegularExpression>
#include <QDebug>

#include <QQuickTextDocument>

SyntaxHighlighter::SyntaxHighlighter(QObject *parent) : QSyntaxHighlighter(parent)
{
	QTextCharFormat formatNumber;
	formatNumber.setForeground(QColor(0, 153, 255));
	highlightingRules.append(HighlightingRule(QRegExp("\\b\\d+\\b"), formatNumber));
}


QQuickTextDocument* SyntaxHighlighter::document() const
{
	return textDocument;
}

void SyntaxHighlighter::setTextDocument(QQuickTextDocument* document)
{
	textDocument = document;
	this->setDocument(textDocument->textDocument());
}


void SyntaxHighlighter::highlightBlock(QString const& text)
{
	foreach (const HighlightingRule &rule, highlightingRules) {
		QRegExp expression(rule.pattern);
		int index = expression.indexIn(text);
		while (index >= 0) {
			int length = expression.matchedLength();
			setFormat(index, length, rule.format);
			index = expression.indexIn(text, index + length);
		}
	}
   setCurrentBlockState(0);
}
