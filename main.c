#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill(int fillMode, int Na, int Nb, int Mb, int** A, int** B);
void result(int Na, int Nb, int Mb, int** A, int** B);

int** allocateMemory(int rows, int cols);
void clearMemory(int** matrix, int Nb);

void max_min(int Na, int Nb, int Mb, int** A, int** B);
void transpose(int Nb, int Mb, int** B);
void multiply(int Nb, int Mb, int** A, int** B);
void sort(int Na, int** A);
void sum(int Nb, int Mb, int** A, int** B);

int main() {

	int Na = 0, Nb = 0, Mb = 0;
	int fillMode = 0, answer = 2;

	while ((Na <= 0 && Nb <= 0 && Mb <= 0) || answer == 2) {

		printf("\nEnter number of column-rows of matrix A:");
		printf("\n\t[A] = ");
		scanf_s("%d", &Na);

		printf("\nEnter number of rows of matrix B:");
		printf("\n\t[Rows] = ");
		scanf_s("%d", &Mb);

		printf("\nEnter number of columns of matrix B:");
		printf("\n\t[Columns] = ");
		scanf_s("%d", &Nb);

		/*if (Na <= 0 || Nb <= 0 || Mb <= 0) {
			printf("\nInvalid values! Please, try again.\n(Amount of rows/columns cannot be < 1).\n");
		}*/

		if (Na != Mb) {

			printf("\nRows of matrix B must match with columns of matrix A. Otherwise, you won't be able to multiplication. Are You sure?\n\t[1] - Continue\n\t[2] - Enter values again");
			printf("\n\tOption: ");
			scanf_s("%d", &answer);
		}
		else {
			answer = 1;
		}
		
		system("cls");
	}

	int** A = allocateMemory(Na, Na);
	int** B = allocateMemory(Nb, Mb);

	/*int** A = NULL;
	A = (int**)malloc(Na * sizeof(int));

	for (int i = 0; i < Na; i++) {
		A[i] = (int*)malloc(Na * sizeof(int));
	}

	int** B = NULL;
	B = (int**)malloc(Nb * sizeof(int));

	int** T = NULL;
	T = (int**)malloc(Mb * sizeof(int));

	int** Multi = NULL;
	Multi = (int**)malloc(Nb * sizeof(int));


	for (int i = 0; i < Nb; i++) {
		B[i] = (int*)malloc(Mb * sizeof(int));
		Multi[i] = (int*)malloc(Mb * sizeof(int));
		T[i] = (int*)malloc(Mb * sizeof(int));
	}*/

	while (fillMode <= 0 || fillMode > 4) {

		printf("\nChoose a fill mode:\n\t[1] - Enter values manually\n\t[2] - Generate values automatically\n\t");
		printf("\n\tOption: ");
		scanf_s("%d", &fillMode);

		if (fillMode < 1 || fillMode > 2) {
			printf("Invalid option! Please, try again.\n");
		}
	}

	fill(fillMode, Na, Nb, Mb, A, B);

	while (1) {

		int doNext = 0;

		do {
			printf("\nChoose an operation:\n\t[1] - Show the maximum and minimum value of matrix A\n\t[2] - Transpose matrix B\n\t[3] - Multiply matrix A by B (A * B)\n\t[4] - Sort matrix A\n\t[5] - Add matrix A to B (A + B)\n\t[6] - Exit the program");
			printf("\n\tOption: ");
			scanf_s("%d", &doNext);
		} while (doNext < 1 && doNext > 5);

		switch (doNext) {

		case 1:
			max_min(Na, Nb, Mb, A, B);
			break;
		case 2:
			transpose(Nb, Mb, B);
			break;
		case 3:

			if (Na != Mb) {
				printf("\nInvalid option selected! Please, try again.");
			}
			else {
				multiply(Nb, Mb, A, B);
				break;
			}
			
		case 4:
			sort(Na, A);
			break;
		case 5:
			sum(Nb, Mb, A, B);
			break;
		case 6:
			clearMemory(A, Na);
			clearMemory(B, Nb);
			return 0;

		default:
			printf("\nInvalid option selected! Please try again.\n");

		}	
	}
	
	return 0;
}

int** allocateMemory(int rows, int cols) {

	int** matrix = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
	}

	return matrix;

}

