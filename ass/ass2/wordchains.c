#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>


#include "Graph.h"


#define MAX_NODES 1000
int visited[MAX_NODES];

int max_num,max_len;

int main(void) {
    int i,n;
    printf("Enter a number: ");
    scanf("%d", &n);

    char word[1000][19];

    //printf("%d",n);
    //getchar();
    for (i = 0; i < n; i++) {
        printf("Enter word: ");
        scanf("%s", word[i]);
        //printf("a=%c",&word[i][0]);
    }
    printf("\n");

    Graph wordGraph = newGraph(n);
    Edge e;


    /* time complexity:O(n^2),because there is one "for loop" in other "for loop" */
    for (i = 0; i < n; i++) {
        printf("%s:", word[i]);
        for (int j = i+1; j < n; j++) {
            if (judge_word(word[i], word[j]) == 1) {
                printf(" %s", word[j]);
                e.v=i;
                e.w=j;
                insertEdge(wordGraph,e);
            } else { continue; }
        }
        printf("\n");
    }
    //showGraph(wordGraph);

    char cout[n*(n-1)][n];//store 5->4->1->0
    char c[10000]={NULL};
    int count=0;//length
    int src = 0, dest = n-1;
    int ca=0,cb=0;//store which one
    /* time complexity:O(n^2),because there is one "for loop" in other "for loop" .   */
    for(src=0;src<n-1;src++) {
        for(dest=n-1;dest>src;dest--){
        if (findPathDFS(wordGraph, n, src, dest) == 1) {
            Vertex v = dest;
            while (v != src) {
                cout[ca][cb]=v;
                count++;
                cb++;
                //printf("%d -> ", v);
                v = visited[v];
            }
            cout[ca][cb]=src;
            c[ca]=count+1;
            //printf("%d\n", src);
        }
            //printf("%d",ca);
            count=0;
            ca++;
            cb=0;
        }
    }

    /* time complexity:O(n),because there is one "for loop" . c[i] is to count the number of  path,this part will choose the longest length of pace.  */
    max_num=0,max_len=0;
    for(i=0;i<n;i++){
        if (c[i]>max_len){
            max_len=c[i];
            max_num=1;
        }else if(c[i]<max_len){
            continue;
        }else{
            max_num++;
        }
    }


    printf("\n");
    printf("Maximum chain length: %d\n",max_len);
    printf("Maximal chains:\n");


    /* time complexity:O(n^2),because there is one "for loop" in other "for loop" */
    for(i=max_num;i>=0;i--){
        if(c[i]==max_len){
            for(int j=max_len-1;j>0;j--){
            printf("%s",word[cout[i][j]]);
            printf(" -> ");
            }
            printf("%s",word[cout[i][0]]);
            printf("\n");
        }

    }


}

#define MAX_NODES 1000

int visited[MAX_NODES];  // array to store visiting order
// indexed by vertex 0..nV-1

int dfsPathCheck(Graph g, int nV, Vertex v, Vertex dest) {
    Vertex w;
    for (w = 0; w < nV; w++)
        if (adjacent(g, v, w) && visited[w] == -1) {
            visited[w] = v;
            if (w == dest)
                return 1;
            else if (dfsPathCheck(g, nV, w, dest)==1)
                return 1;
        }
    return 0;
}

int findPathDFS(Graph g, int nV, Vertex src, Vertex dest) {
    Vertex v;
    for (v = 0; v < nV; v++)
        visited[v] = -1;
    visited[src] = src;
    return dfsPathCheck(g, nV, src, dest);
}

//
/*int max(int max_len,int c[],int i,int max_num) {

    while (c[i + 1]) {
    if (c[i] > max_len) {
        max_len = c[i];//最大长度
        max_num=1;//最大长度的数量有几个
        return max(max_len, c[i + 1], i + 1, max_num);
    } else if (c[i]<max_len){
        return max(max_len, c[i + 1], i + 1, max_num);
    }else{
        max_num++;
        return max(max_len, c[i + 1], i + 1, max_num);
    }

 }

}*/


//whether two words are similar
int judge_word(char word1[], char word2[]){
    int i = 0;
    int sign = 0;


    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if(len1==len2){
        for (i=0;i<len1;i++)
        {
            if (word1[i]==word2[i]){ continue;}
            else{
                sign++;
                if (sign>1){
                    return 0;
                }
            }
        }
        return 1;
    }
    else if(abs(len1-len2)>1){ return 0;}

    else{
        if (len1>len2){
            for (i=0;i<len2;i++)
            {
                if (word1[i]!=word2[i]){
                    for (int j=i;j<len2;j++){
                       if(word2[j]!=word1[j+1]){return 0;}
                    }
                }
            }
        }
        else{
            for (i=0;i<len1;i++)
            {
                if (word2[i]!=word1[i]){
                    for (int j=i;j<len1;j++){
                        if(word1[j]!=word2[j+1]){return 0;}
                    }
                }
            }

        }
        return 1;
    }

}



