#include <bits/stdc++.h>
using namespace std;
void printF(int ind, vector<int>& ds,int s, int arr[], int n,int target) {
    if (ind == n) {
        if(s==target){
        for (auto it : ds) {
            cout << it << " ";
        }
          cout << endl;
        }
        return;
    }

    // take 
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printF(ind + 1, ds,s, arr, n,target);
    ds.pop_back();
    s-=arr[ind];
    //not take 
    printF(ind + 1, ds,s, arr, n,target);
}
int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum=2;
    vector<int> ds;
    printF(0,ds,0,arr,n,sum); //output: {[1,1], [2]}
    return 0;
}
