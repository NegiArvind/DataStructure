#include<stdio.h>
 
#define MAX 100 
#define NIL -1 
#define infinity 9999
#define TEMPORARY 0
#define PERMANENT 1
 
int Path_Finder(int source, int vertex);
void Dijkstra_function(int source);
int minimum_temp();
void make_graph();
 
int vertices;
int adjacent_matrix[MAX][MAX];
int predecessor[MAX];
int vertex_status[MAX];
int pathLength[MAX];
 
int main()
{
     // int source, vertex;
      make_graph();
     // printf("Enter Source Vertex:\t");
     // scanf("%d", &source);
     // Dijkstra_function(source);
      /*while(1)
      {
            printf("Enter destination vertex(-1 to Quit):\t");
            scanf("%d", &vertex);
            if(vertex == -1)
            {
                  break;
            }
            if(vertex < 0 || vertex >= vertices)
            {
                  printf("The Entered Vertex does not exist\n");
            }
            else if(vertex == source)
            {
                  printf("Source Vertex and Destination Vertex are same\n");
            }
            else if(pathLength[vertex] == infinity)
            {
                  printf("There is no path from Source vertex to Destination vertex\n");
            }
            else
            {
                  Path_Finder(source, vertex);
            }
      }*/
      return 0;
}
 
void Dijkstra_function(int source)
{
      int count, current;
      for(count = 0; count < vertices; count++)
      {
            predecessor[count] =  NIL;   
            pathLength[count] = infinity;
            vertex_status[count] = TEMPORARY;
      }
      pathLength[source] = 0; 
      while(1)
      {
            current = minimum_temp(); 
            if(current == NIL)
            {
                  return;
            }
            vertex_status[current] = PERMANENT;
            for(count = 0; count < vertices; count++)
            {
                  if(adjacent_matrix[current][count] != 0 && vertex_status[count] == TEMPORARY)
                  {
                        if( pathLength[current] + adjacent_matrix[current][count] < pathLength[count])
                        { 
                              predecessor[count] = current;
                              pathLength[count] = pathLength[current] + adjacent_matrix[current][count];    
                        }
                  }
            }
      }
}
 
int minimum_temp()
{
      int count;
      int min = infinity;
      int x = NIL;  
      for(count = 0; count < vertices; count++)
      {
            if(vertex_status[count] == TEMPORARY && pathLength[count] < min)
            {
                  min = pathLength[count];
                  x = count;
            }
      }
      return x;
}
 
int Path_Finder(int source, int vertex)
{
      int count, u;
      int path[MAX]; 
      int shortest_distance = 0;
      int temp = 0; 
      while(vertex != source)
      {
            temp++;
            path[temp] = vertex;
            u = predecessor[vertex];
            shortest_distance = shortest_distance + adjacent_matrix[u][vertex];
            vertex = u; 
      }
      count++;
      path[temp] = source;
     // printf("Shortest Path\n");
      /*for(count = temp; count >= 1; count--) 
      {
            printf("%d  ", path[count]);
      }*/
      //printf("\nShortest distance:\t%d\n", shortest_distance);
      return(shortest_distance);
}
 
void make_graph()
{
      int count,cities, maximum_edges, origin_vertex, destination_vertex, weight,k,q,home,shortpath=0,c;
      //printf("Enter total number of vertices:\t");
      int i,j,t;
      scanf("%d %d %d %d",&cities, &vertices,&k,&q);
      int goal[k];
      maximum_edges = vertices * (vertices - 1);
      for(count = 0; count < vertices; count++)
      {
           /// printf("Enter Edge [%d] Co-ordinates [-1 -1] to Quit\n", count + 1);
           // printf("Enter Origin Vertex Point:\t"); 
            scanf("%d", &origin_vertex);
           // printf("Enter Destination Vertex Point:\t");
            scanf("%d", &destination_vertex);
          //  if((origin_vertex == -1) && (destination_vertex == -1))
          //  {
          //        break;
          //  }
          //  printf("Enter the weight for this edge:\t");
            scanf("%d", &weight);
            if(origin_vertex >= vertices || destination_vertex >= vertices || origin_vertex < 0 || destination_vertex < 0)
            {
                 // printf("Edge Co - ordinates are Invalid\n");
                  count--;
            }
            else
            {
                  adjacent_matrix[origin_vertex][destination_vertex] = weight;
            }
      }
      for(i=0;i<k;i++)
      {
         scanf("%d",&goal[i]);
      }
      
      for(i=0;i<q;i++)
      {
         scanf("%d",&home);
          Dijkstra_function(home);
         for(j=0;j<k;j++)
         {
            t=Path_Finder(home,goal[j]);
            if(c==0)
            {
              shortpath=t;
              c=1;
            }
            if(c!=0)
            {
               if(t<shortpath)
               shortpath=t;
            }
        }
        printf("%d",shortpath);
        c=0;
      }
      
}
