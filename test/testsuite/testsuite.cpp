#include "testsuite.h"

std::ostream& operator<<(std::ostream& os, TestSuite const& suite)
{
	for (auto const& result: suite.results)
	{
		os.width(suite.maxTitleLength);
		os << std::left << result.name << " -> ";
		if (result.state)
			os << "OK";
		else
			os << "KO";
		os << " " << result.info << std::endl;
	}
	return os;
}

TestSuite::TestSuite(): maxTitleLength(0)
{}

void TestSuite::operator()(const std::string &name, std::function<void ()> func)
{
	maxTitleLength = std::max(maxTitleLength, name.size());
	try {
		func();
		results.push_back(TestResult(name, true));
	} catch(std::exception& ex) {
		results.push_back(TestResult(name, false, ex.what()));
	}
}
