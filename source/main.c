#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



//definindo constantes fixas no periodo de compilacao
#define COLS 68
#define LINHAS 38

int main() {
  
  //Removendo o cursor do terminal:
  //Para isso, usamos uma sequencia de escape, composta do caracter de escape da tabela ASCII (e)
  //e o codigo [?25l que sinaliza que o cursor deve ser removido do terminal.
  
  printf("\e[?25l");
  
  int X[1000], Y[1000];
  
  int quit = 0;
  
  while (quit = 0){
  
    //Gerando a tela do jogo sempre que quit estiver false (=0) ou seja
    //quando o jogo estiver rodando!
    //percorrendo a matriz da tela do jogo com 2 fors, referenciando as constantes COLS E LINHAS
    
    
    printf("┌");
    for(int i = 0; i < COLS; i++){
       printf("─");
       printf("┐\n");
      

    for(int j = 0; j < LINHAS; j++) {
         printf("|");
         
      for(int i = 0; i < COLS; i++){
         printf("·");
         printf("|\n");
       
    }
      
      printf("└");
      
      for(int i = 0; i < COLS; i++){
       printf("─");
       printf("┘\n");
       
       // movendo o cursor de volta ao topo da tela
       printf("\e[%iA",LINHAS + 2);
       
       
       int cabeca = 0, rabo = 0;
       
       X[cabeca] = COLS / 2;
       Y[rabo] = LINHAS / 2;
       int gameOver = 0;
       int dirX = 1, dirY = 0;
       int macaX = -1, macaY, maca;
       
       
       //setando a movimentacao da cobra na tela
       while(!quit && !gameOver) {
          
          //gerando as macas
          if(macaX < 0) {
           //criando uma nova maca de forma aleatoria caso nao haja nenhuma na dimensao x
           
           macaX = rand() % COLS;
           macaY = rand() % LINHAS;
           
           for (int i = rabo; i != cabeca; i = (i + 1) % 1000){
             if (X[i] == macaX && Y[i] == macaY){
             	macaX = -1;
             }
           
           if (maca >= 0){
              // desenhando maca
              printf("\e[%iB\e[%iC❤", macaY + 1, macaX + 1);
              printf("\e[%iF", macaY + 1);
           }
          
          }
       }
       
       
       
          // limpar rabo da cobra usando uma sequencia de escape
          //para que de a impressao de movimentacao da cobra
          printf("\e[%iB\e[%iC·", Y[rabo] + 1, X[rabo] + 1);
          printf("\e[%iF", Y[rabo] + 1);
         
          rabo = (rabo + 1) % 1000;
          int novaCabeca = (cabeca + 1) % 1000;
          X[novaCabeca] = (X[cabeca] + dirX + COLS) % COLS;
          Y[novaCabeca] = (Y[cabeca] + dirY + LINHAS) % LINHAS;
          cabeca = novaCabeca;
          
          
          
       //desenhando a cabeca da cobrinha
       printf("\e[%iB\e[%iC▓", Y[cabeca] + 1, X[cabeca] + 1);
       printf("\e[%iF", Y[cabeca] + 1);
       
       //usando a funcao da biblioteca <unistd.h> de c em unix: usleep() para     implementar um atraso de   
       //microsegundos no jogo
       
       usleep(5 * 1000000 / 60);
       
       //lendo a entrada do teclado

       keyboard();
       }
       
       
       
  
  }
  
   //ao sair do jogo, cursor pode aparecer novamente
   printf("\e[?25h");
   return 0;
    } 
  }
}
