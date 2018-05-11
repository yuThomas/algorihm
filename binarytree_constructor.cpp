#include <iostream>
#include <stdexcept>

/*
	根据二叉树的前序遍历和中序遍历构造原始二叉树
*/

using std::cout;
using std::endl;
using std::logic_error;

struct BinaryNode
{
	int m_value;
	BinaryNode *m_left;
	BinaryNode *m_right;
	BinaryNode(int value):m_value(value),m_left(NULL),m_right(NULL){}
};

class BinaryTreeConstructor
{
public:
	static BinaryNode* Construct(int *preorder, int *inorder, int length);
	static void Destruct(BinaryNode *root);
	static void PrintBinaryTree(const BinaryNode *root);
private:
	static BinaryNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);
	static void ConstructError(BinaryNode *node);
};

inline void BinaryTreeConstructor::ConstructError(BinaryNode *node)
{
	delete node;
	throw logic_error("Invalid Input");
}

BinaryNode* BinaryTreeConstructor::Construct(int *preorder, int *inorder, int length)
{
	if( preorder==NULL || inorder==NULL || length<=0 )
		return NULL;

	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryNode* BinaryTreeConstructor::ConstructCore(
	int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	int rootValue = startPreorder[0];
	BinaryNode *root = new BinaryNode(rootValue);	

	if( startPreorder == endPreorder )
	{
		if( startInorder == endInorder && *startPreorder == *startInorder )	
			return root;
		else
			ConstructError(root);
	}

	//中序查找根节点
	int *rootInorder = startInorder;
	while( *rootInorder != rootValue && rootInorder<=endInorder )
		++rootInorder;

	if( rootInorder == endInorder && *rootInorder != rootValue )
		ConstructError(root);

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if( leftLength>0 )
	{
		root->m_left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if( leftLength < endPreorder - startPreorder )
	{
		root->m_right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}

	return root;
}

void BinaryTreeConstructor::Destruct(BinaryNode *root)
{
	if( root != NULL )
	{
		Destruct(root->m_left);
		Destruct(root->m_right);
		delete root;
	}
}

void BinaryTreeConstructor::PrintBinaryTree(const BinaryNode *root)
{
	if( root != NULL )
	{
		PrintBinaryTree(root->m_left);
		cout << root->m_value << endl;
		PrintBinaryTree(root->m_right);
	}
}


int main(int argc, char **argv)
{
	int preorder[] = {1,2,4,8,5,3,7,9};
	int inorder[] = {8,4,2,5,1,3,9,7};
	BinaryNode *root = BinaryTreeConstructor::Construct(preorder, inorder, sizeof(preorder)/sizeof(preorder[0]));
	BinaryTreeConstructor::PrintBinaryTree(root);
	BinaryTreeConstructor::Destruct(root);

	return 0;
}
