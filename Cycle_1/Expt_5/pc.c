#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int mutex, empty, full, i, n;

void producer(int a[]);
void consumer(int a[]);

int main ()
{
    printf("Enter the total number of positions in the circular array\n");
    scanf("%d", &empty);
    n = empty;
    full = 0;
    mutex = 0;
    i = -1;
    int a[empty];
    int choice;
    while (1)
    {
        printf("\n---------------------------\n");
        printf("Enter 1 for producer\n");
        printf("Enter 2 for consumer\n");
        printf("Enter 3 to exit\n");
        printf("Make your choice\n");
        scanf("%d", &choice);
        printf("---------------------------\n\n");
        switch(choice)
        {
            case 1:
                producer(a);
                break;
            case 2:
                consumer(a);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void producer(int a[])
{
    if(empty == 0)
    {
        printf("Cant perform Producer operation now\n");
        return;
    }
    if(mutex == 1)
    {
        printf("Can't perform Producer operation now\n");
        return;
    }
    int t;
    printf("Enter the value to be inserted into the array\n");
    scanf("%d", &t);
    mutex = 1;
    i = (i+1)%n;
    a[i] = t;
    mutex = 0;
    empty --;
    full ++;
    return;
}

void consumer(int a[])
{
    if(full == 0)
    {
        printf("Can't perform consumer operation now\n");
        return;
    }
    if(mutex == 1)
    {
        printf("Can't perform the consumer operation now\n");
        return;
    }
    mutex = 1;
    printf("Element consumed --> %d\n", a[i]);
    if(i == 0 && full == 1)
        i = -1;
    else if (i == 0)
    {
        i = n-1;
    }
    else
    {
        i --;
    }
    mutex = 0;
    empty ++;
    full --;
    return;
}