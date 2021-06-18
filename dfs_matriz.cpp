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
int n, m, vis[1010][1010], dx[] = {0,1,0,-1},dy[] = {1,0,-1,0}; // dx e dy podem variar

bool dentro(int x,int y){
	return x < n && y < m && x >=0 && y>=0; // && mat[x][y] != "parede"
}

void dfs(int x,int y){
	vis[x][y] = 1;
	int xx,yy;
	rep(i,0,4) { // depende de dx e dy
		xx = x + dx[i];
		yy = y + dy[i];
		if(dentro(xx,yy) && !vis[xx][yy]){
			dfs(xx,yy);
		}
	}
}

int main(){
	int a,b;
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		rep(j,0,m)
			scanf(" %c",&mat[i][j]);
	
	dfs(0,0);		
	
	return 0;
}
