#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 10

/*
- khoi tao cac bien:
    mutex: (khoa)- bien nay kiem tra cho phep mot tien trinh hoat dong
    n: so tien trinh
    empty: chua cac tien trinh trong trang thai cho
    full: chua cac tien trinh duoc danh thuc
- ham wait():
    thuc hien vong lap neu s < 0 in ra thong bao: khong the hoat dong them tien trinh 
    giam gia tri cua semaphore xuong, tuc dang co tien trinh cho de hoat dong
- ham signal(): tang gia tri semaphore len - danh thuc tien trinh dang cho
- ham producer(): 
    chay vong lap it nhat 1 lan
    + thuc hien dua tien trinh ve trang thai ngu
    + dua mutex ve che do ngu tuong ung voi so tien trinh -1 o trang thai ngu
    + nhan gia tri tien trinh
    +them gia tri tien trinh vao bo nho dem, tang in
    + goi mutex tang  len 1 tuong uong 1 tien trinh them vao dem
    + tang full
- ham consumer():
    thuc hien it nhat 1 lan:
    + dua tien trinh vao trang thai ngu, giam so luong tien trinh
    + giam mutex tien trinh do
    + lay gia tien trinh ra va in ra
    + tang so luong tien trinh duoc lay ra- tuong ung vi tri
    + tang vung nho tien trinh ngu
*/

int mutex, n, empty, full = 0, item, item1;
int buffer[20];
int in = 0, out = 0, mutex = 1;
void wait(int s)
{
    while(s < 0)
    {
        printf("\nCannot add an item\n");
        exit(0);
    }
    s--;
}
void signal(int s) { s++; }
void producer()
{
    do
    {
        wait(empty);
        wait(mutex);
        printf("\nEnter an item: ");
        scanf("%d",&item);
        buffer[in] = item;
        in = in + 1;
        signal(mutex);
        signal(full);
    } while (in < n);
}
void consumer()
{
    do
    {
        wait(full);
        wait(mutex);
        item1 = buffer[out];
        printf("\nConsumed item = %d", item1);
        out = out + 1;
        signal(mutex);
        signal(empty);
    } while (out < n);
}
int main()
{
    printf("Enter the value of n: ");
    scanf("%d",&n);
    empty = n;
    while(in < n)
        producer();
    while(in != out)
        consumer();
}