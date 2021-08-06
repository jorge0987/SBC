#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/**Typedef da estrutura que apontará para o primeiro dado da lista*/
typedef struct tipopri tipopri;

/**Typedef da estrutura que representará um dado da lista*/
typedef struct tipono tipono;

/**Prototipo para criar uma nova lista**/
tipopri* CriarLista(void);

/**Prototipo de inserir um elemento na lista*/
void InsereLista(tipopri* p, char* nome, char* livro);

/**Prototipo da função para saber se a lista esta vazia*/
int EstaVaziaLista(tipopri* v);

/**Prototipo de função para liberar lista*/
void LiberarLista(tipopri* v);

/**Prototipo de função para criar o arquivo da lista de devolução*/
void ArquivoLista(tipopri* v);

/**Prototipo de função para exibir os elementos que estão na lista*/
void ExibirLista(tipopri* v);

#endif // LISTA_H_INCLUDED
