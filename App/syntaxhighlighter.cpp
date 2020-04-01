#include "syntaxhighlighter.h"

#include <QRegularExpression>
#include <QDebug>

#include <QQuickTextDocument>

SyntaxHighlighter::SyntaxHighlighter(): QObject(),
		highlighter(new SyntaxHighlighterPrivate(this))
	{}


QQuickTextDocument* SyntaxHighlighter::document() const
{
	return textDocument;
}

void SyntaxHighlighter::setTextDocument(QQuickTextDocument* document)
{
	textDocument = document;
	highlighter->setDocument(textDocument->textDocument());
}

void SyntaxHighlighter::setEnabled(bool value)
{
	if (value == highlighter->getEnabled())
		return;

	highlighter->setEnabled(value);
	emit enabledChanged();

	highlighter->rehighlight();

}

bool SyntaxHighlighter::getEnabled() const
{
	return highlighter->getEnabled();
}

SyntaxHighlighterPrivate::SyntaxHighlighterPrivate(QObject *parent) : QSyntaxHighlighter(parent), enabled(true)
{
	QTextCharFormat formatNumber;
	formatNumber.setForeground(QColor(0, 153, 255));
	highlightingRules.append(HighlightingRule(QRegExp("\\b\\d+\\b"), formatNumber));
}


void SyntaxHighlighterPrivate::highlightBlock(QString const& text)
{
	if (!enabled)
		return;
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


void SyntaxHighlighterPrivate::setEnabled(bool value)
{
	enabled = value;
}

bool SyntaxHighlighterPrivate::getEnabled() const
{
	return enabled;
}
