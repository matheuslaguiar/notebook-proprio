#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i < b;i++)
#define F first
#define S second
#define pb push_back
#define mk make_pair
#define debug(a) cerr << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
#define all(c) (c).begin(),(c).end()
typedef long long int ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;

map<int,int> primeFactors(ll n)
{
    map<int,int> factors;
    while (n % 2 == 0)
    {
        factors[2]++;
        n = n/2;
    }

    for (ll i = 3; i*i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n = n/i;
        }

    }

    if (n > 2)
        factors[n]++;

    return factors;
}

int main(){
    int n;
    scanf("%d\n",&n);
    
    map<int,int> factors= primeFactors(n); // F->base S->expoente
    
    for(map<int,int> ::iterator it= factors.begin(); it!=factors.end(); it++){
        cout << it->F << " elevado a " << it->S << endl;
    }
    return 0;
}
