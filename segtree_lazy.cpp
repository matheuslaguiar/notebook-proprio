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
// UPDATE EM INTERVALO
// EX.: URI 1500

ll tree[4*100010], lazy[4*100010];
int N;

void build(int no, int i, int j){
    if(i>j) return;
    if(i==j){
        tree[no] = 0;
        return;
    }
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    build(L, i, mid);
    build(R, mid+1, j);
    tree[no] = tree[L] + tree[R];
}

void propagate(int no, int i, int j){
    if(!lazy[no]) return;
    tree[no] = tree[no] + (j-i+1) * lazy[no];
    if(i!=j){
        int L = no*2, R = no*2+1;
        lazy[L] += lazy[no];
        lazy[R] += lazy[no];
    }
    lazy[no] = 0;
}

ll query(int no, int i, int j, int a, int b){
    propagate(no, i, j);
    if(i>j || i>b || j<a) return 0;
    if(i>=a && j<=b) return tree[no];
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    return query(L, i, mid, a, b) +
            query(R, mid+1, j, a, b);
}

void update(int no, int i, int j, int a, int b, int v){
    propagate(no, i, j);
    if(i>j || i>b || j<a) return;
    if(i>=a && j<=b){
        lazy[no] = v;
        propagate(no, i, j);
        return;
    }
    int L = no*2, R = no*2+1, mid = (i+j)/2;
    update(L, i, mid, a, b, v);
    update(R, mid+1, j, a, b, v);
    tree[no] = tree[L] + tree[R];
}


int main(){
    ll v;
    int t,c,x,y;
    // t -> no. caso de testes
    // c -> no. de consultas
    cin>>t;
    
    while(t--){
        scanf("%d%d",&N,&c);
    	memset(tree,0,sizeof tree);
    	memset(lazy,0,sizeof lazy);
    	
        build(1, 1, N);
        
        while(c--){
            scanf("%d",&x); // operacao
            if(x == 0){ // atualiza o intervalo [x,y] com o valor v
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1,1,N,x,y,v);
            }
            else{ // consulta [x,y]
                scanf("%lld %lld",&x,&y);
                cout<<query(1,1,N,x,y)<<endl;
            }
        }
    }
    
    return 0;
}
