#include <iostream>

typedef int grid[9][9];

bool solve(grid myGrid)
{
	//Find empty spot
	int x, y, s = 0;
	for (int i = 0; i < 9 && !s; i++)
	{
		for (int j = 0; j < 9 && !s; j++)
		{
			if (myGrid[i][j] == 0)
			{
				x = i;
				y = j;
				s = 1;
			}
		}
	}

	//No empty spots, solution found
	if (!s)
		return true;

	//Empty spot, determine possible entries
	char nums[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 0, j = y; i < 9; i++)
	{
		nums[(int)myGrid[i][j]] = 0;
	}
	for (int j = 0, i = x; j < 9; j++)
	{
		nums[(int)myGrid[i][j]] = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			nums[(int)myGrid[i + ((int)(x / 3)) * 3][j + ((int)(y / 3)) * 3]] = 0;
		}
	}

	//Try all possibilities and recurse for each
	for (int i = 1; i<10; i++)
		if (nums[i] > 0)
		{
			myGrid[x][y] = i;
			if (solve(myGrid))
				return true;
		}

	//When failed, reset position
	myGrid[x][y] = 0;
	return false;
}

void printGrid(grid myGrid)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << myGrid[i][j];
			if (j == 2 || j == 5)
				std::cout << "|";
		}
		std::cout << std::endl;
		if (i == 2 || i == 5)
		{
			for (int k = 0; k < 11; k++)
				std::cout << "-";
			std::cout << std::endl;
		}
	}
}

int solutions(grid myGrid)
{
	// This algorithm is based upon "solve" and determines the amount of solutions of the given grid. It will return the amount of solutions.
	return 0;
}

int main(void)
{
	grid sudoku =
	{
		{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
		{ 0, 0, 0,   0, 0, 3,   0, 8, 5 },
		{ 0, 0, 1,   0, 2, 0,   0, 0, 0 },

		{ 0, 0, 0,   5, 0, 7,   0, 0, 0 },
		{ 0, 0, 4,   0, 0, 0,   1, 0, 0 },
		{ 0, 9, 0,   0, 0, 0,   0, 0, 0 },

		{ 5, 0, 0,   0, 0, 0,   0, 7, 3 },
		{ 0, 0, 2,   0, 1, 0,   0, 0, 0 },
		{ 0, 0, 0,   0, 4, 0,   0, 0, 9 }
	};

	printGrid(sudoku);
	solve(sudoku);
	std::cout << "Result:" << std::endl;
	printGrid(sudoku);
	getchar();
	return 0;
}