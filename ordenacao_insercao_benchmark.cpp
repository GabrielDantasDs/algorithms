#include <iostream>
#include <limits>
#include <stdio.h>
#include <cstring>
#include <benchmark/benchmark.h>

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

static void BM_InsertionSort(benchmark::State& state) {
	int array[5] = {6, 5, 4, 3, 2};
	algorithm instancia = algorithm();

	for(auto _: state) {
		instancia.insertion_sort(array, 5);
	}
}

BENCHMARK(BM_InsertionSort);
BENCHMARK_MAIN();

