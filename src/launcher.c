#include <stdint.h>
#include <stdlib.h>
#include <err.h>
#include <dlfcn.h>

int
main(int argc, char **argv) {
	int64_t * (*run)() = NULL;
	int i;

	for (i = 1; i < argc; i++) {
		if (! dlopen(argv[i], RTLD_LAZY | RTLD_GLOBAL))
			errx(1, "%s", dlerror());

		if (i == 1)
			run = dlsym(RTLD_DEFAULT, "__ceylon_run");
	}


	if (! run)
		errx(1, "Module does not have 'run' symbol");

	run();
	return 0;
}
