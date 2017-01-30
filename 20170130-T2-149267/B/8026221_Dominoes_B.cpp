#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  set<int> st;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    st.insert(x);
  }
  int dd = n - (int)st.size();
  if (dd & 1) dd ++;
  printf("%d\n", n - dd);
  return 0;
}
