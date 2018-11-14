#include<stdlib.h>
#include<stdio.h>
double ** Transpose(double **, int, int);
void MultiplyMatrix(double ** arr, double **arr2, double **result, int mat1_row, int mat1_col, int mat2_col);
double ** Inverse(double ** matrix, int N);
double ** Estimate(double ** W, int K, FILE*);
double round(double);

int main(int argc, char *argv[]){
        if (argc != 3){
		
                return 0;
        }
        FILE* training = fopen(argv[1],"r");
        if (training==NULL)
        {
		       
                return 0;
        }

        int N = 0;
        int K = 0;
        fscanf(training, "%d\n", &K);
        fscanf(training, "%d\n", &N);

        double ** X = (double **)malloc(N*sizeof(double *));
        int i = 0;
        for(i=0; i<N; i++){
                X[i] = (double*)malloc((K+1)*sizeof(double));
        }
	double ** Y = (double **)malloc(N*sizeof(double *));
	for(i=0; i<N; ++i){
		Y[i] = (double *)malloc(1*sizeof(double));
	}
	
	
        int j = 0;
        for(i=0; i<N; ++i){
                for(j=0; j<(K+1); ++j){
                        if(j == 0){
                                X[i][j] = 1;
                        }
                        else{
                                fscanf(training, "%lf,", &X[i][j]);	
                        }
			
                }
		fscanf(training, "%lf", &Y[i][0]);
        }
	// Take out
	/*
	printf("X\n\n");
        for(i=0; i<N; ++i){
                for(j=0; j<(K+1); ++j){
                        printf("%lf ", X[i][j]);
                }
                printf("\n");
        }
	printf("\n");
	printf("House prices\n");
	for(i=0; i<N; ++i){
		printf("%lf\n", Y[i][0]);
	}
	*/
	
	double ** transpose_x = Transpose(X, N, K+1);

	double ** result = (double**)malloc((K+1)*sizeof(double*));
	for(i=0; i<(K+1); ++i){
		result[i] = (double*)malloc((K+1)*sizeof(double));
	}
	for(i=0; i<(K+1); i++){
		for(j=0; j<(K+1) ; j++){
			result[i][j] = 0;
		}
	}
	
	//printf("X^T * X\n\n");
	MultiplyMatrix(transpose_x, X, result, (K+1), N, (K+1));

	double ** new_result_inverse = Inverse(result, (K+1));

	// (Inverse) times (X^T)
	double ** inverse_times_transpose = (double**)malloc((K+1)*sizeof(double*));
	for(i=0; i<(K+1); ++i){
		inverse_times_transpose[i] = (double*)malloc(N*sizeof(double));
	}
	for(i=0; i<(K+1); i++){
		for(j=0; j<N ; j++){
			inverse_times_transpose[i][j] = 0;
		}
	}
	//printf("Inverse times X^T\n\n");
	MultiplyMatrix(new_result_inverse, transpose_x, inverse_times_transpose, (K+1), (K+1), N);
	
	// Final matrix to get W
	double ** W = (double**)malloc((K+1)*sizeof(double*));
	for(i=0; i<(K+1); ++i){
		W[i] = (double*)malloc(1*sizeof(double));
	}
	for(i=0; i<(K+1); i++){
		for(j=0; j<1 ; j++){
			W[i][j] = 0;
		}
	}
	//printf("Final answer: W\n\n");
	MultiplyMatrix(inverse_times_transpose, Y, W, (K+1), N, 1);
	fclose(training);
	FILE* test = fopen(argv[2], "r");
	double ** house_price_estimate = Estimate(W, K, test);
	free(house_price_estimate);

	
	
	

        return 0;
}

