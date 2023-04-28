#include <iostream>

using namespace std;

void imprimir(int vetor[]){
    for(int cont = 0; cont < 10; cont ++){
        cout << "[ " << vetor[cont] << " ]";
    }
}

void insertionSort(int vetor[10]){
    int i, j, atual;
    for(i = 1; i<10; i++){
        atual = vetor[i];
        j = i-1;
        while( (j >= 0 ) && ( atual < vetor[j] ) ){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = atual;
    }

}

int main(){
    setlocale(LC_ALL,"PT-BR");
    int vetor[10] = {10,9,8,7,6,5,4,3,2,1};
    imprimir(vetor);
    insertionSort(vetor);
    cout << endl;
    imprimir(vetor);
    return 0;
}
