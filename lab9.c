#include<stdio.h>
struct ff {
    int pid,ser,wait;
} p[20];
struct ff tmp;
int main() {
    int i,n,j,tot=0,avwait,totwait=0,tturn=0,aturn;
    printf("enter the number of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("enter process id: ");
        scanf("%d",&p[i]);
        printf("enter service time: ");
        scanf("%d",&p[i].ser);
        p[i].wait=0; 
    }
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(p[i].ser>p[j].ser) {
            tmp=p[i];
            p[i]=p[j];
            p[j]=tmp; }
        }
    }
    printf("PID\tSER\tWAIT\tTOT\n");
    for(i=0;i<n;i++) {
        tot=tot+p[i].ser;
        tturn=tturn+tot;
        p[i+1].wait=tot;
        totwait=totwait+p[i].wait;
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].ser,p[i].wait,tot);
    }
    avwait=totwait/n;
    aturn=tturn/n;
    printf("TOTAL WAITING TIME :%d\n",totwait);
    printf("AVERAGE WAITING TIME : %d\n",avwait);
    printf("TOTAL TURNAROUND TIME :%d\n",tturn);
    printf("AVERAGE TURNAROUND TIME:%d\n",aturn);
}

/*
- khoi tao toi da 20 tien trinh gom:
    pid: dia chi process
    wait: thoi gian cho:
    ser: thoi gian thuc hien tien trinh
- ban dau:
    thoi gian cho trung binh = 0
    tong thoi gian = 0
    thoi gian tung quy trinh = 0
    thoi gian quay vong = 0
- nhan so luong tien trinh can tinh
- nhan process id , thoi gian thuc hien cua tung tien trinh, gan thoi gian cho moi tien trinh = 0
- thuc hien so sanh doi 1 tien trinh lien nhau
    neu tien trinh nao co thoi gian thuc hien nho hon thi vao truoc
- in ra cac thong so:
    tong thoi gian tien trinh = tong thoi gian cu + thoi gian thuc hien tien trinh hinh tai
    tong thoi gian lap lai tien trinh = thoi gian cu + tong toi gian moi
    thoi gian cho cua tien trinh ke tiep bang tong thoi gian tien trinh truoc
    tong thoi gian cho = tong thoi gian cho cu + thoi gian cho cua tien trinh hien tai
- tinh tong thoi gian cho 
- tinh tong thoi gian lap
- in ra
*/