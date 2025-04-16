#include <stdio.h>
#include <string.h>

struct Employee
{
    char emp_name[50];
    int emp_ID;
    char address[100];
};

void sortData(struct Employee data[], int len)
{
    struct Employee tmp;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (strcmp(data[i].emp_name, data[j].emp_name) > 0)
            {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
}

void main()
{
    int n;
    printf("Enter total number of employees: ");
    scanf("%d", &n);
    getchar();

    struct Employee employeeData[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter data of employee %d\n", i + 1);
        printf("Enter Employee name: ");
        fgets(employeeData[i].emp_name, 50, stdin);
        printf("Enter Employee ID: ");
        scanf("%d", &employeeData[i].emp_ID);
        getchar();
        printf("Enter Employee address: ");
        fgets(employeeData[i].address, 100, stdin);
    }

    sortData(employeeData, n);

    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Data of employee %d\n", i + 1);
        printf("Employee name: %s\n", employeeData[i].emp_name);
        printf("Employee ID: %d\n", employeeData[i].emp_ID);
        printf("Enter Employee address: %s\n", employeeData[i].address);
    }
}