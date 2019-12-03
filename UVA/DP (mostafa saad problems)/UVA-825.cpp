
///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define mp                  make_pair
#define x                   first
#define y                   second
#define all(v)			    ((v).begin()), ((v).end())
#define sz(v)			    ((int)((v).size()))
#define ll                  long long
#define rep(i,n)            for(int i=0 ; i<sz(n) ; i++)
#define repit(it, m)        for(it = m.begin(); it!=m.end(); it++)
#define reprit(it, m)       for(it = rbegin(); it!=rend() ; it++)
#define lp(i, n)            for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define ms(arr, v)      memset(arr, v, sizeof arr)

typedef vector<int> vi;
typedef deque<int> de;

int q, n , m;
int unsafe[105][105];

bool valid(int r, int c)
{
    return !(r > n || c > m || unsafe[r][c] == 1);
}

int ctr;
int mem[105][105];

int solve(int r, int c)
{
    if(!valid(r, c)) return 0;
    if(mem[r][c] != -1) return mem[r][c];
    if(r == n && c == m) return mem[r][c] = 1;
    ctr = solve(r, c+1) + solve(r+1, c);
    return mem[r][c] = ctr;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    int nn, mm, qq;
    cin >> q;
    while(q--)
    {
        ms(unsafe, -1);
        ms(mem, -1);
        cin >> n >> m;
        nn = n; mm = m; qq = q;
        lp(i, n)
        {
            int x, y;
            cin >> x;
            string str;
            getline(cin, str);
            stringstream sin(str);
            while(sin >> y)
                unsafe[x][y] = 1;
        }
        //cout << dp(1,1) << endl;
        int res = 0;
        res = solve(1, 1);
        cout << res << endl;
        if(q) cout << endl;
    }
}

