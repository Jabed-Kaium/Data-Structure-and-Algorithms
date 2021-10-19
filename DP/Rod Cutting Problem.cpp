//Rod Cutting Problem
//Ref : Youtube (Aditya Verma)
//Complexity : O(sz*N)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int sz = 100;
const int N = 100;
int dp[sz + 2][N + 2];

int knapsack(int length[], int price[], int N, int n) {
    //initialization
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= N; j++) {
            //if current element <= current weight
            if (length[i - 1] <= j) {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]] , dp[i - 1][j]);
            }
            //if current element > current weight
            else if (length[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][N];
}

int main()
{
    int n, N;
    cin >> n >> N;
    int price[n + 1], length[n + 1];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> length[i];

    int ans = knapsack(length, price, N, n);

    cout << ans << "\n";

    return 0;
}