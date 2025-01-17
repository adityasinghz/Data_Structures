#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapsack(wt, val, W, n);
}