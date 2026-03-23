#include "../lib/hcow/hcow.h"
#include <stdlib.h>
#include <sys/types.h>



int main(int argc, char *argv[]) {

	if (argc < 2) {
		hcow_log(HCOW_ERROR, "Use: autosh <tag> <program.c>");
		exit(1);
	}

//	flag(argv[1]);
	
	if (hcow_exists(argv[2])) hcow_run_script(argv[2]);
	else hcow_log(HCOW_ERROR, "'%s' destine don't exists", argv[2]);


	return 0;
}
