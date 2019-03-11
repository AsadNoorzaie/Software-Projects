#include <iostream>
using namespace std;

void printAandB(int ** a, int ** b, int rows1, int cols1, int rows2, int cols2);
void printMatrix(int **, int, int);
void printDMatrix(double ** a, int rows1, int cols1);
int findAndExecuteOperation(int menu_opt);
void performAddition();
void inputArray(int ** a, int rows, int cols);
void performSubtraction();
void performMultiplication();
void performDeterminant();
void performTranspose();
void performInverse();

int * result_sizes = (int *)malloc(4 * sizeof(int));

int main(){
 
    int menu_option;
    int result = 1;
    while(result!=0){
        cout << "Menu\n";
        cout << "Choice 1: addition\n";
        cout << "Choice 2: subtraction\n";
        cout << "Choice 3: multiplication\n";
        cout << "Choice 4: determinant\n";
        cout << "Choice 5: transpose\n";
        cout << "Choice 6: inverse\n";
        cout << "Choice 0: exit\n";
        cout << "Enter your choice: ";
        cin >> menu_option;
        result = findAndExecuteOperation(menu_option);
   }  
}

int findAndExecuteOperation(int menu_opt){
    switch(menu_opt){
         case 0:
            return 0;
        case 1:
            performAddition();
            return 1;
        case 2:
            performSubtraction();
            return 1;
        case 3:
            performMultiplication();
            return 1;
        case 4:
            performDeterminant();
            return 1;
        case 5:
            performTranspose();
            return 1;
        case 6:
            performInverse();
            return 1;
        default:
            return 1;
    }
}

void performTranspose(){
    int ** a;
    int ** b;
    int rows1, cols1, rows2, cols2;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);
    int ** result = (int **)malloc(cols1 * sizeof(int *));
    for(int i=0; i<cols1; ++i){
        result[i] = (int *)malloc(rows1 * sizeof(int));
    }

    for(int i=0; i<rows1; ++i){
        for(int j=0; j<cols1; ++j){
            result[j][i] = a[i][j];
        }
    }

    printMatrix(result, cols1, rows1);


    // for(int i=0; i<cols1; i++){
    //     for(int j=0; j<rows1; j++){
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void performInverse(){
    int ** a;
    int rows1, cols1;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);

    if(rows1!=3 || cols1!=3){
        cout << "Operation is not supported!" << endl;
        cout << endl;
        return;
    }

    double determinant = a[0][0]*((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1]*(a[1][0]*a[2][2] - a[2][0]*a[1][2]) + a[0][2]*(a[1][0]*a[2][1] - a[2][0]*a[1][1]);
    double ** result = (double **)malloc(rows1 * sizeof(double *));

    for(int i=0; i<rows1; i++){
        result[i] = (double *)malloc(cols1 * sizeof(double));
    }

    for(int i=0; i<rows1; ++i){
        for(int j=0; j<cols1; j++){
            result[i][j] = ((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3])) / determinant;
        }
    }

    printDMatrix(result, rows1, cols1);


    // for(int i=0; i<rows1; ++i){
    //     for(int j=0; j<cols1; ++j){
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
}

void performDeterminant(){
    int ** a;
    int rows1, cols1;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);
    if(rows1!=3 || cols1!=3){
        cout << "Operation is not supported!" << endl;
        cout << endl;
        return;
    }

    int determinant = a[0][0]*((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1]*(a[1][0]*a[2][2] - a[2][0]*a[1][2]) + a[0][2]*(a[1][0]*a[2][1] - a[2][0]*a[1][1]);

    cout << "Determinant: " << determinant << endl;
    cout << endl;
}

void performMultiplication(){
    int ** a;
    int ** b;
    int rows1, cols1, rows2, cols2;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);
    cout << "Matrix 2 # of rows: ";
    cin >> rows2;
    cout << endl;
    cout << "Matrix 2 # of columns: ";
    cin >> cols2;  
    cout << endl;
    b = new int *[rows2];
    for(int i = 0; i < rows2; i++){
        b[i] = new int[cols2];
    }
    inputArray(b, rows2, cols2);
    if(cols1!=rows2){
        cout << "Error, column number for first matrix does not equal to rows number for second matrix " << endl;
        cout << endl;
        return;
    }
    int ** result = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; ++i){
        result[i] = (int *)malloc(sizeof(int)*cols2);
    }
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < cols2; ++j)
        {
            result[i][j]=0;
        }
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < cols2; ++j)
            for(int k = 0; k < cols1; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }

    printMatrix(result, rows1, cols2);


    // for(int i=0; i<rows1; ++i){
    //         for(int j=0; j<cols2; ++j){
    //             cout << result[i][j] << " ";
    //         }
    //     cout << endl;
    // }
    // cout << endl;
}

