#include <cstdio>
#include <iostream>
using namespace std;

template <class T>
class SplayTree{
	public:
	SplayTree(){
		nullNode = new item;
		nullNode->left = nullNode->right = nullNode;
		root = nullNode;
	}
	const T & findMin(){
		item *ptr = root;
		while( ptr->left != nullNode )
			ptr = ptr->left;
		splay( ptr->element, root );
		return ptr->element;
	}
	const T & findMax(){
		item *ptr = root;
		while( ptr->right != nullNode )
			ptr = ptr->right;
		splay( ptr->element, root );
		return ptr->element;
	}
	bool contains( const T& x ){
		if( isEmpty() )
			return false;
		splay( x, root );
		return root->element == x;
	}
	bool isEmpty() const{
		return root == nullNode;
	}
	void insert( const T& x ){
		static item* newNode = NULL;

		if( newNode == NULL )
			newNode = new item;
		newNode->element = x;
		newNode->times = 1;

		if( root == nullNode ){
			newNode->left = newNode->right = nullNode;
			root = newNode;
		}
		else{
			splay( x, root );
			if( x < root->element ){
				newNode->left = root->left;
				newNode->right = root;
				root->left = nullNode;
				root = newNode;
			}
			else if( root->element < x ){
				newNode->right = root->right;
				newNode->left = root;
				root->right = nullNode;
				root = newNode;
			}
			else{
				++root->times;
				return;
			}
		}
		newNode = NULL;
	}
	void remove( const T& x ){
		item *newTree;

		splay( x, root );
		if( root->element != x || --root->times)
			return;

		if( root->left == nullNode )
			newTree = root->right;
		else{
			newTree = root->left;
			splay( x, newTree );
			newTree->right = root->right;
		}

		delete root;
		root = newTree;
	}
	private:
	struct item{
		T  element;
		item *left;
		item *right;
		int times;

		item() : left(0), right(0), times(0){}
		item( const T & theElement, item *lt, item *rt )
			: element( theElement ), left( lt ), right( rt ), times(1){}
	};

	item *root;
	item *nullNode;
	void rotateLeft( item * & k2 ){
		item *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
	}
	void rotateRight( item * & k1 ){
		item *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1 = k2;
	}
	void splay( const T& x, item*& t ){
		static item header;
		header.left = header.right = nullNode;
		item *leftMax=&header, *rightMin=&header;
		nullNode->element = x;

		for(;;){
			if( x < t->element ){
				if( x < t->left->element )
					rotateLeft( t );
				if( t->left == nullNode )
					break;
				rightMin->left = t;
				rightMin = t;
				t = t->left;
			}
			else if( t->element < x ){
				if( t->right->element < x )
					rotateRight( t );
				if( t->right == nullNode )
					break;
				leftMax->right = t;
				leftMax = t;
				t = t->right;
			}
			else
				break;
		}

		leftMax->right = t->left;
		rightMin->left = t->right;
		t->left = header.right;
		t->right = header.left;
	}
};

int main(){	
	long long int sum=0;
	int N;
	SplayTree<int> tr;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		int j;
		scanf("%d",&j);
		for(;j>0;--j){
			int n;
			scanf("%d",&n);
			tr.insert(n);
		}
		sum+=(tr.findMax()-tr.findMin());
		tr.remove(tr.findMax());
		tr.remove(tr.findMin());
	}
	cout<<sum<<endl;
}
