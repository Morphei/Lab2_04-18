#include "squarematrix.h"
#include <iostream>

SquareMatrix::~SquareMatrix()
{
    for(int i = 0; i < _size; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

bool SquareMatrix::setSize(int size)
{
    if(size > 0 && size <= maxSize)
    {
        _size = size;
        matrix = new int*[_size];

        for(int i = 0; i < _size; ++i)
        {
            matrix[i] = new int[_size];
        }

        for(int i = 0; i < _size; ++i)
        {
            for(int j = 0; j < _size; ++j)
            {
                matrix[i][j] = 0;
            }
        }
        return true;
    }
    else return false;
}

int SquareMatrix::getSize()
{
    return _size;
}

bool SquareMatrix::isEmpty()
{
    if(!_size)
        return true;
    else return false;
}

int* SquareMatrix::getElement(int i, int j)
{
    return &matrix[j][i];
}
