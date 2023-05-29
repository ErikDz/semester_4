/*
 * trans.col - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * my_transpose - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char my_transpose_desc[] = "Transpose submission";
void my_transpose(int M, int N, int A[N][M], int B[M][N]) {
    int block_row, block_col; 
    int row, col;
    int val0, val1, val2, val3, val4, val5, val6, val7;

    if (N == 32) {
        for (block_col = 0; block_col < M; block_col += 8) {
            for (block_row = 0; block_row < N; block_row += 8) {
                for (row = block_row; row < block_row + 8; row++) {
                    for (col = block_col; col < block_col + 8; col++) {
                        if (row != col) {
                            B[col][row] = A[row][col];
                        } else {
                            val0 = A[row][col];
                            val1 = row;
                        }
                    }
                    if (block_row == block_col) {
                        B[val1][val1] = val0;
                    }
                }
            }
        }
    } else if (N == 64) {
        for (block_col = 0; block_col < M; block_col += 8) {
            for (block_row = 0; block_row < N; block_row += 8) {
                for (row = block_row; row < block_row + 4; row++) {
                    val0 = A[row][block_col];
                    val1 = A[row][block_col + 1];
                    val2 = A[row][block_col + 2];
                    val3 = A[row][block_col + 3];
                    val4 = A[row][block_col + 4];
                    val5 = A[row][block_col + 5];
                    val6 = A[row][block_col + 6];
                    val7 = A[row][block_col + 7];
                    B[block_col][row] = val0;
                    B[block_col + 1][row] = val1;
                    B[block_col + 2][row] = val2;
                    B[block_col + 3][row] = val3;
                    B[block_col][row + 4] = val4;
                    B[block_col + 1][row + 4] = val5;
                    B[block_col + 2][row + 4] = val6;
                    B[block_col + 3][row + 4] = val7;
                }
                for (col = block_col; col < block_col + 4; col++) {

                    // A left-down
                    val4 = A[block_row + 4][col];
                    val5 = A[block_row + 5][col];
                    val6 = A[block_row + 6][col];
                    val7 = A[block_row + 7][col];

                    // B right-above
                    val0 = B[col][block_row + 4];
                    val1 = B[col][block_row + 5];
                    val2 = B[col][block_row + 6];
                    val3 = B[col][block_row + 7];

                    // set B right-above
                    B[col][block_row + 4] = val4;
                    B[col][block_row + 5] = val5;
                    B[col][block_row + 6] = val6;
                    B[col][block_row + 7] = val7;

                    // set B left-down
                    B[col + 4][block_row] = val0;
                    B[col + 4][block_row + 1] = val1;
                    B[col + 4][block_row + 2] = val2;
                    B[col + 4][block_row + 3] = val3;

                    // set B right-down
                    B[col + 4][block_row + 4] = A[block_row + 4][col + 4];
                    B[col + 4][block_row + 5] = A[block_row + 5][col + 4];
                    B[col + 4][block_row + 6] = A[block_row + 6][col + 4];
                    B[col + 4][block_row + 7] = A[block_row + 7][col + 4];
                }
            }
        }
    } else {
        for (block_col = 0; block_col < M; block_col += 16) {
            for (block_row = 0; block_row < N; block_row += 16) {
                for (row = block_row; (row < N) && (row < block_row + 16); row++) {
                    for (col = block_col; (col < M) && (col < block_col + 16); col++) {
                        if (row != col) {
                            B[col][row] = A[row][col];
                        } else {
                            val0 = A[row][col];
                            val1 = row;
                        }
                    }
                    if (block_row == block_col) {
                        B[val1][val1] = val0;
                    }
                }
            }
        }
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * simple_transpose - A simple baseline transpose function, not optimized for the cache.
 */
char simple_transpose_desc[] = "Simple row-wise scan transpose";
void simple_transpose(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions() {
    /* register your solution function */
    registerTransFunction(my_transpose, my_transpose_desc);

    /* register any additional transpose functions */
    registerTransFunction(simple_transpose, simple_transpose_desc);
}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
