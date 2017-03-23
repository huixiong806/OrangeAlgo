#include <iostream>
#include <ShortestPathFasterAlgorithm.hpp>
using namespace orange_algo::graph;
using namespace std;
using Graph = AdjacencyListGraph<int,int>;
using SPFAres = SPFA_Result_AllDistance<int>;
int main()
{
	int n, m;
	while (cin >> n >> m,n&&m)
	{
		Graph g = Graph(n+1);
		for (int i = 1; i <= m; ++i)
		{
			int a, b, v;
			cin >> a >> b >> v;
			g.addEdge(a, b, v);
			g.addEdge(b, a, v);
		}
		SPFAres res = SPFA(g, 1,std::less<int>());
		cout<<res[n].distance << endl;
	}
	return 0;
}