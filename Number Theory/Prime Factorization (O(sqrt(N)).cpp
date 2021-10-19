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

void primeFact(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			cout << i << "^" << cnt << "\n";
		}
	}
	if (n > 1) {
		cout << n << "^" << "1" << "\n";
	}
}

int main()
{

	int n;
	cin >> n;
	primeFact(n);

	return 0;
}