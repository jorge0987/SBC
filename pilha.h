#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/**Typedef da estrutura que apontara para o topo da pilha*/
typedef struct tipoppri tipoppri;

/**Typedef da estrutura que representará um livro na pilha*/
typedef struct tipopno tipopno;

/**Prototipo da função que vai inserir um livro no topo da pilha*/
void InserePilha(tipoppri* v, char* livro);

/**Prototipo da função que vai selecionar a pilha certa para cada livro*/
void SelGenero(tipoppri* v1, tipoppri* v2, tipoppri* v3, char* livro, int genero);

/**Prototipo de função que vai mostrar a fila selecionada*/
void SelGeneroMostrar (tipoppri* v1, tipoppri* v2, tipoppri* v3, int op);

/**Prototipo da função que vai criar uma pilha*/
tipoppri* CriarPilha(void);

/**Prototipo da função para dizer se a pilha esta vazia*/
int EstaVaziaPilha(tipoppri* v);

/**Prototipo da função que exibir a pilha*/
void ExibirPilha(tipoppri* v);

/**Prototipo da função que vai remover a pilha*/
void LiberarPilha(tipoppri* v);

#endif // PILHA_H_INCLUDED
