#include "../lib/hcow/hcow.h"
#include <sys/types.h>

int main(int argc, char *argv[]) 
{
	if (argc < 2) {
		hcow_log(HCOW_ERROR, "Erro!");
		return 1;
	}

	char *mkdir_folder[] = {"mkdir", argv[1], NULL};
	hcow_run(mkdir_folder);

	if (hcow_exists(argv[1])) {

			hcow_cd(argv[1]);

			char *create_file[] = {"touch", "my_hcow_file.txt", NULL};
			hcow_run(create_file);

			char *ls_cm[] = {"ls", "./", NULL};
			hcow_run(ls_cm);

			hcow_log(HCOW_INFO, "script succesfully!");
	}

	char *cmd[] = {"ls", NULL};

	char *out = hcow_capture(cmd);
	printf("Output:\n%s\n", out);

	free(out);

	hcow_log(HCOW_INFO, "script end!");

	return 0;
}
