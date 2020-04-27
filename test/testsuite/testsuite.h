#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <functional>
#include <list>

#include "testresult.h"
#include "assertions.h"

class TestSuite {
public:
	TestSuite();

	void operator()(std::string const& name, std::function<void()> func);

private:
	std::list<TestResult> results;
	unsigned long maxTitleLength;

	friend std::ostream& operator<<(std::ostream& os, TestSuite const& suite);
};




#endif // TESTSUITE_H
