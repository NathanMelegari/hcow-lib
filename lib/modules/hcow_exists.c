#include "../hcow/hcow.h"
#include <unistd.h>

int hcow_exists(const char *path) {

	return access(path, F_OK) == 0;
}
