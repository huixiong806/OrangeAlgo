#include <vector>
#include <queue>
#include <functional>
#include <AdjacencyListGraph.hpp>
namespace orange_algo
{
	namespace graph
	{
		template <class EdgeType>
		class SPFA_Result_SingleDistance
		{
		public:
			EdgeType distance;
			bool visited;
			SPFA_Result_SingleDistance() { distance = visited = 0; }
			SPFA_Result_SingleDistance(bool _visited, EdgeType _distance) :
				distance(_distance),
				visited(_visited)
			{
			}
		};
		template <class EdgeType>
		class SPFA_Result_SingleDistanceAndPath
		{
		private:
		public:
		};
		template <class EdgeType>
		//visited,reslut
		class SPFA_Result_AllDistance:public std::vector<SPFA_Result_SingleDistance<EdgeType>>
		{
		public:
			SPFA_Result_AllDistance() {}
			SPFA_Result_AllDistance(size_t _size)
			{
				this->resize(_size);
			}
			SPFA_Result_SingleDistance<EdgeType> getSingleResult(size_t index)
			{
				return (*this)[index];
			}
		};
		template <class NodeType, class EdgeType, class Compare>
		SPFA_Result_AllDistance<EdgeType> SPFA(const AdjacencyListGraph<NodeType, EdgeType>& graph, size_t startNodeIndex,Compare compare = std::less<EdgeType>)
		{
			std::queue<size_t> queue;
			std::vector<bool>inQueue;
			const std::vector<std::forward_list<std::pair<size_t, EdgeType>>>& edge = graph.adjacencyList();
			SPFA_Result_AllDistance<EdgeType> result(graph.getNodeSize());
			inQueue.resize(graph.getNodeSize());
			queue.push(startNodeIndex);
			result[startNodeIndex] = SPFA_Result_SingleDistance<EdgeType>(true,EdgeType());
			while (!queue.empty())
			{
				size_t curNodeIndex = queue.front();
				queue.pop();
				inQueue[curNodeIndex] = false;
				for (auto& nextNode: edge[curNodeIndex])
				{
					const size_t& nextNodeIndex = nextNode.first;
					const EdgeType& distanceBetweenNowAndNext = nextNode.second;
					//if 0->now + now->nex < 0->nex,update 0->nex
					if (result[nextNodeIndex].visited==false||compare(result[curNodeIndex].distance + distanceBetweenNowAndNext,result[nextNodeIndex].distance))
					{
						result[nextNodeIndex].distance = result[curNodeIndex].distance + distanceBetweenNowAndNext;
						result[nextNodeIndex].visited = true;
						if (inQueue[nextNodeIndex] == false)
						{
							queue.push(nextNodeIndex);
							inQueue[nextNodeIndex] = true;
						}
					}
				}
			}
			return result;
		}
		template <class NodeType, class EdgeType, class Compare>
		SPFA_Result_SingleDistance<EdgeType> SPFA(AdjacencyListGraph<NodeType, EdgeType>& graph, size_t startNodeIndex,size_t targetNodeIndex, Compare compare = std::less<EdgeType>)
		{
			return SPFA(graph, startNodeIndex, compare).getSingleResult(targetNodeIndex);
		}
	}
}