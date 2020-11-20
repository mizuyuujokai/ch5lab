#include<stdio.h>
#include<stdlib.h>

#define student 3
#define exams 4

void minimum(int grades[][exams], int pupils, int tests) {
	int i, j;
	int mini = 100;

	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grades[i][j] < mini)
				mini = grades[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d", mini);
	printf("\n");
}
void maximum(int grades[][exams], int pupils, int tests) {
	int i, j;
	int maxi = 0;

	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grades[i][j] > maxi)
				maxi = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d", maxi);
	printf("\n");
}
void average(int grades[][exams], int pupils, int tests) {
	int i, j,total;
	for (i = 0; i < pupils; i++) {
		total = 0;
		for (j = 0; j < tests; j++) {
			total += grades[i][j];
		}
		printf("\n\tThe average grade for student %d is %.1f", i + 1, (double)total / tests);
	}
	printf("\n");
}
void printarray(int grades[][exams], int pupils, int tests) {
	int i, j;

	printf("\n\t\t\t[0]		[1]		[2]		[3]");
	for (i = 0; i < pupils; i++) {
		printf("\n\tstudentgrade[%d]", i);
		for (j = 0; j < tests; j++) {
			printf("%-7d", grades[i][j]);
		}
		printf("\n");
	}
}
void printmenu() {
	printf("\n");
	printf("\tEnter a choice;\n");
	printf("\t0 Printf the array of grades\n");
	printf("\t1 Find the minimum grade\n");
	printf("\t2 Find the maximum grade\n");
	printf("\t3 Printf the average on all tests for each student\n");
	printf("\t4 End program\n");
	printf("Choice");
}

int main()
{
	int studentgrade[student][exams] = { {77,68,86,73},
										 {96,87,89,78},
										 {70,90,86,81} };
	void(*processgrades[4])(int grades[][exams], int, int)
		= { printarray,minimum,maximum,average };

	int choice = 0;
	while (choice != 4)
	{
		do {
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4) {
			(*processgrades[choice])(studentgrade, student, exams);
		}
		else {
			printf("\tProgram Ended.\n");
		}
	}
	system("pause");
	return 0;
}

