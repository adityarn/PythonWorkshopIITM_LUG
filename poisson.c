/* COMPILE WITH gcc -O3 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    double *t, tijp, tijm, timj, tipj;
    unsigned long n, i, j, l;

    assert(argc == 2 && "Atleast one argument is required.");
    n = atoi(argv[1]);
    /* CALLOC GETS ZERO'd MEMORY */
    t = calloc(n * n, sizeof(double));
    assert(t && "Allocation on heap failed.");

    for (i = 0; i < n; i++) {
	t[n * i + 0] = 1;
    }

    l = 0;
    while (l < 10) {
	for (i = 1; i < n-1; i++) {
	    for (j = 1; j < n-1; j++) {

		tijm = t[n * i + j - 1];
		tijp = t[n * i + j + 1];
		timj = t[n * (i - 1) + j];
		tipj = t[n * (i + 1) + j];

		t[n * i + j] = 0.25 * (tijp + tijm + tipj + timj);
	    }
	}
	l++;
    }

    printf("t : %+.15E\n", t[n * n - 4]);
    free(t);

    return 0;
}
