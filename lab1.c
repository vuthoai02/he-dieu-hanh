#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int id;
	id=fork();
	if(id<0){
		printf("cannot create the file");
		exit(-1);
	}
	if(id==0){
		printf("child process\n");
		exit(0);
	}
	else{
		printf("parent process\n");
	}
}

// ham fork() dung de tao ra cac tien trinh rieng.
/*
- khoi tao mot tien trinh 'id'
- sau khi  goi fork se tach tien trinh cha ra them nhieu tien trinh con
- neu fork() tra ve < 0 tuc la phan tach tien trinh that bai
	neu tra ve 0 tuc la dang o tien trinh con
	neu tra ve mot so nguyen duong bat ky > 0 tuc la tra ve dia chi cua tien trinh con, dang o tien trinh cha*/