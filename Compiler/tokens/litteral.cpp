#include "litteral.h"


namespace tokens {

template<typename T> Litteral<T>::Litteral(T value):
	value(value)
{
}

template<typename T> void Litteral<T>::evaluate() const
{
	//return value;
}

}
