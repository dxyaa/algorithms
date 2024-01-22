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
void stalinsort(int arr[], int arr2[], int n)
{
    p = 0;
    arr2[0] = arr[0];
    p++;
    for (int i = 1; i < n; i++)
    {
        printf("\np:%d", p);
        if (arr[i] > arr2[p - 1])
        {
            arr[p] = arr[i];
            p++;
            printf("\ninside p:%d", p);
            printf("\n");
            for (int i = 0; i < p; i++)
            {
                printf("%d\t", arr2[i]);
            }
        }
    }
    printf("\nsorted:\n");
    for (int i = 0; i < p; i++)
    {
        printf("%d\t", arr2[i]);
    }
}
void main()
{
    int n, ch;
    printf("\nNumber of elements enter karde: ");
    scanf("%d", &n);
    int arr[n];
    int arr2[n];
    printf("\nGo on,enter the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
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
        printf("\nAlready giving a sorted array? Nop bad game :(");
        return;
    }
    printf("\nWhich sorting u wanna do?\n1. Bogo Sort\n2. Stalin sort \n : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nBogosort hehe\n");
        bogosort(arr, n);
        break;
    case 2:
        printf("Stalin sort oooh");
        for (int i = 0; i < n; i++)
        {
            arr2[i] = 0;
        }
        stalinsort(arr, arr2, n);
        break;
    default:
        printf("Nope wrong choice bro\n");
    }
}
