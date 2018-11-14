#include <stdio.h>
#include <stdlib.h>


void MultiplyMatrix(int ** arr, int **arr2, int **result, int mat1_row, int ma1_col, int mat2_col);

int main(int argc, char** argv){
	if (argc != 2){
		return 0;
	}
	FILE* file = fopen(argv[1],"r");
	if (file==NULL) 
	{
		printf("error"); 
		return 0;
	}
	// get size of the 2D array
	int mat1_row;
	int mat1_col;
	int i;
	int j;

	fscanf(file, "%d %d", &mat1_row, &mat1_col);
	int **arr = (int**)malloc(mat1_row*sizeof(int *));
	//int *arr[mat1_row];
	for (i=0; i<mat1_row; i++){
		arr[i] = (int *)malloc(mat1_col * sizeof(int));
	}
	for(i=0; i<mat1_row; i++){
		for(j=0; j<mat1_col ; j++){
			//printf("%d\n", arr[i][j]);
		}
	}
	
	int count = 0;
	int row_count = 0;
	int col_count=0;
	for (i = 0; i <  mat1_row; i++){
		for (j = 0; j < mat1_col; j++){
			arr[i][j] = ++count;
		}
	}
	while(row_count<mat1_row){
		while(col_count<mat1_col){
			fscanf(file, "%d\n", &arr[row_count][col_count]);
			col_count ++;
		}
		col_count=0;
		row_count++;
	}	
	for (i = 0; i < mat1_row; i++){
		for (j = 0; j < mat1_col; j++){
			//printf("%d ", arr[i][j]);
		}
	}


	int mat2_row, mat2_col; 
	fscanf(file, "%d %d\n", &mat2_row, &mat2_col);
	int **arr2 = (int **)malloc(mat2_row*sizeof(int *));

	if(mat1_col!=mat2_row){
		printf("bad-matrices\n");
		return 0;
	}

	for (i=0; i<mat2_row; i++) {
		arr2[i] = (int *)malloc(mat2_col * sizeof(int));
	}
	row_count = 0; 
	col_count = 0;
	while(row_count < mat2_row){
		while(col_count < mat2_col){
			fscanf(file, "%d\n", &arr2[row_count][col_count]); 
			col_count++;
		}
		col_count = 0;
		row_count++;
	}

	for (i = 0; i <  mat2_row; i++){ 
		for (j = 0; j < mat2_col; j++){ 
			printf("%d ", arr2[i][j]);
		}
		printf("\n"); 
	}

  // initialize the result matrix size
	int ** result = (int**)malloc(mat1_row*sizeof(int*));
	for(i=0; i<mat1_row; ++i){
		result[i] = (int*)malloc(mat2_col*sizeof(int));
	}
	for(i=0; i<mat1_row; i++){
		for(j=0; j<mat2_col ; j++){
			result[i][j] = 0;
		}
	}


	MultiplyMatrix(arr, arr2, result, mat1_row, mat1_col, mat2_col);

	return 0;
}

void MultiplyMatrix(int ** arr, int **arr2, int **result, int mat1_row, int mat1_col, int mat2_col){
	int i, j, z;
	for(i=0; i<mat1_row; ++i){
		for(j=0; j<mat2_col; ++j){
			for(z=0; z<mat1_col; ++z)
			{
				result[i][j]+=arr[i][z]*arr2[z][j];
			}
		}
	}
	for (i = 0; i <  mat1_row; i++){ 
		for (j = 0; j < mat2_col; j++){ 
			printf("%d", result[i][j]);
			if(mat2_col - j == 1){
				continue;
			}
			printf("\t");
		}
		printf("\n"); 
	}
}




