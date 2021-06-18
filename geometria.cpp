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
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
  point operator*(double t) { return point(x * t, y * t); }
  point operator/(double t) { return point(x / t, y / t); }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x))
      return t;
    return ::cmp(y, q.y);
  }
  bool operator==(point q) const { return cmp(q) == 0; };
  bool operator!=(point q) const { return cmp(q) != 0; };
  bool operator<(point q) const { return cmp(q) < 0; };
};
ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")";
}
#define vec(a, b) (b - a)
typedef vector<point> polygon;

double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double collinear(point a, point b, point c) {
  return cmp(cross(b - a, c - a)) == 0;
}
// retorna 1 se R esta a esquerda do vetor P->Q, -1 se estiver a
// direita. 0 se P, Q e R forem colineares
int ccw(point p, point q, point r) { return cmp(cross(q - p, r - p)); }

// Rotaciona um ponto em relacao a origem em 90 graus sentido
// anti-horario
point RotateCCW90(point p) { return point(-p.y, p.x); }
// Rotaciona um ponto em relacao a origem em 90 graus sentido horario
point RotateCW90(point p) { return point(p.y, -p.x); }

// Rotaciona um ponto P em A graus no sentido anti-horario em relacao a
// origem; Para rotacionar no sentido horario, basta A ser negativo
point RotateCCW(point p, double a) {
  a = (a / 180.0) * acos(-1.0); // convertendo para radianos
  return point(p.x * cos(a) - p.y * sin(a),
               p.x * sin(a) + p.y * cos(a));
}
// Rotaciona P em A graus em relacao a Q.
point RotateCCW(point p, point q, double a) {
  return RotateCCW(p - q, a) + q;
}
// Tamanho ou norma de um vetor
double abs(point u) { return sqrt(dot(u, u)); }
// Projeta o vetor A sobre a direcao do vetor B
point project(point a, point b) { return b * (dot(a, b) / dot(b, b)); }
// Retorna a projecao do ponto P sobre reta definida por [A,B]
point projectPointLine(point p, point a, point b) {
  return p + project(p - a, b - a);
}
// Retorna o angulo que p faz com +x
double arg(point p) { return atan2(p.y, p.x); }
// Retorna o angulo entre os vetores AB e AC
double arg(point b, point a, point c) {
  point u = b - a, v = c - a;
  return atan2(cross(u, v), dot(u, v));
}

//////////////////////////////////////////////////////////////////////
/////////////////////////  Segmentos, Retas  /////////////////////////
//////////////////////////////////////////////////////////////////////

// Determina se P esta entre o segmento fechado [A,B], inclusive
bool between(point p, point a, point b) {
  return collinear(p, a, b) && dot(a - p, b - p) <= 0;
}

/* Distancia de ponto P para reta que passa por [A,B]. Armazena em C
 * (por ref) o ponto projecao de P na reta. */
double distancePointLine(point p, point a, point b, point &c) {
  c = projectPointLine(p, a, b);
  return fabs(cross(p - a, b - a)/abs(a - b)); // or abs(p-c);
}

/* Distancia de ponto P ao segmento [A,B]. Armazena em C (por ref) o
 * ponto de projecao de P em [A,B]. Se este ponto estiver fora do
 * segmento, eh retornado o mais proximo. */
double distancePointSeg(point p, point a, point b, point &c) {
  if (dot((b - a),(p - a)) <= 0) {
    c = a;
    return abs(a - p);
  }
  if (dot((a - b),(p - b)) <= 0) {
    c = b;
    return abs(b - p);
  }

  c = projectPointLine(p, a, b);
  return fabs(cross(p - a, b - a)/abs(a - b)); // or abs(p-c);
}

// Determina se os segmentos [A, B] e [C, D] se tocam
bool seg_intersect(point a, point b, point c, point d) {
  int d1, d2, d3, d4;
  d1 = ccw(c, a, d);
  d2 = ccw(c, b, d);
  d3 = ccw(a, c, b);
  d4 = ccw(a, d, b);
  if (d1 * d2 == -1 && d3 * d4 == -1)
    return true;
  if (d1 == 0 && between(c, a, d))
    return true;
  if (d2 == 0 && between(c, b, d))
    return true;
  if (d3 == 0 && between(a, c, b))
    return true;
  if (d4 == 0 && between(a, d, b))
    return true;
  return false;
}

// Encontra a interseccao das retas (p-q) e (r-s) assumindo que existe
// apenas 1 intereccao. Se for entre segmentos, verificar se
// interseptam primeiro.
point line_intersect(point p, point q, point r, point s) {
  point a = q - p, b = s - r, c = point(cross(p, q), cross(r, s));
  double x = cross(point(a.x, b.x), c);
  double y = cross(point(a.y, b.y), c);
  return point(x, y) / cross(a, b);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(point a, point b, point c, point d) { //! Nao
                                                         //! testado
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(point a, point b, point c,
                    point d) { //! Nao testado
  return LinesParallel(a, b, c, d) &&
         fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}

//////////////////////////////////////////////////////////////////////
////////////////////////////  Triangulos  ////////////////////////////
//////////////////////////////////////////////////////////////////////

bool pointInTriangle(point p, point a, point b, point c) {
	int s1,s2,s3;
	s1 = ccw(a,b,p);
	s2 = ccw(b,c,p);
	s3 = ccw(c,a,p);
	if(s1 == s2 && s2 == s3) // dentro 
		return 1;
	else if(s1*s2 == -1 || s1*s3 == -1 || s2*s3 == -1) // fora
		return 0;
	else // na borda
		return 1;
}

// Heron's formula - area do triangulo(a,b,c) -1 se nao existe
double area_heron(double a, double b, double c) {
  if (a < b)
    swap(a, b);
  if (a < c)
    swap(a, c);
  if (b < c)
    swap(b, c);
  if (a > b + c)
    return -1;
  return sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) *
              (a + (b - c)) / 16.0);
}

//////////////////////////////////////////////////////////////////////
////////////////////////////  Circulos  //////////////////////////////
//////////////////////////////////////////////////////////////////////

bool pointInCircle(point p, point c, double radius) {
  // Todo
}

/*Dado dois pontos (A, B) de uma circunferencia e seu raio R, eh
 * possivel obter seus possiveis centros (C1 e C2). Para obter o outro
 * centro, basta inverter os paramentros */
bool circle2PtsRad(point a, point b, double r, point &c) {
  point aux = a - b;
  double d = dot(aux, aux);
  double det = r * r / d - 0.25;
  if (det < 0.0)
    return false;
  double h = sqrt(det);
  c.x = (a.x + b.x) * 0.5 + (a.y - b.y) * h;
  c.y = (a.y + b.y) * 0.5 + (b.x - a.x) * h;
  return true;
}

//	Menor distancia entre dois pontos numa esfera de raio r
//	lat = [-90,90]; long = [-180,180]
double spherical_distance(double lt1, double lo1, double lt2,
                          double lo2, double r) {
  double pi = acos(-1);
  double a = pi * (lt1 / 180.0), b = pi * (lt2 / 180.0);
  double c = pi * ((lo2 - lo1) / 180.0);
  return r * acos(sin(a) * sin(b) + cos(a) * cos(b) * cos(c));
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////  Planos  ///////////////////////////////
//////////////////////////////////////////////////////////////////////

// Distancia entre (x,y,z) e plano ax+by+cz=d
double distancePointPlane(double x, double y, double z, double a,
                          double b, double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}


int main(){
	
	return 0;
}













