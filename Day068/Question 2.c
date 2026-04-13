/*A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, 
where the words are claimed to be sorted lexicographically according to the language’s rules.
Your task is to determine the correct order of letters in this alien language based on the given words.
If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. 
If there are multiple valid orders, return any one of them.
However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").
A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a
appears earlier in the alien language than the corresponding character in b.
If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.*/
Note: Your implementation will be tested using a driver code.
  It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.*/

#include <stdio.h>
#include <string.h>

#define MAX 26

char* findOrder(char dict[][100], int N, int K) {
    static char result[MAX + 1];
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    for (int i = 0; i < N - 1; i++) {
        char *w1 = dict[i];
        char *w2 = dict[i + 1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        if (!found && len1 > len2) {
            result[0] = '\0';
            return result;
        }
    }

    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < K; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int idx = 0;

    while (front < rear) {
        int u = queue[front++];
        result[idx++] = u + 'a';

        for (int v = 0; v < K; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (idx < K) {
        result[0] = '\0';
        return result;
    }

    result[idx] = '\0';
    return result;
}
