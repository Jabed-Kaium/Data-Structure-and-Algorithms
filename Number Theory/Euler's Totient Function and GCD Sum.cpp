//Euler's Totient Function and GCD Sum
//Ref : CodeNCode (Youtube)
//Complexity : O(NlogN + Q*sqrt(N))

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

int phi[1000001];

//pre-process for phi array
void init(int maxN) {
	for (int i = 1; i <= maxN; i++)
		phi[i] = i;

	for (int i = 2; i <= maxN; i++)
		if (phi[i] == i) {
			for (int j = i; j <= maxN; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
}

int getCount(int d, int n) {
	return phi[n / d];
}

int main()
{
	init(1000000);

	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		int res = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				int d1 = i;
				int d2 = n / i;

				res += (d1 * getCount(d1, n));
				if (d1 != d2)
					res += (d2 * getCount(d2, n));
			}
		}
		cout << res << "\n";
	}

	return 0;
}