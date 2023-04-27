#include <iostream>
#include <new>
#include <string>

using namespace std;


struct palavra{
    int ordem;
    string nome;
    char letra;
    int idade;
};

int main(){
    setlocale(LC_ALL,"PT-BR");
    struct palavra Aluno;
    Aluno.ordem = 1;
    Aluno.nome = "Andrey";
    Aluno.letra = 'A';
    cout << "NOME:" << Aluno.nome ;

    // USANDO NEW

    palavra *novaPalavra = new palavra;
    novaPalavra->ordem = 1;
    novaPalavra->nome = "Jorde";
    novaPalavra->letra = 'j';
    novaPalavra->idade = 50;
    cout << "\nNOME: " << novaPalavra->nome;
    return 0;
}

