#include <iostream>

using namespace std;

void imprimir(int vetor[]){
    cout << endl;
    for(int cont = 0; cont < 10; cont ++){
        cout << "[ " << vetor[cont] << " ]";
    }
}

void selectionSort(int vetor[10]){
    int posicaoDoMenorValor, aux, i, j;
    for(i = 0; i < 10; i++){
        posicaoDoMenorValor = i;
        for(j = i+1; j < 10; j++){
            if(vetor[j] < vetor[posicaoDoMenorValor]){
                posicaoDoMenorValor = j;
            }
        }

        if (posicaoDoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }
        imprimir(vetor);

    }

}

int main(){
    setlocale(LC_ALL,"PT-BR");
    int vetor[10] = {10,9,8,7,6,5,4,3,2,1};
    imprimir(vetor);
    selectionSort(vetor);
    cout << endl;
    imprimir(vetor);
    return 0;
}
