#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int M[MAX][MAX];
int chk[MAX];

typedef struct NODE{
    int v;//?뺤젏
    struct NODE* link;// ?댁쟾 ?몃뱶
}NODE;


typedef struct Stack{
    int count;
    struct NODE* top;
}Stack;

Stack* create(){
    Stack* stack= malloc(sizeof(Stack));
    stack->count=0;
    stack->top=NULL;
    return stack;

}

void push(Stack* stack, int v){
    NODE *node =malloc(sizeof(NODE));
    node->v=v;
    node->link=stack->top;

    stack->top = node;
    stack->count++;
}

int pop(Stack* stack){
    int ver=stack->top->v;
    stack->top=stack->top->link;
    stack->count--;

    return ver;
}

int isEmpty(Stack* stack){
    return stack->count==0;
}

int dfs(int start,int vertex_num){
    Stack* stack=create();
    push(stack,start);
    while(!isEmpty(stack)){
        int a=pop(stack);
        chk[a]=1;
        for(int k=0;k<vertex_num;k++){
            if(M[a][k]==1){
                if(start==k) return 1;
                if(chk[k]!=1){
                    push(stack,k);
                }     
            }     
        }         
        }
    return 0;
}

void init(){
    for(int i=0; i<MAX; i++){
        chk[i]=-1;
        for(int k=0;k<MAX;k++){
            M[i][k]=0;
        }
    }
}

void init_chk(){
        for(int i=0; i<MAX; i++){
            chk[i]=-1;
        }
}
int main(){
    FILE* fp_read=fopen("input-4.txt","r");
    FILE* fp_write=fopen("output.txt","w");   
    
    int num;
    int N;
    int cycle=0;
    int posi;
    fscanf(fp_read,"%d",&num);
    for(int i=0;i<num;i++){ //?곹솴媛쒖닔
        fscanf(fp_read,"%d",&N);// ?뺤젏媛쒖닔
        init();
        for(int k=0;k<N;k++){
            for(int z=0;z<N;z++){
                fscanf(fp_read,"%d ",&posi);
                M[k][z]=posi;
            }
        }
        for(int fp=0;fp<N;fp++){
            init_chk();
            cycle=dfs(fp,N);
            if(cycle==1) break;
        }
        fprintf(fp_write,"%d\n",cycle);
    }
}