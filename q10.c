#include <stdio.h>
#include <stdlib.h>

struct Customer
{
    char name[50];
    long account_number;
    float balance;
    float loan_amount;
};

int main()
{
    FILE *bankFile, *retrievedFile;
    struct Customer customers[10] = {
        {"Alice", 1001, 60000.0, 10000.0},
        {"Bob", 1002, 40000.0, 5000.0},
        {"Charlie", 1003, 120000.0, 20000.0},
        {"David", 1004, 30000.0, 1000.0},
        {"Emma", 1005, 70000.0, 15000.0},
        {"Frank", 1006, 200000.0, 8000.0},
        {"Grace", 1007, 50001.0, 25000.0},
        {"Hannah", 1008, 149999.0, 4000.0},
        {"Ivy", 1009, 155000.0, 50000.0},
        {"Jack", 1010, 100000.0, 12000.0}};

    bankFile = fopen("bank.txt", "w");
    if (bankFile == NULL)
    {
        printf("Error creating bank.txt\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        fprintf(bankFile, "%s %ld %.2f %.2f\n",
                customers[i].name,
                customers[i].account_number,
                customers[i].balance,
                customers[i].loan_amount);
    }
    fclose(bankFile);

    bankFile = fopen("bank.txt", "r");
    retrievedFile = fopen("retrieved.txt", "w");

    if (bankFile == NULL || retrievedFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    struct Customer temp;
    while (fscanf(bankFile, "%s %ld %f %f",
                  temp.name, &temp.account_number, &temp.balance, &temp.loan_amount) == 4)
    {
        if (temp.balance > 50000 && temp.balance < 150000)
        {
            fprintf(retrievedFile, "%s %ld\n", temp.name, temp.account_number);
        }
    }

    fclose(bankFile);
    fclose(retrievedFile);

    printf("Filtered customer details saved in retrieved.txt.\n");
    return 0;
}
