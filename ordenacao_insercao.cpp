#include <iostream>
#include <limits>
#include <stdio.h>
#include <cstring>

using std::cout;
using std::endl;

class algorithm
{
public:
    int* insertion_sort(int (&array)[5], int tamanho)
    {
        int temp;

        for (int i = 0; i < tamanho; i++)
        {
            temp = array[i];

            if (i > 0) {
                for (int j= i - 1; j > 0 && array[j] > temp; j--)
                {
                    array[j + 1] = array[j];
                }
            }
        }

        return array;
    };
};

int main () {
    int array[5] = {6,5,4,3,2};
    algorithm instancia = algorithm();
    int* aux = instancia.insertion_sort(array, 5);
    for(int i =0;i < 5; i ++) {
        cout << aux[i] << endl;
    }
}
