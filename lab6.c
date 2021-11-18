#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int i =20;
int main(){
    int pid = fork();
    if(pid ==0){
        printf("initial value of i %d\n",i);
        i+=10;
        printf("value of i %d\n",i);
        printf("child terminated\n");
    }
    else{
        wait(0);
        printf("value of in parent process %d",i);
    }
}
//su dung lenh cho
/*
- khoi tao gia tri ban dau = 10
- chia tien trinh bang fork()
- neu dang o tien trinh con:
+ in ra gia tri ban dau
+ tang gia tri len - chi tang o tien trinh con
+ in ra gia tri sau khi tang len
+ ket thuc tien trinh con
- neu dang o tien trinh cha:
+ in ra gia tri tien trinh cha la tien trinh ban dau
*/