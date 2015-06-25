#include <stdio.h>
#include <stdint.h>

#include "util.h"

API_EXPORT int64_t *
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
