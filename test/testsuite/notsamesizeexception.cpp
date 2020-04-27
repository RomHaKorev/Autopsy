#include "notsamesizeexception.h"

NotSameSizeException::NotSameSizeException(int expected, int result)
{
	std::stringstream ss;
	ss << "Size are different: Expecting " << expected << " elements. Got " << result << " elements";
	message = ss.str();
}

const char *NotSameSizeException::what() const noexcept { return message.c_str(); }
