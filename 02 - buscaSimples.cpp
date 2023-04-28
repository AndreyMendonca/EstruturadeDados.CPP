#include <iostream>
#define TAM 5

using namespace std;

void imprimirVetor(int vetor[TAM]){
    cout << endl;
    for(int cont = 0; cont < TAM; cont ++){
        cout << "[ " << vetor[cont] << " ]";
    }
}

int validarNumeroNoVetor(int vetor[TAM], int numero){
    int retorno = -1;
    for(int cont = 0; cont < TAM; cont++ ){
        if(numero == vetor[cont]){
            retorno = cont;
        }
    }
    return retorno;
}

int main(){
    setlocale(LC_ALL,"PT-BT");
    int vetor[TAM] = {0,11,22,33,44};
    int numero, posicaoEncontrada;

    imprimirVetor(vetor);
    cout << endl << "QUAL POSIÇÃO VOCÊ QUER VER SE ESTÁ NO VETOR: ";
    cin >> numero;
    posicaoEncontrada = validarNumeroNoVetor(vetor,numero);
    if (posicaoEncontrada == -1){
        cout << "\n" << numero << " NÃO ESTÁ NO VETOR";
    }else{
        cout << "\nNUMERO ENCONTRADO, NA POSICAO " << posicaoEncontrada;
    }
    return 0;
}
