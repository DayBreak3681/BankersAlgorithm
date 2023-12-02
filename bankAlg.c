// Operating Systems Project 2: Banker's Algorithm
// 12-1-23
//Lennice Bolton
#include <stdio.h>

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here
 
    int n, m, i, j, k;

    //file io
    FILE *inFile = fopen("input.txt","r");
    if(inFile == NULL){
      printf("Problem opening file!\n");
      return 1;
    }

    fscanf(inFile, "%d %d", &n, &m);

   // n = 5; // Number of processes
   // m = 3; // Number of resources
    int alloc[5][3];
    int max[5][3];
    int avail[3];

    //reading allocation matrix
    for(i = 0; i < n; ++i){
      for(j = 0; j < m; ++j){
        fscanf(inFile, "%d", &alloc[i][j]);
      }
    }
    // reading MAX Matrix
    for(i = 0; i < n; ++i){
      for(j = 0; j < m; ++j){
        fscanf(inFile, "%d", &max[i][j]);
      }
    }
    //reading available resources
    for(j = 0; j < m; ++j){
      fscanf(inFile, "%d", &avail[j]);
    }

    fclose(inFile);
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
     
 
    return (0);
 

}