#include "../hcow/hcow.h"
#include <unistd.h>

int hcow_cd(const char *path) {

	if (chdir(path) != 0) {
		perror("cd failed");
		return -1;
	}

	return 0;
}
