#include <stdio.h>

int solve(int *grid)
{
	int set[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, };
	size_t n;

	for (n = 0; n < 81; n++) {
		if (grid[n] == 0)
			break;
	}

	if (n == 81)
		return 1;

	size_t i, j;
	for (i = 9 * (n / 9); i < 9 * (n / 9 + 1); i++) {
		if (grid[i] > 0)
			set[grid[i] - 1] = 0;
	}

	for (i = (n % 9); i < 81; i += 9) {
		if (grid[i] > 0)
			set[grid[i] - 1] = 0;
	}

	for (i = 27 * (n / 27); i < 27 * (n / 27 + 1); i += 9) {
		for (j = 3 * ((n % 9) / 3); j < 3 * ((n % 9) / 3 + 1); j++) {
			if (grid[i + j] > 0)
				set[grid[i + j] - 1] = 0;
		}
	}

	for (i = 0; i < 9; i++) {
		if (set[i] == 1) {
			grid[n] = i + 1;
			if (solve(grid))
				return 1;
			grid[n] = 0;
		}
	}
	//grid[n] = 0;

	return 0;
}

int
main(void)
{
	int grid[81] = {
		0, 0, 0,   0, 0, 0,   0, 0, 0,
		0, 0, 0,   0, 0, 3,   0, 8, 5,
		0, 0, 1,   0, 2, 0,   0, 0, 0,

		0, 0, 0,   5, 0, 7,   0, 0, 0,
		0, 0, 4,   0, 0, 0,   1, 0, 0,
		0, 9, 0,   0, 0, 0,   0, 0, 0,

		5, 0, 0,   0, 0, 0,   0, 7, 3,
		0, 0, 2,   0, 1, 0,   0, 0, 0,
		0, 0, 0,   0, 4, 0,   0, 0, 9,
	};
	printf("%d\n", solve(grid));

	size_t i;
	for (i = 0; i < 81; i++) {
		printf("%d", grid[i]);
		if (!((i + 1) % 9))
			putchar('\n');
		else if (!((i + 1) % 3))
			putchar(' ');
	}
	getchar();
}