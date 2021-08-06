#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"

int main(){

    /**Customização da cor do fundo e da fonte*/
    system("color 1F");

    /**Para poder usar palavras e acentos que exitem na lingua portuguesa.*/
    setlocale(LC_ALL,"Portuguese");

    /**Criar Pilhas, Filas, Lista*/
    tipofpri* fila = CriarFila();
    tipopri* lista = CriarLista();
    tipoppri* pilha1 = CriarPilha();
    tipoppri* pilha2 = CriarPilha();
    tipoppri* pilha3 = CriarPilha();

    /**Criação do menu*/
    int op;

    /**Boas vindas ao programa*/
    printf("Bem vindo ao sistema de devolução da biblioteca.\n");
    printf("Por favor, selecione o que irá fazer...\n");

    /**Para pausar o sistema até apertar qualquer botão*/
    system("pause");

    /**Laço para o programa ficar se repetindo até desejarem sair*/
    do{

    /**Função para limpar a tela*/
    system("cls");

    /**Apresentação do menu*/
    printf("Selecione de acordo com o numero.\n\n");
    printf("1- Inserir alguém na fila.\n");
    printf("2- Fazer a devolução de um livro.\n");
    printf("3- Exibir quem esta na fila.\n");
    printf("4- Exibir quais livros estão na pilhas de cada genero.\n");
    printf("5- Exibir as informações da lista.\n");
    printf("6- Criar um arquivo .txt do relatorio de devolução.\n");
    printf("7- Sair do sistema.\n\n");

    /**Onde de selecionará a opção*/
    printf("Escolha a opção -> ");
    scanf("%d", &op);

    /**Para limpar a tela*/
    system("cls");

    /**Caso selecionem a opção 1*/
    if(op==1){

        /**Alocando variaveis*/
        char* n = (char*) malloc(100 * sizeof(char));
        char* l = (char*) malloc(100 * sizeof(char));
        int g;

        /**Pegando as Informações do cliente*/
        printf("Informe o nome do cliente -> ");
        scanf(" %[^\n]", n);
        printf("Informe o nome do livro -> ");
        scanf(" %[^\n]", l);
        printf("Informe o gênero do livro de acordo com o numero\n");
        do{
        printf("1- Ficção\n2- Romance\n3- Outros\n");
        printf("Opção escolhida -> ");
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

        /**Informa sobre a devolução*/
        printf("Livro devolvido.\n");

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

        }else{
            /**Printf caso a fila esteja vazia*/
            printf("Fila está vazia.\n");

            /**Para pausar o sistema até apertar qualquer botão*/
            system("pause");
        }

     /**Caso escolham a terceira opção*/
    }else if(op==3){

        /**Função para exibir a fila*/
        ExibirFila(fila);

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

    /**Caso escolham a quarta opção*/
    }else if(op==4){

        /**Scanf para saber qual fila ele quer ver*/
        int op2;
        printf("Qual pilha você deseja vê?\n1- Ficção\n2- Romance\n3- Outros\nEscolha -> ");
        scanf("%d", &op2);

        /**Função para limpar a tela*/
        system("cls");

        /**Mostrando a fila selecionada*/
        SelGeneroMostrar( pilha1, pilha2, pilha3, op2);

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

    /**Caso escolham a quinta opção*/
    }else if(op==5){

        /**Função para exibir a lista*/
        ExibirLista(lista);

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

    /**Caso escolham a sexta opção*/
    }else if(op==6){

        /**Função para criar um arquivo txt da lista*/
        ArquivoLista(lista);

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

    }else if(op>7){

        /**Quando digitarem uma opção invalida*/
        printf("Opção invalida.\n");

        /**Para pausar o sistema até apertar qualquer botão*/
        system("pause");

    }
    }while(op!=7);

    /**Libera toda a alocação feita na pilha, fila e lista*/
    RemoveTudoFila(fila);
    LiberarLista(lista);
    LiberarPilha(pilha1);
    LiberarPilha(pilha2);
    LiberarPilha(pilha3);

    printf("Fim da operação, Obrigado :)\n\n\n");


    return 0;
    }
