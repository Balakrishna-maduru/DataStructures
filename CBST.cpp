#include<stdlib.h>
#include<stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct Node {
	int data;
	Node* left;
	Node* right;
};


Node* GetNewNode(int data) {
	struct Node* node = (Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;

}

Node* Insert(Node* root, int data) {
	struct Node* node = NULL;
	node = GetNewNode(data);
	if (root == NULL) { 
		root = node; 
	}
	else if (data<= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(Node* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);

}

int FindMinUsingRecursion(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty.");
		return -1;
	}
	else if (root->left == NULL)
		return root->data;
	return FindMinUsingRecursion(root->left);
}

int FindMaxUsingRecursion(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty.");
		return -1;
	}
	else if (root->right == NULL)
		return root->data;
	return FindMaxUsingRecursion(root->right);
}


int FindMin(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty.");
		return -1;
	}
	while (root->left != NULL)
		root = root->left;
	return root->data;
}

int FindMax(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty.");
		return -1;
	}
	while (root->right != NULL)
		root = root->right;
	return root->data;
}

int FindHeight(Node* root) {
	if(root == NULL) return -1;
	return MAX(FindHeight(root->left), FindHeight(root->right)) + 1;
}

/*
void LevelOrder(Node* root) {
	if (root == NULL) return;
	queue<Node*> Q;
	Q.push(root)
	while (!Q.empty()) {
		Node* current = Q.front();
		printf("%d", current->data);
		if (current->left != NULL) Q.push(current.left);
		if (current->right != NULL) Q.push(current.right);
		Q.pop();
	}
}
*/

void Preorder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

void Postorder(Node* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}

bool IsSubtreeLesser(Node* root, int value) {
	if (root == NULL) return true;
	if (root->data <= value &&
		IsSubtreeLesser(root->left, value) &&
		IsSubtreeLesser(root->right, value)) return true;
	else return false;
}
bool IsSubtreeGreater(Node* root, int value) {
	if (root == NULL) return true;
	if (root->data > value &&
		IsSubtreeGreater(root->left, value) &&
		IsSubtreeGreater(root->right, value)) return true;
	else return false;
}

bool IsBinaraySearchTree(Node* root) {

	if (root == NULL) return true;
	if (IsSubtreeLesser(root->left, root->data) &&
		IsSubtreeGreater(root->right, root->data) &&
		IsBinaraySearchTree(root->left) &&
		IsBinaraySearchTree(root->right))
		return true;
	else return false;
}

Node* FindMinToDelete(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

Node* Delete(Node* root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
			return root;
		}
		else if (root->left == NULL) {
			struct Node* temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) {
			struct Node* temp = root;
			root = root->left;
			free(temp);
		}
		else {
			struct Node* temp = FindMinToDelete(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

Node* Find(Node* root, int data) {
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return Find(root->right, data);
	else return Find(root->left, data);
}

Node* GetSuccesor(Node* root, int data) {
	Node* current = Find(root, data);
	if(current == NULL) return NULL;
	if (current->right != NULL) {
		return FindMinToDelete(current->right);
	}
	else {
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}

}

int main() {
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 8);
	root = Insert(root, 4);
	root = Insert(root, 25);
	root = Insert(root, 30);
	int number = 25;
	if (Search(root, number) == true)
		printf("Record found in tree :%d\n", number);
	else
		printf("Record not found in tree :%d\n", number);

	printf("Find min and max\n");
	printf("Min :%d\n", FindMin(root));
	printf("Max :%d\n", FindMax(root));

	printf("Find min and max using Recursion\n");
	printf("Min :%d\n", FindMinUsingRecursion(root));
	printf("Max :%d\n", FindMaxUsingRecursion(root));

	printf("Height of the tree: %d\n", FindHeight(root));
//	LevelOrder(root);
	printf("\nPreorder: ");
	Preorder(root);
	printf("\nInorder: ");
	Inorder(root);
	printf("\nPostorder: ");
	Postorder(root);
	printf("\n");
	if (IsBinaraySearchTree(root) == true)
		printf("It's a binary tree\n");
	else
		printf("Its not a binary tree\n");

	root = Delete(root, 20);
	printf("\nInorder after delete: ");
	Inorder(root);
	printf("\nGet successor for 10 : ");
	Node* node = GetSuccesor(root, 10);
	printf("%d\n", node->data);
	
	return 0;
}
