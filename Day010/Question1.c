/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    printf("Enter a word \n");
    scanf("%s",s);
    
    int left=0;
    int right= strlen(s)- 1;
    
    int ispalindrome=1;
    while(left < right){
        if (s[left]!=s[right]){
            ispalindrome=0;
            break;
        }
        left++;
        right--;
    }
    
    if (ispalindrome==1)
    printf("Palindrome");
    else if (ispalindrome==0)
    printf("Not Palindrome");
    else
    printf("Wrong input");
 
}
