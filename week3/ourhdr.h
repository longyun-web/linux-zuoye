#ifndef __ourhdr_h
#define __ourhdr_h

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

#define is_writelock(fd,offset,whence,len)\
			lock_test(fd,F_WRLCK,offset,whence,len)
void err_sys(const char *,...);
#endif
