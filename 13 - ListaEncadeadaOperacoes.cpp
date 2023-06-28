#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

void limpatela(){
    system("CLS");
}

int retornaTamanhoListaEncadeada(pessoa *ponteiroEncadeada){
   int tamanho = 0;
   pessoa *p = ponteiroEncadeada;
   while(p != NULL){
        p = p->proximo;
        tamanho++;
   }
   return tamanho;

}

void imprimeEncadeada(pessoa *ponteiroEncadeada) {
   pessoa *p = ponteiroEncadeada;
   int posicao = 0;
   while(p != NULL){
        cout << posicao << " - " << p->nome << ", " << p->rg << "\n";
        p = p->proximo;
        posicao++;
   }
   free(p);

}

void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){
    pessoa *novovalor = new pessoa;
    novovalor->nome = nome;
    novovalor->rg = rg;
    novovalor->proximo = ponteiroEncadeada;

    ponteiroEncadeada = novovalor;

}

void adcFimEncadeada(pessoa *ponteiroEncadeada, string nome, int rg){
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;
    pessoa *p = ponteiroEncadeada;
        while(p != NULL){
            if(p->proximo == NULL){
                p->proximo = novoValor;
                return;
            }
            p = p->proximo;

        }
    free(p);
    free(novoValor);

}

void adcPosicaoEncadeada(pessoa *ponteiroEncadeada,string nome,int rg, int posicao){
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;
    pessoa *p = ponteiroEncadeada;
    int i = 0;
    while(i <= posicao){

        if(i == posicao-1){
            pessoa *aux = new pessoa;
            aux->proximo = p->proximo;
            p->proximo = novoValor;
            novoValor->proximo = aux->proximo;
            free(aux);

        }
        p = p->proximo;

        i++;

    }

}

void removeInicioEncadeada(pessoa *&ponteiroEncadeada, string *nome, int *rg){
    *nome = ponteiroEncadeada->nome;
    *rg = ponteiroEncadeada->rg;

    ponteiroEncadeada=ponteiroEncadeada->proximo;

}

void removeFinalEncadeada(pessoa *&ponteiroEncadeada, string *nome, int *rg){
    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    if(ponteiroEncadeada->proximo == NULL){
        *nome = ponteiroEncadeada->nome;
        *rg = ponteiroEncadeada->rg;


        free(ponteiroEncadeada);
        ponteiroEncadeada = NULL;

    }else{
        p = ponteiroEncadeada;
        while(p->proximo != NULL){
            aux = p;
            p=p->proximo;
        }
        *nome = p->nome;
        *rg = p->rg;
        aux->proximo = NULL;
        free(p);
    }
}

void removePosicaoEncadeada(pessoa *ponteiroEncadeada,string *nome,int *rg, int posicao){
    pessoa *p = ponteiroEncadeada;
    int i = 0;
    while(i <= posicao){
        if(i == posicao-1){
            *nome = p->nome;
            *rg = p->rg;
            pessoa *aux = new pessoa;
            aux = p->proximo;
            p->proximo = aux->proximo;
            free(aux);
        }
        p = p->proximo;
        i++;
    }
    free(p);
}

int main(){
    //Variáveis
    int funcaoDesejada = 1, tamanho;
    //Cria o inicio da lista Encadeada
    pessoa *ponteiroEncadeada;
    //Cria um novo valor para o primeiro
    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "john";
    novoPrimeiroValor->rg = 13;
    novoPrimeiroValor->proximo = NULL;
    //Transforma o ponteiro do inicio da lista no novo valor
    ponteiroEncadeada = novoPrimeiroValor;
    //Cria um novo valor para o segundo
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "johnzin";
    novoSegundoValor->rg = 20;
    novoSegundoValor->proximo = NULL;
    //Colocando o segundo valor
    novoPrimeiroValor->proximo = novoSegundoValor;

    while(funcaoDesejada < 10 && funcaoDesejada > 0){
        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista \n";
        cout << "2 - Insercao de um node no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";

        cout << "\nTamanho Atual[" << retornaTamanhoListaEncadeada(ponteiroEncadeada) << "]\n";

        imprimeEncadeada(ponteiroEncadeada);
        cin >> funcaoDesejada;
        limpatela();
        string nome;
        int rg, posicao,posicaoNaLista;

        //Alterna as Operacoes
        switch(funcaoDesejada){
            case 1:
                cout << "Funcao Escolhida: Insere um node no inicio da lista\n";
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                adcComecoEncadeada(ponteiroEncadeada, nome, rg);
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado ao inicio da lista)";
                break;
            case 2:
                cout << "Funcao Escolhida: Insere um node no fim da lista\n";
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                if(retornaTamanhoListaEncadeada(ponteiroEncadeada) < 1){
                        adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else{
                        adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }
                cout << "Usuario: "<< nome<< ",RG: "<< rg<< " adicionado ao final da lista("<< retornaTamanhoListaEncadeada(ponteiroEncadeada) << ")";

                break;

            case 3:
                cout << "Funcao Escolhida: Insere um node na posicao escolhida da lista\n";
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                if(posicao == 0 ){
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else if(posicao == retornaTamanhoListaEncadeada(ponteiroEncadeada) - 1){
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                    adcPosicaoEncadeada(ponteiroEncadeada,nome,rg, posicao);
                }
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado na posicao "  <<  posicao  << " da lista.";
                break;
            case 4:
                if(retornaTamanhoListaEncadeada(ponteiroEncadeada) == 0){
                    cout << "Lista Vazia";
                }else{
                    removeInicioEncadeada(ponteiroEncadeada, &nome, &rg);
                    cout << "Usuario: " << nome<< ",RG: " << rg << " foi removido do inicio";
                }
                break;
            case 5:
                removeFinalEncadeada(ponteiroEncadeada, &nome, &rg);
                cout << "Usuario: " << nome << ",RG: " << rg << " foi removido do final.";
                break;
            case 6:
                cout << "Funcao Escolhida: Remove um node na posicao escolhida\n";
                cout << "Tamanho da Lista" << retornaTamanhoListaEncadeada(ponteiroEncadeada);
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                if(posicao == 0){
                    removeInicioEncadeada(ponteiroEncadeada, &nome, &rg);
                }/*else if (posicao == retornaTamanhoListaEncadeada(ponteiroEncadeada) - 1){
                    //Remove no final
                    removeFinalEncadeada(ponteiroEncadeada, &nome, &rg);
                }*/else{
                    removePosicaoEncadeada(ponteiroEncadeada, &nome, &rg, posicao);
                }
                cout << "Usuario: "<< nome<< ",RG: "<< rg<< " foi removido da posicao" << posicao;
                break;
            case 7:
                cout << "Funcao Escolhida: Retorna o nome e a posicao pelo RG\n";
                cout << "Digite o RG: ";
                cin >> rg;
                break;
            case 8:
                imprimeEncadeada(ponteiroEncadeada);
                break;
        }
    }
    return 0;
}
