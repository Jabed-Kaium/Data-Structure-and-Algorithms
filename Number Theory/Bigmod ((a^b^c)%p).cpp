//a^b^c % p
//p is a prime number
//Complexity : O(log(b) + log(c))

#include<bits/stdc++.h>
using namespace std;

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
    int t;
    cin>>t;
    while(t--){
        int a,b,c,p;
        cin>>a>>b>>c>>p;

        int res = bigmod(b,c,p-1);

        cout << bigmod(a,res,p) << "\n";
    }

    return 0;
}