#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signalHandler(int sig)
{
	if (sig==SIGINT)
	{
		printf("this program will stop in 3 seconds...\n");
		sleep(3);
		exit(0);
	}
	if (sig==SIGQUIT)
	{
		printf("signal SIGQUIT\n");
	}
}

int main()
{
	signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);
	printf("input ctrl+c or ctrl+\\ \n");
	while (1);
}
