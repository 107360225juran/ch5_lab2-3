#include<stdio.h>
#include<stdlib.h>
#define student 3
#define exam 4
void minimum(int grades[][exam], int pupils, int test);
void maximum(int grades[][exam], int pupils, int test);
void average(int grades[][exam], int pupils, int test);
void printarray(int grades[][exam], int pupils, int test);
void printmenu(void);
main()
{
	void (*processgrades[4])(int [][exam], int, int)
		= { printarray, minimum ,maximum ,average };
	int choice=0;
	int studentgrade[student][exam] = { {77,68,86,73},
									    {96,87,89,78},
									    {70,90,86,81} };
	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);
		if (choice != 4)
		{
			processgrades[choice](studentgrade, student, exam);
		}
		else
		{
			printf("program ended\n");
		}
	}
	system("pause");
}
void minimum(int grades[][exam], int pupils, int test)
{
	int i;
	int j;
	int lowest=100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < test; j++)
		{
			if (grades[i][j] < lowest)
			{
				lowest = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowest);
}
void maximum(int grades[][exam], int pupils, int test)
{
	int i;
	int j;
	int highest=0;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < test; j++)
		{
			if (grades[i][j] > highest)
			{
				highest = grades[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highest);
}
void average(int grades[][exam], int pupils, int test)
{
	int i;
	int j;
	int total;
	printf("\n");
	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < test; j++)
		{
			total += grades[i][j];
		}
		printf("\tThe average for student %d is %.lf\n",
			i + 1, (double)total / test);
	}
}
void printarray(int grades[][exam], int pupils, int test)
{
	int i;
	int j;
	printf("\n\t                    [0]   [1]     [2]    [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\n\tstudentgrade[%d]",i);
		for (j = 0; j < test; j++)
		{
			printf("%7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printmenu(void)
{
	printf("\n\tEnter a Choice:\n"
		"\t   0 Print the array of grade\n"
		"\t   1 Find the minium grade\n"
		"\t   2 Find the maxium grade\n"
		"\t   3 Print the average on all test for each student\n\n"
		"\t   4 End program\n"
		"\t?");
}
