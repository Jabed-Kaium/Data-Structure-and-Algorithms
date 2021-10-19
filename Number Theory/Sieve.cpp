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


//prime[i] == 1 , prime
//prime[i] == 0 , not prime
int prime[1000001];

void sieve() {
	int MAXN = 1000000;

	for (int i = 1; i <= MAXN; i++)prime[i] = 1;

	prime[0] = prime[1] = 0;

	for (int i = 2; i * i <= MAXN; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAXN; j += i) {
				prime[j] = 0;
			}
		}
	}
}

int main()
{

	sieve();

	return 0;
}