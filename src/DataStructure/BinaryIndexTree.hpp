/**
* Birnary Index Tree manual
* Operation        Function		    Time Complexity   Range
* size()     return the size of BIT		 O(1)          ~
* resize(x)  resize BIT,new size is x	 O(1)         x>=0
* add(i,v)   add v to index i		     O(logn)    0<=i<size
* sum(i)     return the sum of[0,i]	     O(logn)    0<=i<size
* sum(l,r)   return the sum of[l,r]	     O(logn)    0<=l<=r<size
* a[i]       return the sum of[0,i]		 O(logn)    0<=i<size
* a[i]+=v    add v to index i			 O(logn)    0<=i<size
* a[i]-=v    sub v from index i			 O(logn)    0<=i<size
**/
#ifndef BINARY_INDEX_TREE_HPP
#define BINARY_INDEX_TREE_HPP
#include<vector>
namespace orange_algo
{
	namespace data_structure 
	{
		template<typename Type>
		class BinaryIndexTree
		{
		private:
			size_t mSize;
			std::vector<Type> mArray;
		protected:
			struct BinaryIndexTree_Node
			{
				BinaryIndexTree_Node(BinaryIndexTree& bit, size_t pos) :
					mBIT(bit), mPos(pos) {}
				const BinaryIndexTree_Node operator +=(Type value)
				{
					mBIT.add(mPos, value);
					return *this;
				}
				const BinaryIndexTree_Node operator -=(Type value)
				{
					mBIT.add(mPos, -value);
					return *this;
				}
				operator Type()
				{
					return mBIT.sum(mPos);
				}
			private:
				BinaryIndexTree& mBIT;
				size_t mPos;
			};
			int lowbit(int num)
			{
				return num&(~num + 1);
			}
		public:
			BinaryIndexTree() {}
			BinaryIndexTree(size_t size) :
				mSize(size)
			{
				mArray.resize(mSize);
			}
			virtual ~BinaryIndexTree() {}
			virtual const size_t size()
			{
				return mSize;
			}
			virtual void resize(size_t size)
			{
				mSize = size;
				mArray.resize(size);
			}
			virtual void add(int index, Type value)
			{
				for (; index < mSize; index += lowbit(index + 1))
					mArray[index] += value;
			}
			virtual Type sum(int index)
			{
				Type answer = Type();
				for (; index >= 0; index -= lowbit(index + 1))
					answer += mArray[index];
				return answer;
			}
			virtual Type sum(int left, int right)
			{
				return sum(right) - sum(left - 1);
			}
			virtual BinaryIndexTree_Node operator[](size_t pos)
			{
				return BinaryIndexTree_Node(*this, pos);
			}
		};
	}
}
#endif// BINARY_INDEX_TREE_HPP