#include "../hcow/hcow.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pid_t hcow_run_async(char *args[]) {

	pid_t pid = fork();

	if (pid < 0) {
		hcow_log(HCOW_ERROR, "fork failed!");
		exit(0);
	}
	else {
		execvp(args[0], args);
		perror("Cannot possible exec the command");
		exit(1);
	}

	return pid;
}
