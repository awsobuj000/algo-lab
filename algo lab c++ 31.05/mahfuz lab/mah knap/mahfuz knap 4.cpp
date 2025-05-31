#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=3,w=5;
    vector<int>weight= {2,3,4},value= {3,4,5};
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(weight[i-1]<=j) dp[i][j]=max(dp[i-1][j],value[i-
                                                1]+dp[i-1][j-weight[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<"Value "<<dp[n][w]<<endl;
    int i=n,j=w;
    vector<int>taken;
    while(i>0 && j>0)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            taken.push_back(i);
            j-=weight[i-1];
        }
        i--;
    }
    cout<<"Taken ";
    for(int idx:taken)
    {
        cout<<idx<<" ";
    }
    cout<<endl;
}
