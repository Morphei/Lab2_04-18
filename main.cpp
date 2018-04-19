#include <iostream>
#include "squarematrix.h"

using namespace std;
void fillMatrix(SquareMatrix *matrix);
void showSequence(SquareMatrix *matrix);

int main()
{
    int size = 0;
    SquareMatrix* matrix = new SquareMatrix;
    cout << "---> Інформація про виконавця тут <---" << endl << endl;
    cout << "За квадратною матрицею надрукувати послідовність її елементів обходом" << endl;
    cout << "центрального ромба спіраллю від нижнього кута за годинниковою стрілкою." << endl << endl;

    cout << "Введіть розмірність матриці: ";
    cin >> size;
    cout << endl;

    if(!matrix->setSize(size))
    {
        cout << "Введено некоректну розмірність матриці" << endl;
    }
    else
    {
        cout << "Задано розмірність " << size << " елементів." << endl << endl;
        fillMatrix(matrix);
        showSequence(matrix);
        cout << endl;
    }

    return 0;
}

void fillMatrix(SquareMatrix *matrix)
{
    int size = matrix->getSize();

    int n = 0;

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            int* currentElement = matrix->getElement(i,j);
            *currentElement = n;
            n++;
        }
}

void showSequence(SquareMatrix *matrix)
{

}
