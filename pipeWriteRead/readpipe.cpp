#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<iostream>
#include<sys/stat.h>
#include<string.h>

using namespace std;

int main(){
	char pipe[] = "./myPipe";
	struct stat st;
	if(stat(pipe,&st)!=0)
		mkfifo(pipe,0644);
	int fd = open(pipe,O_RDONLY);

	while(1){
		char msg[256];
		read(fd,msg,256);
		printf("%s",msg);
		fflush();
	}
	unlink(pipe);
	return 0;
}
