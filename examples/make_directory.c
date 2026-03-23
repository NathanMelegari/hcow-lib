#include "../lib/hcow/hcow.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	if (argc < 2) {
		fprintf(stderr, "needs two arguments: ./program <name>\n");
		exit(1);
	}

	char *make_directory[] = {"mkdir", argv[1], NULL};
	hcow_run(make_directory);
	
	if (hcow_exists(argv[1])) {
		hcow_cd(argv[1]);
	}

	char *async[] = {"touch", "async.txt", NULL};
	hcow_run_async(async);

	hcow_log(HCOW_INFO, "folder '%s' created!", argv[1]);

	return 0;
}
