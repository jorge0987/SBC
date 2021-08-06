#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"

int main(){

    /**Customiza��o da cor do fundo e da fonte*/
    system("color 1F");

    /**Para poder usar palavras e acentos que exitem na lingua portuguesa.*/
    setlocale(LC_ALL,"Portuguese");

    /**Criar Pilhas, Filas, Lista*/
    tipofpri* fila = CriarFila();
    tipopri* lista = CriarLista();
    tipoppri* pilha1 = CriarPilha();
    tipoppri* pilha2 = CriarPilha();
    tipoppri* pilha3 = CriarPilha();

    /**Cria��o do menu*/
    int op;

    /**Boas vindas ao programa*/
    printf("Bem vindo ao sistema de devolu��o da biblioteca.\n");
    printf("Por favor, selecione o que ir� fazer...\n");

    /**Para pausar o sistema at� apertar qualquer bot�o*/
    system("pause");

    /**La�o para o programa ficar se repetindo at� desejarem sair*/
    do{

    /**Fun��o para limpar a tela*/
    system("cls");

    /**Apresenta��o do menu*/
    printf("Selecione de acordo com o numero.\n\n");
    printf("1- Inserir algu�m na fila.\n");
    printf("2- Fazer a devolu��o de um livro.\n");
    printf("3- Exibir quem esta na fila.\n");
    printf("4- Exibir quais livros est�o na pilhas de cada genero.\n");
    printf("5- Exibir as informa��es da lista.\n");
    printf("6- Criar um arquivo .txt do relatorio de devolu��o.\n");
    printf("7- Sair do sistema.\n\n");

    /**Onde de selecionar� a op��o*/
    printf("Escolha a op��o -> ");
    scanf("%d", &op);

    /**Para limpar a tela*/
    system("cls");

    /**Caso selecionem a op��o 1*/
    if(op==1){

        /**Alocando variaveis*/
        char* n = (char*) malloc(100 * sizeof(char));
        char* l = (char*) malloc(100 * sizeof(char));
        int g;

        /**Pegando as Informa��es do cliente*/
        printf("Informe o nome do cliente -> ");
        scanf(" %[^\n]", n);
        printf("Informe o nome do livro -> ");
        scanf(" %[^\n]", l);
        printf("Informe o g�nero do livro de acordo com o numero\n");
        do{
        printf("1- Fic��o\n2- Romance\n3- Outros\n");
        printf("Op��o escolhida -> ");
        scanf("%d", &g);
        if(g<1 || g>3){
            printf("O genero deve ser entre 1 e 3.\n");
        }
        }while(g<1 || g>3);

        /**Inserindo a fila*/
        InsereFila(fila, n, l, g);

    }else if(op==2){
        /**Verificando se esta vazia*/
        if(!(EstaVaziaFila(fila))){

        /**Criando algumas variaveis temporarias*/
        char* n = RetornaNomeFila(fila);
        char* l = RetornaLivroFila(fila);
        int g = RetornaGeneroFila(fila);

        /**Remover a primeira pessoa da fila*/
        RemoveUmFila(fila);

        /**Inserindo dados na lista*/
        InsereLista(lista, n, l);

        /**Inserindo o livro na pilha certa*/
        SelGenero(pilha1, pilha2, pilha3, l, g);

        /**Informa sobre a devolu��o*/
        printf("Livro devolvido.\n");

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

        }else{
            /**Printf caso a fila esteja vazia*/
            printf("Fila est� vazia.\n");

            /**Para pausar o sistema at� apertar qualquer bot�o*/
            system("pause");
        }

     /**Caso escolham a terceira op��o*/
    }else if(op==3){

        /**Fun��o para exibir a fila*/
        ExibirFila(fila);

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

    /**Caso escolham a quarta op��o*/
    }else if(op==4){

        /**Scanf para saber qual fila ele quer ver*/
        int op2;
        printf("Qual pilha voc� deseja v�?\n1- Fic��o\n2- Romance\n3- Outros\nEscolha -> ");
        scanf("%d", &op2);

        /**Fun��o para limpar a tela*/
        system("cls");

        /**Mostrando a fila selecionada*/
        SelGeneroMostrar( pilha1, pilha2, pilha3, op2);

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

    /**Caso escolham a quinta op��o*/
    }else if(op==5){

        /**Fun��o para exibir a lista*/
        ExibirLista(lista);

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

    /**Caso escolham a sexta op��o*/
    }else if(op==6){

        /**Fun��o para criar um arquivo txt da lista*/
        ArquivoLista(lista);

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

    }else if(op>7){

        /**Quando digitarem uma op��o invalida*/
        printf("Op��o invalida.\n");

        /**Para pausar o sistema at� apertar qualquer bot�o*/
        system("pause");

    }
    }while(op!=7);

    /**Libera toda a aloca��o feita na pilha, fila e lista*/
    RemoveTudoFila(fila);
    LiberarLista(lista);
    LiberarPilha(pilha1);
    LiberarPilha(pilha2);
    LiberarPilha(pilha3);

    printf("Fim da opera��o, Obrigado :)\n\n\n");


    return 0;
    }
