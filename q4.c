#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, idx;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the values of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the index to reverse array: ");
    scanf("%d", &idx);

    int end = n - 1;
    while (idx < end)
    {
        arr[idx] = arr[idx] + arr[end] - (arr[end] = arr[idx]);
        idx++;
        end--;
    }

    printf("Array after reversing: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    printf("\n");
}