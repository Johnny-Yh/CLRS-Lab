#include <bits/stdc++.h>
using namespace std;

int dynamic(vector<int> &weight,vector<int> &value,int c){
    // 动态规划方法解决背包问题
    int n=weight.size();
    // dp[i][j]->前i件物品装入限重为j的背包能获得的最大价值
    vector<vector<int>> dp(n+1,vector<int>(c+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=c;++j){
            if(j>=weight[i-1]){
                // 可以装的下第i件物品
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
            // 装不下第i件物品
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][c];
}

int greedy(vector<int> &weight,vector<int> &value,int c){
    // 贪心方法解决背包问题
    int n=weight.size(),res=0;
    vector<pair<int,int>> vpw(n);
    for(int i=0;i<n;++i) {
        vpw[i].first=weight[i];// 重量
        vpw[i].second=value[i];// 价值
    }
    // 按单位价值降序排序
    auto cmp=[&](pair<int,int> x,pair<int,int> y){
        return (double)x.second/(double)x.first>
        (double)y.second/(double)y.first;
    };
    sort(vpw.begin(),vpw.end(),cmp);
    for(int i=0;i<n;++i){
        if(c<vpw[i].first) break;
        // 从大到小装入
        res+=vpw[i].second;
        c-=vpw[i].first;  
    }
    return res;
}
int main(){
    vector<int> weight={2,2,6,5,4};// 重量
    vector<int> value={6,3,5,4,6};// 价值
    int c=10;// 背包容量
    cout<<"动态规划算出的最大价值:"<<dynamic(weight,value,c)<<endl;
    cout<<"贪心算出的最大价值:"<<greedy(weight,value,c)<<endl;
    return 0;
}