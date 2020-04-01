#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>

class QQuickTextDocument;
class SyntaxHighlighterPrivate;

class SyntaxHighlighter : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QQuickTextDocument* document READ document WRITE setTextDocument)
	Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled)
public:
	SyntaxHighlighter();
	Q_INVOKABLE QQuickTextDocument* document() const;
	Q_INVOKABLE void setTextDocument(QQuickTextDocument* document);

	Q_INVOKABLE void setEnabled(bool value);
	Q_INVOKABLE bool getEnabled() const;
private:
	SyntaxHighlighterPrivate* highlighter;
	QQuickTextDocument* textDocument;

signals:
	void enabledChanged();
};

class SyntaxHighlighterPrivate : public QSyntaxHighlighter
{
public:
	SyntaxHighlighterPrivate(QObject* parent=nullptr);
	void setEnabled(bool value);
	bool getEnabled() const;
private:
	void highlightBlock(QString const& text);


	struct HighlightingRule
	{
		HighlightingRule() {}
		HighlightingRule(QRegExp p, QTextCharFormat f): pattern(p), format(f) {}
		QRegExp pattern;
		QTextCharFormat format;
	};

	QList<HighlightingRule> highlightingRules;

	bool enabled;

	/*QTextCharFormat formatMC0; //Format des mots-clés bleu et gras
	QTextCharFormat formatMC1; //Format des mots-clés noir et gras
	QTextCharFormat formatMC2; //Format des mots-clés bleu
	QTextCharFormat formatComm; //Format des commentaires simples
	QTextCharFormat formatNombre; //Format des nombres
	QTextCharFormat formatData; //Format du texte apres le "end."
	QTextCharFormat formatPA; //Format des points d'arret*/

};

#endif // SYNTAXHIGHLIGHTER_H
