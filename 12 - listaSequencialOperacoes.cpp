#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
};

void limpatela(){
    system("CLS");
}

void imprimeSequencial(pessoa *ponteiroSequencial,int tamanhoDaListaSequencial) {
   cout << "\nLista: \n";
   int cont;
   for(cont = 0; cont < tamanhoDaListaSequencial ; cont++)
        cout << cont << " - " << ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n";

}

void adcComecoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg){
    if(*tamanhoDaListaSequencial == 0){
        pessoa *novalistaSequencial = new pessoa[1];
        novalistaSequencial[0].nome = nome;
        novalistaSequencial[0].rg = rg;
        ponteiroSequencial = novalistaSequencial;

    }else{
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];
        copiaListaSequencial[0].nome = nome;
        copiaListaSequencial[0].rg = rg;
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont+1].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont+1].rg = ponteiroSequencial[cont].rg;
        }
        ponteiroSequencial = copiaListaSequencial;

    }
    *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;

}

void adcFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg,int *posicaoNaLista){
        *posicaoNaLista = *tamanhoDaListaSequencial;
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];
        copiaListaSequencial[*tamanhoDaListaSequencial].nome = nome;
        copiaListaSequencial[*tamanhoDaListaSequencial].rg = rg;
        int cont;

        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }
        ponteiroSequencial = copiaListaSequencial;
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;
}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg,int posicao){
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];
        int cont;
        for(cont = 0; cont < posicao; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }

        copiaListaSequencial[posicao].nome = nome;
        copiaListaSequencial[posicao].rg = rg;

        for(cont = posicao + 1; cont < *tamanhoDaListaSequencial + 1; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont-1].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont-1].rg;
        }
        ponteiroSequencial = copiaListaSequencial;

        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;
}

void removeInicioSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial){

        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];
        int cont;
        for(cont = 1; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont-1].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont-1].rg = ponteiroSequencial[cont].rg;
        }
        ponteiroSequencial = copiaListaSequencial;
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;

}

void removeFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int *posicaoNaLista){
        *posicaoNaLista = *tamanhoDaListaSequencial - 1;
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial - 1; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }
        ponteiroSequencial = copiaListaSequencial;
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;
}

void removePosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int posicao){
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial - 1; cont++){
            if(cont < posicao){
                copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
                copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
            }else{
                copiaListaSequencial[cont].nome = ponteiroSequencial[cont+1].nome;
                copiaListaSequencial[cont].rg = ponteiroSequencial[cont+1].rg;
            }
        }
        ponteiroSequencial = copiaListaSequencial;
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;
}

string retornaNomeSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int rg,int *posicao){
        string nome = "Nao Encontrado";
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){
            if(ponteiroSequencial[cont].rg == rg){
                nome = ponteiroSequencial[cont].nome;
                cout << "Encontrado na Posicao:" << cont <<"\n";
            }
        }
        return nome;
}

int main(){
    int funcaoDesejada = 1;
    pessoa *ponteiroSequencial;
    int tamanhoDaListaSequencial = 0;
    while(funcaoDesejada < 10 && funcaoDesejada > 0){
        cout << "Tamanho Atual[" << tamanhoDaListaSequencial << "]\n";
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
        cin >> funcaoDesejada;
        limpatela();
        string nome;
        int rg, posicao,posicaoNaLista;
        switch(funcaoDesejada){
            case 1:
                cout << "Funcao Escolhida: Inserir um node no comeco da lista";
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);
                cout << "\nUsuario: " << nome << ",RG: " << rg << " adicionado ao inicio da lista.\n";
                break;
            case 2:
                cout << "Funcao Escolhida: Inserir um node no fim da lista";
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                if(tamanhoDaListaSequencial == 0){
                    adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);
                }else{
                    adcFimSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg, &posicaoNaLista);
                }
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado ao fim da lista(" << posicaoNaLista << ")";
                break;
             case 3:
                cout << "Funcao Escolhida: Inserir um node na posicao N da lista";
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;
                if(posicao == 0){
                    adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);
                }else if(posicao == tamanhoDaListaSequencial + 1){
                    adcFimSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg, &posicaoNaLista);
                }else{
                    adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, nome, rg, posicao);
                }
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado na posicao" << posicao<< "da lista.";
                break;
            case 4:
                cout << "Funcao Escolhida: Retirar um node do inicio da lista\n";
                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{
                    removeInicioSequencial(ponteiroSequencial, &tamanhoDaListaSequencial);
                    cout << "Usuario: " << nome <<",RG: "<<rg<< "foi removido do inicio da lista";
                }
                break;
            case 5:
                cout << "Funcao Escolhida: Retirar um node do fim da lista\n";
                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{
                    removeFimSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, &posicaoNaLista);
                    cout << "Usuario: "<<nome<<",RG: "<<rg<<" foi removido da posicao " << posicaoNaLista <<" da lista.";
                }
                break;
            case 6:
                cout << "Funcao Escolhida: Retirar um node do de uma posicao da lista\n";
                cout << "Digite a Posicao: ";
                cin >> posicao;
                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{

                    if(posicao == 0){
                        removeInicioSequencial(ponteiroSequencial, &tamanhoDaListaSequencial);
                    }else if(posicao == tamanhoDaListaSequencial - 1){
                        removeFimSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, &posicaoNaLista);
                    }else{
                        removePosicaoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial,posicao);
                    }
                }
                cout << "Usuario: "<<nome<<",RG: "<<rg<<" foi removido da posicao "<< posicao <<" da lista.";
                break;
            case 7:
                cout << "Funcao Escolhida: Retorna o nome e posicao pelo RG \n";
                cout << "Digite um RG: ";
                cin >> rg;
                cout << "Nome:" << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, rg, &posicao);
                break;
            case 8:
                cout << "Funcao Escolhida: Imprime a lista\n";
                imprimeSequencial(ponteiroSequencial, tamanhoDaListaSequencial);
                break;
        }
    }
    return 0;
}
