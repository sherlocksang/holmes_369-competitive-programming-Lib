
//***********************************************************
//**************kahn's algo *********************************

vector<int>ans;
void toposort(int n){
	
	queue<int > q;
	for (int i = 0; i < n; ++i)
	{
		if(inc[i] == 0)q.push(i);
	}

	while (!q.empty())
	{
		int curr = q.top();
		q.pop();
		ans.push_back(curr);
		for (auto x : vv[curr])
		{
			inc[x]--;
			if(inc[x] == 0){
				q.push(x);
			}
		}
	}


}

//***********************************************************************
//*********************** dfs method ********************************

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}





