#include "testresult.h"


TestResult::TestResult(const std::string &name, bool result, const std::string &info): name(name),
	state(result), info(info)
{}
