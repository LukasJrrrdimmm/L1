// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main ()
{

// declarações de variáveis
  pid_t pid1, pid2;          // definindo um identificador de processo - inteiro longo
  char *mensagem;     // string que contém a mensagem
  
   
  printf("Começando o programa fork3 ... \n");
  for(int i = 0; i<10; i++){
    sleep(1);
    printf("\nSou o processo Pai \n");
    system("ps -axl | grep fork3 &");
   }
  pid1 = fork();   // dividindo o processo em dois
  switch(pid1)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // Parte a ser executada pelo processo Filho1
      for(int i=1;i<30;i++) {
       sleep(1);
       printf("Sou o processo Filho1 \n");
      }
      break;
    default:       // parte a ser executada pelo processo Pai
      for(int i=1;i<10;i++) {
       sleep(1);
       printf("\nSou o processo Pai \n");
	system("ps");
       //system("ps -axl | grep fork &");
      }
      pid2 = fork();
      switch(pid2)
      {
        case -1:    // erro
           exit(1);
        case 0:        // Parte a ser executada pelo processo Filho2
         for(int i=1;i<30;i++) {
         sleep(1);
         printf("Sou o processo Filho2 \n");
         }
        exit(1);
        default:  // última parte do processo Pai
	int c = 0;
        while(1) {
          sleep(1);
          printf("\nSou o processo Pai \n");
	printf("%d\n", c);
          //system("ps -axl | grep fork &");
          //system("ps -axf | grep fork &");
	if(c >= 30){
		cout<<"pai terminou\n";
		break;
	}
	c++;
        }

        break;
      }

      break;
    }
  exit (0);

}
