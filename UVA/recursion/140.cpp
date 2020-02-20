///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>
#include <boost/algorithm/string.hpp>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define pii                 pair<int, int>
#define mp                  make_pair
#define x                   first
#define y                   second
#define all(v)			    ((v).begin()), ((v).end())
#define sz(v)			    ((int)((v).size()))
#define ll                  long long
#define rep(i,n)            for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)            for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define ms(arr, v)      memset(arr, v, sizeof arr)
typedef vector<vector<char>> vcc;
typedef vector<int> vi;
typedef deque<int> de;

const int N = 30;
bool vis[N];
string all;
bool connect[N][N];

char c, temp, temp2;
string input, str, resStr;
int mx, res;
vector<string> splitted;

void findPermutations(string str)
{
    sort(all(str));	///all(str) : str.begin(), str.end()
    do
    {
        rep(i, str)
        {
            for(int j = 0 ; j < str.size() ; j++)
            {
                if(connect[str[i] - 'A'][str[j] - 'A'])
                {
                    mx = max(mx, abs(i - j));
                }
            }
        }
        if(mx < res)
        {
            resStr = str;
            res = mx;
        }
        mx = -1;
    } while (next_permutation(all(str)));
    rep(is, resStr)
    {
        cout << resStr[is] << " ";
    }
    cout << "-> " << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> input)
    {
        if(input[0] == '#') break;
        //initializations
        mx = -1;
        res = INT_MAX;
        splitted.clear();
        memset(vis, 0, sizeof vis);
        memset(connect, 0, sizeof connect);
        all = "";

        boost::split(splitted, input, boost::is_any_of(";"));
        rep(i, splitted)
        {
            if(!vis[splitted[i][0] - 'A'])
            {
                vis[splitted[i][0] - 'A'] = 1;
                all += splitted[i][0];
            }
            for(int j  = 2 ; j < splitted[i].size() ; j++)
            {
                if(!vis[splitted[i][j] - 'A'])
                {
                    vis[splitted[i][j] - 'A'] = 1;
                    all += splitted[i][j];
                }
                if(!connect[splitted[i][0] - 'A'][splitted[i][j] - 'A'])
                {
                    connect[splitted[i][0] - 'A'][splitted[i][j] - 'A'] = 1;
                    connect[splitted[i][j] - 'A'][splitted[i][0] - 'A'] = 1;
                }
            }
        }
        findPermutations(all);
    }
    return 0;
}