double ** Estimate(double ** W, int K, FILE* test){
	// Initialize test matrix
	
	int M;
	fscanf(test, "%d\n", &M);
	double ** test_matrix = (double**)malloc(M*sizeof(double**));
	int i, j;
	for(i=0; i<M; ++i){
		test_matrix[i] = (double*)malloc(K*sizeof(double));
	}
	for(i=0; i<M; i++){
		for(j=0; j<K; j++){
			fscanf(test, "%lf,", &test_matrix[i][j]);
		}
	}
	
	double ** new_W = (double **)malloc(K*sizeof(double *));
	for(i=0; i<K; i++){
		new_W[i] = (double *)malloc(1*sizeof(double));
		new_W[i][0] = W[i+1][0];
	}
	double ** estimate_prices = (double **)malloc(M*sizeof(double *));
	for(i=0; i<M; i++){
		estimate_prices[i] = (double *)malloc(1*sizeof(double));
		estimate_prices[i][0] = 0;
	}
	MultiplyMatrix(test_matrix, new_W, estimate_prices, M, K, 1);

	//printf("Estimate Prices: \n\n");
	for(i=0; i<M; i++){
		for(j = 0; j<1; j++){
			estimate_prices[i][0] = estimate_prices[i][0] + W[0][0];
			
			printf("%0.0f\n", estimate_prices[i][0]);
		}
	}




	return estimate_prices;
	
}

double ** Transpose(double **a, int N, int total_k){
	double ** transpose = (double **)malloc(total_k*sizeof(double*));
	
	int i;
	for(i=0; i<total_k; ++i){

		transpose[i] = (double *)malloc(N*sizeof(double));
	}

	int j;
	for(i=0; i<total_k; ++i){
		for(j=0; j<N; ++j){
			transpose[i][j] = a[j][i];
		}
	}

	// Take this out
	/*
	printf("transpose\n");
	for(i=0; i<total_k; ++i){
                for(j=0; j<N; ++j){
                        printf("%lf ", transpose[i][j]);
                }
                printf("\n");
        }
	*/
	return transpose;
}

void MultiplyMatrix(double ** arr, double **arr2, double **result, int mat1_row, int mat1_col, int mat2_col){
	//printf("%d %d %d\n", mat1_row, mat1_col, mat2_col);
	int i, j, z;
	for(i=0; i<mat1_row; ++i){
		for(j=0; j<mat2_col; ++j){
			for(z=0; z<mat1_col; ++z)
			{
				result[i][j]+=arr[i][z]*arr2[z][j];
			}
		}
	}

	// Take this out
	/*
	for (i = 0; i <  mat1_row; i++){ 
		for (j = 0; j < mat2_col; j++){ 
			printf("%lf", result[i][j]);
			printf(" ");
		}
		printf("\n"); 
	}	
	*/
}



double ** Inverse(double ** matrix, int N){
	//printf("%d hbahksnkl\n", N);

	double** result=(double**)malloc(N*sizeof(double*));
	int i,j,k;
	for(i=0;i<N;i++){
		result[i]=(double*)malloc((N*2)*sizeof(double));
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			result[i][j]=matrix[i][j];
		}
	}
	
			
	
	for(i=0;i<N;i++){
		for(j=N;j<(N*2);j++){
			if(j-N==i){
				result[i][j]=1;
			}else{
				result[i][j]=0;
			}

		}
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
		    if(i!=j){
		        double l = result[j][i]/result[i][i];
		        for(k = 0; k < 2*N; k++){
		            result[j][k] -= l * result[i][k];
		        }
		    }
		}
    	}
	    for(i = 0; i < N; i++){
		double a = result[i][i];
		for(j = 0; j < 2*N; j++){
		    result[i][j] /= a;
		}
	    }
	
	
	double** answer =(double**)malloc(N*sizeof(double*));

	for(i=0;i<N;i++){
		answer[i]=(double*)malloc((N)*sizeof(double));
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			answer[i][j]=result[i][j+N];
		}
	}

	// Take this out
	/*
	printf("Augmented Matrix\n");
	for(i = 0; i<N; i++){
		for(j = 0; j<N; ++j){
			printf("%lf ", answer[i][j]);
		}
		printf("\n");
	}
	*/

	return answer;

}










                                                                                        
