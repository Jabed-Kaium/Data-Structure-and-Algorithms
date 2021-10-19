//(0-1) Knapsack (bottom - up)
//Ref : Youtube(Aditya Verma)
//Complexity : O(n*w)

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
int dp[N + 2][W + 2];	//memoization table

int knapsack(int wt[], int val[], int w, int n) {
	//initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			//if current element <= current weight
			if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]] , dp[i - 1][j]);
			}
			//if current element > current weight
			else if (wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][w];

}

int main()
{
	int n, w;
	cin >> n >> w;
	int val[n + 1], wt[w + 1];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n; i++)
		cin >> wt[i];

	int ans = knapsack(wt, val, w, n);

	cout << ans << "\n";

	return 0;
}