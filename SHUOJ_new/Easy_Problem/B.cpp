#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int a[100];
    Tcase
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            a[i] = s[i] - '0';
        for (int i = 0; i < s.length(); i++)
            ans = (ans * 10 + a[i]) % 13;
        if (ans)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
