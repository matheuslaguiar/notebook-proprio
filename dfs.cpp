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

int n,m,pai[10100],vis[10100];
vector <int> adj[10100];

void dfs(int u){
	vis[u] = 1;
	rep(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			pai[v] = u;
			dfs(v);
		}
	}
}

int main(){
	int a,b;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	rep(i,0,n) pai[i] = -1;
	
	rep(i,0,n)
		if(!vis[i])
			dfs(i);
	
	return 0;
}
