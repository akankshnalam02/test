#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies in range freq[i...j]
int sum(int freq[], int i, int j) {
    int s = 0;
    int k;
    for ( k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Recursive function to find the minimum cost of an optimal BST
int optCost(int freq[], int i, int j) {
    if (i > j) return 0; // Base case: No elements
    if (i == j) return freq[i]; // Base case: Single node

    int fsum = sum(freq, i, j); // Sum of frequencies in this range
    int minCost = INT_MAX;
			int r;
    // Try making each key in range freq[i...j] the root and find the minimum cost
    for ( r = i; r <= j; r++) {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < minCost) minCost = cost;
    }

    return minCost + fsum; // Add frequency sum to ensure frequently searched keys are near root
}

// Wrapper function to compute optimal BST cost
int optimalSearchTree(int freq[], int n) {
    return optCost(freq, 0, n - 1);
}

// Driver code
int main() {
    int keys[] = {10, 12, 20};  // Keys (not used in calculation)
    int freq[] = {34, 8, 50};   // Frequency of key access
    int n = sizeof(freq) / sizeof(freq[0]); // Number of keys

    // Print the minimum cost of an optimal BST
    printf("Cost of Optimal BST: %d\n", optimalSearchTree(freq, n));
    return 0;
}

