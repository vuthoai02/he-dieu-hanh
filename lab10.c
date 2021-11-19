#include <stdio.h>

/*
- khoi tao toi da 5 tien trinh chua cac bien gia tri:
    pburst: burst ban dau, khi nhap vao
    pburst1: burst nay se thay doi khi tru trong tinh toan thoi gian
    wtime: thoi gian cho
    endtime: thoi gian ket thuc
    arrivt: thoi gian den
    boolean: bien dieu kien xac nhan tien trinh co duong vao hay k
    flagcntl: co hieu xac nhan tien trinh duoc vao
    panme: ten tien trinh
*/
struct roundRobin
{
    int pburst, pburst1, wtime, endtime, arrivt, boolean, flagcntl;
    char pname[5];
} a[5];

/*
-khoi ta0 2 bien:
n: so tien trinh
tq: quantum
*/
int n, tq;
void input();
void initialize();
void calculate();
void display_waittime();
int main()
{
    input();
    initialize();
    calculate();
    display_waittime();
}
//ham nhap du lieu
void input()
{
    int i;
    printf("Enter Total no. of processes\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter process name:");
        scanf("%s", &a[i].pname);
        printf("Enter process burst time:");
        scanf("%d", &a[i].pburst);
        printf("Enter process arrival time:");
        scanf("%d", &a[i].arrivt);
    }
    printf("\nEnter the time quantum/Time Slice:");
    scanf("%d", &tq);
}

/*
- ham nay dung de khoi tao cac gia tri ban dau cho tung bien gia tri trong tien trinh
*/
void initialize()
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i].pburst1 = a[i].pburst;
        a[i].wtime = 0;
        a[i].endtime = 0;
        a[i].boolean = 0;
        a[i].flagcntl = 0;
    }
}

/*
================tinh thoi gian=================
- khoi tao cac bien co ban i,j
- khoi tao co hieu flag, bien count dem thoi gian cho cua tat ca, bien k de xac nhan so lan lap khong vuot qua so tien trinh
-thuc hien vong lap while voi flag = 1 tuc luon dung, vong lap se lap khi flag bi thay doi thanh bien dieu kien dung
-duyet qua tung tien trinh:
    
    + neu so lan lap cua tien trinh do (k) < hon so tien trinh (n) va thoi gian den nho count, co cua tien trinh do = 0 
    tinh thoi gian cho bang tru di thoi gian den, thoi gian ket thuc = thoi gian , doi bien dieu kien boolean va flagcntl tuc la da duyet qua, tang so luot 
    lap qua (k) len
    => cai nay chu yeu tinh khi tien trinh vao lan dau
    
    + neu tien trinh do co burst > quantum va thoi gian den <= count
    neu boolen = 1 thi chuyen trang thai ve 0
    neu chua thi tinh thoi gian cho = thoi gian cho cu + thoi gian thuc hien cua cac tien trinh khac truoc do 
    tang count += tq vui moi lan thuc hien chi thuc hien tien trinh trong khoang <= tq
    khi ma thuc hien tru tien trinh r thi burst se giam ne pburst1 - mot khoang tq
    gan thoi gian ket thuc = count, vi sau khi thuc hien count tang len tq la so burst da duoc tinh
    => cai nay chu yeu tinh khi so burst nhieu hon tq, phai tru nhieu lan
    
    +neu so burst sau khi tru van con > 0 nhung lai < tq thi tinh thoi gian cho nhu tren
    count se tang len so burst con lai nay vi day la so burst cuoi, so burst nay < tq , vi sau khi tru nhieu lan thi so burst con la 2 , quantum la 4, k the tang len 4 dc
    thoi gian ket thuc = count
    sau khi tru het thi so burst ve 0
    tang j len - j o day de kiem tra so tien trinh da tinh het
    => cai nay chu yeu tinh nhung cai tien trinh giai doan cuoi cung
    
    + neu j = n tuc so tien trinh tinh het thi dung vong lap bang cach gan bien dieu kien flag = 0(1 true - 0 false)
*/
void calculate()
{
    int i, j = 0, k = 0, flag = 1, count = 0;
    printf("\n---GANTT CHART---\n");
    printf("0 | ");
    while (flag)
    {
        for (i = 0; i < n; i++)
        {
            if ((k<n)&&(a[i].arrivt <= count) && (a[i].flagcntl == 0)) 
                {
                    a[i].wtime = count - a[i].arrivt;
                    a[i].endtime = count;
                    a[i].boolean = 1;
                    a[i].flagcntl = 1;
                    k++;
                }
            if ((a[i].pburst1 > tq) && (a[i].arrivt <= count))
            {
                if (a[i].boolean == 1)
                    a[i].boolean = 0;
                else
                    a[i].wtime = a[i].wtime + (count - a[i].endtime);
                    count = count + tq;
                    a[i].pburst1 = a[i].pburst1 - tq;
                    a[i].endtime = count;
                    printf("%d %s| ", count, a[i].pname);
            }
            else if ((a[i].pburst1 > 0) && (a[i].pburst1 <= tq) && (a[i].arrivt <= count))
            {
                if (a[i].boolean == 1)
                    a[i].boolean = 0;
                else
                    a[i].wtime = a[i].wtime + (count - a[i].endtime);
                    count = count + a[i].pburst1;
                    a[i].endtime = count;
                    printf("%d %s| ", count, a[i].pname);
                    a[i].pburst1 = 0;
                    j++;
            }
            else if (j == n)
                flag = 0;
        }
    }   
}

/*
=========in ra time = ============
- tong thoi gian = tong thoi gian cu + thoi gian cho moi tien trinh
- thoi gian trung binh = time tb cu + time ket thuc tung tien trinh - time den tung tien trinh
*/
void display_waittime()
{
    int i, tot = 0, turn = 0;
    for (i = 0; i < n; i++)
    {
        printf("\n\nWaiting time for Process %s is %d", a[i].pname, a[i].wtime);
        tot = tot + a[i].wtime;
        turn = turn + a[i].endtime - a[i].arrivt;
    }
    printf("\n\n\tAverage waiting time=%f", (float)tot / (float)n);
    printf("\n\tAverage turnaround time=%f\n", (float)turn / (float)n);
}