#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid = fork();
	if(pid==0){
		pid = fork();
		if(pid==0){
			printf("Child of child here(will die after sleep for 3s)! %d\n",getpid());
			sleep(3);
		}else{
			printf("Child process(going to die after sleep of 1s): %d\n",getpid());
			sleep(1);
		}
	}else{
		printf("Parent of all! will die after 5 sec\n");
		sleep(5);
	}
	system("ps -o pid,ppid,stat");
	return 0;
}

