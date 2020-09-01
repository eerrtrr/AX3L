#ifndef MATRIX_H
#define MATRIX_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>


//Matrix structure
struct MATRIX{
	unsigned int row;
	unsigned int column;
	float** data;
};
typedef struct MATRIX matrix;


//Matrix allocation & desallocation functions
matrix* initializeMatrix(unsigned int row,unsigned int column);
void deleteMatrix(matrix *m); 

//Randomize matrix data between -1 & 1
void randomizeMatrix(matrix* m);

//Matrix calculus
matrix* transposeMatrix(matrix* m);
matrix* addMatrix(matrix* a, matrix* b, bool res);
matrix* subMatrix(matrix* a, matrix* b, bool res);
matrix* mulMatrix(matrix* a, matrix* b, bool res);
matrix* mulMatScalar(matrix* a, float scalar, bool res);
matrix* schurProduct(matrix* a, matrix* b, bool res);
//Matrix print function
void printMatrix(matrix* m);

//Convertion between array and matrix
matrix* fromArray(float arr[], int length);
float* toArray(matrix* m);

//Matrix size check
bool sameNumOfRow(matrix* a, matrix* b);
bool sameNumOfColumn(matrix* a, matrix* b);
bool mulCompatibility(matrix* a, matrix* b);

#endif