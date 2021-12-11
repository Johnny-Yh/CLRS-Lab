#include <bits/stdc++.h>
using namespace std;

vector<int> greedy(const vector<pair<int,int>> &dw){
    // dw.first->截止时间 dw.second->惩罚 ai=i+1
    int n=dw.size();
    vector<int> res(n,-1);
    for(int i=0;i<n;++i){
        int pos=dw[i].first-1;
        while(pos>=0&&res[pos]!=-1) --pos;
        if(pos!=-1) res[pos]=i+1;
        else{
            pos=n-1;
            while(pos>=0&&res[pos]!=-1) --pos;
            res[pos]=i+1;
        }
    }
    return res;
}

int main(){
    // word需要按惩罚大小降序排列
    vector<pair<int,int>> work={{4,70},{2,60},{4,50},{3,40},{1,30},{4,20},{6,10}};
    vector<int> res=greedy(work);
    cout<<"可行的最优调度为:";
    for(int num:res) cout<<num<<" ";
    return 0;
}