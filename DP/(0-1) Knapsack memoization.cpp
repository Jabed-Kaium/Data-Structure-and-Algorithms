//(0-1) Knapsack (memoization)
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
	if (n == 0 || w == 0)
		return 0;
	if (dp[n][w] != -1)
		return dp[n][w];

	//if current element <= current weight
	if (wt[n - 1] <= w) {
		return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1) , knapsack(wt, val, w, n - 1));
	}
	//if current element > current weight
	else if (wt[n - 1] > w) {
		return dp[n][w] = knapsack(wt, val, w, n - 1);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, w;
	cin >> n >> w;
	int val[n + 1], wt[w + 1];
	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}
	int ans = knapsack(wt, val, w, n);

	cout << ans << "\n";

	return 0;
}