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

int n, m, pai[100100];
ll dist[100100];
vector <ii> adj[100100];

ll bfs(int ini,int fim){
	int u,v,cost;
	priority_queue <ii> pq;
	rep(i,0,n){
		dist[i] = INF; // CUIDADO COM O VALOR DE INF
		pai[i] = -1;
	}
	dist[ini] = 0;
	pq.push(ii(0,ini));
	
	while(!pq.empty()){
		u = pq.top().S;
		pq.pop();
		rep(i,0,adj[u].size()){
			v = adj[u][i].F;
			cost = adj[u][i].S;
			if(dist[v] < dist[u] + cost){
				dist[v] = dist[u] + cost;
				pai[v] = u;
				pq.push(ii(-dist[v],v));
			}
		}
	}
	return dist[fim];
}

int main(){
	int a,b,c,ini,fim;
	
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d",&a,&b);
		adj[a].pb(ii(b,c));
		adj[b].pb(ii(a,c));
	}
	
	scanf("%d%d", &ini, &fim);
	
	bfs(ini,fim); // distancia de ini a fim, pode-se recuperar o caminho pelo pai
	
	return 0;
}
