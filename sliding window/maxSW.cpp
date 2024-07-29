#include<iostream>
#include<vector>
using namespace std;

void getmax(vector<int> &nums, vector<int> &arr, int l, int r){
    int maxi = INT_MIN;
    for(int i=l;i<=r; i++){
        maxi = max(maxi, nums[i]);
    }
    arr.push_back(maxi);
}

vector<int> maxslidingwindow(vector<int> &nums, int n, int k){
    int left = 0; int right = 0;
    vector<int> arr;
    while(right<k-1){
        right++;
    }
    while(right<n){
        getmax(nums, arr, left, right);
        right++;
        left++;
    }
    return arr;
}

int main()
{
    int n;
    int k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> result = maxslidingwindow(nums, n, k);
    for(auto ans: result){
        cout<<ans<<" ";
    }
    return 0;
}