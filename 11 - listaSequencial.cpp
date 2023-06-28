#include <iostream>
#include <new>
#define TAM 3

using namespace std;

void imprimeLista(int *vetor, int tamanhoDaLista){
    for(int cont = 0; cont < tamanhoDaLista; cont++){
        cout << "Posição: [" << cont << "] = " << vetor[cont] << endl;
    }
}
int main(){
    int vetor[TAM] = {1,2,3};
    imprimeLista(vetor,TAM);

    //alocando memoria na hora
    int n;
    cout << "\nDigite o tamanho do vetor: ";
    cin >> n;
    int *newVetor = new int[n];

    cout << "\nGrave os valores do vetor: ";
    for(int cont = 0; cont < n; cont++){
        cout << "Posição: [" << cont << "] = ";
        cin >> newVetor[cont];
        cout << endl;
    }
    cout << "\nNovo vetor: ";
    imprimeLista(newVetor, n);

    return 0;


}
