#include "../hcow/hcow.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *hcow_capture(char *args[])
{

	int fd[2];
	pipe(fd);

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed\n");
		exit(0);
	}
	else if (pid == 0) {

		close(fd[0]);

		dup2(fd[1], STDOUT_FILENO);

		close(fd[1]);
		
		execvp(args[0], args);
		perror("exec failed");
		exit(0);
	}
	else {
		close(fd[1]);

		char buffer[1024];
		int n = read(fd[0], buffer, sizeof(buffer) - 1);

		buffer[n] = '\0';

		waitpid(pid, NULL, 0);

		return strdup(buffer);
	}
}
