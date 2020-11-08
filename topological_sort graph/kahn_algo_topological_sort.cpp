//********topological sort *********///
///*****kahn algorithm ************
const int nax = 1000005;
vector<vector<int> > gr(nax);
int vis[nax];
int in[nax];
vector<int> ans;
int n,m;
void kahn_algo(){

	priority_queue<int, vector<int>, greater<int> > q;	 // first element contain smallest 
	for (int i = 0; i < n; ++i)
	{
		
		if(in[i] == 0) {
			q.push(i);
		    
		}
	}
	
	while (!q.empty())
	{
		int next = q.top();
		ans.push_back(next+1);
		
		q.pop();
		for (int i = 0; i < gr[next].size(); ++i)
		{
			int child = gr[next][i];
			in[child]--;
			
			if(in[child] == 0 ){
				
				q.push(child);
				
			}
			
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

	for (int i = 0; i < m; ++i)
	{
		int a,b;cin>>a>>b;
		a--;
		b--;
		gr[a].push_back(b);// because graph is directed
		in[b]++;

	}
	kahn_algo();
	
	if(ans.size() != n){ // check if contain cycle 
		cout<<"Sandro fails.\n";
		return 0;
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		std::cout << ans[i]  << " ";
	}

	return 0;
}
