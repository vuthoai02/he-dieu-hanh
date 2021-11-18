#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int id;
	id=fork();
	if(id==-1){
		printf("cannot create the file");
		exit(1);
	}
	if(id==0){
        sleep(2);
		printf("child process\n");
	}
	else{
		printf("parent process\n");
        exit(1);
	}
}

/*
- tao process id, sau do goi ham fork() chia tien trinh con tu tien trinh cha
- neu id = -1 thi tien trinh khong the khoi tao
- neu id = 0 tuc dang o  tien trinh con, tam dung hoat dong tien trinh trong 2s sau do in ra 'child process'
- neu id > 0 tuc dang o tien trinh cha, in ra ' parent process', sau do dufng tien trinh
=> ngu tien trinh
*/