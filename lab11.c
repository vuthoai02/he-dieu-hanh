#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
- cac bien gom:
    turn: thoi gian quay vong
    burst
    p: priority - do uu tien
    wt: time cho
    c: cpu - so luong quy trinh
    await: thoi gian cho trung binh
    aturn: thoi gian quy vong trung binh
    twait: tong thoi gian cho
    tturn: tong thoi gian quay vong
- nhan so luong tien trinh
- nhan so luong quy trinh, thoi gian lien tuc, muc do uu tien 
- so sanh hai tien trinh ke nhau:
    neu su uu tien tien trinh truoc lon hon tien trinh sau hoan doi vi tri cua 2 tien trinh do
    => sap xep tien trinh theo do uu tien
- xet tung tien trinh:
    + neu la tien trinh dau tien thi setup thoi gian cho cua tien trinh nay = 0,thoi gian quay vong cua tien trinh nay = burst cua no
    + neu la tien trinh khac: thoi gian quay vong = thoi gian quay vong cu tien trinh truoc + burst cua no
    thoi gian cho = thoi gian quay vong cua no - burst 
    tong thoi gian cho = tong thoi gian cho cu + thoi gian cho cua tien trinh hien tai
    tong thoi gian quay vong = tong thoi gian quay vong cu + thoi gian quay vong cua tien trinh hien tai
- tinh thoi gian cho trung binh
- tinh thoi gian quay vong trung binh
*/

void main()
{
    int i, j, n, t, turn[20], burst[20], p[20], wt[20], c[20];
    float await, aturn, twait = 0, tturn = 0;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    printf("\n Enter the process no burst and arrivaltime");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        scanf("%d", &burst[i]);
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
                t = burst[i];
                burst[i] = burst[j];
                burst[j] = t;
                t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            wt[i] = 0;
            turn[i] = burst[i];
        }
        else
        {
            turn[i] = turn[i - 1] + burst[i];
            wt[i] = turn[i] - burst[i];
            twait = twait + wt[i];
            tturn = tturn + turn[i];
        }
    }
    await = twait / n;
    aturn = tturn / n;
    printf("pno\tbtime\tatime\twtime\tttime");
    for (i = 0; i < n; i++)
    {
        printf("\n %d\t %d\t %d\t %d\t %d\n", c[i], burst[i], p[i], wt[i], turn[i]);
    }
    printf("\n The average waiting time is: %f", await);
    printf("\n The average turn around time is: %f", aturn);
}