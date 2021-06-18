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

// SEGTREE DE SOMA
// RAIZ -> 1
// UPDATE EM POSIÇÃO

int n,tree[4*111111],a[111111];

void build(int no, int i, int j){
    if(i>j) return;
    if(i==j){
        tree[no] = a[i];
        return;
    }
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    build(L, i, mid);
    build(R, mid+1, j);
    tree[no] = tree[L] + tree[R];
}

int query(int no, int i, int j, int a, int b){
    if(i>b || j<a) return 0;
    if(i>=a && j<=b) return tree[no];
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    return query(L, i, mid, a, b) + query(R, mid+1, j, a, b);
}

void update(int no, int i, int j,int x, int v){
    if(x>j || x<i) return;
    if(i==j && i==x){
    	tree[no] = v;
        return;
    }
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    update(L, i, mid, x, v);
    update(R, mid+1, j, x, v);
    tree[no] = tree[L] + tree[R];
}

int main(){
	int m,x,y,op;
	
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
		scanf("%d",&a[i]);
	}
	
	
	build(1,1,n);
	
	rep(i,0,m){
		scanf("%d",&op);
		if(op == 0) { // query no intervalo [x,y]
			scanf("%d%d",&x,&y);
			printf("%d\n", query(1,1,n,x,y));
		}
		else{ // atualiza a posicao x com o valor y (a[x] = y)
			scanf("%d%d",&x,&y);
			update(1,1,n,x,y);
		}
		
	}
	return 0;
}
