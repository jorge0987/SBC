#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/**Typedef da estrutura que apontar� para o primeiro dado da lista*/
typedef struct tipopri tipopri;

/**Typedef da estrutura que representar� um dado da lista*/
typedef struct tipono tipono;

/**Prototipo para criar uma nova lista**/
tipopri* CriarLista(void);

/**Prototipo de inserir um elemento na lista*/
void InsereLista(tipopri* p, char* nome, char* livro);

/**Prototipo da fun��o para saber se a lista esta vazia*/
int EstaVaziaLista(tipopri* v);

/**Prototipo de fun��o para liberar lista*/
void LiberarLista(tipopri* v);

/**Prototipo de fun��o para criar o arquivo da lista de devolu��o*/
void ArquivoLista(tipopri* v);

/**Prototipo de fun��o para exibir os elementos que est�o na lista*/
void ExibirLista(tipopri* v);

#endif // LISTA_H_INCLUDED
