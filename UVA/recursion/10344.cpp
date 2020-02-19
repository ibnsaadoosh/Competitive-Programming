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
typedef vector<vector<char>> vcc;
typedef vector<int> vi;
typedef deque<int> de;

bool result, enter;
const int N = 10;
int arr[N];
vector<vector<int>> all;
void findPermutations(int arr[], int n)
{
    sort(arr, arr + n);
    do
    {
        vector<int> temp(arr, arr+n);
        all.pb(temp);
    } while (next_permutation(arr, arr + n));
}
void func(vector<int> &arr,int n, int i, bool& result)
{
    if(i == 5)
    {
        if(n == 23)
        {
            result = true;
            return;
        }
        else return;
    }

    func(arr,n + arr[i], i+1, result);
    func(arr,n - arr[i], i+1, result);
    func(arr,n * arr[i], i+1, result);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if(arr[0] == 0) return 0;
        result = false; enter = false;
        all.clear();
        findPermutations(arr, 5);
        for(vector<int> arr : all)
        {
           /* for(int p : arr) cout << p << " ";
            cout << endl;*/
            func(arr,arr[0], 1, result);
            if(result)
            {
                cout << "Possible\n";
                enter = true;
                break;
            }
        }
        if(!enter)
            cout << "Impossible\n";
    }
    return 0;
}
