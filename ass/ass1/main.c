/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"


void printHelp();
void StudentLinkedListProcessing();


int main(int argc, char *argv[]) {
	if (argc == 2) {
		float aWAM=0, waWAM=0, total_aWAM=0, total_waWAM = 0; 
		int total_credits = 0;
		studentRecordT *head = malloc(atoi(argv[1]) * sizeof(studentRecordT));
		int ID, Credits;

	

		float WAM ;
		int times=atoi(argv[1]);
		for (int a = 0; a<times; a++)
		{
			ID = readValidID();
			Credits = readValidCredits();
			WAM = readValidWAM();
			(head + a)->zID = ID;
			(head + a)->credits = Credits;
			(head + a)->WAM = WAM;
		}
		for (int a = 0; a<times; a++)
		{
			
			printf("------------------------\n");
			printStudentData((head + a)->zID, (head + a)->credits, (head + a)->WAM);
			printf("------------------------\n");

			total_credits = total_credits + (head + a)->credits;
			total_aWAM = total_aWAM + (head + a)->WAM;
			total_waWAM = total_waWAM + ((head + a)->WAM) * ((head + a)->credits);
			
		}

		aWAM = total_aWAM / times;
		waWAM = total_waWAM / total_credits;
		printf("Average WAM: %.3f\n", aWAM);
		printf("Weighted average WAM: %.3f\n", waWAM);


	  

      /*** Insert your code for stage 1 here ***/
      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch;
   List list = newLL();   // create a new linked list
   int zID=0, credits=0;
float wam;
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
			 
			zID = readValidID();
			
			credits = readValidCredits();
			
			wam = readValidWAM();
			
			 insertLL(list, zID, credits, wam);

		
			 
            /*** Insert your code for adding a student record ***/

	    break;

         case 'f':
         case 'F':
		
			zID = readValidID();
			 inLL(list, zID);

            /*** Insert your code for finding a student record ***/

	    break;
	    
         case 'g':
         case 'G':
			
			 getStatLL(list, NULL, NULL, NULL);
			 
            /*** Insert your code for getting statistical information ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
			 
			 showLL(list);



            /*** Insert your code for printing all student records ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}


