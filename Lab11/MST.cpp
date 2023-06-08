#include<iostream>
#include<vector>
using namespace std;

#define max 6		//Number of vertices

int selectMinVertex(vector<int>& value,vector<bool>& isMST)
{
	int min = INT_MAX;
	int vertex;
	for(int i=0;i<max;++i)
	{
		if(isMST[i]==false && value[i]<min)
		{
			vertex = i;
			min= value[i];
		}
	}
	return vertex;
}

void getMST(int graph[max][max])
{
	int parent[max];		
	vector<int> val(max,INT_MAX);	
	vector<bool> isMST(max,false);	

	//Node is 0
	parent[0] = -1;	
	val[0] = 0;	
	
	for(int i=0;i<max-1;++i)
	{
		//using greedy method
		int U = selectMinVertex(val,isMST);
		isMST[U] = true;	//adding new Vertex to MST

		for(int j=0;j<max;++j)
		{
			if(graph[U][j]!=0 && isMST[j]==false && graph[U][j]<val[j])
			{
				val[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for(int i=1;i<max;++i)
		cout<<parent[i]<<"->"<<i<<"  weight= "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[max][max] = { {0, 3, 0, 0, 0, 1},
						{3, 0, 2, 1, 10, 0},
						{0, 2, 0, 3, 0, 5},
						{0, 1, 3, 0, 5, 0},
						{0, 10, 0, 5, 0, 4},
						{1, 0, 5, 0, 4, 0} };

	getMST(graph);	
	return 0;
}
