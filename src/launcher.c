#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <err.h>
#include <dlfcn.h>

extern unsigned char launcher_help_txt[];
extern unsigned int launcher_help_txt_len;

int
main(int argc, char **argv) {
	void *bind;
	int64_t * (*run)();
	int i;

	for (i = 1; i < argc; i++) {
		if (! strcmp("--_print-summary", argv[i])) {
			printf("Executes a Ceylon program\n");
		} else if (! strcmp("--_print-usage", argv[i])) {
			printf("<module>\n");
		} else if (! strcmp("--_print-description", argv[i])) {
			printf("%*s\n", launcher_help_txt_len,
			       launcher_help_txt);
		} else {
			continue;
		}

		exit(0);
	}

	if (argc != 2)
		errx(1, "Wrong number of arguments");

	bind = dlopen(argv[1], RTLD_LAZY);

	if (! bind) {
		fprintf(stderr, "%s\n", dlerror());
		errx(1, "Failed to load library");
	}

	run = dlsym(bind, "run");

	if (! run)
		errx(1, "Module does not have \'run\' symbol");

	run();
	return 0;
}
