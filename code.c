/*
    Libraries
    ==========================================
    include any libraries you use here
*/

#include <stdio.h>
#include <math.h>
#include "foc_fa23.h"
/*
    Global variables
    ==========================================
    The below are global variables you may need in this program. You can use them anywhere in your code.
        e.g., printf("%d", IMAGE_FILE_NAME) anywhere in your code will print image.in
    Global variables are variables that can be used anywhere in the code.
    Do not change their values!

    Note 1: It is not advised to use global variables unless you need to define variables that will be used everywhere in your code.
    Note 2: You should be able to solve this project without defining ANY global variables
*/

char IMAGE_FILE_NAME[] = "image.in";


/*
    Function prototypes
    ==========================================
    Check the function definitions below for more
    information about each function

    Note 1: Do NOT modify the names, return types, or arguments of these functions.
    Note 2: You are allowed to create additional functions if you need to.
*/

int mainMenu();
int isPrime(int number);
void primesInRange(int rangeEnd);
void sieve(int numbers[], int arraySize);
void primesInRangeSieve(int numbers[], int arraySize);
void flipImageVertically(int rows, int columns, int image[rows][columns]);
void rotateImageClockwise(int rows, int columns, int image[rows][columns]);

/* Helper functions */
int extractImageRows(char fileName[]);
int extractImageColumns(char fileName[]);
void readImageFromFile(char fileName[], int rows, int columns, int image[rows][columns]);
void drawImageFromFile(char fileName[], int rows, int columns);
void storeImageInFile(int rows, int columns, int image[rows][columns], char fileName[]);


/*
    The main function
    ==========================================
    No need to implement this, we already implemented it for you!
    It calls the mainMenu function and keeps calling it until it returns 1.
    When it does, it exits the program.
*/
int main() {
    int shouldExit;
    do {
        shouldExit = mainMenu();
    } while (shouldExit != 1);
    printf("Thanks for using this program!\n");
    return 0;
}


/*
    Function definitions
    ==========================================
    Note 1: Do NOT modify the names, return types, or arguments of these functions.
    Note 2: You are allowed to create additional functions if you need to, but you HAVE TO
    implement all of these functions.
*/



/*
    TODO: Displays the main menu of the program and processes the user's choice.
    RETURNS 1 to main if the user chooses to Exit, otherwise RETURNS 0.
    
    The main menu contains the following functionalities:
    1 -> Check if a number is prime
    2 -> List all prime numbers from 1 to a number
    3 -> Use the Sieve of Eratosthenes algorithm to print prime numbers from 1 to a number
    4 -> Flip an image vertically
    5 -> Rotate an image clockwise
    6 -> Exits the program

    If the user enters any other number, PRINT "Invalid Choice" and RETURN 0.
*/
int mainMenu() {
    int x;
printf("welcome! please choose one of the following options:\n 1.check if a number is prime.\n 2.list all prime number from 1 to the number. \n 3. use the sieve of erathosthenes algorithm to print prime number from 1 to a number. \n 4.flip an image vertically.\n 5.rotate an image clockwise.\n 6. exit the program.\n please enter your choice: ");
scanf ("%d",&x);
switch(x)
{
int n,v;
case 1:
printf("please enter number:");
scanf("%d",&n);
v=isPrime(n);
        if (v)
        {
            printf("%d is a prime number\n",n);
        } 
        else 
        {
            printf("%d is not a prime number\n",n);
        }

        break;

    case 2:
          printf("Enter a number to print all primes from 1 to the number : ");
          scanf("%d", &n);
          primesInRange(n);
        break;

    case 3:{
    
          printf("Enter a number to print all primes from 1 to the number : ");
          scanf("%d", &n);
           int z[n+1];
          sieve(z,n);
          primesInRangeSieve(z,n);
            
        break;
}
    case 4:{
int rows=extractImageRows("image.in");
int columns=extractImageColumns("image.in");
int image[rows][columns];
readImageFromFile("image.in",rows,columns,image);

 flipImageVertically(rows,columns,image);
 drawImageFromFile("image.in",rows,columns);
        break;
}
    case 5:{
	int rows=extractImageRows("image.in");
int columns=extractImageColumns("image.in");
int image[rows][columns];
readImageFromFile("image.in",rows,columns,image);

 rotateImageClockwise(rows,columns,image);
 drawImageFromFile("image.in",columns,rows);
        break;
        break;
}
    case 6:
  
        return 1;
        break;
        default:
        printf("Invalid Choice");
        return 0;
        break;

}
return 2;
}
  



