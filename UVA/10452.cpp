
/*
notes :
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

int m, n;
int r, c;
char maze[10][10];
bool vis[10][10];
deque<string> result;


bool valid(char a) {return (a == 'I' || a == 'E' || a == 'H' || a == 'O' ||  a == 'V' || a == 'A' || a == '@' || a == '#');}

void floodFill(int r, int c, string direction)
{
    if(!valid(maze[r][c]) || vis[r][c] == 1) return;

    result.pb(direction);
    vis[r][c] = 1;

    if(maze[r][c] == '#') return;

    floodFill(r, c-1, "left");
    floodFill(r, c+1, "right");
    floodFill(r-1, c, "forth");
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int x;
    cin >> x;
    while(x--)
    {
        fill(*vis, * vis + 10*10, 0);
        fill(*maze, *maze + 10*10 , '/');
        cin >> m >> n;
        lp(i, m)
            lp(j, n) cin >> maze[i][j];
        r = m-1;
        lp(i, n)
            if(maze[m-1][i] == '@') c = i;

        floodFill(r, c, "base");
        result.pop_front();
        rep(i, result)
        {
            if(i == sz(result) - 1) cout << result[i];
            else cout << result[i] << " ";
        }
        cout << "\n";

        result.clear();
    }
}
