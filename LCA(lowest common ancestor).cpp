
//************************************************
/// DAY - 6.___#Q-34 lowest common Ancestor
///*************************************************
const int nax = 1005;
std::vector<std::vector<int>> vv(nax);
int level[nax] ,parent[nax];
int maxN = 10;
int LCA[nax][12];

int n;
// Run this dfs to store level for each vertex and there parent

void dfs(int v , int par , int lev){

	// this is tree we dont need vis array just keep par
	level[v] = lev;
	parent[v] = par;
	// we dont need parent array just keep in LCA[v][0]
	LCA[v][0] = par;

	for(auto x : vv[v]){
		if(x == par) continue;
		else{
			dfs(x , v , lev+1);
		}
	}
}

void init(){
	dfs(1, -1 , 0);

	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= maxN; ++i)
		{
			// fill one colume all element
			if(LCA[j][i-1] != -1){
				int val = LCA[j][i-1];
				LCA[j][i] = LCA[val][i-1];
			}
		}
	}

}

int LCA_vertex(int a , int b){
	if(level[a] > level[b]) swap(a,b);

	int d = level[b] - level[a];

	while (d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];

		d = d - (1<<i);

	}

	if(a == b) return a;

	for (int i = maxN; i >= 0; --i)
	{
		if(LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}

	return parent[a];
}

//int distance_Between_twoNode_InLognTime(int a,int b)

void test_case(){
	cin>>n;
	for (int i = 0; i < nax; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			LCA[i][j] = -1;
		}
	}
	for (int i = 1; i < n; ++i)
	{
		int a,b;cin>>a>>b;
		vv[a].push_back(b);
		vv[b].push_back(a);
	}

	init();

	//distance_Between_twoNode_InLognTime

	int q;cin>>q;
	while (q--)
	{
		int a,b;cin>>a>>b;
		int x = LCA_vertex(a,b);
		cout<<level[a]-level[x] + level[b]-level[x]<<"\n";

	//	error(level[a] , level[b] , level[x]);
	//	error(x);
	}
}
