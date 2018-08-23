#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
static const int nthr = 4;

void process(pid_t runPI){
	//thread ts[4];
	runPI.fork();
	switch(runPI)
	{
		case -1:       // erro na abertura do processo filho
			exit(1);  
		case 0:        // Parte a ser executada pelo processo Filho1
			for(int i=1;i<10;i++) {
				sleep(1);
				printf("\n\nSou o processo Filho1 \n");
				//system("ps -axf| grep fork1 &");
			}
			printf("Sou o processo Filho e vou morrer agora - Asta la vista baby :( \n");
			break;
		default:       // parte a ser executada pelo processo Pai
			for(int i=1;i<5;i++) {
				sleep(1);
				printf("\n\nSou o processo Pai \n");
				//system("ps -axf| grep fork1");
			}
		printf("Sou o processo Pai e vou morrer agora - Asta la vista, baby :( \n");
	} 
	exit (0);
}

int main(){
	pid_t pid[8];
	thread tv[4];
	
	for(int i2 = 0; i2 < 8; i2++){
		for(int i = 0; i < 4; i++){
			tv[i](process, pid[i2]);
			i2++;
		}
		for(int i = 0; i < 4; i++){
			tv[i].join();
		}
		cout<<"threads completed\n";
	}
		
	return 0;
}
