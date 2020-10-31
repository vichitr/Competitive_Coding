#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int ans = 0;

void solve(int i, long long x, long long y, long long z,int bx, int by, int bz) {
  if (i == n) {
    ans += (x == y && x == z && bx && by && bz );
    return;
  }
  solve(i + 1, x + a[i], y, z, 1,by,bz);
  solve(i + 1, x, y + a[i], z,bx,1,bz);
  solve(i + 1, x, y, z + a[i],bx,by,1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve(0, 0, 0, 0,0,0,0);
  cout << ans << '\n';
  return 0;
}
