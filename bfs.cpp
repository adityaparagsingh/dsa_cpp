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
        
        //bfs travesal
        void bfs(){
            queue<int> Q; //create a Queue of type integer and name Q
            vector<bool> visited(V,false);
            Q.push(0);
            visited[0] = true;

            while(Q.size()>0){
                int u = Q.front();
                Q.pop(); 
                //u is source v is next node(destination/immidiate neighbour)
                cout<<u<<" ";
                
                for(int v : l[u]){
                    if(!visited[v]){ //if the immidiate neighbour is not visited do this
                        visited[v]=true;
                        Q.push(v);
                    }
                }

            }
            cout<<endl;
        }
};

int main(){
    Graph g(5); 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.bfs();
    return 0;
}