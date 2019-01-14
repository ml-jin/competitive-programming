// Segment Tree
// if n = 100000, MAXN should be 1<<17 or larger
// if n = 200000, MAXN should be 1<<18 or larger
const int MAXN;

struct {
  int N;
  vector<long long> dat = vector<long long>(2*MAXN);

  void init(int n) {
    N = 1;
    while(N < n) N *= 2;
    for(int i=0; i<2*N-1; i++) {
      dat[i] = LONG_MAX;
    }
  }

  // update k-th element
  void update(int k, long long a) {
    k += N-1;
    dat[k] = a;
    while(k > 0) {
      k = (k-1)/2;
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
  }

  // return min[a, b)
  long long query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  long long query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return LONG_MAX;
    if (a <= l && r <= b) return dat[k];
    int m = (l+r)/2;
    return min(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
  }
};