//Euler's Totient Function using sieve
//Ref : CodeNCode (Youtube)
//Complexity : O(Nlog(logN))

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

int main()
{
	init(1000000);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << phi[n] << "\n";
	}

	return 0;
}