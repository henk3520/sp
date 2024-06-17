#include <stdio.h>
#include <stdlib.h>

// 矩陣結構
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// 創建矩陣
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// 釋放矩陣內存
void freeMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

// 矩陣轉置
Matrix transpose(Matrix matrix) {
    Matrix result = createMatrix(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

// 矩陣相加
Matrix add(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// 矩陣相乘
Matrix multiply(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        printf("Error: Matrices dimensions do not match for multiplication.\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// 印出矩陣
void dump(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 測試函數庫
    Matrix a = createMatrix(2, 3);
    Matrix b = createMatrix(2, 3);
    Matrix c = createMatrix(3, 2);

    // 初始化矩陣a
    a.data[0][0] = 1; a.data[0][1] = 2; a.data[0][2] = 3;
    a.data[1][0] = 4; a.data[1][1] = 5; a.data[1][2] = 6;

    // 初始化矩陣b
    b.data[0][0] = 7; b.data[0][1] = 8; b.data[0][2] = 9;
    b.data[1][0] = 10; b.data[1][1] = 11; b.data[1][2] = 12;

    // 初始化矩陣c
    c.data[0][0] = 1; c.data[0][1] = 4;
    c.data[1][0] = 2; c.data[1][1] = 5;
    c.data[2][0] = 3; c.data[2][1] = 6;

    // 印出矩陣a
    printf("Matrix a:\n");
    dump(a);
    
    // 印出矩陣b
    printf("Matrix b:\n");
    dump(b);
    
    // 矩陣相加
    Matrix sum = add(a, b);
    printf("Sum of a and b:\n");
    dump(sum);
    
    // 矩陣轉置
    Matrix transposedA = transpose(a);
    printf("Transposed matrix a:\n");
    dump(transposedA);
    
    // 矩陣相乘
    Matrix product = multiply(a, c);
    printf("Product of a and c:\n");
    dump(product);

    // 釋放內存
    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(c);
    freeMatrix(sum);
    freeMatrix(transposedA);
    freeMatrix(product);

    return 0;
}
//chatgpt輔助生成
