#include <stdio.h>
#include <stdlib.h>

#define	FILE_READ_ERROR			-1
#define INSUFFICIENT_MEMORY		-2

void readFile(char* fileName, int*** matrix, int* rows, int* columns);
int isMagic(int** matrix, int rows, int columns);
void modifyMatrix(int*** matrix, int rows, int columns);
void makeOutputFile(int** matrix, int rows, int columns);
int** allocMemory(int rows, int columns);
void printMatrix(int** matrix, int rows, int columns);
void errorManager(int code);

int main()
{
	int rows, columns;
	int** matrix;
	char fileName[100];

	printf("Inserire il nome del file di input: ");
	scanf("%s", fileName);

	readFile(fileName, &matrix, &rows, &columns);

	printf("La matrice:\n");
	printMatrix(matrix, rows, columns);

	if (rows == columns)
	{
		printf("%s magica\n", (isMagic(matrix, rows, columns)) ? "E'" : "Non e'");
	}
	else
	{	
		printf("Non e' quadrata\n");
	}

	modifyMatrix(&matrix, rows, columns);
	makeOutputFile(matrix, rows, columns);

	return 0;
}

void readFile(char* fileName, int*** matrix, int* rows, int* columns)
{
	FILE* filePnt = fopen(fileName, "r");
	int rowsTemp, columnsTemp;
	int** matrixTemp;
	int x, i, j;

	if (filePnt == NULL)
	{
		errorManager(FILE_READ_ERROR);
	}

	fscanf(filePnt, "%d%d", &rowsTemp, &columnsTemp);

	matrixTemp = allocMemory(rowsTemp, columnsTemp);

	while (fscanf(filePnt, "%d%d%d", &x, &i, &j) != EOF)
	{
		matrixTemp[i - 1][j - 1] = x;
	}

	fclose(filePnt);

	*rows = rowsTemp;
	*columns = columnsTemp;
	*matrix = matrixTemp;
}

int isMagic(int** matrix, int rows, int columns)
{
	int sum = 0, expectedSum = 0;
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			sum += matrix[i][j];
		}

		if (i == 0)
		{
			expectedSum = sum;
		}
		else
		{
			if (expectedSum != sum)
			{
				return 0;
			}
		}
		sum = 0;
	}

	for (j = 0; j < columns; j++)
	{
		for (i = 0; i < rows; i++)
		{
			sum += matrix[i][j];
		}

		if (expectedSum != sum)
			{
				return 0;
			}
		sum = 0;
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (i == j)
			{
				sum += matrix[i][j];
			}
		}
	}

	if (expectedSum != sum)
	{
		return 0;
	}
	sum = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (i + j == rows - 1)
			{
				sum += matrix[i][j];
			}
		}
	}

	if (expectedSum != sum)
	{
		printf("Riga 143");
		return 0;
	}

	return 1;
}

void modifyMatrix(int*** matrix, int rows, int columns)
{
	int i, j;
	int** matrixTemp = *matrix;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (((matrixTemp[i][j] % (i + 1)) == 0) && ((matrixTemp[i][j] % (j + 1)) == 0))
			{
				matrixTemp[i][j] = 0;
			}
		}
	}
	*matrix = matrixTemp;
}

void makeOutputFile(int** matrix, int rows, int columns)
{
	FILE* filePnt = fopen("output.txt", "w");
	int i, j;

	fprintf(filePnt, "%d %d", rows, columns);

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (matrix[i][j] != 0)
			{
				fprintf(filePnt, "\n%d %d %d", matrix[i][j], (i + 1), (j + 1));
			}
		}
	}

	fclose(filePnt);
}

int** allocMemory(int rows, int columns)
{
	int** matrix;

	matrix = (int**)calloc(rows, sizeof(int*));

	if (matrix == NULL)
	{
		errorManager(INSUFFICIENT_MEMORY);
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*)calloc(columns, sizeof(int));

		if (matrix[i] == NULL)
		{
			errorManager(INSUFFICIENT_MEMORY);
		}
	}

	return matrix;
}

void printMatrix(int** matrix, int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}

void errorManager(int code)
{
	switch (code)
	{
	case FILE_READ_ERROR:
		printf("Errore nella lettura del file");
		break;
	case INSUFFICIENT_MEMORY:
		printf("Memoria insufficiente");
		break;
	}
	exit(-1);
}