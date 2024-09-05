#include <bits/stdc++.h>
using namespace std;
bool printF(int ind, vector<int>& ds,int s, int arr[], int n,int target) {
    if (ind == n) {
        if(s==target){
        for (auto it : ds) {
            cout << it << " ";
        }
        return true;
        }
        return false;
    }
    // take 
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printF(ind + 1, ds,s, arr, n,target)){
        return true;
    }
    ds.pop_back();
    s-=arr[ind];
    //not take 
    if(printF(ind + 1, ds,s, arr, n,target)){
        return true;
    }
    return false;
}
int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum=2;
    vector<int> ds;
    printF(0,ds,0,arr,n,sum);
    return 0;
}
