#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x="AGGTAB";
    string y="GXTXAYB";
    int n=x.length();
    int m=y.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string lcs="";
    int i=n,j=m;
    while(i>=1&&j>=1)
    {
        if(x[i-1]==y[j-1])
        {
            lcs+=x[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<"LCS:"<<lcs<<endl;
    return 0;
}
