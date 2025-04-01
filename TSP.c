#include <stdio.h>
#include <limits.h>

#define MAX 9999
#define N 4  // Number of cities

int dist[N][N] = {  
    {0, 22, 26, 30},  
    {30, 0, 45, 35},  
    {25, 45, 0, 60},  
    {30, 35, 40, 0}  
};  

int dp[16][N];  // DP table to store solutions

// TSP function using bitmasking
int TSP(int mask, int pos) {  
    if (mask == (1 << N) - 1)  
        return dist[pos][0];  // Return to starting city  

    if (dp[mask][pos] != -1)  
        return dp[mask][pos];  
   int city;
    int ans = MAX;
    for ( city = 0; city < N; city++) {  
        if (!(mask & (1 << city))) {  // If city is unvisited
            int newAns = dist[pos][city] + TSP(mask | (1 << city), city);  
            if (newAns < ans) ans = newAns;  
        }
    }  
    return dp[mask][pos] = ans;  
}  

int main() {  
int i,j;
    // Initialize DP table with -1
    for ( i = 0; i < (1 << N); i++)  
        for ( j = 0; j < N; j++)  
            dp[i][j] = -1;  

    printf("Minimum Distance: %d\n", TSP(1, 0));  
    return 0;  
}

