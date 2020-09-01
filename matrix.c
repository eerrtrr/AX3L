#include "matrix.h"


//MEMORY ALLOCATION & DESALLOCATION//


//A simple fct to allocate memory of the matrix and return a pointer 
matrix* initializeMatrix(unsigned int row,unsigned int column){
	matrix* m = malloc(sizeof(matrix));

	if(m == NULL){
		printf("Matrix memory allocation has failed\n");
		return NULL;
	}

	m->row = row;	m->column = column;
	
	m->data = (float **)malloc(row * sizeof(float *));
  	for(int i=0; i<row; i++){
   		m->data[i] = (float *)malloc(column*sizeof(float));
  	}

   	for(int i=0; i<m->row; i++){
   		for(int k=0; k<m->column; k++){
    		m->data[i][k] = 0;
   		}
   	}

	return m;
}

//Desallocate matrix element by ekement
void deleteMatrix(matrix *m){
	if(m == NULL){
		printf("The matrix is NULL\n");
		return;
	}

	for(int i=0; i<m->row; i++){
		free(m->data[i]);
		m->data[i] = NULL;
	}

	free(m->data);
	free(m);

	m = NULL;
}


//RANDOMIZE//


//Randomize matrix data between -1 & 1
void randomizeMatrix(matrix* m){
	srand(time(0));

   	for(int i=0; i<m->row; i++){
   		for(int k=0; k<m->column; k++){
    		m->data[i][k] = (float)(rand()%51)/100;
   		}
   	}

   	//sleep(1);
}


//PRINT MATRIX//


//Properly print a matrix on the console
void printMatrix(matrix* m){
	if(m == NULL){
		printf("The matrix is NULL\n");
		return;
	}

	printf("Matrix %p %ix%i\n", m, m->row, m-> column);
	for(int i=0; i<m->row; i++){
		for(int k=0; k<m->column; k++){
			printf("%f ", m->data[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}


//ARRAY & MATRIX CONVERTION


matrix* fromArray(float* arr, int length){
	matrix* m = initializeMatrix(length, 1);
	for(int i=0; i<m->row; i++){
		m->data[i][0] = arr[i];
	}

	return m;
}


float* toArray(matrix* m){
	if(m == NULL){
		printf("Arguments are NULL\n");
		return NULL;
	}
	else if(m->column != 1){
		printf("Matrix argument can only have 1 column\n");
		return NULL;
	}

	float* arr = malloc(m->row*sizeof(float));
	for(int i=0; i<m->row; i++){
		arr[i] = m->data[i][0];
	}

	return arr;
}


//USEFULL FUNCTION//


//Bool fct, return true if matrixes have the same number of row
bool sameNumOfRow(matrix* a, matrix* b){
	return (a->row == b->row);
}

//Bool fct, return true if matrixes have the same number of column
bool sameNumOfColumn(matrix* a, matrix* b){
	return(a->column == b->column);
}

//Bool fct, return true if matrixes can be multiply
bool mulCompatibility(matrix* a, matrix* b){
	return(a->column == b->row);	
}



//CALCULUS//


//Transpose a matrix
matrix* transposeMatrix(matrix* m){
	if(m == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}

	matrix* t = initializeMatrix(m->column, m->row);
	for(int i=0; i<m->row; i++){
		for(int k=0; k<m->column; k++){
			t->data[k][i] = m->data[i][k];
		}
	}

	return t;
}


//Add 2 matrixes
matrix* addMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL || b == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}
	if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
		if(!res){
			if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
				for(int i=0; i<a->row; i++){
	   				for(int k=0; k<a->column; k++){
	    				a->data[i][k] = a->data[i][k] + b->data[i][k];
	   				}
	  		 	}
			}

			return NULL;
		}

		else{
			matrix* res = initializeMatrix(a->row, a->column);

			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			res->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		}

			return res;
		}
	}

	else{
		printf("Number of rows and columns must match\n");
		return NULL;
	}
}

//Substract 2 matrixes
matrix* subMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL || b == NULL){
		printf("\n\nArgument()s is/are NULL\n\n");
		return NULL;
	}
	if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
		if(!res){
			mulMatScalar(b, -1.0, false);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			a->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		 }

			return NULL;
		}

		else{
			matrix* res = initializeMatrix(a->row, a->column);
			mulMatScalar(b, -1.0, false);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			res->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		}

			return res;
		}
	}

	else{
		printf("\n\nNumber of rows and columns must match\n\n");
		return NULL;
	}
}

//Multiply 2 matrixes
matrix* mulMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL && b == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}
	if(mulCompatibility(a, b)){
		if(res){
			matrix* res = initializeMatrix(a->row, b->column);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<b->column; k++){
	   				float sum = 0;
	   				for(int u=0; u<a->column; u++){
	    				sum += a->data[i][u]*b->data[u][k];
	    			}
	    			res->data[i][k] = sum;
	    		}   			
	  		}

	  		return res;
	  	}

	  	else{
	  		matrix* res = initializeMatrix(a->row, b->column);
	  		for(int i=0; i<a->row; i++){
	   			for(int k=0; k<b->column; k++){
	   				float sum = 0;
	   				for(int u=0; u<a->column; u++){
	    				sum += a->data[i][u]*b->data[u][k];
	    			}
	    			res->data[i][k] = sum;
	    		}   			
	  		}

	  		for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	   				a->data[i][k] = res->data[i][k];
	    		}   			
	  		}
	  		deleteMatrix(res);
	  		return a;
	  	}
	}

	else{
		printf("Number of rows and columns must match\n");
		return NULL;
	}
}

//Multiply a matrix by a scalar
matrix* mulMatScalar(matrix* a, float scalar, bool res){
	if(a == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}

	if(!res){
		for(int i=0; i<a->row; i++){
			for(int k=0; k<a->column; k++){
				a->data[i][k] *= scalar; 
			}
		}

		return NULL;
	}

	else{
		matrix* res = initializeMatrix(a->row, a->column);
		for(int i=0; i<a->row; i++){
			for(int k=0; k<a->column; k++){
				res->data[i][k] = res->data[i][k]*scalar; 
			}
		}

		return res;
	}
}


matrix* schurProduct(matrix* a, matrix* b, bool res){
	if(a == NULL && b == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}
	if(sameNumOfRow(a,b) && sameNumOfColumn(a,b)){
		if(res){
			matrix* res = initializeMatrix(a->row, a->column);
			for(int i=0; i<res->row; i++){
	   			for(int k=0; k<res->column; k++){
	    			res->data[i][k] = a->data[i][k]*b->data[i][k];
	    		}   			
	  		}

	  		return res;
	  	}

	  	else{
	  		for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			a->data[i][k] *= b->data[i][k];
	    		}   			
	  		}

	  		return NULL;
	  	}
	}

	else{
		printf("Number of rows and columns must match\n");
		return NULL;
	}
}