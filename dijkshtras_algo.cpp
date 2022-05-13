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
typedef struct Parent
{
	int p,w;
}parent;
void sorting(g* graph)
{
	int temp;
	for (int i=0;i<graph->num_edges;i++)
	{
		for(int j=i+1;j<graph->num_edges;j++)
		{
			if(graph->edges[i].weight > graph->edges[j].weight)
			{
				temp = graph->edges[j].weight;
				graph->edges[j].weight = graph->edges[i].weight;
				graph->edges[i].weight = temp;
				temp = graph->edges[j].src;
				graph->edges[j].src = graph->edges[i].src;
				graph->edges[i].src = temp;
				temp = graph->edges[j].dest;
				graph->edges[j].dest = graph->edges[i].dest;
				graph->edges[i].dest = temp;
			}
		}
	}
}
int find_min(parent* shortest_path, vector<int> &visited)
{
	int min = INT_MAX, min_index = -1;
	for (int i=0;i<visited.size();i++)
	{
		if (visited[i] == 0 && min > shortest_path[i].w)
		{
			min = shortest_path[i].w;
			min_index = i;
		}
	}
	return min_index;
}
void find_shortestpath(g* graph)
{
	// sorting edges w.r.t to weights
	sorting(graph);
	cout<<"sorted edges:\n";
	for(int i=0;i<graph->num_edges;i++)
	{
		cout<<graph->edges[i].src<<" - "<<graph->edges[i].dest<<" - "<<graph->edges[i].weight<<endl;
	}

    // declaring shortest path structure with parent and weights
    parent* shortest_path = new parent[graph->num_vertices * sizeof(parent)];
    // visited array to keep track of visited vertices
    vector<int> visited;
    // initializing shortest path and visited arrays
    for(int i=0;i<graph->num_vertices;i++)
    {
    	shortest_path[i].p = -1;
    	shortest_path[i].w = INT_MAX;
    	visited.push_back(0);
	}

    // Taking first vertex as start
    visited[0] = 1;
    int V=0;
    
    // Initializing shortest with first vertex as start
    for (int i=0;i<graph->num_edges;i++)
    {
    	if (graph->edges[i].src == V)
    	{
    		shortest_path[graph->edges[i].dest].p = V;
    		shortest_path[graph->edges[i].dest].w = graph->edges[i].weight;
		}
	}
	
	// Going through each minimum unvisited edge
    while(1)
    {
    	// finding minimum unvisited edge
        V = find_min(shortest_path, visited);
        
        // if there is no unvisited min edge then breaking the loop
        if (V == -1)
        {
        	break;
		}
		// seeting visited true for minimum edge parent vertex
        visited[V] = 1;
        
        // Relaxation step: going through the graph and updating weights
        for(int i=0;i<graph->num_edges;i++)
        {
    	    if (graph->edges[i].src == V &&
			    (shortest_path[graph->edges[i].dest].w > graph->edges[i].weight + shortest_path[V].w))
    	    {
    		    shortest_path[graph->edges[i].dest].p = V;
    		    shortest_path[graph->edges[i].dest].w = graph->edges[i].weight;
		    }
		}
	}

    // printing shortest path
	int total_weight =0;
	cout<<"\n------------------------------------Shotest Path:-----------------------------------------\n";
	cout<<"0->";
	
    int temp=0,count=0;
	while(count < graph->num_vertices-1)
	{
        for (int j=0;j<graph->num_vertices;j++)
        {
        	if (shortest_path[j].p == temp)
        	{
        		cout<<j<<"->";
        		total_weight += shortest_path[j].w;
        		temp=j;
        		count++;
        		break;
			}
		}
	}
	cout<<"Total weight:"<<total_weight<<endl;
}
int main()
{
	cout<<"allocating memory";
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
