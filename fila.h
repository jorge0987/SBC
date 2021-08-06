#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/**Typedef da estrutura que apontará para o primeiro dado da fila*/
typedef struct tipofpri tipofpri;

/**Typedef da estrutura que representará uma pessoa na fila*/
typedef struct tipofno tipofno;

/**Prototipo de função para criar uma fila*/
tipofpri* CriarFila(void);

/**Prototipo de função que insere uma pessoa a fila*/
void InsereFila(tipofpri* v, char* nome, char* livro, int n);

/**Prototipo de função que mostra se a fila esta vazia*/
int EstaVaziaFila(tipofpri* v);

/**Prototipo de função que retorna o nome do cliente*/
char* RetornaNomeFila(tipofpri* v);

/**Prototipo de função que retorna o livro do cliente*/
char* RetornaLivroFila(tipofpri* v);

/**Prototipo de função que retorna o genero do livro do cliente*/
int RetornaGeneroFila(tipofpri* v);

/**Prototipo de função que remove a estrutura da fila*/
void RemoveUmFila(tipofpri* v);

/**Prototipo de função que remove todos os clientes da fila e apaga a fila*/
void RemoveTudoFila(tipofpri* v);

/**Prototipo de função que exibe os nomes, livro e seu respectivo genero dos clientes*/
void ExibirFila(tipofpri* v);

#endif // FILA_H_INCLUDED
