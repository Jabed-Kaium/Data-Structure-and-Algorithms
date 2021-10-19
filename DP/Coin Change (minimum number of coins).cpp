//Coin Change (minimum number of coins)
//Ref : Youtube (Aditya Verma)
//Complexity : O(n*sum)

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

const int N = 100;
const int W = 100;
const int MAX = INT_MAX - 1;
int dp[N + 2][W + 2];	//actually dp[n+2][sum+2]

int coin_change(int coin[], int sum, int n) {
	//initialization starts
	for (int i = 0; i <= sum; i++) {
		dp[0][i] = MAX;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1, j = 1; j <= sum; j++) {
		if (j % coin[0] == 0) {
			dp[i][j] = j / coin[0];
		}
		else {
			dp[i][j] = MAX;
		}
	}
	//initialization ends

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (coin[i - 1] <= j) {
				dp[i][j] = min(dp[i][j - coin[i - 1]] + 1 , dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][sum];	//if dp[n][sum] >= MAX, return -1.
}

int main()
{
	int n, sum;
	cin >> n >> sum;
	int coin[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int ans = coin_change(coin, sum, n);

	cout << ans << "\n";

	return 0;
}