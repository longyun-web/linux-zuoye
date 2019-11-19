#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
 
int main()
{
	int n;
	int open_fd;
	int fd[2];
	pid_t pid;
	char line[16];
	open_fd = open("local.c", O_RDONLY);
	if(pipe(fd) < 0) {
		perror("pipe error!");
		exit(-1);
	}
	if((pid = vfork()) < 0) {
		perror("cannot vfork!");
		exit(-1);
	}
	else if(pid == 0) {
		printf("open_fd=%d\n", open_fd); 
		close(open_fd);
	}
	else {
		printf("open_fd=%d\n", open_fd);
		n = read(open_fd, line, 16);
		printf("n=%d\n", n);
		write(STDOUT_FILENO, line ,n);
	}
	exit(0);
}
