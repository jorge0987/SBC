#include<stdlib.h>
#include<stdio.h>
#include "lista.h"

/**Estrutura que vai apontar para o primeiro dado da lista*/
struct tipopri{
    tipono* p;
};

/**Estrutura dos dados da lista*/
struct tipono{
    char* nome;
    char* livro;
    tipono* p;
};

/**Função para criar um ponteiro que vai apontar para o primeiro dado da lista*/
tipopri* CriarLista(void){
    tipopri* p = (tipopri*) malloc(sizeof(tipopri));
    if(p==NULL){
        printf("Falha ao alocar o inicio da lista.\n");
        exit(1);
    }
    p->p=NULL;
    return p;
}

/**Função para adicionar um elemento a lista*/
void InsereLista(tipopri* v,char* nome,char* livro){
    tipono* novo = (tipono*) malloc(sizeof(tipono));
    if(novo==NULL){
        printf("Falha ao alocar o elemento na lista.\n");
        exit(1);
    }
    novo->livro=livro;
    novo->nome=nome;
    novo->p=NULL;
    if(v->p==NULL){
        v->p=novo;
    }else{
        tipono* aux;
        tipono* anterior;
        for(aux=v->p;aux!=NULL;aux=aux->p){
            anterior=aux;
        }
            anterior->p=novo;
    }
}

/**Função para saber se a lista esta vazia*/
int EstaVaziaLista(tipopri* v){
    if(v->p==NULL){
        return 1;
    }else{
        return 0;
    }
}

/**Função para liberar a lista*/
void LiberarLista(tipopri* v){
    tipono* aux=v->p;
    while(aux!=NULL){
        tipono* aux2=aux->p;
        free(aux);
        aux=aux2;
    }
    free(v);
    v=NULL;
}

/**Função para criar o arquivo de devolução*/
void ArquivoLista(tipopri* v){
    if(!(EstaVaziaLista(v))){
    FILE* arq = fopen("Lista de devolução.txt","wt");
    fprintf(arq,"Lista de devolução\n\n");
    tipono* aux;
    for(aux=v->p;aux!=NULL;aux=aux->p){
        fprintf(arq,"Nome: %s\n", aux->nome);
        fprintf(arq,"Livro: %s\n\n", aux->livro);
    }
    fprintf(arq,"\n\nFim da lista.");
    fclose(arq);
    printf("Arquivo criado com sucesso.\n");
}else{
    printf("A lista está vazia.\n");
}}

/**Função para exibir a lista*/
void ExibirLista(tipopri* v){
    if(EstaVaziaLista(v)){
        printf("A lista esta vazia.\n");
    }else{
        tipono* aux;
        for(aux=v->p;aux!=NULL;aux=aux->p){
            printf("Nome: %s\nLivro: %s\n\n", aux->nome, aux->livro);
        }
    }
}
