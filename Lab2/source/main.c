#include<stdio.h>
#include<stdlib.h>

#define issues 5
#define ratting 10

int responses[issues][ratting];
const char *topics[issues] = { "Global Warming","The Economy","War","Health Care","Education" };

void recordResponse(int issue, int rating) {
	responses[issue][rating - 1]++;
}
void highest() {
	int high = 0;
	int topic = 0;
	int i, j;

	for (i = 0; i < issues; i++) {
		int tr = 0;
		for (j = 0; j < ratting; j++){
			tr += responses[i][j] * (j + 1);
		}

		if (high < tr) {
			high = tr;
			topic = i;
		}
	}

	printf("The highest rated topic was ");
	printf("%s", topics[topic]);
	printf("with atotal ratting of %d\n", high);	
}
void lowest() {
	int low = 0;
	int topic = 0;
	int i, j;

	for (i = 0; i < issues; i++) {
		int lr = 0;
		for (j = 0; j < ratting; j++) {
			lr += responses[i][j] * (j + 1);
		}

		if (low < lr) {
			low = lr;
			topic = i;
		}
	}

	printf("The highest rated topic was ");
	printf("%s", topics[topic]);
	printf("with atotal ratting of %d\n", low);
}
float average(int issue) {
	float total = 0;
	int counter = 0;
	int i;

	for (i = 0; i < ratting; i++) {
		if (responses[issue][i] != 0) {
			total += responses[issue][i] * (i + 1);
			counter += responses[issue][i];
		}
	}
	return total / counter;
}
void display() {
	int i, j;
	printf("%20s", "Topic");
	
	for (i = 1; i <= ratting; i++) {
		printf("%4d", i);
	}

	printf("%20s", "Average Rating");

	for (i = 0; i < issues; i++) {
		printf("%20s", topics[i]);
		for (j = 0; j < ratting; j++) {
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", average(i));
	}
	highest();
	lowest();
}

int main() {
	int response, i;
	do {
		printf("Please ratr the following topics on a scale from 1-10""\n 1 = least important,10 = most important\n");

		for (i = 0; i < issues; i++) {
			do {
				printf("%s?", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordResponse(i, response);
		}
		printf("Enter 1 to stop.Enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response != 1);

	display();
	system("pause");
	return 0;
}