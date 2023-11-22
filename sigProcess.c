#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main( )
{
	int pid1, pid2;
	pid1 = fork( );
	if (pid1 == 0) {
		while (1) {
			sleep(1);
			printf("Process 1…\n");
		}
	}
	pid2 = fork( );
	if (pid2 == 0) {
		while (1) {
			sleep(1);
			printf("Process 2…\n");
		}
	}
	sleep(3);
	kill(pid1, SIGSTOP);
	sleep(3);
	kill(pid1, SIGCONT);
	sleep(3);
	kill(pid2, SIGSTOP);
	sleep(3);
	kill(pid2, SIGCONT);
	sleep(3);
	kill(pid1, SIGKILL);
	kill(pid2, SIGKILL);
}

