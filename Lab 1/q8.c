#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[1000];
    char word[100] = "";
    fgets(str, 1000, stdin);
    int palindrome_count = 0;
    char palindromes[1000][1000];
    for (int i = 0;; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            int palindrome_check = 1;
            for (int i = strlen(word) - 1; i >= 0; i--)
            {
                printf("%c", word[i]);
            }
            if (str[i + 1] == '\n')
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
            for (int i = 0, j = strlen(word) - 1; j >= 0 && i < strlen(word); i++, j--)
            {
                if (word[i] != word[j])
                {
                    palindrome_check = 0;
                }
            }
            if (palindrome_check && strlen(word) > 1)
            {
                strcpy(palindromes[palindrome_count], word);
                palindrome_count++;
            }
            strcpy(word, "");
        }
        else
        {
            strncat(word, &str[i], 1);
        }
        if (str[i] == '\n')
        {
            break;
        }
    }
    printf("\n");
    if (!palindrome_count)
    {
        printf("NO PALINDOROMES");
    }
    for (int i = 0; i < palindrome_count; i++)
    {
        printf("%s ", palindromes[i]);
    }
    printf("\n");
    return 0;
}