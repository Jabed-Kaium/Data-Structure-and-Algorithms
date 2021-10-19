//Minimum subset sum difference
//Ref : Aditya Verma (Youtube)
//Complexity : O(n*sum)

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
int dp[N+1][W+1];   //actual size is dp[n+1][sum+1]

void subsetSum(int arr[], int sum, int n){
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
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int min_subset_sum_diff(int arr[], int sum, int n){
    subsetSum(arr,sum,n);
    vector<int> v;
    //store values which can be a subset sum between (0-renge/2)
    for(int i=0; i<=sum/2; i++){
        if(dp[n][i] == 1){
            v.push_back(i);
        }
    }
    //calculate min diff of two subsets
    int ans = INT_MAX;
    for(int i=0; i<v.size(); i++){
        ans = min(ans,sum-(2*v[i]));
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    int sum = 0;    //it is the range
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int res = min_subset_sum_diff(arr,sum,n);

    cout << "Minimum difference is : " << res << "\n";

    return 0;
}