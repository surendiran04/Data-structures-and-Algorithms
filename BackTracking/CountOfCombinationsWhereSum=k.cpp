#include <bits/stdc++.h>
using namespace std;
int printF(int ind, vector<int>& ds,int s, int arr[], int n,int target) {
    if(s>target) return 0; //strictly for positive array
    if (ind == n) {
        if(s==target){
        return 1;
        }
        return 0;
    }
    // take 
    ds.push_back(arr[ind]);
    s+=arr[ind];
    int take=printF(ind + 1, ds,s, arr, n,target);
    ds.pop_back();
    s-=arr[ind];
    //not take 
    int notTake=printF(ind + 1, ds,s, arr, n,target);
    return take+notTake;
}
int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum=2;
    vector<int> ds;
    cout<<printF(0,ds,0,arr,n,sum);
    return 0;
}
