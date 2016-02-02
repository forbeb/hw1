/*********************************************************************************/
/* Assignment 1: 2-D/ NxN Matrix Swap and  Multiplication ************************/
/* Name: Brendan Forbes *****************************************************/
/*********************************************************************************/

/*********************************************************************************/
/* Usual suspects to include *****************************************************/
/*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

/*********************************************************************************/
/* Function Calls ****************************************************************/
/*********************************************************************************/

double **mm_alloc( int size )
{
    /*
     * hints: allocate an array of pointers to a double, 
     * then allocate an row/array of doubles and assign each double pointer that row
     * use calloc for allocation and zeroing out all the bytes
     */

  double** matrix;
  int i;   

  matrix = (double**) malloc(sizeof(double*) * size);
  for(i=0; i<size; ++i){
    matrix[i] = (double*) malloc(sizeof(double) * size);
  }

  return(matrix); // delete for your implementation
}

void mm_free( int size, double **matrix  )
{
    /*
     * hint: reverse of the allocation process 
     * by freeing each array of doubles, 
     * then free the array of double pointers
     */

  int i;
  for(i=0; i<size; ++i){
    free(matrix[i]);
  }
  free(matrix);
}

double **mm_read( char *filename, int *size ) 
{
  /*
   * hints: fopen the file, then use fgets to read each line of data.
   * The first line is the size of the matrix, so read it first. 
   * make sure you record the "size" in the size argument.
   * Next alloc each of the matrixes.
   * Use sscanf to take the line of text and parse out the matrix entry.
   */
  double **matrix = NULL;
  FILE *myfile = fopen(filename, "r");
  
  //temporary variables
  int matrix_size, i, j;
  char buffer[1024];

  //read in the matrix size
  fgets(buffer, 1024, myfile);
  matrix_size = atoi(buffer);

  //dynamically allocate memory for matrix
  matrix = mm_alloc(matrix_size);

  //insert data into matrix
  for(i=0; i<matrix_size; ++i){
    for(j=0; j<matrix_size; ++j){
      fgets(buffer, 1024, myfile);
      matrix[i][j]=atof(buffer);
    }
  }

  //set size as equal to matrix_size
  *size = matrix_size;  
  
  return( matrix );
}

void mm_print( int size, double **matrix )
{
  /*
   * iterate over the matrix entries across each row.
   * when a row is complete insert a newline character "\n"
   */

  int i, j;
  for(i=0; i<size; ++i){
    for(j=0; j<size; ++j){
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }

}

double **mm_swap( int size, double **matrix ) 
{
    /*
     * hints: allocate space for swapped matrix
     * compute swap matrix using original matrix as input. 
     */

  double **swap=NULL;
  int i, j;

  //dynamically allocate memory for swap
  swap = mm_alloc(size);


  /*
  swaps 1 with 3 and 2 with 4
  assumes size=4
  was unsure about how the swap function was supposed to operate
  */
  for(i=0; i<size; ++i){
    for(j=0; j<size; ++j){
      if(j<2)
        swap[i][j] = matrix[i][j+2];
      
      else
        swap[i][j] = matrix[i][j-2];
    }
  }

  return( swap ); // return the transpose matrix
}

double **mm_matrix_mult( int size, double **matrix, double **transpose )
{
    /*
     * hints: alloc a results matrix, 
     * do the matrix multiple per the quad loop method.
     * this is an extension of regular 2-D matrix mult. 
     * return the results_matrix
     */

  double** result = NULL;
  int i, j, k;
  double sum;

  //dynamically allocate memory for result
  result = mm_alloc(size);

  //performs matrix multipication for each slot in resulting matrix
  for(i=0; i<size; ++i){
    for(j=0; j<size; ++j){
      sum=0;
      for(k=0; k<size; ++k){
        sum+=matrix[i][k]*transpose[k][j];
      }
      result[i][j]=sum;
    }
  }

  return result;

}

int main()
{
    /*
     * you must keep this function AS IS. 
     * you cannot modify it!
     */
    char filename[256];
    double **matrix=NULL;
    double **swap_matrix=NULL;
    double **results_matrix=NULL;
    int size=0;

    printf("Please enter the matrix data file name: ");
    scanf( "%s", filename );
    
    matrix = mm_read( filename, &size );
    swap_matrix = mm_swap( size, matrix ); 
    results_matrix = mm_matrix_mult( size, matrix, swap_matrix );

    mm_print( size, results_matrix );
    mm_free( size, matrix );
    mm_free( size, swap_matrix );
    mm_free( size, results_matrix );
    return( 0 ); 
}
