#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph{
    int V; 
    list<int> *l;  //create a list of type integer and name l

    //time complexity O(V+E) ,,, worst case because we are traversing each vertex at a time one by one 
    
    public: 
        Graph(int V){
            this->V=V;
            l = new list<int> [V];
        }
        void addEdge(int u , int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }


        //DFS traversal
        void dfsHelper(int u, vector<bool> &vis){  //src node u and vector of boolean values which tells the u node is visited or not 
            cout<<u<<" ";   
            vis[u] = true;  //u visited 

            for (int v: l[u]){  //v is destination
                if(!vis[v]){    //if next neighbour node is not visited 
                    dfsHelper(v,vis); //then v is next src node and pass new updated vis vector
                }
            }
        }

        void dfs(){
            int src = 0;
            vector<bool>vis(V,false);

            dfsHelper(src,vis);
        }

};

int main(){
    Graph g(5); 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.dfs();
    return 0;
}