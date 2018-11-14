#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool filled_puzzle(int**, int *, int *);
bool sudoku_solver(int**);
void printSudoku(int **);
bool safe_to_enter(int **, int, int, int);
bool invalidSubGrid(int ** puzzle, int row, int col, int num);
bool invalidPuzzle(int ** puzzle);


int main(int argc, char *argv[]){

	FILE* file = fopen(argv[1], "r");
	// create 9x9 grid and fill values
	int ** puzzle = (int **)malloc(9*sizeof(int *));
	char val;
	int i, j;
	int x = 0;
	for(i=0; i<9; ++i){
		puzzle[i] = (int *)malloc(9*sizeof(int));
	}
	for(i=0; i<9; ++i){
		for(j=0; j<9; ++j){
			fscanf(file, "%c\t", &val);
			if(val != '-'){
				x = val - '0';
				puzzle[i][j] = x;
				continue;
			}
			puzzle[i][j] = 0;
			
		}
	}
	if(invalidPuzzle(puzzle)){
		printf("no-solution");
		return 0;
	}

	if(!sudoku_solver(puzzle))
		printf("no-solution\n");
	else
		printSudoku(puzzle);

	return 0;
}

bool invalidPuzzle(int ** puzzle){
	/*
 	* 1. Check if there are duplicate rows from 1 to 9
 	* 2. Check if there are duplicate number in columns from 1 to 9
 	* 3. Check subgrids to make sure there are no duplicates 	
 	*/
	int count = 0;
	for(int num=1; num<=9; ++num){
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j){
				if(puzzle[i][j] == num)
					count ++;
				if(count > 1)
					return true;		
			}
			count = 0;
		}
	}
	
	count=0;
	for(int num=1; num<=9; ++num){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(puzzle[j][i] == num)
					count++;
				if(count > 1)
					return true;
			}
			count = 0;
		}
	}
	count=0;

	for(int num=1; num<=9; ++num){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(invalidSubGrid(puzzle, i, j, num))
					return true;
			}
		}
	}
	
	return false;
	
	
}

bool invalidSubGrid(int ** puzzle, int row, int col, int num){
	int count = 0;
	int starting_row = (row/3)*3;
	int starting_col = (col/3)*3;
	for(int i=starting_row; i<(starting_row+3); ++i){
		for(int j=starting_col; j<(starting_col+3); ++j){
			if(puzzle[i][j] == num){
				count++;
			}
			if(count > 1)
				return true;
		}
	}
	return false;

}

void printSudoku(int ** puzzle){
	int i;
	int j;
	for(i=0; i<9; ++i){
		for(j=0; j<9; ++j){
			printf("%d", puzzle[i][j]);
			if(j==8)
				continue;
			printf("\t");
		}
		if(i!=8)
			printf("\n");
	}
}


bool sudoku_solver(int** puzzle){
	
	int column;
	int row;
	if(!filled_puzzle(puzzle, &column, &row)){
		return true;
	}


	int i = 0;
	for(i=1; i<=9; i++){
		if(safe_to_enter(puzzle, i, column, row)){
			puzzle[row][column] = i;
			if(sudoku_solver(puzzle)){
				return true;
			}
			else{
				puzzle[row][column] = 0;
			}
		}
	}
	return false;
	
}

bool safe_to_enter(int **puzzle, int num, int col, int row){
	/*
	1) Check the columns of the specified index of row to see if i exists
	2) Same thing for the rows
	3) Check submatrix if the value i exists within 3x3 grid
	4) If not in any of them return true
	*/

	for(int i=0; i<9; ++i){
		if(puzzle[row][i] == num){
			return false;
		}
	}

	for(int i=0; i<9; ++i){
		if(puzzle[i][col] == num){
			return false;
		}
	}
	

	int j;
	int starting_row = (row/3)*3;
	int starting_col = (col/3)*3;
	for(int i=starting_row; i<(starting_row+3); ++i){
		for(j=starting_col; j<(starting_col+3); ++j){
			if(puzzle[i][j] == num){
				return false;
			}
		}
	}
	return true;

}

bool filled_puzzle(int**puzzle, int * col, int * row){
	int i = 0;
	int j = 0;
	for(i=0; i<9; ++i){
		for(j=0;j<9;++j){
			if(puzzle[i][j] == 0){
				*col = j;
				*row = i;
				return true;
			}	
		}
	}
	return false;
}









