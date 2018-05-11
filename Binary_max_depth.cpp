#include <algorithm>
#include "alg_common.h"

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		if(root == nullptr)
			return 0;

		int ldepth = maxDepth(root->left);
		int rdepth = maxDepth(root->right);

		return max(ldepth, rdepth) + 1;
	}
}