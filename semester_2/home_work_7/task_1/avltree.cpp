#include "avltree.h"
#include "stdio.h"

AVLTree::~AVLTree()
{
	deleteTree(root);
}

int AVLTree::getHeight()
{
	return height(root);
}

bool AVLTree::isExists(int value)
{
	TreeNode *current = root;
	while (current != nullptr && current->value != value)
	{
		if (current->value > value)
			current = current->left;
		else
			current = current->right;
	}

	return current != nullptr;
}

void AVLTree::deleteTree(TreeNode *node)
{
	if (node == nullptr)
		return;
	if (node->left)
		deleteTree(node->left);
	if (node->right)
		deleteTree(node->right);
	delete node;
}

int AVLTree::height (TreeNode *node)
{
	if (node)
		return node->height;
	return 0;
}

int AVLTree::balanceFactor(TreeNode* node)
{
	return height(node->right)-height(node->left);
}

void AVLTree::findHeight (TreeNode* node)
{
	int heightLeft = height(node->left);
	int heightRight = height(node->right);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

AVLTree::TreeNode* AVLTree::leftRoate (TreeNode *q)
{
	TreeNode *p = q->right;
	q->right = p->left;
	p->left = q;
	findHeight(p);
	findHeight(q);
	return p;
}

AVLTree::TreeNode* AVLTree::rightRoate (TreeNode *p)
{
	TreeNode *q = p->left;
	p->left = q->right;
	q->right = p;
	findHeight(p);
	findHeight(q);
	return q;
}

AVLTree::TreeNode* AVLTree::findMinNode (TreeNode *node)
{
	if (node->left)
		return findMinNode(node->left);
	return node;
}

AVLTree::TreeNode* AVLTree::removeMinNode (TreeNode *node)
{
	if (node->left == nullptr)
		return node->right;
	node->left = removeMinNode(node->left);
	return balanseNode(node);
}

AVLTree::TreeNode* AVLTree::balanseNode (TreeNode *node)
{
	findHeight(node);
	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
			node->right = rightRoate(node->right);
		return leftRoate(node);
	}
	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
			node->left = leftRoate(node->left);
		return rightRoate(node);
	}
	return node;
}

AVLTree::TreeNode* AVLTree::addValue (TreeNode **node, int value)
{
	if (! *node)
		return new TreeNode(value);
	if (value == (*node)->value)
	{
		(*node)->count++;
	}
	else if (value < (*node)->value)
		(*node)->left = AVLTree::addValue(&(*node)->left, value);
	else
		(*node)->right = AVLTree::addValue(&(*node)->right, value);
	return balanseNode((*node));
}

void AVLTree::add(int value)
{
	root = AVLTree::addValue(&root, value);
}

AVLTree::TreeNode* AVLTree::removeNode(TreeNode *node, int value)
{
	if(!node)
	{
		printf("Element not found!\n");
		return nullptr;
	}
	if(value < node->value)
		node->left = removeNode(node->left, value);
	else if(value > node->value)
		node->right = removeNode(node->right, value);
	else
	{
		if (node->count > 1)
			node->count--;
		else
		{
			TreeNode *left = node->left;
			TreeNode *right = node->right;
			delete node;
			if(!right)
				return left;
			TreeNode *min = findMinNode(right);
			min->right = removeMinNode(right);
			min->left = left;
			return balanseNode(min);
		}
	}
	balanseNode(node);
}

void AVLTree::del(int value)
{
	root = removeNode(root, value);
}

void AVLTree::printTreeInc(TreeNode *node)
{
	if(node->left != nullptr)
		printTreeInc(node->left);
	printf("%d  ", node->value);
	if(node->right != nullptr)
		printTreeInc(node->right);
}

void AVLTree::printTreeInc()
{
	printTreeInc(root);
}

void AVLTree::printTreeDec (TreeNode *node)
{
	if(node->right != nullptr)
		printTreeDec(node->right);

	printf("%d  ", node->value);
	if(node->left != nullptr)
		printTreeDec(node->left);
}

void AVLTree::printTreeDec ()
{
	printTreeDec(root);
}

void AVLTree::printDebug(TreeNode *node)
{
	if (node == nullptr)
	{
		printf("null");
	}
	else
	{
		printf("(%d ", node->value);
		printDebug(node->left);
		printf(" ");
		printDebug(node->right);
		printf(")");
	}
}

void AVLTree::printDebug()
{
	printDebug(root);
}

