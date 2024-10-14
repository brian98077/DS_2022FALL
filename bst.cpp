// B10502070  
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//traversal
	vector<int> preorder(int root, vector<int> &nodes){
		
		if(nodes.size() == 1)
			return {root};
		
		vector<int> ans = {root}; 
		vector<int> rightSubtree;
		vector<int> leftSubtree;
		 
    	for(int i=0;i<nodes.size();i++)
    		if(nodes[i] < root)
    			leftSubtree.push_back(nodes[i]);
    	
    	if(leftSubtree.size() > 0)
    	{
	    	int leftRoot = leftSubtree[leftSubtree.size()-1];
	    	vector<int> leftAns = preorder(leftRoot,leftSubtree);
			
	    	ans.insert(ans.end(),leftAns.begin(),leftAns.end());	
		}
    	
    	
		for(int i=0;i<nodes.size();i++)
    		if(nodes[i] > root)
    			rightSubtree.push_back(nodes[i]);
    	
		if(rightSubtree.size() > 0)		
    	{
	    	int rightRoot = rightSubtree[rightSubtree.size()-1];
	    	vector<int> rightAns = preorder(rightRoot,rightSubtree);
			
	    	ans.insert(ans.end(),rightAns.begin(),rightAns.end());
		}
				
		
		return ans;
	}

// find tree height
int height = 1;
	int treeHeight(int root, vector<int> &nodes){
		if(nodes.size() == 1)
			return 1;
		
		vector<int> rightSubtree;
		vector<int> leftSubtree;
		static int tempHeight = 1;
		
		for(int i=0;i<nodes.size();i++)
    		if(nodes[i] > root)
    			rightSubtree.push_back(nodes[i]);
    	
		if(rightSubtree.size() > 0)		
    	{
	    	int rightRoot = rightSubtree[rightSubtree.size()-1];
	    	tempHeight++;
	    	height = max(height,tempHeight);
	    	treeHeight(rightRoot,rightSubtree);
	    	tempHeight--; // back to previous level
		}
		
		for(int i=0;i<nodes.size();i++)
    		if(nodes[i] < root)
    			leftSubtree.push_back(nodes[i]);
    	
		if(leftSubtree.size() > 0)		
    	{
	    	int leftRoot = leftSubtree[leftSubtree.size()-1];
	    	tempHeight++;
	    	height = max(height,tempHeight);
	    	treeHeight(leftRoot,leftSubtree);
	    	tempHeight--;
		}
		
		return height;
	}

// find max of each level
	void maxNum(int root, vector<int> &nodes, vector<int> &arrMax){
		
		static int height = 1;
		if(height == 1)
			arrMax[1] = root;
		if(nodes.size() == 1)
			arrMax[height] = max(root,arrMax[height]);
		
		vector<int> rightSubtree;
		vector<int> leftSubtree;
		 
    	for(int i=0;i<nodes.size();i++)
    		if(nodes[i] < root)
    			leftSubtree.push_back(nodes[i]);
    	
    	if(leftSubtree.size() > 0)
    	{	
    		height++;
	    	int leftRoot = leftSubtree[leftSubtree.size()-1];
	    	arrMax[height] = max(leftRoot,arrMax[height]);
	    	maxNum(leftRoot,leftSubtree,arrMax);
	    	height--; // back to previous level
		}
    	
    	
		for(int i=0;i<nodes.size();i++)
    		if(nodes[i] > root)
    			rightSubtree.push_back(nodes[i]);
    	
		if(rightSubtree.size() > 0)		
    	{
	    	height++;
	    	int rightRoot = rightSubtree[rightSubtree.size()-1];
	    	arrMax[height] = max(rightRoot,arrMax[height]);
	    	maxNum(rightRoot,rightSubtree,arrMax);
	    	height--; 
		}
		
	}

// main function
int main(){
    
    int howManyBST;
    cin >> howManyBST;
    
    for(int i=0;i<howManyBST;i++)
    {
		
	    int howManyNodes;
	    cin >> howManyNodes;
	    vector<int>  tree;
	    
	    for(int i=0;i<howManyNodes;i++)
	    {
	    	int a;
	    	cin >> a;
	    	tree.push_back(a); 
		}
	    
		int root = tree[tree.size()-1];
	    vector<int> finalAns = preorder(root,tree);
	    
	    for(int i=0;i<finalAns.size();i++)
	    	cout << finalAns[i] << "¡@";
		cout << endl;
	    	
	    cout << treeHeight(root,tree)<<endl;
	    	
	    vector<int> arrMax(treeHeight(root,tree));
	    for(int i=0;i<=treeHeight(root,tree);i++)
	    	arrMax[i] = INT_MIN; // initialize the max of each level
	
	    maxNum(root,tree,arrMax);
	    for(int i=1;i<=treeHeight(root,tree);i++)
	    	cout << arrMax[i]<<endl;
	    	
	    height = 1; // reset tree height after finish each BST
	}
    return 0;
}
