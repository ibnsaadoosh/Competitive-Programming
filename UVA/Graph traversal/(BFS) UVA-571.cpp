
///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

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

typedef vector<int> vi;
typedef deque<int> de;

int a, b, c, t;
set<pii> vis;
queue<pii> q;
set<pair<pii, pii>> par;
set<pair<pii, string>> parStr;

void markVis(pii cc, int a, int b, string str)
{
    pii temp = mp(a, b);
    if(vis.find(temp) == vis.end())
    {
        vis.insert(mp(a, b));
        q.push(mp(a, b));
        par.insert(mp(mp(a, b), cc));
        parStr.insert(mp(mp(a, b), str));
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#else
	#endif
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        bool ok = false;
        vis.clear();
        par.clear();
        parStr.clear();

        q = queue<pii>();

        q.push(mp(0, 0));
        vis.insert(mp(0, 0));
        int dep = 0, sz = 1;
        pii cur;
        for( ; !q.empty() ; dep++, sz = q.size())
        {
            while(sz--)
            {
                cur = q.front(); q.pop();
                if(cur.x == c || cur.y == c)
                {
                    ok = true;
                    break;
                }
                markVis(cur, a, cur.y, "fill A");
                markVis(cur, cur.x, b, "fill B");
                markVis(cur, 0, cur.y, "empty A");
                markVis(cur, cur.x, 0, "empty B");
                int b2 = min(b, cur.x + cur.y);
                int a2 = cur.x - (b2 - cur.y);
                markVis(cur, a2, b2, "pour A B");
                a2 = min(a, cur.x + cur.y);
                b2 = cur.y - (a2 - cur.x);
                markVis(cur, a2, b2, "pour B A");
            }
            if(ok)
            {
                pii d = cur;
                vector<string> path;

                while(dep--)
                {
                    auto it = find_if(parStr.begin(), parStr.end(),
                       [d](const pair<pii, string> & i ) { return i.first.first == d.first && i.first.second == d.second;} );
                    path.pb(it->second);

                    auto it2 = find_if(par.begin(), par.end(),
                       [d](const pair<pii, pii> & i ) { return i.first.first == d.first && i.first.second == d.second;} );
                    d = it2->second;
                }
                reverse(all(path));
                for(auto & i : path) cout << i << endl;
                printf("success\n");
                break;
            }
        }
    }

    return 0;
}
