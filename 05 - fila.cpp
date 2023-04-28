#include <iostream>

using namespace std;

struct numero{
    int num;
    numero *proximo;
};

struct fila{
    numero *inicio;
    numero *fim;
    int total;
};

void iniciar(fila *f){
    f->fim = NULL;
    f->inicio = NULL;
    f->total = 0;
}
int filaVazia(fila *f){
    int retorno = 0;
    if (f->total == 0){
        retorno = 1;
    }
    return retorno;
}
void enfileirar(fila *f, int num){
    numero *item = new numero;
    item->num = num;
    if(filaVazia(f)){
        item->proximo = NULL;
        f->inicio = item;
    }else{
        item->proximo = NULL;
        f->fim->proximo = item;

    }
    f->fim = item;
    f->total++;
}

void desenfileirar(fila *f){
    numero *item = f->inicio;
    if(filaVazia(f)){
        cout << "\nFILA VAZIA";
    }else{
        f->inicio = item->proximo;
        delete(item);
    }
}
void imprimir(fila *f){
    numero *auxiliar = f->inicio;
    cout << endl;
    while(auxiliar != NULL){
        cout << " [ " << auxiliar->num << " ]";
        auxiliar = auxiliar->proximo;
    }
}

fila f;
int main(){
    setlocale(LC_ALL,"PT-BR");
    iniciar(&f);
    enfileirar(&f,10);
    enfileirar(&f,15);
    enfileirar(&f,20);
    imprimir(&f);
    desenfileirar(&f);
    imprimir(&f);
    return 0;
}
