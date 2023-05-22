#include <iostream>
#define TAM 10

using namespace std;

void imprimir(int v[TAM]){
    int cont = 0;
    cout << endl;
    for(cont; cont < TAM; cont++){
        cout << " [ " << v[cont] << " ]";
    }
}

void quickSort(int vetor[TAM], int inicio, int fim){
    int pivo, esquerda, direita, meio, aux;

    esquerda = inicio;
    direita = fim;

    meio = (int) ((esquerda+direita)/2);
    pivo = vetor[meio];

    while(direita > esquerda){
        while(vetor[esquerda] < pivo){
            esquerda = esquerda + 1;
        }
        while(vetor[direita] > pivo){
            direita = direita - 1;
        }

        if(esquerda <= direita){
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;

            esquerda++;
            direita--;
        }
        imprimir(vetor);
    }

    if(inicio < direita){
        system("pause");
        cout << "\n--primeiro";
        quickSort(vetor,inicio,direita);
    }
    if(esquerda < fim){
        system("pause");
        cout << "\n--segundo";
        quickSort(vetor,esquerda,fim);
    }

}


int main(){
    setlocale(LC_ALL,"PT-BR");
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    imprimir(vetor);
    quickSort(vetor,0,TAM);
    cout << endl << "FINAL: ";
    imprimir(vetor);
    return 0;
}

