#ifndef NUMBER_H
#define NUMBER_H

#include "assessable.h"

namespace tokens {

template<typename T> class Litteral: Assessable
{
public:
	Litteral(T value);
	virtual void evaluate() const override;

private:
	T const value;
};

}
#endif // NUMBER_H
