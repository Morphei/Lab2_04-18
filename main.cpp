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
void showArray(int arr[], int size)
{
    int i = 0;

    while(i < size)
    {
        for(int n = 0; n < 10; n++)
        {
            if(i < size)
                cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
}

//Функція обчислення послідовності елементів масиву
//за заданим алгоритмом
void calculateSequence(SquareMatrix *matrix)
{
    bool is_even = false;

    int rhombus_size = 0;
    int matrix_size = matrix->getSize();

    if(matrix_size % 2 == 0){
        is_even = true;
    }

    int array_size = 0;

    if(is_even){
        rhombus_size = matrix_size + 1;
        array_size = 2;
        for(int i = 1; i < matrix_size / 2; i++)
        {
            array_size = array_size + (2 * i + 2);
        }

        array_size *= 2;
    }
    else{
        array_size = 1;
        rhombus_size = matrix_size;
        for(int i = 1; i < matrix_size / 2; i++)
        {
            array_size = array_size + (2 * i + 1);
        }
        array_size *= 2;
        array_size += matrix_size;
    }

    int array[array_size];

    int loops = rhombus_size / 2;
    int loop_counter = 0;

    int direction_x = -1; //Змінні, що визначають напрям руху по х та у
    int direction_y = -1;

    if(is_even){
        direction_x = 0;
        direction_y = -1;
    }

    int max_index = matrix_size - 1;
    int min_index = 0;

    int current_index = 0;

    bool step_over_x = false;
    bool step_over_y = true;

    while(loops)
    {
        int y = 0;
        if(is_even){
            y = max_index / 2 + 1;
        }else{
            y = max_index / 2;
        }
        int x = max_index - loop_counter;

        //Визначаємо стартову позицію
        int start_x = x;
        int start_y = y;

        //Додаємо перший елемент в послідовність, і йдемо в циклі по ромбу, поки не дійдемо
        //до стартової позиції
        array[current_index] = *matrix->getElement(x, y);
        current_index++;
        x += direction_x;
        y += direction_y;

        while(x != start_x || y != start_y)
        {
            if(x >= 0 && y >= 0)
            {
                array[current_index] = *matrix->getElement(x, y);
                current_index++;
            }
            // Визначаємо напрям руху, якщо дійшли до мінімальних чи максимальних індексів
            if(x == max_index - loop_counter){
                if(is_even){
                    if(step_over_x){
                        step_over_x = false;
                        direction_x = 0;
                    }else{
                        step_over_x = true;
                        direction_x = -1;
                    }
                }
                else{
                    direction_x = -1;
                }
            }

            if(x == min_index + loop_counter){
                if(is_even){
                    if(step_over_x){
                        step_over_x = false;
                        direction_x = 0;
                    }else{
                        step_over_x = true;
                        direction_x = 1;
                    }
                }
                else{
                    direction_x = 1;
                }
            }

            if(y == max_index - loop_counter){
                if(is_even){
                    if(step_over_y){
                        step_over_y = false;
                        direction_y = 0;
                    }else{
                        step_over_y = true;
                        direction_y = -1;
                    }
                }
                else{
                    direction_y = -1;
                }
            }

            if(y == min_index + loop_counter){
                if(is_even){
                    if(step_over_y){
                        step_over_y = false;
                        direction_y = 0;
                    }else{
                        step_over_y = true;
                        direction_y = 1;
                    }
                }
                else{
                    direction_y = 1;
                }
            }

            x += direction_x;
            y += direction_y;
        }
        loop_counter++;
        loops--;

        if(is_even){
            direction_x = 0;
            direction_y = -1;
        }else{
            direction_x = -1;
            direction_y = -1;
        }

        step_over_x = false;
        step_over_y = true;
    }

    //Додавання останнього центрального елементу послідовності
    if(!is_even){
    array[current_index] = *matrix->getElement(max_index / 2, max_index - loop_counter);
    }
    showArray(array, array_size);
}
