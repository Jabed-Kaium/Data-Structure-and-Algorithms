//Segmented Sieve
//Ref : CodeNCode (Youtube)
//Complexity :

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

vector<int>primes;	//store prime till sqrt(r)

int prime[100001];	//prime[r-l+1]

void sieve(int maxN) {
	vector<int> ar(maxN + 1, 0);
	ar[1] = 1;	//not prime

	for (int i = 2; i <= maxN; i++) {
		if (ar[i] == 0) {
			for (int j = 2 * i; j <= maxN; j += i)
				ar[j] = 1;
		}
	}

	for (int i = 1; i <= maxN; i++)
		if (ar[i] == 0)
			primes.push_back(i);
}

void init(int l, int r) {
	if (l == 1)l++;

	int maxN = r - l + 1;
	vector<int> ar(maxN , 0);

	for (int p : primes) {
		if (p * p <= r) {
			int i = (l / p) * p;
			if (i < l)i += p;

			for ( ; i <= r; i += p) {
				if (i != p)
					ar[i - l] = 1;	//not prime
			}
		}
	}

	for (int i = 0; i < maxN; i++) {
		if (ar[i] == 0)
			cout << l + i << "\n";
	}
}

int main()
{
	sieve(100000);	//passing sqrt(r)
	int t, l, r;
	cin >> t;

	while (t--) {
		cin >> l >> r;
		init(l, r);
		cout << "\n";
	}

	return 0;
}