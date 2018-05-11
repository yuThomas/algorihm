//output log to stderr

#include <cstdio>
#include <cstdlib>
#include <stdarg.h>

class CLog
{
public:
	static void LoggerError(const char *fmt, ...)
	{
		va_list  ap;
		va_start(ap, fmt);
		char log[1024];
		vsnprintf(log, 1024, fmt, ap);
		fputs(log, stderr);
		exit(0);
	}
};
