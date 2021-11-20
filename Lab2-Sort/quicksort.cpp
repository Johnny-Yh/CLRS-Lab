#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums,int low,int high){
    int temp=nums[low];
    while(low<high){
        while(low<high&&temp<=nums[high]) --high;
        if(low<high) nums[low]=nums[high];
        while(low<high&&temp>=nums[low]) ++low;
        if(low<high) nums[high]=nums[low];
    }
    nums[low]=temp;
    return low;
}

void quicksort(vector<int> &nums,int low,int high){
    if(low>=high) return;
    int pivot=partition(nums,low,high);
    quicksort(nums,low,pivot-1);
    quicksort(nums,pivot+1,high);
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    quicksort(nums,0,nums.size()-1);
    for(auto i : nums) cout<<i<<" ";
    return 0;
}
