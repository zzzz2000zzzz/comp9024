// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
	printf("Enter student ID: ");
	int ID = readInt();
	
s1:
	if(ID<1000000 || ID>9999999)
	{
		
		printf("Not valid. Enter a valid value: ");
		ID = readInt();

		goto s1;
	}
	
   return ID;  /* needs to be replaced */
}

int readValidCredits(void) {
	printf("Enter credit points: ");

	int Credits = readInt();
	
s2:
	if (Credits > 480 || Credits < 2 ) {
	 
	 printf("Not valid. Enter a valid value: " );
	 Credits = readInt();

	 goto s2;
	}
	
		return Credits; /* needs to be replaced */

}

float readValidWAM(void) {
	printf("Enter WAM: ");

	float WAM = readFloat();
	
s3:
	if (WAM > 100 || WAM < 50)
	{
	
	printf("Not valid. Enter a valid value: ");
	WAM = readFloat();

	goto s3;
	}
	
   return WAM;  /* needs to be replaced */
}

void printStudentData(int zID, int credits, float WAM) {
	
	{
		printf("Student zID: z%d\n", zID);
		printf("Credits: %d\n", credits);
		if (WAM >= 85) {
			printf("Level of performance: HD\n");
		}
		else if (WAM >= 75)
		{
			printf("Level of performance: DN\n");
		}
		else if (WAM >= 65)
		{
			printf("Level of performance: CR\n");
		}
		else {
			printf("Level of performance: PS\n");
		}
	}
	return;  /* needs to be replaced */
}
