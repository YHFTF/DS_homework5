#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//행렬을 동적할당하는 함수 createMatrix()
int** create_Matrix(int row, int col){
    int** matrix = (int**)malloc(sizeof(int*)*row);
    for(int i=0; i<row; i++){
        matrix[i] = (int*)malloc(sizeof(int)*col);
    }
    return matrix;
}

//A와 B 행렬을 출력하는 함수 printMatrix()
void print_Matrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//A와 B행렬을 더하고 printMatrix를 통해 출력하는 함수 addMatrix
void add_Matrix(int** matrixA, int** matrixB, int row, int col){
    int** matrixC = create_Matrix(row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    print_Matrix(matrixC, row, col);
    free(matrixC);
}

//A와 B행렬을 빼고 printMatrix를 통해 출력하는 함수 subtractMatrix
void subtract_Matrix(int** matrixA, int** matrixB, int row, int col){
    int** matrixC = create_Matrix(row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    print_Matrix(matrixC, row, col);
    free(matrixC);
}

//A행렬의 전치행렬을 구하고 printMatrix를 통해 출력하는 함수 transposeMatrix
void transpose_Matrix(int** matrixA, int row, int col){
    int** matrixC = create_Matrix(col, row);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixC[j][i] = matrixA[i][j];
        }
    }
    print_Matrix(matrixC, col, row);
    free(matrixC);
}

//A행렬과 B행렬의 곱을 구하고 printMatrix를 통해 출력하는 함수 multiplyMatrix
void multiply_Matrix(int** matrixA, int** matrixB, int row, int col){
    int** matrixC = create_Matrix(row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixC[i][j] = 0;
            for(int k=0; k<col; k++){
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    print_Matrix(matrixC, row, col);
    free(matrixC);
}

//동적할당한 메모리를 해제하는 함수 freeMatrix()
void free_Matrix(int**matrixA, int**matrixB){
    free(matrixA);
    free(matrixB);
}

int main(){
    int row,col;
    scanf("%d %d", &row, &col);
    int** matrixA = create_Matrix(row, col);
    int** matrixB = create_Matrix(row, col);

    //랜덤값으로 행렬을 채운다.
    srand(time(NULL));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixA[i][j] = rand()%10;
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixB[i][j] = rand()%10;
        }
    }

    printf("Matrix A\n");
    print_Matrix(matrixA, row, col);
    printf("Matrix B\n");
    print_Matrix(matrixB,row,col);
    printf("Matrix A + B\n");
    add_Matrix(matrixA,matrixB,row,col);
    printf("Matrix A - B\n");
    subtract_Matrix(matrixA,matrixB,row,col);
    printf("Transpose Matrix A\n");
    transpose_Matrix(matrixA,row,col);
    printf("Matrix A * B\n");
    multiply_Matrix(matrixA,matrixB,row,col);

    free_Matrix(matrixA,matrixB);

    return 0;

}