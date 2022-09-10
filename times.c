#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include "times.h"

float user_time_difference(struct timeval *start, struct timeval *end){
    return(end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

float system_time_difference(struct rusage *start, struct rusage *end){
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) + 1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}