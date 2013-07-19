#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include <ctime>
#include <list>
#include <map>

using namespace std; 

template <typename T>
class BinaryTree{
  struct node {
		node* left;
		node* right;
		T data;
		node(T x):data(x),left(NULL),right(NULL){}
	};
	node* root;
	void add(node* &ptr,T x) {
		int dir = rand()%2;
		if(ptr == NULL)
			ptr = new node(x);
		else if(dir == 0)
			add(ptr->left,x);
		else 
			add(ptr->right,x);
	}
	vector<T> preOrder(node* ptr) {
		vector<T> tmp,tmp1;
		if(ptr != NULL) {
			tmp.push_back(ptr->data);
			tmp1 = preOrder(ptr->left);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			tmp1 = preOrder(ptr->right);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			return tmp;
		}
		return tmp;
	}
	vector<T> inOrder(node* ptr) {
		vector<T> tmp,tmp1;
		if(ptr != NULL) {
			tmp1 = inOrder(ptr->left);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			tmp.push_back(ptr->data);
			tmp1 = inOrder(ptr->right);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			return tmp;
		}
		return tmp;
	}
	vector<T> postOrder(node* ptr) {
		vector<T> tmp,tmp1;
		if(ptr != NULL) {
			tmp1 = postOrder(ptr->left);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			tmp1 = postOrder(ptr->right);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			tmp.push_back(ptr->data);
			return tmp;
		}
		return tmp;
	}
	void print(node* ptr,string tab="") {
	    if(ptr!=NULL) { 
	        cout << tab <<ptr->data <<endl;
	        tab += "|";
	        print(ptr->left,tab);
	        print(ptr->right,tab);
	    }
	    else cout<<tab<< "#" <<endl;
	}
	BinaryTree<T> construct(vector<T> preOrder,vector<T> inOrder,
									node*& ptr) {

	}
public:
	BinaryTree():root(NULL){}
	~BinaryTree(){}
	void add(T x){add(root,x);}
	vector<T> preOrder(){return preOrder(root);}
	vector<T> postOrder(){return postOrder(root);}
	vector<T> inOrder(){return inOrder(root);}
	void print(){print(root);}
	BinaryTree<T> construct(vector<T> preOrder,vector<T> inOrder) {
	    return construct(preOrder,inOrder,root);
	}
};


int main(int n, char* args[]) {
	
	BinaryTree<int> bst1;
		
	//generate uniform random numbers 
	//between 1 to 10 using mersenne 
	// twister algorithm using a random deive
	// curr_time as a seed
	mt19937 engine;
	engine.seed(time(NULL));
	uniform_int_distribution<int> distrib(1,10);
	auto generator = bind(distrib,engine);
	for(int i=0; i<10; ++i)bst1.add(generator());

	for(auto i: bst1.preOrder()) cout<< i <<" ";
	cout<<endl;
	for(auto i: bst1.inOrder()) cout<< i <<" ";
	cout<<endl;
	for(auto i: bst1.postOrder()) cout<< i <<" ";
	cout<<endl;
	

}
