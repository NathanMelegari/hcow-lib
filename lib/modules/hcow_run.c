#include "../hcow/hcow.h"
#include <bits/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int hcow_run(char *args[]) {

	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (pid == 0) {

		execvp(args[0], args);
		perror("exec failed");
		exit(1);
	}
	else {
		int status;
		waitpid(pid, &status, 0);

		return WEXITSTATUS(status);
	}
}
