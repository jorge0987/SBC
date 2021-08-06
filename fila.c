#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

/**Estrutura da fila que vai apontar para o primeiro cliente*/
struct tipofpri{
    tipofno* p;
};

/**Estrutura de dados dos clientes na fila*/
struct tipofno{
    char* nome;
    char* livro;
    int genero;
    tipofno* p;
};

/**Fun��o para criar o a estrutura que vai apontar para o primeiro cliente da fila*/
tipofpri* CriarFila(void){
    tipofpri* f = (tipofpri*) malloc(sizeof(tipofpri));
    if(f==NULL){
        printf("Fila n�o alocada.\n");
        exit(1);
    }else{
        f->p=NULL;
    }
    return f;
}

/**Fun��o que insere um cliente no final da fila*/
void InsereFila(tipofpri* v, char* nome, char* livro, int n){
    tipofno* no = (tipofno*) malloc(sizeof(tipofno));
    if(no==NULL){
        printf("Elemento para a fila n�o alocado.\n");
        exit(1);
    }else{
        no->nome=nome;
        no->livro=livro;
        no->genero=n;
        no->p=NULL;
        if(v->p==NULL){
        v->p=no;
        }else{
        tipofno* aux;
        tipofno* anterior;
        for(aux=v->p;aux!=NULL;aux=aux->p){
            anterior=aux;
        }
            anterior->p=no;
        }
    }
}

/**Fun��o para ver se a fila esta vazia*/
int EstaVaziaFila(tipofpri* v){
    if(v->p==NULL){
        return 1;
    }else{
        return 0;
    }
}

/**Fun��o para retornar o nome do primeiro cliente da fila*/
char* RetornaNomeFila(tipofpri* v){
    if(EstaVaziaFila(v)){
        printf("A fila esta vazia.\n");
        return NULL;
    }else{
        return v->p->nome;
    }
}

/**Fun��o para retornar o livro do primeiro cliente da fila*/
char* RetornaLivroFila(tipofpri* v){
    if(EstaVaziaFila(v)){
        printf("A fila esta vazia.\n");
        return NULL;
    }else{
        return v->p->livro;
    }
}

/**Fun��o para retorna o genero do livro do primeiro cliente*/
int RetornaGeneroFila(tipofpri* v){
    if(EstaVaziaFila(v)){
        printf("A fila esta vazia.\n");
        return NULL;
    }else{
        return v->p->genero;
    }
}

/**Fun��o para remover a primeira estrutura*/
void RemoveUmFila(tipofpri* v){
    tipofno* aux=v->p;
    v->p=aux->p;
    free(aux);
    aux=NULL;
}

/**Fun��o para remover todos os clientes da fila e remover a fila*/
void RemoveTudoFila(tipofpri* v){
    tipofno* aux=v->p;
    while(aux!=NULL){
        tipofno* aux2=aux->p;
        free(aux);
        aux=aux2;
    }
    free(v);
    v=NULL;
}

/**Fun��o para exibir todos os clientes na fila*/
void ExibirFila(tipofpri* v){
    if(EstaVaziaFila(v)){
        printf("A Fila esta vazia.\n");
    }else{
        tipofno* aux;
        for(aux=v->p;aux!=NULL;aux=aux->p){
            printf("Nome: %s\nLivro: %s\n", aux->nome, aux->livro);
            if(aux->genero==1){
                printf("Genero: Fic��o\n\n");
            }else if(aux->genero==2){
                printf("Genero: Romance\n\n");
            }else if(aux->genero==3){
                printf("Genero: Outros\n\n");
            }
        }
    }
}
