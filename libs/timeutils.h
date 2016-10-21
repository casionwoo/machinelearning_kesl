#ifndef __TIME_UTILS_H__
#define __TIME_UTILS_H__

#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define DIFF_TIME_SEC(x)		((double)(x.etime.tv_sec - x.stime.tv_sec))
#define DIFF_TIME_USEC(x)		((double)(x.etime.tv_usec - x.stime.tv_usec))

#define START_TIME(x)			gettimeofday(&(x.stime), NULL)
#define END_TIME(x)				gettimeofday(&(x.etime), NULL); 		\
								x.total_sec += DIFF_TIME_SEC(x);		\
								x.total_usec += DIFF_TIME_USEC(x)		\

#define TOTAL_SEC_TIME(x)		(x.total_sec)
#define TOTAL_SEC_UTIME(x)		(x.total_usec)

typedef struct timeutils {
	struct timeval stime;
	struct timeval etime;

	long total_sec;
	long total_usec;
} timeutils;

#endif /* __TIME_UTILS_H__ */