#include <iostream>

using namespace std;

struct adicionar{
    int num;
    adicionar *proximo;
};

struct pilha{
    adicionar *topo;
    int total;
};

void iniciar(pilha *p){
    p->topo = NULL;
    p->total = 0;
}

int pilhaVazia(pilha *p){
    int retorno = 0;
    if(p->total = 0){
        retorno = 1;
    }
    return retorno;
}

void push(pilha *p, int num){
    adicionar *numero = new adicionar;
    numero->num = num;
    numero->proximo = p->topo;
    p->topo = numero;
    p->total++;
}

void pop(pilha *p){
    adicionar *auxiliar = p->topo;
    if(pilhaVazia(p)){
        cout << "\nPILHA VAZIA";
    }else{
        p->topo = auxiliar->proximo;
        delete(auxiliar);
    }
}

void imprimir(pilha *p){
    adicionar *auxiliar;
    auxiliar = p->topo;
    cout << endl;
    while(auxiliar != NULL){
        cout << " [ " << auxiliar->num << " ]";
        auxiliar = auxiliar->proximo;
    }
}

pilha p;
int main(){
    setlocale(LC_ALL,"PT-BR");
    iniciar(&p);
    push(&p,10);
    push(&p,11);
    push(&p,12);
    imprimir(&p);
    pop(&p);
    imprimir(&p);
    return 0;
}
