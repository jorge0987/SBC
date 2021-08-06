#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

/**Estrutura que vai apontar para o topo da pilha*/
struct tipoppri{
    tipopno* p;
};

/**Estrutura que vai representar um livro na pilha*/
struct tipopno{
    char* livro;
    tipopno* p;
};

/**Fun��o que insere um livro no topo da pilha*/
void InserePilha(tipoppri* v, char* livro){
    tipopno* no = (tipopno*) malloc(sizeof(tipopno));
    if(no==NULL){
        printf("Elemento para a pilha n�o alocado.\n");
        exit(1);
    }else{
        no->livro=livro;
        no->p=v->p;
        v->p=no;
    }
}

/**Fun��o para colocar o livro no genero certo*/
void SelGenero(tipoppri* v1, tipoppri* v2, tipoppri* v3, char* livro, int genero){
    if(genero==1){
            InserePilha(v1, livro);
        }else if(genero==2){
            InserePilha(v2, livro);
        }else if(genero==3){
            InserePilha(v3, livro);
        }
}

/**Fun�ao para exibir a pilha selecionada*/
void SelGeneroMostrar (tipoppri* v1, tipoppri* v2, tipoppri* v3, int op){
    if(op==1){
            printf("Pilha de ""Fic��o"" do topo para o �ltimo...\n");
            ExibirPilha(v1);
        }else if(op==2){
            printf("Pilha de ""Romance"" do topo para o �ltimo...\n");
            ExibirPilha(v2);
        }else if(op==3){
            printf("Pilha de ""Outros"" do topo para o �ltimo...\n");
            ExibirPilha(v3);
        }
}

/**Fun��o para criar a pilha*/
tipoppri* CriarPilha(void){
    tipoppri* v = (tipoppri*) malloc(sizeof(tipoppri));
    v->p=NULL;
    return v;
}

/**Fun��o para dizer se a pilha esta vazia*/
int EstaVaziaPilha(tipoppri* v){
    if(v->p==NULL){
        return 1;
    }else{
        return 0;
    }
}

/**Gun��o para exibir a fila*/
void ExibirPilha(tipoppri* v){
    if(EstaVaziaPilha(v)){
        printf("A pilha esta vazia!!\n");
    }else{
        tipopno* aux;
        for(aux=v->p;aux!=NULL;aux=aux->p){
            printf("\t*%s\n", aux->livro);
        }
    }
}

/**Fun��o para liberar lista*/
void LiberarPilha(tipoppri* v){
    tipopno* aux=v->p;
    while(aux!=NULL){
        tipopno* aux2=aux->p;
        free(aux);
        aux=aux2;
    }
    free(v);
    v=NULL;
}
