#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 3, W = 5;
    vector<int> weight = {2, 3, 4};
    vector<int> value = {3, 4, 5};
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (weight[i] <= w) dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]);
            else dp[i + 1][w] = dp[i][w];
        }
    }
    cout << "Maximum value = " << dp[n][W] << endl;
    vector<int> taken;
    int w = W;
    for (int i = n; i > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            taken.push_back(i);
            w -= weight[i - 1];
        }
    }
    reverse(taken.begin(), taken.end());
    cout << "Items taken: ";
    for (int item : taken)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
