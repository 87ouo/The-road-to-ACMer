#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 200005;
int a[N];
char s[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%s", s + 1);
    int j;
    for (int i = 1; i < n; i = j)
    {
        j = i;
        while (j < n && s[i] == s[j]) j++;
        if (s[i] == '1') sort(a + i, a + j + 1);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != i) return puts("NO"), 0;
    puts("YES");
    return 0;
}
