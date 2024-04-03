#include<stdio.h>
#include<stdlib.h>
int n;
void search(int edges[][n],int visited[],int start,int n) {
 visited[start] = 1;
 printf("%d ",start);
 for(int i = 0 ; i < n;i++) {
 if((i != start) && (visited[i] ==0) && (edges[i][start] == 1) &&
(edges[start][i]== 1)) {
 visited[i] = 1;
 search(edges,visited,i,n);
 }
 }
}
void dfs(int edges[][n], int visited[],int n) {
 for(int i = 0 ;i < n;i++) {
 if(visited[i] == 0) {
 search(edges,visited,i,n);
 }
 }
}
int main(void) {
 int e;
 printf("enter the number of vertex and number of edges :");
 scanf("%d %d",&n,&e);
 int edges[n][n];
 for(int i =0 ; i < n;i++) {
 for(int j = 0; j < n;j++) {
 edges[i][j] = 0;
 }
 }
 for(int i = 0 ; i < e ;i++) {
 int first;
 int second;
 printf("enter the source and destination :");
 scanf("%d %d",&first,&second);
 edges[first][second] = 1;
 edges[second][first] = 1;
 }
 int visited[n];
 for(int i =0 ; i < n; i++) {
 visited[i] = 0;
 }
 printf("\n");
 printf("dfs traversal :\n");
 dfs(edges,visited,n);
 return 0;
}