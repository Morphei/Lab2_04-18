#include <iostream>
#include <vector>
#include "squarematrix.h"

using namespace std;
void fillMatrix(SquareMatrix *matrix);
void calculateSequence(SquareMatrix *matrix);

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

    if(!matrix->setSize(size)) //Перевірка на коректність введеногї розмірності
    {
        cout << "Введено некоректну розмірність матриці" << endl;
    }
    else
    {
        cout << "Задано розмірність " << size << " елементів." << endl << endl;
        cout << "Варіант 188" << endl << endl;
        fillMatrix(matrix);
        calculateSequence(matrix);
        cout << endl;
    }

    return 0;
}

//Функція заповнення матриці
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

//Функція відображення вихідного масиву на екрані
void showArray(vector<int> arr)
{
    int i = 0;

    while(i < arr.size())
    {
        for(int n = 0; n < 10; n++)
        {
            if(i < arr.size())
                cout << arr.at(i) << " ";
            i++;
        }
        cout << endl;
    }
}

//Функція обчислення послідовності елементів масиву
//за заданим алгоритмом
void calculateSequence(SquareMatrix *matrix)
{
    vector<int> array;

    int rhombus_size = 0;
    int matrix_size = matrix->getSize();

    if(matrix_size % 2 == 0)
        rhombus_size = matrix_size + 1;
    else rhombus_size = matrix_size;

    int loops = rhombus_size / 2;
    int loop_counter = 0;

    int direction_x = -1; //Змінні, що визначають напрям руху по х та у
    int direction_y = -1;

    int max_index = matrix_size - 1;
    int min_index = max_index / 2 - rhombus_size / 2;

    while(loops)
    {
        int x = max_index / 2;
        int y = max_index - loop_counter;

        //Визначаємо стартову позицію
        int start_x = x;
        int start_y = y;

        //Додаємо перший елемент в послідовність, і йдемо в циклі по ромбу, поки не дійдемо
        //до стартової позиції
        array.push_back(*matrix->getElement(x, y));
        x += direction_x;
        y += direction_y;

        while(x != start_x || y != start_y)
        {
            if(x >= 0 && y >= 0)
                array.push_back(*matrix->getElement(x, y));
            // Визначаємо напрям руху, якщо дійшли до мінімальних чи максимальних індексів
            if(x == max_index - loop_counter) direction_x = -1;
            if(y == max_index - loop_counter) direction_y = -1;
            if(x == min_index + loop_counter) direction_x = 1;
            if(y == min_index + loop_counter) direction_y = 1;

            x += direction_x;
            y += direction_y;
        }
        loop_counter++;
        loops--;

        direction_x = -1;
        direction_y = -1;
    }

    //Додавання останнього центрального елементу послідовності
    array.push_back(*matrix->getElement(max_index / 2, max_index - loop_counter));

    showArray(array);
}
