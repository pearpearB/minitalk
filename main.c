// #include <stdio.h>
// #include <signal.h>

// void (*old_fun)( int);

// void sigint_handler( int signo)
// {
//    printf( "Ctrl-C를 누른 것을 기억하고 있어요. 다시 누르면 종료:)\n");
//    signal( SIGINT, old_fun);   // 또는 signal( SIGINT, SIG_DFL);
// }

// int main( void)
// {
//    old_fun = signal( SIGINT, sigint_handler);
//    while(1 ){
//       printf( "jabae is HAPPY!\n");
//       sleep( 1);
//    }
// }

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signo)
{
	printf("^C를 누른 것을 기억하고 있어요. 다시 누르면 종료:)\n");
	signal( SIGINT, SIG_DFL);
}

int main(void)
{
	signal( SIGINT, sigint_handler);
	while(1)
	{
    printf("jabae is HAPPY!\n");
    sleep(1);
	}
}