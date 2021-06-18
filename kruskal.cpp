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

vector<pair<int,ii> > aresta;
int p[100100];

// Encontra o pai do conjunto 
int findset(int x)
{
	if(p[x] != x)
		p[x] = findset(p[x]);
	return p[x];			
}

//une dois conjuntos
void unionset(int a, int b)
{
	int pai_a = findset(a);
	int pai_b = findset(b);
	p[pai_a] = pai_b;
}

// retorna se dois vertices estao no mesmo conjunto
bool sameset( int a, int b)
{
	if(findset(a) == findset(b))
		return true;
	else 
		return false;
}

int main(){
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	rep(i,0,n+1) p[i] = i;
	rep(i,0,m){
		scanf("%d%d%d",&a,&b,&c);
		aresta.pb(mk(c,ii(a,b)));
	}
	int total = 0;
	sort(all(aresta));
	rep(i,0,aresta.size()){
		if(!sameset(aresta[i].S.F,aresta[i].S.S)){
			unionset(aresta[i].S.F,aresta[i].S.S);
			total += aresta[i].F;
		}
	}
	
	printf("%d\n",total);
	return 0;
}













