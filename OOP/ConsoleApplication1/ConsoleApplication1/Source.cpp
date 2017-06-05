#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;

struct node
{
	node* left;
	node* right;
	int info;
};

node* createNewNode(int info)
{
	node* aux = new node;
	aux->info = info;
	aux->left = aux->right = NULL;

	return aux;
}


node* addNode(node* root, int info)
{
	if (root == NULL)
		root = createNewNode(info);
	else if (info <= root->info)
		root->left = addNode(root->left, info);
	else
		root->right = addNode(root->right, info);

	return root;
}


node* getMin(node* root)
{
	if (root->left == NULL)
		return root;
	getMin(root->left);
}


node* deleteNode(node* root, int info)
{

	if (root == NULL)
		return root;
	else if (info < root->info)
		root->left = deleteNode(root->left, info);
	else if (info > root->info)
		root->right = deleteNode(root->right, info);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			node* aux = root;
			root = root->right;
			delete aux;
		}
		else if (root->right == NULL)
		{
			node* aux = root;
			root = root->left;
			delete aux;
		}
		else
		{
			node* aux = getMin(root->right);
			root->info = aux->info;
			root->right = deleteNode(root->right, aux->info);
		}
		return root;
	}
}


void inOrder(node* root)
{
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	cout << root->info << ' ';
	inOrder(root->right);
}

int sizeBag(node* root)
{
	if (root == NULL)
		return 0;
	return sizeBag(root->left) + sizeBag(root->right) + 1;
}


bool searchNode(node* root, int info)
{
	if (root == NULL)
		return false;
	else if (info == root->info)
		return true;
	else if (info < root->info)
		searchNode(root->left, info);
	else if (info > root->info)
		searchNode(root->right, info);
}


void destroyBag(node* root) {

	while (sizeBag(root))
		root = deleteNode(root, root->info);

	
	root = NULL;
	delete root;

}


int main()
{

	node* root = NULL;
	int x = 5;
	srand(time(NULL));


	while (x--)
	{
		root = addNode(root, rand() % 10);
	}
	root = addNode(root, 5);
	inOrder(root);
	cout << endl;
	destroyBag(root);
	cout << sizeBag(root);
	//inOrder(root);


	return 0;
}
