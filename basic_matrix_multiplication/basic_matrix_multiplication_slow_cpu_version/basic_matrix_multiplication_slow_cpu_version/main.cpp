//
//  main.cpp
//  basic_matrix_multiplication_slow_cpu_version
//
//  Created by Odegaard on 7/15/15.
//  Copyright (c) 2015 imandatta. All rights reserved.
//

#include <iostream>

void MatrixMulOnHost(int m, int n, int k, float* A, float* B, float* C);

int main(int argc, const char * argv[])
{

    // insert code here...
    const int m = 2, n = 2, k = 2;
    float A[m][n] = {{1,2},{3,4}};
    float B[n][k] = {{1,2},{3,4}};
    float C[m][k];
    
    MatrixMulOnHost(m, n, k, *A, *B, *C);
    
    for (int Row = 0; Row < m; ++Row)
    {
        for (int Col = 0; Col < k; ++Col)
        {
            //std::cout << C[Row][Col] << " ";
            //std::cout << *(C[Row]+Col) << " ";
            std::cout << * ( *(C+Row)+Col) << " ";
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}

void MatrixMulOnHost(int m, int n, int k, float* A, float* B, float* C)
{
    for (int Row = 0; Row < m; ++Row)       // rows of C (rows of A)
        for (int Col = 0; Col < k; ++Col)   // cols of C (cols of B)
        {
            float sum = 0;                  // initialize sum
            for (int i = 0; i < n; ++i)          // cols of A (rows of B)
            {
                float a = A[Row * n + i];
                float b = B[Col + i * k];
                sum += a*b;
            }
            C[Row * k + Col] = sum;
        }
}