/*
 ============================================================================
 Name        : Q1-1_brute_force_knapsac.c
 Author      : Chetan
 Email       : cgajare1@binghamton.edu
 Created on  : Apr 25, 2017
 Description : 
 ============================================================================
 */

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct knapsac
{
	int weight;
	int profit;
} sac[50];

int no_items;
int sac_capacity;
void create(char *);

int main()
{
	char file_name[50];
	strcpy(file_name, "input.txt");
	create(file_name);

	return 0;
}

void create(char *file_name)
{
	FILE *fp;
	int i = 0;
	//Open file in read mode
	fp = fopen(file_name, "r");
	char buffer[250], a[50];
	char *token;

	if (fp == NULL)
	{
		perror("Error while opening the input file");
		exit(0);
	}
	else
	{
		if (fscanf(fp, "%s", a) == 1)
		{
			no_items = atoi(a);
			printf("Total number of products : %d \n", no_items);
		}
		fgets(buffer, 255, fp);
		fgets(buffer, 255, fp);
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			sac[i].weight = atoi(token);
			printf(" : %d\n", sac[i].weight);
			i++;
			token = strtok(NULL, ",");
		}
		i = 0;
		fgets(buffer, 255, fp);
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			sac[i].profit = atoi(token);
			printf(" > %d\n", sac[i].profit);
			i++;
			token = strtok(NULL, ",");
		}
		if (fscanf(fp, "%s", a) == 1)
		{
			sac_capacity = atoi(a);
			printf("Total sac capacity : %d \n", sac_capacity);
		}
	}
	fclose(fp);
}
