#include <stdio.h>
#include <stdint.h>
extern void run();

int64_t *
print(int64_t *in)
{
	if (! in) {
		printf("<null>\n");
	} else if (in[0]) {
		printf("<badtype>\n");
	} else {
		printf("%*s\n", in[1], in[2]);
	}
	return NULL;
}

int main(void)
{
	run();
	return 0;
}
