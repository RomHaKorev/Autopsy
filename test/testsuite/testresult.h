#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <iostream>


class TestSuite;

class TestResult {
public:
	TestResult(std::string const & name, bool result, std::string const& info= "");
private:
	std::string name;
	bool state;
	std::string info;

	friend std::ostream& operator<<(std::ostream& os, TestSuite const& suite);
};


std::ostream& operator<<(std::ostream& os, TestResult const& result);

#endif // TESTRESULT_H
