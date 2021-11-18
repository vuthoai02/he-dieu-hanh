#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int pid;
	pid=fork();
    if(pid==0){
        printf("\n Child Process\n");
        printf("\nChild Process id is %d",getpid());
        printf("\nIts parent process id is %d",getppid());
        sleep(5);
        printf("\nChild process after sleep=5\n");
        printf("\nChild Process id is %d",getpid());
        printf("\n Its parent process id is %d",getpid());
    }
    else{
        printf("\nParent process\n");
        sleep(10);
        printf("\nChild Process id is %d",getpid());
        printf("\n Its parent process id is %d",getppid());
        printf("\nParent terminates\n");
    }
}

/*
- tien trinh pid, goi ham fork() de chia tien trinh
- neu dang la process con 
+ in ra child process
+ in ra dia chi tien trinh con hien tai qua gia tri tra ve getpid()
+ in ra dia chi tien trinh cha hien tai qua gia tri tra ve getppid()
+ cho tien trinh ngu trong 5s
+ sau do in dia chi cura tien trinh cha va con sau 5s tam dung hoat dong\
- neu dang laf process cha
+ in ra thong bao dang o tien trinh cha
+ cho process tam dung 10s
+ sau do in ra dia chi cua process cha va con sau 10s tam dung
==> muc dich cua chuong trinh nay la ngu tien trinh va in ra process id sau khi tam dung.
*/