#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
int main(){
	char pipe[] = "./myPipe";
	struct stat st;
	char buf[250],ch;
	int fd, ip=1;
	buf[1] = '\0';

	if(stat(pipe,&st)!=0)
		mkfifo(pipe,0644);
	
	printf("Connecting... ");
	fflush(stdout);
	fd = open(pipe,O_WRONLY|O_NONBLOCK);
	printf("Connected!! Enter 0 to exit \n");

	while(1){
		if(ip){
			gets(buf);
			write(fd,buf,strlen(buf));
		}
		else
			break;
		scanf("%d",&ip);
	}
	unlink(pipe);
	return 0;
}
