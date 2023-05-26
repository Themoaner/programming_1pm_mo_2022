#include <iostream>
#include "log.h"

int main()
{
	Log::SetLogPath("log.txt");
	Log::SetLogLevel(LogLevel::DEBUG);

	Log::INFO("abcd");
	Log::Write("efg");
	Log::ERROR("11111111");

	return 0;
}
