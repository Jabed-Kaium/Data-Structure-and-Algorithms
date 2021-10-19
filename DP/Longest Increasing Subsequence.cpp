
/*
    Algorithm : Longest Increasing Subsequence
    Method : Dynamic Programming
    Complexity : O(n*n)  
    Ref : Tushar Roy
    0 index based
*/

#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[],int n){
    int dp[n+5];
    for(int i=0; i<n; i++) dp[i]= 1;

    int res = 1; //longest subsequence will be minimum 1

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],dp[j]+1);   //longest sequence till index i
            }
        }
    }

    for(int i=0; i<n; i++){
        res = max(res,dp[i]);
    }

    return res;

}

int main()
{
    int arr[] = {3,4,-1,0,6,2,3};

    int ans = LIS(arr,7);

    cout<<ans<<"\n";

    return 0;
}