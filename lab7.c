#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    if(argc<2){
        printf("\n You have provided only 1 argument\n");
        exit(1);
    }
    if((dp=opendir(argv[1]))==NULL) {
        printf("\nCannot open %s file!\n",argv[1]);
        exit(1); 
    }
    while((dirp=readdir(dp))!=NULL)
        printf("%s\n",dirp->d_name);
    closedir(dp);
}

/*
===thuc hien lenh cua ls - in ra cac thu muc============
- argc: so luong chuoi trong argv, co so dem
- argv: bao gom ten file thuc hien va tap lenh
- DIR: cho phep xem va theo doi cac tap lenh-folder, o day khoi tao mot con tro 'dp' de tro toi tap lenh hoac folder => mo ra thu muc hien hanh
- struct dirent: dung de doc dir(dp)
- neu co so dem argc < 2 :
    in ra 'You have provided only 1 argument'
    thoat ra voi ket qua khong thanh  cong
- neu thu muc hien tai rong:
    in ra thong bao khong the mo
    thoat ra voi ket qua khong thanh  cong
- in ra tat ca cac folder con neu thu muc khong rong
- dong directory stream.
*/