void performSubtraction(){
    int ** a;
    int ** b;
    int rows1, cols1, rows2, cols2;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);
    cout << "Matrix 2 # of rows: ";
    cin >> rows2;
    cout << endl;
    cout << "Matrix 2 # of columns: ";
    cin >> cols2;  
    cout << endl;
    b = new int *[rows2];
    for(int i = 0; i < rows2; i++){
        b[i] = new int[cols2];
    }
    inputArray(b, rows2, cols2);
    if(rows1!=rows2 || cols1!=cols2){
        cout << "Error, two matrices are not in same dimensions" << endl;
        cout << endl;
        return;
    }


    int ** result = (int **)malloc(rows1*sizeof(int *));
    for(int i=0; i<cols1; ++i){
        result[i] = (int *)malloc(sizeof(int)*cols1);
    }

    for(int i=0; i<rows1; ++i){
        for(int j=0; j<cols1; ++j){
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    printMatrix(result, rows1, cols1);


    // cout << "Result" << endl;
    // for(int i=0; i<rows1; ++i){
    //         for(int j=0; j<cols1; ++j){
    //             cout << result[i][j] << " ";
    //         }
    //     cout << endl;
    // }
    // cout << endl;
}

void performAddition(){
    int ** a;
    int ** b;
    int rows1, cols1, rows2, cols2;
    cout << "Matrix 1 # of rows: ";
    cin >> rows1;
    cout << endl;
    cout << "Matrix 1 # of columns: ";
    cin >> cols1;  
    cout << endl;
    a = new int *[rows1];
    for(int i = 0; i < rows1; i++){
        a[i] = new int[cols1];
    }
    inputArray(a, rows1, cols1);
    cout << "Matrix 2 # of rows: ";
    cin >> rows2;
    cout << endl;
    cout << "Matrix 2 # of columns: ";
    cin >> cols2;  
    cout << endl;
    b = new int *[rows2];
    for(int i = 0; i < rows2; i++){
        b[i] = new int[cols2];
    }
    inputArray(b, rows2, cols2);
    if(rows1!=rows2 || cols1!=cols2){
        cout << "Error, two matrices are not in same dimensions" << endl;
        cout << endl;
        return;
    }
    int ** result = (int **)malloc(rows1*sizeof(int *));
    for(int i=0; i<cols1; ++i){
        result[i] = (int *)malloc(sizeof(int)*cols1);
    }
    for(int i=0; i<rows1; ++i){
        for(int j=0; j<cols1; ++j){
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printMatrix(result, rows1, cols1);

    // cout << "Result" << endl;
    // for(int i=0; i<rows1; ++i){
    //         for(int j=0; j<cols1; ++j){
    //             cout << result[i][j] << " ";
    //         }
    //     cout << endl;
    // }
    // cout << endl;
}

void inputArray(int ** a, int rows, int cols){
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            printf("Enter element (%d,%d): ",i,j);
            cin >> *(*(a+i)+j);
        }
    }
    printMatrix(a, rows, cols);

}

void printDMatrix(double ** a, int rows1, int cols1){
    cout << endl;
    for(int i=0;i<rows1;++i){
        for(int j=0; j<cols1; ++j){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMatrix(int ** a, int rows1, int cols1){
    cout << endl;
    for(int i=0;i<rows1;++i){
        for(int j=0; j<cols1; ++j){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void printAandB(int ** a, int ** b, int rows1, int cols1, int rows2, int cols2){
    cout << "------------------" << endl;
    for(int i=0;i<rows1;++i){
        for(int j=0; j<cols1; ++j){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<rows2;++i){
        for(int j=0; j<cols2; ++j){
            cout << b[i][j] << "  ";
        }
        cout << endl;
    }

        cout << "------------------" << endl;

}