/*
    TODO: Checks if a number is prime or not.
    
    It RETURNS 1 if the number is prime, otherwise it returns 0.
*/
int isPrime(int number) {
 int counter=0;


if (number>1)

{
    for (int i = 1; i <= number&&counter<3; i++)
    {
        if (number % i == 0) 
        {
            counter++;
        }
    }
    if (counter <= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
return 0;
}




/*
    TODO: PRINTS the prime numbers from 1 to rangeEnd.

    Uses the function isPrime to check if each number is prime or not.
*/
void primesInRange(int rangeEnd) {
    for (int c=2;c<=rangeEnd;c++)
{


    if (isPrime(c)) 
    {
        if(c==2)
        {
               printf("%d",c);
        }
        else
        {
               printf(",%d",c);
        }
    }
}
printf("\n");
}


/*
    TODO: Uses the Sieve of Eratosthenes algorithm to find prime numbers from 1 to a number
*/
void sieve(int numbers[], int arraySize) {
    
    int i, j;
    //int prime[arraySize + 1];

    for (i = 2; i <= arraySize; i++)
        numbers[i] = 1;

    for (i = 2; i <= sqrt(arraySize); i++) {
        
        if (numbers[i] == 1) {
        
            for (j = i * i; j <= arraySize; j += i)
                numbers[j] = 0;
        }
        
    }

   
 //   for (i = 2; i <= arraySize; i++)
   //     if (prime[i])
     //   if (i==2)
       // {
         //printf("%d", i);   
        //}
        //else
        //{
          //  printf(",%d", i);
        //}
         
    //printf("\n");
      // arraySize = 0;
       // numbers[arraySize];
   
    
}


/*
    TODO: PRINTS prime numbers from an array prepared by the function sieve.
*/
void primesInRangeSieve(int numbers[], int arraySize) {
    for(int i=0;i<=arraySize;i++){
    if(numbers[i]==1 && i==2)
    {
        printf("%d",i);
    }
    else if(numbers[i]==1 && i!=2)
   {
       printf(",%d",i);
    }

    }
    printf("\n");
    }
    



/*
    TODO: Flips the image in image[rows][columns] vertically and writes it to the file
    "image.in" using the storeImageInFile function.
*/
void flipImageVertically(int rows, int columns, int image[rows][columns]) {
int a[rows][columns];
for(int i=0;i<rows;i++){
for(int j=0;j<columns;j++){
a[rows-1-i][j]=image[i][j];
}
}
  storeImageInFile(rows,columns,a,"image.in");
  //showArray(rows,columns,a);
    return;
    
}


/*
    TODO: Rotates the image in image[rows][columns] clockwise and writes it to the file
    "image.in" using the storeImageInFile function.
*/
void rotateImageClockwise(int rows, int columns, int image[rows][columns]) {
    int rotarry[columns][rows];
for(int i=0;i<rows;i++){
for(int j=0;j<columns;j++){
rotarry[j][rows-1-i]=image[i][j];
}
}
storeImageInFile(columns,rows,rotarry,IMAGE_FILE_NAME);
    return;
}


/*
    TODO: Extracts an image's number of rows from an image file
*/
int extractImageRows(char fileName[]) {
FILE *h;
h=fopen("image.in","r");
int a;
fscanf(h,"%d",&a);
fclose(h);
return a;
 
}


/*
    TODO: Extracts an image's number of columns from an image file
*/
int extractImageColumns(char fileName[]) {

    FILE *h;
h=fopen("image.in","r");
int b;
fscanf(h,"%d %d",&b,&b);
fclose(h);
return b;
}


/*
    TODO: Reads an image from a file and stores it in the array image[rows][columns].
*/
void readImageFromFile(char fileName[], int rows, int columns, int image[rows][columns]) {
FILE *y = fopen(fileName,"r");
    int f;
    for(int i=0;i<=rows;i++){
    for(int j=0;j<columns;j++){
    if(i!=0){
	fscanf(y,"%d",&image[i-1][j]);
	}else{
	fscanf(y,"%d %d",&f,&f);
	break;
	}
    }
    }
    fclose(y);
    
    
    return;
}


/*
    TODO: Reads an image from a file and uses the showArray function to print it.
*/
void drawImageFromFile(char fileName[], int rows, int columns) {
FILE *h;
h=fopen(fileName,"r");

int x[rows][columns];

for(int i=0;i<rows;i++)
	for(int j=0;j<columns;j++)
		fscanf(h,"%d",&x[i][j]);

fclose(h);
showArray(rows,columns,x);
    return;
}


/*
    TODO: Stores an image in a file.
*/
void storeImageInFile(int rows, int columns, int image[rows][columns], char fileName[]) {
FILE *q = fopen(fileName,"w");
fprintf(q," ");
fclose(q);
FILE *y = fopen(fileName,"a");
for(int i = 0;i<=rows;i++){
	for(int j=0;j<columns;j++){
	if(i==0){
	fprintf(y,"%d %d\n",rows,columns);
	break;
	}else{
	fprintf(y,"%d ",image[i-1][j]);
	
}
}
}
}	







