#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 450

struct Student
{
    int roll_number;
    char name[100];
    char department[50];
    char course[50];
    int year_of_joining;
};

void printStudentsByYear(struct Student students[], int n, int year)
{
    printf("\nStudents who joined in the year %d:\n", year);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].year_of_joining == year)
        {
            printf("Name: %s\n", students[i].name);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No students found for the given year.\n");
    }
}

void printStudentsInRollRange(struct Student students[], int n, int low, int high)
{
    printf("\nStudents with roll numbers between %d and %d:\n", low, high);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].roll_number >= low && students[i].roll_number <= high)
        {
            printf("Roll Number: %d\n", students[i].roll_number);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].year_of_joining);
            printf("-----------------------------------\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("No students found in the given roll number range.\n");
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int n, year, low, high;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS)
    {
        printf("Error: Maximum limit of students exceeded.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Department: ");
        scanf(" %[^\n]", students[i].department);
        printf("Course: ");
        scanf(" %[^\n]", students[i].course);
        printf("Year of Joining: ");
        scanf("%d", &students[i].year_of_joining);
    }

    printf("\nEnter year to search students: ");
    scanf("%d", &year);
    printStudentsByYear(students, n, year);

    printf("\nEnter roll number range (low and high): ");
    scanf("%d %d", &low, &high);
    printStudentsInRollRange(students, n, low, high);
}
