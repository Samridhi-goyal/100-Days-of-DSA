/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.*/

#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int count[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++)
        count[s[i] - 'a']++;

    for (i = 0; s[i] != '\0'; i++)
        if (count[s[i] - 'a'] == 1)
            return s[i];

    return '$';
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%c\n", firstNonRepeating(s));
    return 0;
}

