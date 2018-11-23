#include<stdio.h>
#include<stdlib.h>
#define issue 5
#define rating 10
void recordresponse(int i, int response);
void highestrating();
void lowestrating();
float averagerating(int gggg);
void displayresult();
int responses[issue][rating];
char *topics[issue] = { "Global Warming","The Economy","war",
"Health care","Education" };
main()
{
	int response;
	int i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10"
			"\n 1=least important , 10=most important\n");
		for (i = 0; i < issue; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}
		printf("Enter 1 to shop. Enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response != 1);
	displayresult();
	system("pause");
}
void recordresponse(int i, int response)
{
	responses[i][response - 1]++;
}
void highestrating()
{
	int i, j;
	int highestrate=0;
	int highTopic = 0;
	for (i = 0; i < issue; i++)
	{
		int topRating = 0;
	    for (j = 0; j < rating; j++)
		{
			topRating += responses[i][j] * (j + 1);
		}
		if (highestrate < topRating)
		{
			highestrate = topRating;
			highTopic = i;
		}
	}
	printf("The higest rate topic was ");
	printf("%s", topics[highTopic]);
	printf(" with a total rating of %d\n", highestrate);
}
void lowestrating()
{
	int i, j;
	int lowestrate = 100;
	int lowTopic = 0;
	for (i = 0; i < issue; i++)
	{
		int lowRating = 0;
		for (j = 0; j < rating; j++)
		{
			lowRating += responses[i][j] * (j + 1);
		}
		if (lowestrate > lowRating)
		{
			lowestrate = lowRating;
			lowTopic = i;
		}
	}
	printf("The lowest rate topic was ");
	printf("%s", topics[lowTopic]);
	printf(" with a total rating of %d\n", lowestrate);
}
float averagerating(int gggg)
{
	float total = 0;
	int counter = 0;
	int j;
	for (j = 0; j < rating; j++)
	{
		if (responses[gggg][j] != 0)
		{
			total += responses[gggg][j] * (j + 1);
			counter += responses[gggg][j];
		}
	}
		return total / counter;
}
void displayresult()
{
	int i, j;
	printf("%20s", "Topic");
	for (i = 1; i <= rating; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating");
	for (i = 0; i < issue; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < rating; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averagerating(i));
	}
	 highestrating();
	 lowestrating();
}