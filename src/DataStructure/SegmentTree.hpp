#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP
#include<vector>
//TODO: thinking how to make it universal
namespace orange_algo
{
	namespace data_structure
	{
		template<class Node>
		class SegmentTree_QueryResult
		{
		public:
		};
		template<class Node>
		class SegmentTree
		{
		private:
			int size;
			std::vector<Node> tree;
		public:
			template<int Type, class PushUpFunction, class PushDownFunction>
			void update(size_t root, size_t curL, size_t curR, size_t TargetL, size_t TargetR)
			{

			}
			SegmentTree(int _size) :
				size(_size)
			{
				tree.resize(_size)
			}
			virtual ~SegmentTree() {}
		};
	}
}
#endif // SEGMENT_TREE_HPP