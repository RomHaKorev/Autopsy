#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include "notequalsexception.h"
#include "notequalsitemexception.h"
#include "notsamesizeexception.h"

#include <list>

namespace Assertions
{

template<typename T> void assertEquals(std::list<T> expected, std::list<T> result)
{
	if (expected.size() != result.size())
		throw NotSameSizeException(expected.size(), result.size());

	typename std::list<T>::const_iterator itemExpected = expected.begin();
	typename std::list<T>::const_iterator itemResult = result.begin();

	for (int i =0; itemExpected != expected.end(); ++itemResult, ++itemExpected, ++i)
	{
		if (!(*itemExpected == *itemResult))
			throw NotEqualsItemException<T>(i, *itemExpected, *itemResult);
	}


	/*for(int i=0; i != expected.size(); ++i)
	{
		if (expected.at(i) != result.at(i))
			throw NotEqualsItemException<T>(i, expected[i], result[i]);
	}*/
}

template<typename T> void assertEquals(T expected, T result)
{
	if (expected != result)
		throw NotEqualsException<T>(expected, result);
}
template<typename T> void assertTrue(bool result)
{
	if (!result)
		throw NotEqualsException<T>(true, result);
}

template<typename T> void assertFalse(bool result)
{
	if (result)
		throw NotEqualsException<T>(false, result);
}

};

#endif // ASSERTIONS_H
