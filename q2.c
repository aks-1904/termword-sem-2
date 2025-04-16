#include <stdio.h>
#include <string.h>

#define username "akshay"
#define password "akshayIsGreat@123"

void toLowerCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
}

void main()
{
    char user[50], pass[50];

    printf("Enter the username: ");
    scanf("%s", user);
    getchar();
    toLowerCase(user);

    printf("Enter the password: ");
    scanf("%s", pass);
    getchar();

    if (strcmp(user, username) != 0)
    {
        printf("Invalid user");
        return;
    }
    if (strcmp(pass, password) != 0)
    {
        printf("Invalid User");
        return;
    }

    printf("Valid User");
}