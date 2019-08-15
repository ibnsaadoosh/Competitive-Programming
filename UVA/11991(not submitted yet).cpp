
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

const int MAX  = 100005;
vector<int> adj[MAX];
int arr[MAX];
int n, m;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> n >> m)
    {
        loop(i, 1, n)
        {
            int num;
            cin >> arr[i];
            adj[arr[i]].pb(i);
        }

        while(m--)
        {
            int occur, num;
            cin >> occur >> num;
            cout << adj[num][occur-1] << "\n";
        }
        loop(i, 1, n)
        {
            adj[arr[i]].clear();
        }
    }

}
