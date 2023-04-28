#include <iostream>

using namespace std;


void imprimir(int vetor[]){
    for(int cont = 0; cont < 10; cont ++){
        cout << "[ " << vetor[cont] << " ]";
    }
}
void bubbleSort(int vetor[10]){
    int x, y, aux;
    for(x = 0; x < 10; x++){
        for(y = x + 1; y < 10; y++){
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }
}
int main(){
    setlocale(LC_ALL,"PT-BR");
    int vetor[10] = {10,9,8,7,6,5,4,3,2,1};
    imprimir(vetor);
    bubbleSort(vetor);
    cout << endl;
    imprimir(vetor);
    return 0;
}
