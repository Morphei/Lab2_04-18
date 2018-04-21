#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

class SquareMatrix
{
private:
    const int maxSize = 30;
    int _size;
    int matrix[30][30];

public:
    bool setSize(int size);
    int getSize();
    bool isEmpty();
    int *getElement(int i, int j);
};

#endif // SQUAREMATRIX_H
