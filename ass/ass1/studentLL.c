#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
	studentRecordT data;
	struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
	NodeT *head;

	/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: without any loop in this part
List newLL() {
	List l = malloc(sizeof(ListRep));
	l->head = NULL;

	return l;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: only one loop in this part
void dropLL(List listp) {
	NodeT *a;
	a = listp->head;
	NodeT *temp;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}

	return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: only one loop in this part
void inLL(List listp, int zid) {
	int sign = 0;
	//NodeT *listp;
	NodeT *a;
	a = listp->head;
	while (a != NULL)
	{
		if (a->data.zID == zid) {
			printf("------------------------\n");
			printStudentData(a->data.zID, a->data.credits, a->data.WAM);
			printf("------------------------\n");
			sign = 1;//ур╣╫ак
			break;
		}
		else {
			a = a->next;

		}
	}
	if (sign == 0) {
		printf("No record found.\n");
	}
	return;  /* needs to be replaced */
}


// Time complexity: O(n)
// Explanation: only one loop in this part
void insertLL(List listp, int zid, int cr, float wam) {
	NodeT *a;
	a = listp->head;
	NodeT *newnode = malloc(sizeof(NodeT));
	newnode->data.credits = cr;
	newnode->data.WAM = wam;
	newnode->data.zID = zid;
	newnode->next = NULL;
	if (a == NULL) {
		listp->head = newnode;
		printf("Student record added.\n");
		return;
	}
	if (a != NULL) {
		if (a->data.zID>zid) {
			newnode->next = a;
			listp->head = newnode;
			printf("Student record added.\n");
			return;

		}
		else if (a->data.zID<zid)
		{
			a->next = newnode;

			printf("Student record added.\n");
			return;
		}


	}


	while (a != NULL)
	{
		if (a->data.zID == zid) {
			a->data.credits = cr;
			a->data.WAM = wam;
			printf("Student record updated.\n");
			return;
		}
		else if (a->next != NULL && a->next->data.zID>zid) {
			break;
		}
		a = a->next;
	}
	if (a->next == NULL)
	{
		a->next = newnode;
		printf("Student record added.\n");

	}
	else
	{
		if (a->next->next)
		{
			newnode->next = a->next->next;
		}
		a->next = newnode;
		printf("Student record added.\n");

	}


	return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: only one loop in this part
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
	int total_credits = 0;
	float total_aWAM = 0, total_waWAM = 0;
	int num = 0;
	NodeT *a;
	a = listp->head;
	while (a != NULL)
	{
		num++;
		total_credits = total_credits + a->data.credits;
		total_aWAM = total_aWAM + a->data.WAM;
		total_waWAM = total_waWAM + (a->data.WAM) *(a->data.credits);
		a = a->next;
	}

	float w = total_aWAM / num;
	float w2 = total_waWAM / total_credits;


	printf("Number of records: %d\n", num);
	printf("Average WAM: %.3f\n", w);
	printf("Average weighted WAM: %.3f\n", w2);
	return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: only one loop in this part
void showLL(List listp) {
	NodeT *a;
	a = listp->head;

	while (a != NULL)
	{

		printf("------------------------\n");
		printStudentData(a->data.zID, a->data.credits, a->data.WAM);
		printf("------------------------\n");
		a = a->next;
	}
	return;  /* needs to be replaced */
}
