/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. 
  In case of a tie, return the lexicographically smallest candidate name.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    char votes[MAX][50];
    
    printf("Enter number of votes: ");
    scanf("%d", &n);

    // Input votes
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    int maxCount = 0;
    char winner[50];

    for(int i = 0; i < n; i++) {
        int count = 1;

        // Count frequency of votes[i]
        for(int j = i + 1; j < n; j++) {
            if(strcmp(votes[i], votes[j]) == 0) {
                count++;
            }
        }

        // Update winner
        if(count > maxCount) {
            maxCount = count;
            strcpy(winner, votes[i]);
        }
        else if(count == maxCount) {
            // Lexicographically smaller name
            if(strcmp(votes[i], winner) < 0) {
                strcpy(winner, votes[i]);
            }
        }
    }

    printf("Winner: %s\n", winner);
    printf("Votes: %d\n", maxCount);

    return 0;
}

