// Fig. 6.23: fig06_23.c
// Using variable-length arrays in C99
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void print1DArray(int size, int *array);
void print2DArray(int row, int col, int **array);

int **allocMatrix(int row, int cols);

int main(void)
{
   printf("%s", "Enter size of a one-dimensional array: ");
   int arraySize; // size of 1-D array
   scanf("%d", &arraySize);

   int *array; // declare 1-D variable-length array      
   array = calloc(arraySize, sizeof(int));
   
   printf("%s", "Enter number of rows and columns in a 2-D array: ");
   int row1, col1; // number of rows and columns in a 2-D array
   scanf("%d %d", &row1, &col1);

   int **array2D1; // declare 2-D variable-length array
   array2D1 = allocMatrix(row1, col1);
   
   printf("%s", 
      "Enter number of rows and columns in another 2-D array: ");
   int row2, col2; // number of rows and columns in another 2-D array
   scanf("%d %d", &row2, &col2);

   int **array2D2; // declare 2-D variable-length array
   array2D2 = allocMatrix(row2, col2);
   // test sizeof operator on VLA
   printf("\nsizeof(array) yields array size of %ld bytes\n",
      sizeof(array));                                     

   // assign elements of 1-D VLA
   for (int i = 0; i < arraySize; ++i) {
      array[i] = i * i;
   } 

   // assign elements of first 2-D VLA
   for (int i = 0; i < row1; ++i) {
      for (int j = 0; j < col1; ++j) {
         array2D1[i][j] = i + j;
      } 
   } 

   // assign elements of second 2-D VLA
   for (int i = 0; i < row2; ++i) {
      for (int j = 0; j < col2; ++j) {
         array2D2[i][j] = i + j;
      } 
   } 

   /*puts("\nOne-dimensional array:");
   print1DArray(arraySize, array); // pass 1-D VLA to function

   puts("\nFirst two-dimensional array:");
   print2DArray(row1, col1, array2D1); // pass 2-D VLA to function

   puts("\nSecond two-dimensional array:");
   print2DArray(row2, col2, array2D2); // pass other 2-D VLA to function*/
}

void print1DArray(int size, int *array)
{
   // output contents of array
   for (int i = 0; i < size; i++) {
      printf("array[%d] = %d\n", i, array[i]);
   } 
} 

void print2DArray(int row, int col, int **array)
{
   // output contents of array
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
         printf("%5d", array[i][j]);
      } 

      puts("");
   } 
} 

int **allocMatrix(int rows, int cols)
{
	int **M;
	int i;
	
	M = (int **) malloc(rows*sizeof(int *));
	M[0] = (int *) calloc(rows*cols, sizeof(int));
	
	for (i=1; i<rows; i++) {
		M[i] = M[i-1] + cols;
	}
	
	return M;
}

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/