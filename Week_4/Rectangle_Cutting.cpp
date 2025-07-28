#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(x, i) for (int i = 0; i < (x); ++i)
#define in(x) for (auto &i : x)
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))
#define print(x)          \
    for (auto i : x)      \
        cout << i << " "; \
    cout << endl;
#define take(x)                 \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())

const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main()
{
    fastio();
    int a, b;
    cin >> a >> b;
    int sp[a + 1][b + 1];
    for (int i = 1; i <= b; i++)
    {
        sp[1][i] = i - 1;
    }
    for (int i = 2; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                sp[i][j] = 0;
                continue;
            }
            int m = 1e9;
            for (int k = 1; k < i; k++)
            {
                m = min(m, sp[k][j] + 1 + sp[i - k][j]);
            }
            for (int k = 1; k < j; k++)
            {
                m = min(m, sp[i][k] + 1 + sp[i][j - k]);
            }

            sp[i][j] = m;
        }
    }
    cout << sp[a][b];

    return 0;
}