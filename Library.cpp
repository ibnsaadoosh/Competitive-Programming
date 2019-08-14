
const double PI = 3.14159265358979323846;

///gcd
int gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b ); }


///fining all dividors of a number g
vector<int> dividors;
for(int i = 1 ; i <= g/i ; i++)
    {
        if(g%i == 0)
        {
            dividors.push_back(i);
            if(g/i != i) dividors.push_back(g/i);;
        }
    }


///Ceil division
ll ceilDiv(ll a, ll b)
{
    return (a + b - 1)/b;
}


void dfs(int node)
{
	visited[node] = true;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (!visited[child])	// To avoid cyclic behavior
			dfs(child);
	}

	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}

bool isSingleComponent() {
    //because we use 'vis' global variable, we need to clear it before we start
    //if you only call this function once, you don't need to clear it (because it is default initalized to false)
 
    memset(vis, 0, sizeof vis); //function that clears array, use for-loop if you want.
 
    //Start DFS from any node you want.
    DFS(1);
 
    //one-based loop because input is one-based
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false)
            return false;
    }
    return true;
}


void dfs_EdgeClassification(int node)
{
	start[node] = timer++;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (start[child] == -1)	// Not visited Before. Treed Edge
			dfs_EdgeClassification(child);
		else {
			if(finish[child] == -1)// then this is ancestor that called us and waiting us to finish. Then Cycle. Back Edge
				anyCycle = 1;
			else if(start[node] < start[child])	// then you are my descendant
				;	// Forward Edge
			else
				;	// Cross Edge
		}
	}

	finish[node] = timer++;
}


int cnt = 0;
void cntReachalbleCells(int r, int c)
{
    if( !valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
		return;		// invalid position or block position


	vis[r][c] = 1;	// we just visited it, don't allow any one back to it
	cnt++;

	// Try the 4 neighbor cells
	cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
}
