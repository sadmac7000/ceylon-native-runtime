#include <stdio.h>
#include <stdint.h>
#include <err.h>
#include <dlfcn.h>

int
main(int argc, char **argv) {
	void *bind;
	int64_t * (*run)();

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
