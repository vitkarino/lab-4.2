#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fill(int fillMode, int Na, int Nb, int Mb, int** A, int** B);
void result(int Na, int Nb, int Mb, int** A, int** B);

int** allocateMemory(int rows, int cols);
void clearMemory(int** matrix, int Nb);

void max_min(int Na, int Nb, int Mb, int** A, int** B);
void transpose(int** T, int Nb, int Mb, int** B);
void multiply(int** Multi, int Nb, int Mb, int** A, int** B);
void sort(int Na, int** A);
void sum(int Na, int Nb, int Mb, int** A, int** B);

/* --- Additional task --- */
void newFill(int* arr, int row, int column);

int main() {

	int Na = 0, Nb = 0, Mb = 0;
	int fillMode, answer, launch;
	
	int arr[3][5];

	do {
		
		printf("\nPlease select the first step:\n\t[1] - Launch the main program\n\t[2] - Generate the rectangle matrix (Additional task)");
		printf("\n\tOption: ");
		scanf_s("%d", &launch);

		if (launch == 2) newFill(&arr[0][0], 3, 5);

	} while (launch < 1 || launch > 2);

	do {

		printf("\nEnter number of column-rows of matrix A:");
		printf("\n\t[A] = ");
		scanf_s("%d", &Na);

		printf("\nEnter number of rows of matrix B:");
		printf("\n\t[Rows] = ");
		scanf_s("%d", &Mb);

		printf("\nEnter number of columns of matrix B:");
		printf("\n\t[Columns] = ");
		scanf_s("%d", &Nb);

		if (Na != Mb) {

			printf("\nRows of matrix B must match with columns of matrix A. Otherwise, you won't be able to multiplication. Are You sure?\n\t[1] - Continue\n\t[2] - Enter values again\n");
			printf("\n\tOption: ");
			scanf_s("%d", &answer);
		}
		else {
			answer = 1;
		}
		
		system("cls");

	} while ((Na <= 0 && Nb <= 0 && Mb <= 0) || answer == 2);

	int** A = allocateMemory(Na, Na);
	int** B = allocateMemory(Mb, Nb);
	int** Multi = allocateMemory(Mb, Nb);
	int** T = allocateMemory(Nb, Mb);

	do {

		printf("\nChoose a fill mode:\n\t[1] - Enter values manually\n\t[2] - Generate values automatically\n\t");
		printf("\n\tOption: ");
		scanf_s("%d", &fillMode);

		if (fillMode <= 0 || fillMode > 2) {
			printf("\nInvalid option! Please, try again.\n");
		}
	} while (fillMode <= 0 || fillMode > 2);

	fill(fillMode, Na, Nb, Mb, A, B);

	while (1) {

		int doNext = 0;

		do {
			printf("\nChoose an operation:\n\t[1] - Show the maximum and minimum value of matrix A\n\t[2] - Transpose matrix B\n\t[3] - Multiply matrix A by B (A * B)\n\t[4] - Sort matrix A\n\t[5] - Summarize matrix A rows and matrix B columns \n\t[6] - Exit the program\n");
			printf("\n\tOption: ");
			scanf_s("%d", &doNext);
		} while (doNext < 1 && doNext > 5);

		switch (doNext) {

		case 1:
			max_min(Na, Nb, Mb, A, B);
			break;
		case 2:
			transpose(T, Nb, Mb, B);
			break;
		case 3:

			if (Na != Mb) {
				printf("\nInvalid option selected! Please, try again.\n");
				break;
			}
			else {
				multiply(Multi, Nb, Mb, A, B);
				break;
			}
			
		case 4:
			sort(Na, A);
			break;
		case 5:
			sum(Na, Nb, Mb, A, B);
			break;
		case 6:
			system("cls");
			printf("\nProgram finished succesfully.\n");

			clearMemory(A, Na);
			clearMemory(B, Mb);
			clearMemory(T, Nb);
			clearMemory(Multi, Mb);

			return 0;

		default:
			printf("\nInvalid option selected! Please try again.\n");

		}	
	}
}

