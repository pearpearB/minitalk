#include <stdio.h>
#include <signal.h>

int main(){
	printf("{%c}\n", (char)0);
	printf("{%d}\n", SIGUSR1);
	printf("{%d}\n", SIGUSR2);
	return 0;
}