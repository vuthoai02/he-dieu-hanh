#include<stdio.h>
struct process {
    int id,wait,ser,tottime;
} p[20];
int main() {
    int i,n,j,totalwait=0,totalser=0,avturn,avwait;
    printf("enter number of process: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        printf("enter process_id: ");
        scanf("%d",&p[i].id);
        printf("enter process service time: ");
        scanf("%d",&p[i].ser); 
    }
    p[1].wait=0;
    p[1].tottime=p[1].ser;
    for(i=2;i<=n;i++) {
        for(j=1;j<i;j++) {
            p[i].wait=p[i].wait+p[j].ser; 
        }
        totalwait=totalwait+p[i].wait;
        p[i].tottime=p[i].wait+p[i].ser;
        totalser=totalser+p[i].tottime;
    }
    avturn=totalser/n;
    avwait=totalwait/n;
    printf("Id\tservice\twait\ttotal");
    for(i=1;i<=n;i++) {
        printf("\n%d\t%d\t%d\t%d\n",p[i].id,p[i].ser,p[i].wait,p[i].tottime);
    }
    printf("average waiting time %d\n",avwait);
    printf("average turnaround time %d\n",avturn);
}

/*
- tao cau truc 20 tien trinh gom cac du lieu:
    id: dia chi
    wait: thoi gian cho
    ser: thoi gian thuc hien tien trinh
    tottime:tong thoi gian tien trinh do
- ban dau
    khoi tao tong thoi gian cho = 0
    tong thoi gian cua process dau = 0
- nhan so luong ca tien trinh can tinh
- nhan dia chi tung tien trinh va thoi gian thuc hien moi tien trinh
- chay tien trinh 1 dau tien
- sau khi chay xong tien trinh 1 chay cac tien trinh khac:
    nhan thoi gian cho va thoi gian thuc hien
    tinh thong thoi gian cho = tong thoi gian hien tai + thoi gian cho cua tien trinh dang thuc hien
    tinh tong thoi gian cua tien trinh hien tai = thoi gian co + thoi gian thuc hien cua tien trinh do
    tinh thoi gian tong cua tat ca = thoi gian cu + tong thoi gian cua tien trinh hien tai
- tinh tong trung binh thoi gian tat ca: tong thoi gian / so tien trinh
- tinh thoi gian cho trung binh
- in ra cac gia tri thoi gian cua tung tien trinh
- in ra tong thoi gian cho trung binh va tong thoi gian cua tat ca
*/