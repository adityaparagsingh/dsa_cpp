#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data=val;       //assigning value from user to data;
            left = right = NULL;       
        }
};

static int i = -1;
Node* buildTree(vector <int> preorder){
    i++;

    if(preorder[i]==-1){
        return NULL;
    }

    Node* root = new Node (preorder[i]);    //creating root node
    root->left = buildTree(preorder);   //create left subtree;
    root->right = buildTree(preorder);   //create right subtree;

    return root;  //used to form bridge(edge) between child and parent class
}

//preorder traversal (time complexity : 0(n))
void preOrder(Node* root){
    if(root==NULL){     //here root represents current node         
        return;
    }
    cout<<root->data<<",";
    preOrder(root->left);
    preOrder(root->right);
}

//inOrder traversal (time complexity : 0(n))
void inOrder(Node* root){
    if(root==NULL){     //here root represents current node
        return;
    }
    inOrder(root->left);
    cout<<root->data<<",";
    inOrder(root->right);
}

//PostOrder traversal (time complexity : 0(n))
void postOrder(Node* root){
    if(root==NULL){     //here root represents current node
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<",";
}

//level order traversal
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);       //to mark the end of level


    while(q.size()>0){
        Node* curr = q.front();
        q.pop();  //pop out front element (current Node)

        //to use endl at the end of each level while traversing
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }

        cout<<curr->data<<",";

        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int main(){
    vector <int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    // cout<< root->data<<endl;
    // cout<< root->left->data<<endl;
    // cout<< root->right->data<<endl;
    cout<<"PreOrder Traversal: ";
    preOrder(root);
    cout<<endl;
    cout<<"InOrder Traversal: ";
    inOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    postOrder(root);
    cout<<endl;
    cout<<"Level Order Traversal: "<<endl;
    levelOrder(root);
    return 0;
}