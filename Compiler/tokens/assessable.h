#ifndef TOKEN_H
#define TOKEN_H


class Assessable
{
public:
	virtual ~Assessable() {}
	virtual void evaluate() const = 0;
};

#endif // TOKEN_H
