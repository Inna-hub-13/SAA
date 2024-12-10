
// Functions for graphs, represented by adjacency matrix. 
// Exam examples

#include <stdio.h>
#include <stdlib.h>
#define N 7

int* complete_graph(int*, int);
int in_edges(int*, int, int);
int out_edges(int*, int, int);
int find_loop_edges(int*, int);
int find_adjacent(int*, int**, int, int);

int main() {

    int undirected[N][N] = {
        {0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0}
    };

    // We put 1 only for out edges
    int directed[N][N] = {
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}
    };

    int* g = complete_graph((int*)undirected, N);
    if(!g)
        return -1;
    
    int i, j;
    printf("g: \n");
    for(i = 0; i < N; i++){
        
        for(j = 0; j < N; j++)
            printf("%d ", *(g + i * N + j));
        
        printf("\n");
    }

    int in, out, loop_edges;
    in = in_edges((int*)directed, N, 0);
    out = out_edges((int*)directed, N, 5);
    loop_edges = find_loop_edges((int*)undirected, N);

    printf("in = %d\n", in);
    printf("out = %d\n", out);
    printf("loop_edges = %d\n", loop_edges);

    int* adjacent;
    int count = find_adjacent((int*)undirected, &adjacent, N, 5);

    if(adjacent)
        for(i = 0; i < count; i++)
            printf("%d ", *(adjacent + i));
    
    printf("\n");

    return 0;
}

// Returns a matrix, reprsenting graph <g>,
// so that combined <G> and <g> make a complete graph

// *assume there are no loop edges
int* complete_graph(int* G, int n) {

    int* g = (int*)calloc(n*n, sizeof(int));
    if(!g)
        return NULL;
    
    int i, j;
    for(i = 0; i < n; i++){
        
        for(j = 0; j < i; j++)
            if(*(G + i * n + j) == 0)
                *(g + i * n + j) = 1;

        for(j = i + 1; j < n; j++)
            if(*(G + i * n + j) == 0)
                *(g + i * n + j) = 1;
    }

    return g;
}

// Returns the number of in edges of given vertex
int in_edges(int* G, int n, int vertex) {

    // Visit column <vertex>
    int j, count = 0;
    for(j = vertex; j < n*n; j += n)
        if(*(G + j))
            count ++;
    
    return count;
}

// Returns the number of out edges
int out_edges(int* G, int n, int vertex) {

    // Visit row <vertex>
    int i, count = 0;
    for(i = 0; i < n; i++)
        if(*(G + vertex * n + i))
            count++;
    
    return count;
}

int find_loop_edges(int* G, int n) {

    int i, count = 0;
    for(i = 0; i < n; i++)
        if(*(G + i * n + i))
            count++;
    
    return count;
}

int find_adjacent(int* G, int** arr, int n, int vertex) {

    int* adjacent = (int*)calloc(n, sizeof(int));
    if(!adjacent)
        return -1;
    
    int i, count = 0;
    for(i = 0; i < n; i++)
        if(*(G + vertex * n + i)){
            
            *(adjacent + count) = i + 1;
            count++;
        }

    *arr = adjacent;
    return count;
}


