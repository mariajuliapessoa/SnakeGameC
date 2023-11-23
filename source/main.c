/*
Jogo da cobrinha em c
desenvolvido por: Isabela Spinelli, Maria Julia Pessoa e Maria Luisa Arruda
disciplina de programacao imperativa e funcional
*/

#include <stdio.h>
#include <locale.h>
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

        srand((unsigned)time(NULL));
int flag = 0;
while(flag == 0){

jogo -> XAlvo = rand() % 20;
jogo -> YAlvo = rand() % 50;
if(jogo->mat[jogo->XAlvo][jogo->YAlvo] == ' '){

flag = 1;
} else {

flag = 0;
}


if(jogo->macasJogo % 3 == 0 && jogo->macasJogos != 0){
TipoItemGerado A; //descobrir oq é A
while(flag == 0){

jogo->blocos.rabo->item.x = rand() % 20;
jogo->blocos.rabo->item.y = rand() % 50;

if(jogo->mat[jogo->blocos.rabo->TipoItemGerado.x][jogo->blocos.rabo->TipoItemGerados.y] == ' ' && jogo->blocos.rabo->TipoItemGerado == '0' ){ 
flag = 1;
A.x = jogo->blocos.rabo->item.x;
A.y = jogo->blocos.rabo->item.y;
textcolor(15);
gotoxy(A.y+2, A.x+3);
printf("%c", 176);
inserir(&jogo->blocos.A)
}

else{
flag = 0;
}
}

}

}

int ChecarJogo(Jogo *jogo){

TipoGeradoItem A;
A.x = 0;
A.y = 0;
int x, y;

if(jogo->flag == -1){
jogo->flag = -1;
return -1;
} else {
Celula *aux = jogo->posicoes.cabeca->next;
while(aux != NULL){
if(jogo->posicoes.cabeca->item.x == aux->item.x && jogo->posicoes.cabeca->item.y == aux->item.y){
jogo->flag = -1;
return -1;
}
aux = aux->next;
}

Celula *aux2 = jogo->blocos.cabeca->next;
while(aux2 != NULL){

if(jogo->posicoes.cabeca->TipoItemGerado.x == aux2->TipoItemGerado.x && jogo->posicoes.cabeca->TipoItemGerado.y == aux2->TipoItemGerado){
jogo->flag=-1;
return -1;
}
aux2 = aux2->prox;
}
if(jogo->posicoes.cabeca->TipoItemGerado.x == jogo->XAlvo && jogo->poicoes.cabeca->TipoItemGerado.y == jogo-> YAlvo){

//avaliando o placar
x = jogo->posicoes.cabeca->TipoItemGerado.y+2;
y = jogo->posicoes.cabeca->TipoItemGerado.x+3;

gotoxy(1,1);
textcolor(jogo->corLetraPlacar);
textbackground(jogo->corFundoPlacar);
printf("Nome: %s             SCORE: %d pontos            LEVEL: %d          ", jogo->nomeJogador, jogo->pontos, jogo->nivelJogo);
textcolor(15);
textbackground(jogo->corBG);

gotoxy(x, y);
jogo->macasJogo++;
jogo->pontos = (jogo->macasJogo*10)*jogo->nivelJogo);

if(jogo->macasJogo % 3 == 0){

if(jogo->speed >= 60){
jogo->speed -=10;
jogo->nivelJogo++;
printf("\a");
}

inserir(&jogo->posicoes.A);
GerarAlvo(jogo);
}
return 1;

}
}

void imprimirJogo (Jogo jogo){

int i, j, k;
int tamanhoLinha = 20;
int tamanhoColuna = 50;
clrscr(); // p limpar a tela do console de ouput durante a execução do programa
1=0; //?
textcolor(jogo.corParede);
textbackground(jogo.corBG);
printf("\n%c", 178);
while(1<50){
if(i==0){
printf("%c", 178);
}
i++;
}
printf("%c", 178);
}

void liberar(Jogo *jogo){

Celula *aux2 = jogo->posicoes.cabeca;
Celula *aux1;
while(aux2->next != NULL){
aux1 = aux2;
free(aux1);
}

aux2 = jogo->blocos.cabeca;
while(aux2->next != NULL){
aux1 = aux2;
aux2 = aux2->next;
free(aux1);
}
}

