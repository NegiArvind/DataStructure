#include <stdio.h>
#include<malloc.h>
 	 int main()//int argc, char* argv[])
 	 {
  	   int **adj_matrix;
  	   char d;
  	   int r, c, nodes,w;
  	 // printf ("== Adjacency Matrix Demo ==\n");
 	//   printf ("Number of Nodes : ");
  	   scanf ("%d", &nodes);
  	 
  	   /* Dynamic allocation of matrix array */
  	   adj_matrix = (int **) malloc (sizeof(int **)*nodes);
  	   if(!adj_matrix) {
  	    // printf ("Fatal error in memory allocation!");
  	     return -1;
  	   }
  	   for (r = 0; r < nodes; r++) {
  	     adj_matrix[r] = (int *) malloc(sizeof(int)*nodes);
  	     if(!adj_matrix[r]) {
  	      // printf ("Fatal error in memory allocation!");
  	       return -1;
  	     }
  	   }
  	   for (r = 0; r < nodes; r++) {
  	     for (c = 0; c < nodes; c++) {
  	         adj_matrix[r][c] = 0;
  	     }
  	 
  	   }
  	   r = 0;
  	   c = 0;
  	  // printf ("Node pair format <U/D> <V1> <V2>\n");
  	   do {
  	    /// printf ("Enter Node Pair : ");
  	     fflush(stdin);
  	     scanf ("%d %d %d", &r, &c,&w);
  	     if (r > 0 && r <= nodes && c > 0 && c <= nodes){
  	            
  	       
  	       adj_matrix[c - 1][r - 1] =w;
  	       }
  	     }while(r > 0 && c > 0);
  	 
  	   return 0;
  	 }
