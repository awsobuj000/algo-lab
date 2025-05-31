#include <iostream>
#include <vector>
#include <string>
using namespace std;
string LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return lcs;
}
int main()
{
    string X, Y;
    cout << "Enter first sequence: ";
    cin >> X;
    cout << "Enter second sequence: ";
    cin >> Y;
    string lcs = LCS(X, Y);
    cout << "LCS: " << lcs << endl;
    cout << "Length of LCS: " << lcs.length() << endl;
    return 0;
}
