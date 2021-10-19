//Euler's Totient Function
//Ref : CodeNCode (Youtube)
//Complexity : O(sqrt(N))

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

int phi(int n) {
	int res = n;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			res /= i;
			res *= (i - 1);

			while (n % i == 0)
				n /= i;
		}

	if (n > 1)
		res /= n , res *= (n - 1);

	return res;
}

int main()
{
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << "ETF(" << n << ") = " << phi(n) << "\n";
	}

	return 0;
}