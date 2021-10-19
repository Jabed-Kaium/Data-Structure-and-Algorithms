//Bigmod (a^n)%p
//Ref : CodeNCode (Youtube)
//Complexity : O(logn)

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

int bigmod(int a, int n, int p) {
	int res = 1;
	while (n) {
		if (n % 2 != 0) {
			res = (res * a) % p;
			n--;
		}
		else {
			a = (a * a) % p;
			n /= 2;
		}
	}
	return res;
}

int main()
{

	cout << bigmod(2, 6, 7) << "\n";

	return 0;
}