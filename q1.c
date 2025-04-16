#include <stdio.h>

int isValidWord(char *given, char *word)
{
    int freqGiven[26] = {0}, freqWord[26] = {0};

    for (int i = 0; given[i] != '\0'; i++)
        if (given[i] >= 'a' && given[i] <= 'z')
            freqGiven[given[i] - 'a']++;

    for (int i = 0; word[i] != '\0'; i++)
        if (word[i] >= 'a' && word[i] <= 'z')
            freqWord[word[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (freqGiven[i] != freqWord[i])
            return 0;

    return 1;
}

void main()
{
    char given[50], aman[50], swati[50];

    printf("Enter the given set of alphabets: ");
    scanf("%s", given);

    printf("Enter swati's word: ");
    scanf("%s", swati);

    printf("Enter Aman's word: ");
    scanf("%s", aman);

    int validSwati = isValidWord(given, swati);
    int validAman = isValidWord(given, aman);

    if (validSwati && validAman)
        printf("Both are winner\n");
    else if (validSwati)
        printf("Swati is winner\n");
    else if (validAman)
        printf("Aman is winner\n");
    else
        printf("None of you is winner\n");
}