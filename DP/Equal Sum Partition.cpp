//Equal Sum Partition
//Ref : Aditya Verma (Youtube)
//Complexity : O(n*(totalSum/2))

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 100;
const int W = 100;
int dp[N+2][W+2];

bool subsetSum(int arr[], int sum, int n){
    //initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0){
                dp[i][j] = 0;   //false
            }
            if(j == 0){
                dp[i][j] = 1;   //true
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool Equal_Sum_Partition(int arr[], int n){
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    //if total sum = odd its impossible , if total sum = even it may possible to partition into two subset where the sum are equal
    if(sum%2 != 0){
        return false;
    }
    else{
        return subsetSum(arr,sum/2,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool flag = Equal_Sum_Partition(arr,n);

    if(flag){
        cout << "possible\n";
    }
    else{
        cout << "not possible\n";
    }

    return 0;
}