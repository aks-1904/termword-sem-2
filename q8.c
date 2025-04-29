#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input, *single, *multiple;
    int num, count = 0;

    input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Error opening input.txt\n");
        return 1;
    }

    single = fopen("single.txt", "w");
    multiple = fopen("multiple.txt", "w");
    if (single == NULL || multiple == NULL)
    {
        printf("Error opening output files\n");
        return 1;
    }

    while (fscanf(input, "%d", &num) == 1 && count < 20)
    {
        if (num >= -9 && num <= 9)
        {
            fprintf(single, "%d\n", num);
        }
        else
        {
            fprintf(multiple, "%d\n", num);
        }
        count++;
    }

    fclose(input);
    fclose(single);
    fclose(multiple);

    printf("Numbers separated into single.txt and multiple.txt successfully.\n");
    return 0;
}
