#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define vi vector<int>
const int MOD = 1e9 + 7;

int main()
{
    fastio();
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (auto &c : a)
        cin >> c;
    sort(a.begin(), a.end());

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++)
    {
        for (int i = a[j]; i <= x; ++i)
        {
            dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }

    cout << dp[x] << '\n';
    return 0;
}