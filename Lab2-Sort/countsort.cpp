#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int> &a,vector<int> &b){
    vector<int> count(100,0);
    int n=a.size();
    for(int i=0;i<n;++i) ++count[a[i]];
    for(int i=1;i<100;++i) count[i]+=count[i-1];
    for(int i=n-1;~i;--i) b[--count[a[i]]]=a[i];
}

int main(){
    vector<int> nums={95,94,91,98,99,90,99,93,91,92};
    vector<int> res(nums.size());
    countsort(nums,res);
    for(auto i:res) cout<<i<<" ";
    return 0;
}