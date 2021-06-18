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

bitset<10000005> bs;
vector<int> primos;
void crivo(ll limite = 10000000LL) { // calcula primos ate limite
  primos.clear();
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= limite; i++)
    if (bs[i]) {
      for (ll j = i * i; j <= limite; j += i)
        bs[j] = 0;
      primos.push_back(i);
    }
}
bool isPrime(ll N, ll limite) {
  if (N <= limite)
    return bs[N];
  for (int i = 0; i < (int)primos.size(); i++)
    if (N % primos[i] == 0)
      return false;
  return true;
}

 
 int main(){
 	
 	return 0;
 }
