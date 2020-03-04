#ifndef COMPILERINTERFACE_H
#define COMPILERINTERFACE_H

#include <QObject>

class CompilerInterface : public QObject
{
	Q_OBJECT
public:
	explicit CompilerInterface(QObject *parent = nullptr);

signals:

};

#endif // COMPILERINTERFACE_H
