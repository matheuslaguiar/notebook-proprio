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

char mat[1010][1010];
int n, m, dist[1010][1010], dx[] = {0,1,0,-1},dy[] = {1,0,-1,0}; // dx e dy podem variar
ii pai[1010][1010];

bool dentro(int x,int y){
	return x < n && y < m && x >=0 && y>=0; // && mat[x][y] != "parede"
}

ll bfs(int inix,int iniy,int fimx,int fimy){
	int x,y,xx,yy;
	queue <ii> q;
	rep(i,0,n)
		rep(j,0,m){
			dist[i][j] = INF; // CUIDADO COM O VALOR DE INF
			pai[i][j] = ii(-1,-1);
		}
	dist[inix][iniy] = 0;
	q.push(ii(inix,iniy));
	
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		rep(i,0,4){ // depende de dx e dy
			xx = x + dx[i];
			yy = y + dy[i];
			if(dist[xx][yy] < dist[x][y] + 1){
				dist[xx][yy] = dist[x][y] + 1;
				pai[xx][yy]  = ii(x,y);
				q.push(ii(xx,yy));
			}
		}
	}
	return dist[fimx][fimy];
}

int main(){
	int a,b,inix,iniy,fimx,fimy;
	
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		rep(j,0,m)
			scanf(" %c",&mat[i][j]);
	
	bfs(inix,iniy,fimx,fimy); // distancia de ini(x,y) a fim(x,y), pode-se recuperar o caminho pelo pai
	
	return 0;
}
