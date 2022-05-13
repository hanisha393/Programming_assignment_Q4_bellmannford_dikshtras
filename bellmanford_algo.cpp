#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
typedef struct edge
{
	int dest,src,weight;
}E;
typedef struct Graph
{
	int num_vertices,num_edges;
	E* edges;
}g;
void find_shortestpath(g* graph)
{
	// sorting edges w.r.t to weights
	cout<<"Edges:\n";
	for(int i=0;i<graph->num_edges;i++)
	{
		cout<<graph->edges[i].src<<" - "<<graph->edges[i].dest<<" - "<<graph->edges[i].weight<<endl;
	}

    vector<int> distances;

    // Initializing distances with max
    for(int i=0;i<graph->num_vertices;i++)
    {
    	distances.push_back(INT_MAX);
	}
	// marking source dist as 0
	distances[0] =0;

    for (int i=0;i<graph->num_edges;i++)
    {
    	// relaxation: if dest dist > src dest+wieght then update
    	if (distances[graph->edges[i].dest] > distances[graph->edges[i].src] + graph->edges[i].weight)
    	{
    		distances[graph->edges[i].dest] = distances[graph->edges[i].src] + graph->edges[i].weight;
		}
	}

    // printing shortest path
	cout<<"\n------------------------------------Distance from source to each vertex:-----------------------------------------\n";
	for (int i=0;i<graph->num_vertices;i++)
	{
        cout<<"0->"<<i<<"-"<<distances[i]<<endl;
	}
}
int main()
{
	g* graph = new g();
	
	//pre-defined input
	graph->num_vertices = 6;
	graph->num_edges = 8;
	graph->edges = new E[graph->num_edges * sizeof(E)];
	graph->edges[0].src = 0;
	graph->edges[0].dest = 1;
	graph->edges[0].weight = 2;
	graph->edges[1].src = 0;
	graph->edges[1].dest = 2;
	graph->edges[1].weight = 4;
	graph->edges[2].src = 1;
	graph->edges[2].dest = 3;
	graph->edges[2].weight = 7;
	graph->edges[3].src = 1;
	graph->edges[3].dest = 2;
	graph->edges[3].weight = 1;
	graph->edges[4].src = 2;
	graph->edges[4].dest = 4;
	graph->edges[4].weight = 3;
	graph->edges[5].src = 4;
	graph->edges[5].dest = 3;
	graph->edges[5].weight = 2;
	graph->edges[6].src = 3;
	graph->edges[6].dest = 5;
	graph->edges[6].weight = 1;
	graph->edges[7].src = 4;
	graph->edges[7].dest = 5;
	graph->edges[7].weight = 5;

	// For Manula input
	/*cout<<"enter number of vertices";cin>>graph->num_vertices;
    cout<<"enter number of edges";cin>>graph->num_edges;
    graph->edges = new E[graph->num_edges * sizeof(E)];
    cout<<"enter edges:"<<endl;
    for(int i=0;i<graph->num_edges;i++)
    {
    	cout<<"enter src";cin>>graph->edges[i].src;
		cout<<" enter dest:";cin>>graph->edges[i].dest;
		cout<<"enter weight:";cin>>graph->edges[i].weight;
	}*/

    find_shortestpath(graph);
}
