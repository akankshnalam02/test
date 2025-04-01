#include <stdio.h>
#include <string.h>

#define d 256   // Number of possible characters (ASCII)
#define q 101   // A prime number used for hashing

// Rabin-Karp Pattern Matching Algorithm
void RabinKarpSearch(char *text, char *pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1; // Multiplier for the highest order digit

    // Compute h = (d^(M-1)) % q
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Compute initial hash values for pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= N - M; i++) {
        // If hash values match, check characters one by one
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Compute the hash value for next window
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // Convert negative hash to positive
            if (t < 0)
                t = t + q;
        }
    }
}

// Main function
int main() {
    char text[] = "ABAAABDCDLUFFYABAABAB";
    char pattern[] = "LUFFY";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Pattern matching using Rabin-Karp algorithm:\n");

    RabinKarpSearch(text, pattern);

    return 0;
}

