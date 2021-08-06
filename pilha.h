#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/**Typedef da estrutura que apontara para o topo da pilha*/
typedef struct tipoppri tipoppri;

/**Typedef da estrutura que representar� um livro na pilha*/
typedef struct tipopno tipopno;

/**Prototipo da fun��o que vai inserir um livro no topo da pilha*/
void InserePilha(tipoppri* v, char* livro);

/**Prototipo da fun��o que vai selecionar a pilha certa para cada livro*/
void SelGenero(tipoppri* v1, tipoppri* v2, tipoppri* v3, char* livro, int genero);

/**Prototipo de fun��o que vai mostrar a fila selecionada*/
void SelGeneroMostrar (tipoppri* v1, tipoppri* v2, tipoppri* v3, int op);

/**Prototipo da fun��o que vai criar uma pilha*/
tipoppri* CriarPilha(void);

/**Prototipo da fun��o para dizer se a pilha esta vazia*/
int EstaVaziaPilha(tipoppri* v);

/**Prototipo da fun��o que exibir a pilha*/
void ExibirPilha(tipoppri* v);

/**Prototipo da fun��o que vai remover a pilha*/
void LiberarPilha(tipoppri* v);

#endif // PILHA_H_INCLUDED
