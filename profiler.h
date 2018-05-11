#ifndef __PROFILE_H_
#define __PROFILE_H_

#include <sys/time.h>
#include <iostream>
#include <cstring>

class profiler
{
public:
	profiler(const std::string str):_func(str)
	{
		gettimeofday(&_tv, NULL);
	}
	~profiler()
	{
		struct timeval tv;
		gettimeofday(&tv, NULL);
		std::cout << "Function " << _func << " cost "
		<< (tv.tv_sec*1000 + tv.tv_usec/1000) - (_tv.tv_sec*1000 +_tv.tv_usec/1000)
		<< "ms\n";
	}
private:
	struct timeval _tv;
	std::string _func;
};

#define PROFILER profiler __profiler_instance##__LINE__(__FUNCTION__)

#endif