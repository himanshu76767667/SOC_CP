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
    ll n;
    cin >> n;
    ll ways[n][n];
    rep(n, i)
    {
        rep(n, j)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                ways[i][j] = 0;
            }
            else if (x == '.')
            {
                if (i == 0 && j == 0)
                {
                    ways[i][j] = 1;
                }
                else if (i == 0)
                {
                    ways[i][j] = ways[i][j - 1];
                }
                else if (j == 0)
                {
                    ways[i][j] = ways[i - 1][j];
                }
                else
                {
                    ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
                }
            }
            ways[i][j]%=MOD;
          
        }
    }
    cout << ways[n - 1][n - 1];

    return 0;
}