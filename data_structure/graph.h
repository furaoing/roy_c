#include <stdio.h>
#include <stdlib.h>


int* create_graph_in_stack(int n_vertice)
{
    int graph = array[n_vertice][n_vertice];
    int* g_p = &graph;
    return g_p;
}



int** create_graph_in_heap(int n_vertice)
{
    int** the_array = (int**) malloc(n_vertice*sizeof(int*));
    for (int i = 0; i < n_vertice; i++)
    {
        the_array[i] = (int*) malloc(n_vertice*sizeof(int));
    }
    return the_array;
}
