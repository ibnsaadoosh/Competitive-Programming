
/*
notes :
 reading time :()   thinking time : ()  coding time : ()    debugging time : ()
 total time : ()
catagory : DFS
 */

#include <bits/stdtr1c++.h>

using namespace std;

#define pb              push_back
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define ld              long double
#define rep(i,n)        for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)        for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)   for(int i=x ; (int)i<=n ; i++)
#define isPowerOfTwo(s) (!(s & (s-1)))

typedef vector<int> vi;
typedef deque<int> de;
typedef map<int, int> imap;
typedef map<char, int> cmap;
typedef map<string, int> strmap;

const int MAX  = 1005;
vector<int> adj[MAX];
bool vis[MAX];
bool vis2[MAX];
int n, m, ctr;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ctr = 0;
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    lp(i, m)
    {
        int from, to;
        cin >> from >> to;
        if(!vis[to] || !vis2[from])
        {
            adj[from].pb(to);
            vis2[from] = 1;     vis[to] = 1;
            ctr++;
        }
    }
    cout << ctr << "\n";
    loop(i, 1, n)
    {
        if(adj[i].size() > 0)
        {
            lp(j, sz(adj[i]))
                cout << i << " " << adj[i][j] << "\n";
        }
    }

}
