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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    take(a);
    rep(m, i)
    {
        cin >> b[i];
    }
    int l[n + 1][m + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {

                l[i][j] = 1 + l[i - 1][j - 1];
            }
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }

    cout << l[n][m] << endlc;
    vi st;
    int s = l[n][m];
    int k1 = n;
    int k2 = m;

    while (s)
    {
        for (int i = k1 - 1; i >= 0; i--)
        {
            for (int j = k2 - 1; j >= 0; j--)
            {
                if (l[i+1][j+1] == s && a[i] == b[j])
                {
                    s--;
                    k1 = i;
                    k2 = j;
                    st.push_back(a[i]);
                }
            }
        }
    }
    reverse(all(st));
    print(st);

    return 0;
}