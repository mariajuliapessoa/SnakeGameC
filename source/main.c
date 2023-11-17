/*
Jogo da cobrinha em c
desenvolvido por: Isabela Spinelli, Maria Julia Pessoa e Maria Luisa Arruda
disciplina de programacao imperativa e funcional
*/

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <conio.h>

//a biblioteca conio.h foi utilizada para controlar as entradas e saidas do terminal e personalizar a interface do jogo

//a biblioteca windows.h foi utilizada para criar a janela do jogo em si

//criando struct para atribuir cordenadas a um item que vamos gerar na tela

typedef struct item{

int X;
int Y;
} TipoitemGerado;

// criando um tipo de dado que armazena tudo que compoe uma celula da tela vista pelo jogador
//e especifica o item que devera ser gerado naquela coordenada da tela
typedef struct celula{
//duvida aqui
struct celula *next;
struct celula *prev;
TipoItemGerado item;

} Celula;

// criando um novo tipo de dado que armazena tudo que corresponde ao highscore

typedef struct highscore{

char *nomeJogador;
float pontuacao;
int nivel;

} Highscore;

//percursoCobra :: criando uma struct para depois criar uma lista para que possamos acompanhar o deslocamento da cobra ao longo
//da tela para isso, vamos analizar em quais celulas estava a cabeca e o rabo da cobra,
//identificando o percurso total naquele momento

typedef struct percursoCobra{

Celula *cabeca;
Celula *rabo;

} percursoCobra;

//definindo uma struct com todos os dados importantes para o inicio da partida
typedef struct jogo{

char **mat;
percursoCobra posicoes;
int flag;
int XAlvo;
int YAlvo;
int pontos;
int ultimove;
float speed;
char nomeJogador[50];
int ultimo_x;
int ultimo_y;
int corBG;
int corSnake;
int corMaca;
int corParede;
int corLetraPlacar;
int corFundoPlacar;
int nivelJogo;
int macasJogo;
Highscore highscore;
int nivelDificuldade;
percursoCobra blocos;

} Jogo;

//criando uma lista oara acompanhar o percurso da cobrinha
void percursoVazio (percursoCobra *percurso){

percurso -> cabeca = (Celula*) malloc (sizeof(Celula));
percurso -> rabo = percurso -> cabeca;
percurso -> rabo -> next = NULL;
percurso -> cabeca -> prev = NULL;
}

int Vazia (percursoCobra percurso){

return(percurso.cabeca == percurso.rabo);

}

// funcao para inserir novos espacos de memoria na lista do percurso da cobra

void inserir(percursoCobra *percurso, TipoItemGerado x){

percurso -> rabo -> next = (Celula*) malloc (sizeof(Celula));
percurso -> rabo -> next -> prev = percurso -> rabo;
percurso -> rabo = percurso -> rabo -> next;
percurso -> rabo -> next =  NULL;
percurso -> rabo = item = x;
}

void LimparMatriz (Jogo *jogo){

int i, j;
for(i=0; i < 20; i++){
for(j=0; j<50; j++){
jogo->mat(i)(j) = ' ';
}
}
}

//alocando espaco de memoria para a matriz que vamos usar para mostrar o jogo na tela
char** AlocarMatriz(int Linhas, int Colunas){

int i, j;
char **m = (char**) malloc (Linhas * sizeof(char*));

for (i = 0; i < Linhas; i++){
        m[i] = (char*) malloc (Colunas *sizeof(char*));
        for(j = 0; j < Colunas; j++){
        m[i][j] = ' ';
        }
        }
        return m;
}

// VER SE ELE EXPLICA ESSA FUNCAO marcar jogo e baixo
void MarcarJogo(JOgo *jogo){

int x, y, cont = 0;

Celula *aux = jogo -> posicoes.cabeca;
while(aux != NULL){

x = aux -> item.x;
y = aux -> item.y;
if(count == 0){
jogo -> mat[x][y] = 178;
count++;
} else {
   
   jogo -> mat[x][y] = 177;
}
aux= aux -> next;
}

jogo -> mat [jogo -> XAlvo] [jogo -> YAlvo] = '*';

aux = jogo -> blocos.cabeca -> next;

while(aux != NULL){

jogo -> mat [aux -> item.x] [aux -> item.y] = 'p';
aux = aux -> next;
}
  }


void dirBaixo(Jogo *jogo){

if((jogo -> posicoes.cabeca -> item.x + 1) < 20 && jogo -> nivelDificuldade > 3){

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL){

aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> ant;
}

jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';
jogo -> posicoes.cabeca -> item.x++;
jogo -> ultimaJogada = 80;
jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';
jogo -> posicoes.cabeca -> item.x++;
jogo -> ultimaJogada = 80;

} else { jogo -> flag = -1; }

void dirCima(Jogo *jogo){

if((jogo -> posicoes.cabeca -> item.x -1) >= 0 && jogo -> dificuldade > 3){

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL)
{
aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> prev;
}

jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';
jogo ->  posicoes.cabeca -> item.x--;

} else if(jogo -> nivelDificuldade <=3){
Celula *aux = jogo -> posicoes.rabo;
while(aux -> prev != NULL){
aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> prev;
}

jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';

if((jogo -> posicoes.cabeca  -> item.x -1) >= 0){

jogo -> posicoes.cabeca -> item.x--;
}else {
  jogo -> posicoes.cabeca -> item.x = 19;
  jogo -> ultimaJogada == 72;

}
else jogo -> flag = -1;
}

void Esquerda(Jogo *jogo){

if((jogo -> posicoes.cabeca  -> item.y -1) >= 0 && jogo -> nivelDificuldade > 3){

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL)
{
aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> prev;
}

jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';
jogo ->  posicoes.cabeca -> item.y--;
jogo -> ultimaJogada = 75;
} else if(jogo -> nivelDificuldade <=3 ) {

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL){

aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> ant;
}
jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';

if((jogo -> posicoes.cabeca  -> item.y -1) >= 0){

jogo -> posicoes.cabeca -> item.y--;
}else {
  jogo -> posicoes.cabeca -> item.y = 49;
  jogo -> ultimaJogada == 75;
}
else jogo -> flag = -1;

  }
}

void Direita(Jogo *jogo){

if((jogo -> posicoes.cabeca  -> item.y -1) <= 50 && jogo -> nivelDificuldade > 3){

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL)
{
aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> prev;
}

jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';
jogo ->  posicoes.cabeca -> item.y++;
jogo -> ultimaJogada = 77;

} else if(jogo -> nivelDificuldade <=3 ) {

Celula *aux = jogo -> posicoes.rabo;

while(aux -> prev != NULL){

aux -> item.x = aux -> prev -> item.x;
aux -> item.y = aux -> prev -> item.y;
aux = aux -> ant;
}
jogo -> mat [jogo -> posicoes.cabeca -> item.x] [jogo -> posicoes.cabeca -> item.y] = ' ';

if((jogo -> posicoes.cabeca  -> item.y) <= 48){

jogo -> posicoes.cabeca -> item.y++;
}else {
  jogo -> posicoes.cabeca -> item.y = 0;
  jogo -> ultimaJogada == 77;
}
else jogo -> flag = -1;

  }
}

// criando uma fun;'ao para gerar de forma aleatoria, alvos
void GerarAlvo(Jogo *jogo){


}

}

}
}
