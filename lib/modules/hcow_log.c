#include "../hcow/hcow.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



void hcow_log(const char *level, const char *fmt, ...) {

	if (strcmp(level, HCOW_WARNING) == 0) printf("\033[33m");
	else if (strcmp(level, HCOW_ERROR) == 0) printf("\033[31m");
	else printf("\033[32m");

	printf("[%s] ", level);
	printf("\033[0m");

        va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

        printf("\n");
}
