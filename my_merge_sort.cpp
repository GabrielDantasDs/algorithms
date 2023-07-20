#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;

class algorithm {
public:
	int* merge(std::vector<int> v, int tamanho) {

		int inicio = 0;
		int fim = tamanho - 1;
		int meio = tamanho%2 == 0 ? tamanho/2 : tamanho/2  + 1;
		int tamanhoEsquerda = meio;
		int tamanhoDireita = tamanho - meio;
		int* esquerda = new int[tamanhoEsquerda];
		int* direita = new int[tamanhoDireita];
		int* auxiliar = new int[tamanho];

		cout << "array da esquerda => ";
		for (int i=0; i < tamanhoEsquerda; i++) {
			esquerda[i] = v[i];
			cout << v[i] << " ";
		}

		std::vector<int> vetorEsquerda(esquerda, esquerda + tamanhoEsquerda);

		cout<<endl;

		if (vetorEsquerda.size() > 1) {
			esquerda = merge(vetorEsquerda, tamanhoEsquerda);
		}

		cout << endl;

		cout << "array da direita => ";
		for (int j=0; j < tamanhoDireita; j++) {
			direita[j] = v[meio + j];
			cout << v[meio+j] << " ";
		}

		cout << endl;
		std::vector<int> vetorDireita(direita, direita + tamanhoDireita);
		if (vetorDireita.size() > 1) {
			direita = merge(vetorDireita, tamanhoDireita);
		}

		cout << endl;

		int i = 0;
		int j = 0;
		int k = 0;

		while(i < tamanhoEsquerda && j < tamanhoDireita) {
			if (direita[j] < esquerda[i]) {
				auxiliar[k] = direita[j];
				j++;
			} else {
				auxiliar[k] = esquerda[i];
				i++;
			}

			k++;
		};

		cout << endl;

		while (i < tamanhoEsquerda) {
			auxiliar[k] = esquerda[i];
			i++;
			k++;
		};

		while (j < tamanhoDireita) {
			auxiliar[k] = direita[j];
			j++;
			k++;
		};

		cout << "Resultante dessa etapa: " << endl;
		for (int p = 0; p < tamanho; p++) {
			cout << auxiliar[p] << " ";
		}

		cout << endl;

		return auxiliar;
	};

};

int main () {
	std::string entrada;
	std::vector<int> vetor;

	std::cout << "Digite números inteiros separados por espaço:";
	std::getline(std::cin, entrada);
	std::istringstream iss(entrada);
	int elemento;

	while (iss >> elemento) {
		vetor.push_back(elemento);
	}

	algorithm instancia;
	int* res = instancia.merge(vetor, vetor.size());

	for (int i=0; i < (int) vetor.size(); i++) {
	std::cout << res[i] << " ";
	}
}
