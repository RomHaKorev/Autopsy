#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>

class QQuickTextDocument;

class SyntaxHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT
	Q_PROPERTY(QQuickTextDocument* document READ document WRITE setTextDocument)
public:
	explicit SyntaxHighlighter(QObject* parent=nullptr);
	QQuickTextDocument* document() const;
	void setTextDocument(QQuickTextDocument* document);
private:
	void highlightBlock(QString const& text);

	QQuickTextDocument* textDocument;

	struct HighlightingRule
	{
		HighlightingRule() {}
		HighlightingRule(QRegExp p, QTextCharFormat f): pattern(p), format(f) {}
		QRegExp pattern;
		QTextCharFormat format;
	};
	QList<HighlightingRule> highlightingRules;

	/*QTextCharFormat formatMC0; //Format des mots-clés bleu et gras
	QTextCharFormat formatMC1; //Format des mots-clés noir et gras
	QTextCharFormat formatMC2; //Format des mots-clés bleu
	QTextCharFormat formatComm; //Format des commentaires simples
	QTextCharFormat formatNombre; //Format des nombres
	QTextCharFormat formatData; //Format du texte apres le "end."
	QTextCharFormat formatPA; //Format des points d'arret*/

};

#endif // SYNTAXHIGHLIGHTER_H
