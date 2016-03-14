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
	int fd = open(pipe,O_WRONLY);

	for(int i=1;i<6;i++){
		string msg = "#"+to_string(i);
		write(fd,msg.c_str(),msg.length());
		sleep(1);
	}	
	unlink(pipe);
	return 0;
}