void escolherDif(Jogo *jogo){

clrscr();
gotoxy(16, 2);
textbackground(12);
printf("                              ");
clrscr();
gotoxy(16, 3);
printf(" ");
textcolor(15);
textbackground(3);
printf("                              ");
textbackground(12);
printf(" ");
gotoxy(16, 4);
printf(" ");
textbackground(3);
printf("           DIFICULDADE        ");
textbackground(12);
printf(" ");
gotoxy(16, 5);
printf(" ");
textbackground(3);
printf("                              ");
textbackground(12);
printf(" ");
gotoxy(16, 6);
printf("                                ");
textcolor(7);
textbackground(0);
printf("%c", 175);
textcolor(15);
printf("        MUITO FACIL\n");
printf("\n                       FACIL\n");
printf("\n                       NORMAL\n");
printf("\n                       DIFICIL\n");
printf("\n                       EXPERT\n");
printf("\n\n As dificuldades    ");
textcolor(10);
printf("DIFICL");
textcolor(15);
printf(" e ");
textcolor(10);
printf("EXPERT");
textcolor(15);
printf(" não é possível atravessar a parede ");
int tecla = 0;
while(tecla!=13){

tecla = getch();
switch(tecla){
case 72:
if(jogo->dificuldade > 0) jogo->dificuldade--;
break;
case 80:
if(jogo->difculdade < 1) jogo->dificuldade++;
break;
}
if(jogo->dificuldade == 0){
gotoxy(21, 11);
printf(" ");
gotoxy(21, 13);
printf(" ");
gotoxy(21, 13);
printf(" ");
gotoxy(21, 15);
printf(" ");
gotoxy(21, 17);
printf(" ");
gotoxy(21, 9);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
else if(jogo->dificuldade == 1){
gotoxy(21, 9);
printf(" ");
gotoxy(21, 13);
printf(" ");
gotoxy(21, 15);
printf(" ");
gotoxy(21, 17);
printf(" ");
gotoxy(21, 11);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
else if(jogo->dificuldade == 2){
gotoxy(21, 9);
printf(" ");
gotoxy(21, 11);
printf(" ");
gotoxy(21, 15);
printf(" ");
gotoxy(21, 17);
printf(" ");
gotoxy(21, 13);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
else if(jogo->dificuldade == 3){
gotoxy(21, 9);
printf(" ");
gotoxy(21, 11);
printf(" ");
gotoxy(21, 13);
printf(" ");
gotoxy(21, 17);
printf(" ");
gotoxy(21, 15);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
else if(jogo->dificuldade == 4){
gotoxy(21, 9);
printf(" ");
gotoxy(21, 13);
printf(" ");
gotoxy(21, 15);
printf(" ");
gotoxy(21, 17);
printf(" ");
gotoxy(21, 17);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
}
jogo->dificuldade += 1;
switch(jogo->dificuldade){
case 1:
jogo->speed = 250;
break;
case 2:
jogo->speed = 200;
break;
case 3:
jogo->speed = 150;
break;
case 4:
jogo->speed = 100;
break;
case 5:
jogo->speed = 50;
break;
default:
printf("\nOpção inválida, a dificuldade 'NORMAL' foi escolhida automaticamente");
jogo->speed = 150;

default:
printf("\nOpção inválida, a dificuldade 'NORMAL' foi escolhida automaticamente");
jogo->speed = 150;
break;
}
jogo->ultimove = 0;
clrscr();
}

void NovoJogo (Jogo *jogo){

jogo->mat = AlocarMatriz(20, 50);
percursoVazio(&jogo->posicoes);
jogo->posicoes.cabeca->TipoItemGerado.x = 0;
jogo->posicoes.cabeca->ipoItemGerado.y = 0;
jogo->flag = 0;
jogo -> pontos = 0;
jogo->ultimove = 0;
jogo->ultimo_y = 1;
jogo->ultimo_x = 1;
jogo->corBG = 2;
jogo->corSnake = 10;
jogo->macasJogo = 12;
jogo->corFundoPlacar = 0;
jogo->corLetraPlacar = 15;
jogo->corParede = 8;
jogo->speed = 1000;
jogo->jogoLevel = 1;
jogo -> macasJogo = 0;
jogo->dificuldade = 0;
jogo->ultimo_y = 1;
jogo->ultimo_x = 1;
percursoVazio(&jogo->blocos);
GerarAlvo(jogo);
MarcarJogo(jogo);

}

void AutoMove(Jogo *jogo){
Sleep(jogo->speed);
if(jogo->ultimove == 72){
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.x;
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.y;
dirCima(jogo);
LimparMatriz(jogo);
MarcarJogo(jogo);
}

else if(jogo->ultimove == 80){
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.x;
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.y;
dirBaixo(jogo);
LimparMatriz(jogo);
MarcarJogo(jogo);
}

else if(jogo->ultimove == 77){
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.x;
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.y;
Direita(jogo);
LimparMatriz(jogo);
MarcarJogo(jogo);
}

else if(jogo->ultimove == 75){
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.x;
jogo->ultimo_x = jogo->posicoes.ultimo->TipoItemGerado.y;
Esquerda(jogo);
LimparMatriz(jogo);
MarcarJogo(jogo);
}
}

void ThreadImprimir(Jogo *jogo){

int cont;

while(jogo->flag != -1){

ChecarJogo(jogo);
gotoxy(1, 24);
textcolor(jogo->corLetraPlacar);
textbackground(corFundoPlacar);
printf("Velocidade: %.2f   Loc x y : (%d, %d)\n",
jogo->speed, jogo->posicoes.cabeca->TipoItemGerado.x, jogo->posicoes.cabeca->TipoItemGerado.y;
textbackground(jogo->corBG);

Celula *aux;
aux = jogo->posicoes.cabeca;

gotoxy(jogo->ultimo_y+2),(jogo->ultimo_x+3));
printf(" ");
gotoxy(jogo->YAlvo+2, jogo->XAlvo+3);
textcolor(jogo->corMaca);
textbackground(jogo->corBG);
printf("%c", 254);

aux = jogo->posicoes.cabeca;
textcolor(jogo->corSnake);
textbackground(jogo->corBG);
cont = 0;

while(aux!=NULL){
if(cont == 0){
gotoxy((aux->TipoItemGerado, y+2), (aux->TipoItemGerado.x+3));
textcolor(11);
printf("%c", 178);
cont++;

} else if (cont > 0){
textcolor(jogo->corSnake);
gotoxy(aux->TipoItemGerado.y+2),(aux->TipoItemGerado.x+3);
printf("%c", 176);
cont++;
}
aux = aux->next;
}
textcolor(jogo->corBG);
}
}

void ThreadMove (Jogo *jogo){

int var;

while (jogo->flag != -1){
Automove(jogo);
}
}

void Mover(Jogo *jogo){

int var;
while(jogo->flag != -1){

fflush(stdin);
var = getch();

switch(var){
case 112:
jogo->ultimove = 112;
break;
case 72:
if(jogo->ultimove!=80)
jogo->ultimove = 72;
break;
case 80:
if(jogo->ultimove!=72)
jogo->ultimove = 80;
break;
case 77:
if(jogo->ultimove!=75)
jogo->ultimove = 77;
break;
case 75:
if(jogo->ultimove!=77)
jogo->ultimove = 75;
case 43:
jogo->speed +=10;
break;
case 45:
if(jogo->speed-10 >= 10) jogo->speed -=10;
break;
}
}

if(jogo->pontos > jogo->recorde.pontos){

jogo->highscore.pontos = jogo->pontos;
jogo->highscore.nomeJogador = jogo->nomeJogador;
jogo->highscore.nivelJogo = jogo->nivelJogo;
}

getch();
textcolor(15);
textbackground(0);
gotoxy(25, 15);
printf("\a");
printf("Você perdeu :C Tente outra vez!\n");
liberar(jogo);
getch();
system("cls");
}

void imprimirSlowMotion (char *string){

int 1 = 0;
while(string(1) != '\0'){

Sleep(15);
printf("%c", string(1));
i++;
}
}

void imprimirLogo(){

system("cls");
textbackground(12);
gotoxy(14, 2);
printf("                                  ");
textcolor(15);
textbackground(3);
gotoxy(14, 3);
textbackground(12);
printf(" ");
textbackground(3);
printf("                                  ");
textbackground(12);
printf(" ");
gotoxy(14, 4);
printf(" ");
textbackground(3);
printf("         %c%c%c%c%c  %c    %c     %c    %c     %c    %c%c%c%c%c%c%c                             ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbavkground(12);
printf(" ");
gotoxy(14, 5);
printf(" ");
textbackground(3);
printf(" %c         %c %c   %c  %c  %c  %c  %c   %c   %c      ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);                          ");
textbackground(12);
printf(" ");
gotoxy(14, 6);
printf(" ");
textbackground(3);
printf("  %c         %c  %c   %c  %c  %c  %c  %c   %c      ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbackground(12);
printf(" ");
gotoxy(14, 7);
printf(" ");
textbackground(3);
printf("         %c%c%c%c%c   %c  %c  %c   %c     %c  %c%c%c  %c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbackground(12);
printf(" ");
gotoxy(14, 8);
printf(" ");
textbackground(3);
printf("         %c   %c     %c %c  %c%c%c%c%c%c  %c  %c    %c          ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbackground(12);
printf(" ");
gotoxy(14, 9);
printf(" ");
textbackground(3);
printf("  %c   %c  %c         %c%c          %c    %c     %c    %c     %c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbackground(12);
printf(" ");
gotoxy(14, 10);
printf(" ");
textbackground(3);
printf("        %c%c%c%c%c     %c        %c  %c          %c  %c        %c       %c%c%c%c%c%c%c       ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
textbackground(12);
printf(" ");
gotoxy(14, 11);
printf(" ");
textbackground(3);
printf("                                       ");
background(12);
printf(" ");
gotoxy(14, 12);
printf("                                       ");
textcolor(15);
textbackground(0);
}

void main(){

Jogo jogo;
jogo.highscore.nomeJogador = "Vazio";
jogo.highscore.pontos = 0;
jogo.highscore.nivelJogo = 0;

int var, 1=0;
char *cred1 = "Desenvolvido por Bells, Jubinha e Lulu S2";
char *cred2 = "Alunas bem lindas de PamPam :* - CIÊNCIA DA COMPUTAÇÃO";
char *cred3 = "Inspo: Dinho Duarte"

char *var1 = "Jogo Cobrinha em C";
char *var2 = "Aproveite :*";

printf("\n\n\n\n\n                                  ");
textcolor(10);
imprimirSlowMotion(var1);
printf("\n\n                              ");
textcolor(7);
imprimirSlowMotion(var2);
printf("   %c\n\n                                 ", 169);
textcolor(10);
getch();
clrscr();

while(1>0){

NovoJogo(&jogo);
imprimirJogo();
var = 0;
int tecla = 0;

printf("\n\n\n                                         NOVO JOGO\n");
printf("\n                                        RECORDE\n");
printf("\n                                         CREDITOS\n");
printf("\n                                            SAIR\n");

gotoxy(34, 15);
textcolor(10);
printf("%c", 175);
textcolor(15);

while(tecla != 15){
switch(tecla){
case 72:
if (var > 0){
var--;
break;
}
case 80:
if(var < 3){
var++;
break;
}

if(var == 0){
gotoxy(34, 19);
printf(" ");
gotoxy(34, 17);
printf(" ");
gotoxy(34, 21);
printf("", 175);
gotoxy(34, 15);
textcolor(10);
printf("%c", 175);
textcolor(15);
}

else if(var == 1){
gotoxy(34, 15);
printf(" ");
gotoxy(34, 19);
printf(" ");
gotoxy(34, 21);
printf("", 175);
gotoxy(34, 17);
textcolor(10);
printf("%c", 175);
textcolor(15);

} else if ( var == 2){
gotoxy(34, 15);
printf(" ");
gotoxy(34, 17);
printf(" ");
gotoxy(34, 21);
printf("", 175);
gotoxy(34, 19);
textcolor(10);
printf("%c", 175);
textcolor(15);
}

else if(var == 3){
gotoxy(34, 15);
printf(" ");
gotoxy(34, 17);
printf(" ");
gotoxy(34, 19);
printf("", 175);
gotoxy(34, 21);
textcolor(10);
printf("%c", 175);
textcolor(15);
}
}
clrscr();
var+-1;
switch(var){
case 1:
imprimirJogo();
gotoxy(23, 15);
printf("Digite seu nome: ");
scanf("%s", &jogo.nomeJogador);
escolherDif(&jogo);
imprimirJogo(jogo);
_beginthread(ThreadMove, 0, &jogo);
_beginthread(ThreadImprimir, 0, &jogo);
gotoxy(1, 1);
textcolor(jogo.corLetraPlacar);
textbackground(jogo.corFundoPlacar);
printf("Nome:  %s                   SCORE: %d pontos      NIVEL: %d        ", jogo.nomeJogador, jogo.pontos*10, ((jogo.pontos/3)+1);
Mover(&jogo);
break;

case 2:
clrscr();
gotoxy(16, 2);
textbackground(12);
printf("                                                   ");
gotoxy(16, 3);
printf(" ");
textbackground(12);
printf(" ");
gotoxy(16, 4);
printf(" ");
textbackground(3);
printf("                  HIGH SCORE                          ");
textbackground(12);
printf(" ");
gotoxy(16, 5);
printf(" ");
textbackground(3);
printf("                                                     ");
textbackground(12);
printf(" ");
gotoxy(16, 6);
printf("                                                    ");
textcolor(7);
textbackground(0);
printf("\n                                             ");
textcolor(15);
printf("\n\n   NOME:  %s   Pontos: %.2f     Nivel: %d", jogo.highscore.nomeJogador, jogo.highscore.pontos, jogo.highscore.nivelJogo);
getch();
case 3:
printf("\n\n\n\n\n\n\n               ");
imprimirSlowMotion(cred1);
printf("\n\n                   ");
printf("\n\n\n\n\n\n\n               ");
imprimirSlowMotion(cred2);
printf("\n\n                   ");
printf("\n\n\n\n\n\n\n               ");
imprimirSlowMotion(cred3);
printf("\n\n                   ");
getch();
break;
case 4:
exit(0);
break;


}


}

return 0;

}
