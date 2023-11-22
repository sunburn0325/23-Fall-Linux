#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler();
void intHandler2();
void intHandler3();
int j;
int child_id;
int main(){
	int pid;

	pid = fork();
	if(pid==0){//child
		signal(SIGINT, intHandler2);
		for(j=1;j<=20;j++){
			for(int i=1; i<=9;i++){
				printf("%d * %d = %d\n",j,i,j*i);
				
			}
			sleep(1);
			if(j==9)
				signal(SIGINT, intHandler3);
		}

		pause();

	}
	else{//parent
		child_id = pid;
		signal(SIGINT, intHandler);
		wait();
	}

	signal(SIGINT, intHandler);
	while(1)
		pause();

}
void intHandler(int signo){
	kill(child_id, SIGINT);
}
void intHandler2(int signo){

		printf("구구단 실행 중 종료불가");
}
void intHandler3(int signo){
	kill(-getppid(), SIGKILL);
}
