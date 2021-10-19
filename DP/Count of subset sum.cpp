//Count of Subset Sum
//Ref : Aditya Verma (Youtube)
//Compexity : O(n*sum)

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

int subsetSum(int arr[], int sum, int n){
    //initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n+1];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt = subsetSum(arr,sum,n);

    cout << "Total number of subset with sum " << sum << " : " << cnt << "\n";

    return 0;
}