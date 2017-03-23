#include<vector>
#include<forward_list>
namespace orange_algo
{
	namespace graph
	{
		template<class EdgeType>
		using AdjacencyList = std::vector<std::forward_list<std::pair<size_t, EdgeType>>>;
		template<class NodeType, class EdgeType>
		class AdjacencyListGraph
		{
		private:
			AdjacencyList<EdgeType> edge;
			std::vector<NodeType> node;
			size_t edgeSize;
		public:
			AdjacencyListGraph(){}
			AdjacencyListGraph(size_t nodeSize_)
			{
				node.resize(nodeSize_);
				edge.resize(nodeSize_);
			}
			//TODO:增加接口
			void addEdge(size_t u, size_t v, EdgeType value)
			{
				edge[u].push_front(std::make_pair(v,value));
				edgeSize++;
			}
			void addNode(const NodeType& node_)
			{
				node.push_back(node_);
				edge.push_back(std::forward_list<std::pair<size_t,EdgeType>>());
			}
			const size_t getNodeSize()const
			{
				return node.size();
			}
			const size_t getEdgeSize()const
			{
				return edgeSize;
			}
			const AdjacencyList<EdgeType>& adjacencyList()const
			{
				return edge;
			}
			virtual ~AdjacencyListGraph(){}
		};
	}
}