#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
	cout<<stdout;
	for(int i =0 ; i< 5; i++){
		printf("hey %d\n",i);
		sleep(1);
	}
	return 0;
}
