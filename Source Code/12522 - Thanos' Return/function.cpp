#include <iostream>
#include "function.h"
using namespace std;

Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            mat[i][j] = 0;
        }
    }
}

int* Matrix::operator[] (const int &x)
{
    return mat[x];
}

Matrix Matrix::operator+ (const Matrix &x) const
{
    Matrix add = Matrix(x.row, x.col);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<x.col;j++)
        {
            add.mat[i][j] = (this->mat[i][j] + x.mat[i][j])%MOD;
            if(add.mat[i][j] < 0)
            {
                add.mat[i][j] = add.mat[i][j] + MOD;
            }
        }
    }
    return add;
}

Matrix operator* (const Matrix &x, const Matrix &y)
{
    Matrix mul = Matrix(x.row, y.col);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<y.col;j++)
        {
            for(int k=0;k<x.col;k++)
            {
                mul.mat[i][j] = (mul.mat[i][j]+(x.mat[i][k]*y.mat[k][j])%MOD)%MOD;
                if(mul.mat[i][j] < 0)
                {
                    mul.mat[i][j] = mul.mat[i][j] + MOD;
                }
            }
        }
    }
    return mul;
}
