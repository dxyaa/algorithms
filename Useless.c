#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int flag, p, q, temp;

void bogosort(int arr[], int n)
{

    flag = 0;
    /*printf("\nArray:")
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    */
    // logic:
    p = rand() % n;
    do
    {
        q = rand() % n;
    } while (p == q);
    // printf("\np:%d", p);
    // printf("\nq:%d", q);
    temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    // check if sorted
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        printf("\nFinally sorted yey!!\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    else
    {
        bogosort(arr, n);
    }
    return;
}

void main()
{
    int n, ch;
    printf("\nEnter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nWhich sorting u wanna do?\n1. Bogo Sort\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nBogosort hehe\n");
        bogosort(arr, n);
        break;
    default:
        printf("Nope wrong choice bro\n");
    }
}
