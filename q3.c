#include <stdio.h>

void main()
{
    int m, n;
    printf("Enter the number of rows {m}: ");
    scanf("%d", &m);
    printf("Enter the number of columns {n}: ");
    scanf("%d", &n);

    int mat[m][n];

    printf("Enter the elements of matrix: ");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int found = 0;

    for (int i = 0; i < m; i++)
    {
        int minRow = mat[i][0];
        int colIdx = 0;

        for (int j = 1; j < n; j++)
            if (mat[i][j] < minRow)
            {
                minRow = mat[i][j];
                colIdx = j;
            }

        int k;
        for (int k = 0; k < m; k++)
            if (mat[k][colIdx] > minRow)
                break;

        if (k == m)
        {
            printf("Saddle point found at (%d, %d): %d\n", i, colIdx, minRow);
            found = 1;
        }
    }

    if (!found)
        printf("No saddle point found\n");
}