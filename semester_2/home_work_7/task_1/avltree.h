#pragma once

class AVLTree
{
	public:
		AVLTree() : root(nullptr) {}
		~AVLTree();
		void add(int value);
		void del(int value);
		bool isExists(int value);
		/// returns height
		int getHeight();
		/// prints your tree in increasing order
		void printTreeInc();
		/// prints your tree in decreasing order
		void printTreeDec ();
		/// prints tree as it realy is
		void printDebug();
	private:
		struct TreeNode
		{
			int value;
			int height;
			int count;
			TreeNode *left;
			TreeNode *right;

			TreeNode(int k)
			{
				value = k;
				left = nullptr;
				right = nullptr;
				height = 1;
				count = 1;
			}
		};
		/// recursion functions:
		void deleteTree(TreeNode *node);
		int height (TreeNode *node);
		int balanceFactor(TreeNode* node);
		void findHeight (TreeNode* node);
		TreeNode* leftRoate (TreeNode *q);
		TreeNode* rightRoate (TreeNode *p);
		TreeNode* findMinNode (TreeNode *node);
		TreeNode* removeMinNode (TreeNode *node);
		TreeNode* balanseNode (TreeNode *node);
		TreeNode* addValue (TreeNode **node, int value);
		TreeNode* removeNode(TreeNode *node, int value);
		void printTreeInc(TreeNode *node);
		void printTreeDec (TreeNode *node);
		void printDebug(TreeNode *node);

		TreeNode *root;
};


