#include<stdlib.h>
#include<stdio.h>


void isMagic(int **, int);

int main(int argc, char **argv){

	if (argc != 2){
			return 0;
	}

	FILE* file = fopen(argv[1],"r");
	if (file==NULL) 
	{
		return 0;
	}

	int size = 0;
	int i;
	int j;

	// create the 2D matrix
	fscanf(file, "%d\n", &size);
	int ** arr = (int **)malloc(size*sizeof(int *));
	for(i=0; i<size; ++i){
		arr[i] = (int *)malloc(size*sizeof(int));
	}

	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			fscanf(file, "%d", &(arr[i][j]));
		}
	}

	// make a matrix that is size^2 and whenever you are indexing this matrix you do mock_matrix[num-1] and set it to 1, if already one then you print 'not-magic'
	// also set mock_matrix values equal to 0 at each index since C puts arbitrary value
	// after check there are no zeros in each index if so, then print 'not-magic'

	int *mock_matrix = (int *)malloc((size*size)*sizeof(int));
	for(i=0; i<(size*size); ++i){
		*(mock_matrix+i) = 0;
	}

	// populate mock_matrix
	int value = 0;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			value = arr[i][j];
			if(value < 1){
				printf("not-magic\n");
				return 0;
			}
			if(value > (size*size)){
				printf("not-magic\n");
				return 0;
			}
			if(mock_matrix[value-1] == 1){
				printf("not-magic\n");
				return 0;
			}
			else{
				mock_matrix[value-1] = 1;
			}
		}
	}

	// check if mock_matrix has any zeroes and if it does then print not-magic

	for(i=0; i<(size*size); ++i){
		if(*(mock_matrix + i) == 0){
			printf("not-magic\n");
			return 0;
		}
	}

	// now matrix is filled in call isMagic to determine if matrix is a magic square
	isMagic(arr, size);

	return 0;
}


void isMagic(int ** arr, int size){
	int i;
	int j;
	int sum = 0;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			if(i==j){
				sum = sum + arr[i][j];
			}
		}
	}
	int check_row_sum = 0;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			check_row_sum = check_row_sum+arr[i][j];
		}
		if(check_row_sum != sum){

			printf("not-magic\n");
			return;
		}
		check_row_sum = 0;
	}

	int check_col_sum = 0;

	for(j=0; i<size; ++i){
		for(i=0; j<size; ++j){
			check_col_sum = check_col_sum + arr[i][j];
		}
		if(check_col_sum != sum){
			printf("not-magic\n");
			return;
		}
		check_col_sum = 0;
	}

	printf("magic\n");
	return;


}
