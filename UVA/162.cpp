
///notes : 

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>   ///for funtion<>
#include <map>
#include <set>

using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define ll              long long
#define ld              long double
#define rep(i,n)       for(int i=0 ; i<n ; ++i)
#define loop(i, x, n)   for(int i=x ; i<=n ; ++i)

typedef vector<int> ve;
typedef deque<int> de;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> fCard;
    fCard['J'] = 1;
    fCard['Q'] = 2;
    fCard['K'] = 3;
    fCard['A'] = 4;

    while(true)
    {
        int turn = 1, fCount = 0, lastFace = -1;
        de deck;
        de p[2];
        string str;
        loop(i, 1, 52)
        {
            cin >> str;
            if(str == "#")
                return 0;
            p[i%2].push_back(str[1]);
        }

        while(!p[turn].empty())
        {
            char card = p[turn].back();
            deck.push_back(card);
            p[turn].pop_back();
            if(fCard.count(card))
            {
                fCount = fCard[card] + 1;
                lastFace = turn;
                turn = (turn + 1)%2;
            }
            if(fCount)
            {
                --fCount;
                if(!fCount)
                {
                    while(!deck.empty())
                    {
                        p[lastFace].push_front(deck.front());
                        deck.pop_front();
                    }
                    turn = lastFace;
                }
            }
            else
                turn = (turn+1)%2;
        }
        int winner = (turn + 1) %2;
        int num = p[winner].size();

        cout << winner+1 << right << setw(3) << num << endl;
    }
    return 0;
}
