#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Binary Search Tree

class binarySearchTree
{
public:
	int data;
	binarySearchTree* left;
	binarySearchTree* right;
	binarySearchTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binarySearchTree(){
		delete left;
		delete right;
	}
	
};

void LevelOrderTraversal(binarySearchTree* root){

	if(!root) return;

	queue<binarySearchTree*> node;
	node.push(root);

	while(!node.empty()){

		int count = node.size();
		while(count--){

			binarySearchTree* ptr = node.front();
			cout<<ptr->data<<" ";
			node.pop();

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";

	}
}

binarySearchTree* builtBinaryTree(binarySearchTree* root,int key){

	if(!root) return new binarySearchTree(key);

	if( root->data > key){
		root->left = builtBinaryTree(root->left,key);
	}
	else{
		root->right = builtBinaryTree(root->right,key);
	}
	return root;
}

bool findElement(binarySearchTree* root,int key){

	if(!root) return false;

	if(root->data == key) return true;

	bool res;
	if(root->data < key) res =  findElement(root->right,key);

	else{
		res = findElement(root->left,key); 
	} 
	return res;
}

class response{
public:
	int maxE;
	int minE;
	bool isBst;
	int height;
	// response(int mx = ){
	// 	maxE = INT_MIN;
	// 	minE = 0;
	// 	isBst = true;
	// 	height = 0;
	// }
};


response* largestBST(binarySearchTree* root){

	response* res = new response();
	if( !root){
		res->maxE = INT_MIN;
		res->minE = INT_MAX;
		res->isBst = true;
		res->height = 0;

		return res;
	}

	if(!root->left && !root->right){
		res->maxE = root->data;
		res->minE = root->data;
		res->isBst = true;
		res->height = 1;

		return res;
	}

	response* leftres = largestBST(root->left);
	response* rightres = largestBST(root->right);

	res->isBst = ((leftres->maxE < root->data) && (rightres->minE > root->data) && leftres->isBst && rightres->isBst);

	if(res->isBst){		
		res->maxE = max(leftres->maxE,max(rightres->maxE,root->data));
		res->minE = min(leftres->minE,min(rightres->minE,root->data));
	}
	res->height = (res->isBst ? (max(leftres->height,rightres->height)) + 1: (max(leftres->height,rightres->height)));
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();
 	int n;
	cin>>n;
	binarySearchTree* root = NULL;
	FOR(i,n){
		int x;
		cin>>x;
		root = builtBinaryTree(root , x);
	}

	cout<<"\n Level Order Traversal : \n";
	LevelOrderTraversal(root);

	response* res = largestBST(root);
	cout<<"\n Height of Maximum BST : "<<res->height;




	delete root;

return 0;

}

/*
Input 1:
8
10 8 20 6 9 18 24 22
Output:
 Level Order Traversal : 
10 
8 20 
6 9 18 24 
22 

 Height of Maximum BST : 4

 Input 2:
 11
 10 6 25 8 9 7 28 4 12 5 6

 output:
  Level Order Traversal : 
10 
6 25 
4 8 12 28 
5 7 9 
6 

 Height of Maximum BST : 3


*/
