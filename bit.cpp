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
int n;
ll bit[100100], v[100100];

ll update(int i,int a){
	for(;i<=n;i+=i&-i)
		bit[i]+=a;
}

ll query(int i){
	ll s=0;
	for(;i>0;i-=i&-i)
		s+=bit[i];
	return s;
}

int main () {
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%lld",&v[i]);
		update(i,v[i]);
	}
	
	return 0;
}














