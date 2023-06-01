#include <iostream>
using namespace std;
#include <limits.h>
  

#define max 6 //change with number of vertices

int minDist(int sssp[], bool visited[])
{
  

    int min = INT_MAX, index;
  
    for (int i = 0; i < max; i++)
        if (visited[i] == false && sssp[i] <= min)
            min = sssp[i], index = i;
  
    return index;
}
  

void printdist(int sssp[],int src)
{
    cout << "Vertex \t Distance from Source : " <<src<< endl;
    int tot=0;
    for (int i = 0; i < max; i++){
        cout << i << " \t\t"<<"|"<<"\t\t"<<sssp[i] << endl;
        tot+=sssp[i];
    }
    cout<<"For source: "<<src<<" ,Average time is : "<<tot*1.0/(max-1)<<endl;
}
  

void dijkstra(int graph[max][max], int src)
{
    int sssp[max];
    bool visited[max]; 
    for (int i = 0; i < max; i++)
        sssp[i] = INT_MAX, visited[i] = false;
  
    
    sssp[src] = 0;
    for (int count = 0; count < max - 1; count++) {
        int min_index = minDist(sssp, visited);
        
        visited[min_index] = true;
        for (int v = 0; v < max; v++){
            if (!visited[v] && graph[min_index][v]
                && sssp[min_index] != INT_MAX
                && sssp[min_index] + graph[min_index][v] < sssp[v]){
                sssp[v] = sssp[min_index] + graph[min_index][v];}}
    }
  
    // print the constructed distance array
    printdist(sssp,src);
}
  

int main()
{
     //graph represented as an adjacent matrix
    int graph[max][max] = {{0, 10, 0, 0, 15, 5}, {10, 0, 10, 30, 0, 0}, {0, 10, 0, 12, 5, 0}, {0, 30, 12, 0, 0, 20}, {15, 0, 5, 0, 0, 0}, {5, 0, 0, 20, 0, 0}};

  

  
  
    for(int vertex=0;vertex<max;vertex++){
        dijkstra(graph, vertex);
    }

  
    return 0;
}
  
