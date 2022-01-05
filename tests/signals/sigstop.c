#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void stopHandler(int sig)
{
	printf(" this program will be exited in 3 seconds...\n");
	sleep(3);
	exit(0);
}

int main()
{
	signal(SIGSTOP, stopHandler);
	printf("input ctrl+z\n");
	while (1);
}

//сигнал, посылаемый для принудительной
//приостановки выполнения процесса.
//Остановка выполнения процесса
//Сигнал прерывания (Ctrl+Z) с терминала
