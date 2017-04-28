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
int binary_seq[10] =
{ 0 };
void create(char *);
void genereate_binary_seq();

int main()
{
	char file_name[50];
	strcpy(file_name, "input.txt");
	create(file_name);
	genereate_binary_seq();
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
			//printf("Total number of products : %d \n", no_items);
		}
		fgets(buffer, 255, fp);
		fgets(buffer, 255, fp);
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			sac[i].weight = atoi(token);
			//printf(" : %d  ", sac[i].weight);
			i++;
			token = strtok(NULL, ",");
		}
		i = 0;
		fgets(buffer, 255, fp);
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			sac[i].profit = atoi(token);
			//printf(" > %d  ", sac[i].profit);
			i++;
			token = strtok(NULL, ",");
		}
		if (fscanf(fp, "%s", a) == 1)
		{
			sac_capacity = atoi(a);
			//printf("\nTotal sack capacity : %d \n", sac_capacity);
		}
	}
	fclose(fp);
}

void genereate_binary_seq()
{
	int decimal_no, final_max_profit = 0,final_max_wt = 0;
	int count = 0, i, j, k, x;
	int total_w[10] =
	{ 0 };
	int total_p[10] =
	{ 0 };
	int w = 0, p = 0;
	int current_seq[10];

	for (i = 1; i < (pow(2,no_items)); i++)
	{

		for (k = 0; k <= no_items; k++)
			binary_seq[k] = 0;

		x = i;
		while (x != 1)
		{
			if (x % 2 == 1)
			{
				binary_seq[count] = 1;
				w = w + sac[count].weight;
				p = p + sac[count].profit;
			}
			x = x / 2;
			count++;
		}
		binary_seq[count] = 1;
		w = w + sac[count].weight;
		p = p + sac[count].profit;
		count = 0;

		if (w > sac_capacity)
		{
			w = 0;
			p = 0;
		}
		total_p[i] = p;
		total_w[i] = w;

		w = 0;
		p = 0;

		if (total_p[i] > final_max_profit)
		{
			final_max_profit = total_p[i];
			final_max_wt = total_w[i];
			for (k = 0; k <= no_items; k++)
				current_seq[k] = binary_seq[k];
		}
	}

	printf("\nTotal Profit : %d\n", final_max_profit);
	printf("\nTotal weight : %d\n", final_max_wt);
	printf("\nItems selected with weights : ");
	for (k = 0; k <= no_items; k++)
	{
		if (current_seq[k] == 1)
			printf(": %d :", sac[k].weight);
	}
}
