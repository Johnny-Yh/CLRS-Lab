#include <bits/stdc++.h>
using namespace std;

int dynamic(vector<int> &weight,vector<int> &value,int c){
    // 动态规划方法
    int n=weight.size();
    vector<vector<int>> dp(c+1,vector<int>(n+1));
    // dp[i][j]->背包容量为j 前i个物品能达到的最大价值
    for(int i=1;i<=c;++i){
        for(int j=1;j<=n;++j){
            // 装不下 和原来的最大价值一样
            if(weight[i-1]>j) dp[i][j]=dp[i-1][j];
            else{
                // 装得下 判断是否装入
                dp[i][j]=max(dp[i-1][j-weight[i-1]]+value[i-1],dp[i-1][j]);
            }
        }
    }
    return dp[c][n];
}

int greedy(vector<int> &weight,vector<int> &value,int c){
    int n=weight.size(),res=0;
    vector<pair<int,int>> vpw(n);
    for(i=0;i<n;++j) {
        vpw[i].first=weight[i];// 重量
        vpw[i].second=value[i];// 价值
    }
    auto cmp=[&](pair<int,int> x,pair<int,int> y){
        return double(x.second/x.first)>double(y.second/y.first);
    };
    sort(vpw.begin(),vpw.end(),cmp);// 按单位价值降序排序
    for(int i=0;i<n&&c>0;++i){
        // 从大到小装入
        res+=vpw[i].second;
        c-=vpw[i].first;
    }
    return res;
}
int main(){
    vector<int> weight={2,2,6,5,4};
    vector<int> value={6,3,5,4,6};
    int c=10;// 背包容量
    cout<<dynamic(weight,value)<<endl;
    cout<<greedy(weight,value)<<endl;
    return 0;
}