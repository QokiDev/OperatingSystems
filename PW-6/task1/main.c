#include <unistd.h>
#include <sys/types.h>

void main(int argc, char const *argv[]) {
	printf("Process PID: %d\n", getpid());
	printf("Parent Process PID: %d\n", getppid());
	printf("Group PID: %d\n", getpgrp());
	printf("Real user ID: %d\n", getuid());
	printf("Effective user ID: %d\n", geteuid());
	printf("Group ID: %d\n", getgid());
	printf("Effective Group ID: %d\n", getegid());

	return 0;
}
