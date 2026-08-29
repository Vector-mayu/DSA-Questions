// Adjacency List for Undirected Unweighted Graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;
    cout<<"Enter the toal Vertex and Edges : ";
    cin>>vertex>>edges;

    vector<vector<int>>adjList(vertex);

    cout<<"Enter the edges..."<<endl;

    int u,v;
    for(int i=0; i<edges; i++){
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    };

    //print the elements
    for(int i=0; i<vertex; i++){
        cout<<"Egdes of "<<i<<" are :- ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Adjacency Matrix for Undirected Weighted Graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;
    cout<<"Enter the toal Vertex and Edges : ";
    cin>>vertex>>edges;

    vector<vector<pair<int, int>>>adjList(vertex);

    cout<<"Enter the edges..."<<endl;

    int u, v, weight;
    for(int i=0; i<edges; i++){
        cin>>u>>v>>weight;

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    };

    //print the elements
    for(int i=0; i<vertex; i++){
        cout<<"Egdes of "<<i<<" are :- ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j].first<<" "<<adjList[i][j].second<<" ";
        }
        cout<<endl;
    }
}

// Adjacency List for Directed Unweighted
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;
    cout<<"Enter the toal Vertex and Edges : ";
    cin>>vertex>>edges;

    vector<vector<int>>adjList(vertex);

    cout<<"Enter the edges..."<<endl;

    int u, v;
    for(int i=0; i<edges; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
    };

    //print the elements
    for(int i=0; i<vertex; i++){
        cout<<"Egdes of "<<i<<" are :- ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }

}

// Adjacency List for Directed Weighetd Graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;
    cout<<"Enter the toal Vertex and Edges : ";
    cin>>vertex>>edges;

    vector<vector<pair<int, int>>>adjList(vertex);

    cout<<"Enter the edges..."<<endl;

    int u, v, weight;
    for(int i=0; i<edges; i++){
        cin>>u>>v>>weight;

        adjList[u].push_back({v, weight});
    };

    //print the elements
    for(int i=0; i<vertex; i++){
        cout<<"Egdes of "<<i<<" are :- ";
        for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j].first<<" "<<adjList[i][j].second<<" ";
        }
        cout<<endl;
    }

}