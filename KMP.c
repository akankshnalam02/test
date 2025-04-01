#include <stdio.h>
#include <string.h>

// Compute the Longest Prefix Suffix (LPS) array
void computeLPS(char *pattern, int M, int *lps) {
    int len = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;   // LPS of first character is always 0
    int i = 1;    

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Backtrack
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Pattern Matching Algorithm
void KMPSearch(char *text, char *pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[M];

    // Preprocess the pattern (calculate LPS array)
    computeLPS(pattern, M, lps);

    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];  // Move to the last matched prefix
        } else if (i < N && pattern[j] != text[i]) {  
            if (j != 0) {
                j = lps[j - 1];  // Try next best prefix match
            } else {
                i++;  // Move to next character in text
            }
        }
    }
}

// Main function
int main() {
    char text[] = "ABABDABACCAABDCDDEEPUABABCABAB";
    char pattern[] = "DEEPU";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Pattern matching using KMP algorithm:\n");

    KMPSearch(text, pattern);

    return 0;
}

