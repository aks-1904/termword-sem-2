#include <stdio.h>
#include <ctype.h>
#include <string.h>

int starts_with_vowel(const char *word)
{
    char ch = tolower(word[0]);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    FILE *input, *output;
    char word[100];

    input = fopen("Data.txt", "r");
    if (input == NULL)
    {
        printf("Error opening Data.txt\n");
        return 1;
    }

    output = fopen("newfile.txt", "w");
    if (output == NULL)
    {
        printf("Error creating newfile.txt\n");
        fclose(input);
        return 1;
    }

    while (fscanf(input, "%99s", word) == 1)
    {
        if (starts_with_vowel(word))
        {
            fprintf(output, " ");
        }
        else
        {
            fprintf(output, "%s ", word);
        }
    }

    fclose(input);
    fclose(output);

    printf("Words starting with vowels have been removed and replaced with blank spaces.\n");
    return 0;
}