void clearMemory(int** matrix, int rows) {
	int i;

	for (i = 0; i < rows; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

void sort(int Na, int** A) {

	int sortMode;

	printf("\nChoose sort mode:\n\t[1] - Sort matrix in ascending order\n\t[2] - Sort the row selected by user\n");
	printf("\n\tOption: ");
	scanf_s("%d", &sortMode);

	if (sortMode == 1) {

		for (int i = 0; i < Na; i++) {
			for (int j = 0; j < Na; j++) {
			
					
				for (int k = i + 1; k < Na; k++) {
					
			
						
						if (A[i][j] > A[i][k]) {
							
							int temp = A[i][j];
							A[i][j] = A[i][k];
							A[i][k] = temp;
						
						}
						
				}
			}
		}
	}
	else {

		int sort = 0;

		printf("\nEnter the row to sort: ");
		scanf_s("%d", &sort);

		for (int i = 1; i < Na; i++) {
			for (int j = 0; j < Na - i; j++) {

				if (A[sort][j] > A[sort][j + 1]) {

					int temp = A[sort][j];
					A[sort][j] = A[sort][j + 1];
					A[sort][j + 1] = temp;

				}

			}
		}
	}

	/*for (int p = 1; p < Na; p++) {
		for (int j = 0; j < Na - p; j++) {
			if (A[sort][j] > A[sort][j + 1]) {
				int temp = A[sort][j];
				A[sort][j] = A[sort][j + 1];
				A[sort][j + 1] = temp;
			}
		}
	}*/

	printf("\nSorted matrix A:\n\n");

	for (int i = 0; i < Na; i++) {

		printf("\t");

		for (int j = 0; j < Na; j++)
		{
			printf("%5d", A[i][j]);
		}

		printf("\n");
	}

		/*for (int k = 0; k < Na * Na; k++) {

			for (int i = 0; i < Na; i++) {
				
				for (int j = 0; j < Na - 1; j++) {

					if (A[i][j] > A[i][j + 1]) {
						int temp = A[i][j];
						A[i][j] = A[i][j + 1];
						A[i][j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < Na - 1; i++) {
				if (A[i][Na - 1] > A[i + 1][0]) {
					int temp = A[i][Na - 1];
					A[i][Na - 1] = A[i + 1][0];
					A[i + 1][0] = temp;
				}
			}
		}*/

		

	/*case 2:
		printf("\nEnter the line to sort: ");
		scanf("%d", &sort);

		for (int k = 1; k < Na; k++) {
			for (int j = 0; j < Na - k; j++) {
				if (A[sort][j] > )
			}
		}*/
}

void fill(int fillMode, int Na, int Nb, int Mb, int** A, int** B) {

	if (fillMode == 1) {

		printf("\nEnter values for matrix A:");

		for (int i = 0; i < Na; i++) {

			for (int j = 0; j < Na; j++) {

				printf("\n\tEnter A[%d][%d] = ", i, j);
				scanf_s("%d", &A[i][j]);
			}
		}

		printf("\nEnter values for matrix B:");

		for (int i = 0; i < Nb; i++) {

			for (int j = 0; j < Mb; j++) {

				printf("\n\tEnter B[%d][%d] = ", i, j);
				scanf_s("%d", &B[i][j]);
			}
		}
	}

	else {

		for (int i = 0; i < Na; i++) {

			for (int j = 0; j < Na; j++) {

				A[i][j] = rand() % 10;
			}
		}

		for (int i = 0; i < Mb; i++) {

			for (int j = 0; j < Nb; j++) {

				B[i][j] = rand() % 10;
			}
		}
	}

	result(Na, Nb, Mb, A, B);
}

void result(int Na, int Nb, int Mb, int** A, int** B) {

	system("cls");

	printf("\nMatrix A:\n\n");

	for (int i = 0; i < Na; i++) {

		printf("\t");

		for (int j = 0; j < Na; j++)
		{
			printf("%5d", A[i][j]);
		}

		printf("\n");
	}

	printf("\nMatrix B:\n\n");

	for (int i = 0; i < Mb; i++) {

		printf("\t");

		for (int j = 0; j < Nb; j++)
		{
			printf("%5d", B[i][j]);
		}

		printf("\n");
	}

}

void multiply(int Nb, int Mb, int** A, int** B) {

	int** Multi = allocateMemory(Nb, Mb);

	for (int i = 0; i < Mb; i++) {

		for (int j = 0; j < Nb; j++) {

			Multi[i][j] = 0;

			for (int k = 0; k < Mb; k++) {

				Multi[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("\nMultiply of matrix A and matrix B:\n\n");

	for (int i = 0; i < Mb; i++) {

		printf("\t");

		for (int j = 0; j < Nb; j++)
		{
			printf("%5d", Multi[i][j]);
		}

		printf("\n");
	}

	clearMemory(Multi, Nb);
}

void max_min(int Na, int Nb, int Mb, int** A, int** B) {

	int max = A[0][0], min = A[0][0];

	for (int i = 0; i < Na; i++) {

		for (int j = 0; j < Na; j++) {

			if (A[i][j] > max) {
				max = A[i][j];
			}
		}
	}

	for (int i = 0; i < Na; i++) {

		for (int j = 0; j < Na; j++) {

			if (A[i][j] < min) {
				min = A[i][j];
			}
		}
	}

	printf("\nMaximum value of matrix A: %d\n", max);

	printf("\nMinimum value of matrix A: %d\n", min);
}

void transpose(int Nb, int Mb, int** B) {

	int** T = allocateMemory(Nb, Mb);

	for (int i = 0; i < Mb; i++) {

		for (int j = 0; j < Nb; j++) {

			T[j][i] = B[i][j];
		}
	}

	printf("\nTranspose of matrix B:\n\n");

	for (int i = 0; i < Nb; i++) {

		printf("\t");

		for (int j = 0; j < Mb; j++)
		{
			printf("%5d", T[i][j]);
		}

		printf("\n");
	}

	clearMemory(T, Nb);
}

void sum(int Nb, int Mb, int** A, int** B) {

	int sum = 0;

	for (int i = 0; i < Mb; i++) {
		
		/*sum = 0;*/

		for (int j = 0; j < Nb; j++) {
			sum += A[i][j];
		}

		printf("\nSum of the row %d of matrix A: %d\n", i, sum);
		sum = 0;

	}

	sum = 0;

	for (int j = 0; j < Nb; j++) {
		
		/*sum = 0;*/

		for (int i = 0; i < Mb; i++) {
			sum += B[i][j];
		}

		printf("\nSum of the column %d of matrix B: %d\n", j, sum);
		sum = 0;

	}
}