/* --- Additional task --- */
void newFill(int* arr, int row, int column) {

	system("cls");
	printf("\nEnter values for the matrix:");

	for (int i = 0; i < row; i++) {
	
		for (int j = 0; j < column; j++) {
			
			printf("\n\tEnter Matrix[%d][%d] = ", i + 1, j + 1);
			scanf_s("%d", &arr[i * column + j]);
		
		}
		
	}

	system("cls");
	printf("\nResult:\n\n");

	for (int i = 0; i < 3; i++) {

		printf("\t");

		for (int j = 0; j < column; j++)
		{
			printf("%5d", arr[i * column + j]);
		}

		printf("\n");
	}

	exit(0);

}

void fill(int fillMode, int Na, int Nb, int Mb, int** A, int** B) {

	if (fillMode == 1) {

		printf("\nEnter values for the matrix A:");

		for (int i = 0; i < Na; i++) {

			for (int j = 0; j < Na; j++) {

				printf("\n\tEnter A[%d][%d] = ", i, j);
				scanf_s("%d", &A[i][j]);
			}
		}

		printf("\nEnter values for the matrix B:");

		for (int i = 0; i < Mb; i++) {

			for (int j = 0; j < Nb; j++) {

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

int** allocateMemory(int rows, int cols) {

	int** matrix = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
	}

	return matrix;

}

void clearMemory(int** matrix, int rows) {

	for (int i = 0; i < rows; i++) {
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

				int min = A[i][j];

				int p = i;
				int m = j;
				int d = j;

				for (int k = i; k < Na; k++) {

					for (d = j; d < Na; d++) {

						if (A[k][d] < min) {

							min = A[k][d];

							p = k;
							m = d;
						}
					}
					d = 0;
				}

				int temp = A[i][j];

				A[i][j] = A[p][m];
				A[p][m] = temp;
			}
		}

	} else {

		int sortRow = 0;

		do {

			printf("\nEnter the row to sort: ");
			scanf_s("%d", &sortRow);

			if (&sortRow > Na) {
				printf("\nInvalid value entered! Try again.\n");
			}

		} while (&sortRow > Na);

		for (int i = 0; i < Na; i++) {

			for (int j = 0; j < Na; j++) {

				for (int k = j + 1; k < Na; k++) {

					if (A[sortRow][j] > A[sortRow][k]) {

						int temp = A[sortRow][j];

						A[sortRow][j] = A[sortRow][k];
						A[sortRow][k] = temp;

					}

				}
			}
		}
	}

	printf("\nSorted matrix A:\n\n");

	for (int i = 0; i < Na; i++) {

		printf("\t");

		for (int j = 0; j < Na; j++)
		{
			printf("%5d", A[i][j]);
		}

		printf("\n");
	}

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

void transpose(int** T, int Nb, int Mb, int** B) {

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
}

void multiply(int** Multi, int Nb, int Mb, int** A, int** B) {

	for (int i = 0; i < Mb; i++) {

		for (int j = 0; j < Nb; j++) {

			Multi[i][j] = 0;

			for (int k = 0; k < Mb; k++) {

				Multi[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("\nMultiplication of matrix A and matrix B:\n\n");

	for (int i = 0; i < Mb; i++) {

		printf("\t");

		for (int j = 0; j < Nb; j++)
		{
			printf("%5d", Multi[i][j]);
		}

		printf("\n");
	}
}

void sum(int Na, int Nb, int Mb, int** A, int** B) {

	int sum = 0;

	for (int i = 0; i < Na; i++) {

		for (int j = 0; j < Na; j++) {
			sum += A[i][j];
		}

		printf("\nSum of the row %d of matrix A: %d\n", i, sum);
		sum = 0;

	}

	sum = 0;

	for (int j = 0; j < Nb; j++) {

		for (int i = 0; i < Mb; i++) {
			sum += B[i][j];
		}

		printf("\nSum of the column %d of matrix B: %d\n", j, sum);
		sum = 0;

	}
}

