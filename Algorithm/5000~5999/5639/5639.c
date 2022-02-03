#include <stdio.h>
typedef struct child{
	int l,r;
} child;
child list[1000002];
int find(int x){
    if(x){
    	find(list[x].l);
    	find(list[x].r);
    	printf("%d\n",x);
	}
	return 0;
}
int input(int root, int x){
    if(x>root)
        if(!list[root].r)
            list[root].r=x;
        else
            input(list[root].r,x);
    else
        if(!list[root].l)
            list[root].l=x;
        else
            input(list[root].l,x);
	return 0;
}
int main(){
    int root,n;
    scanf("%d",&root);
	while(scanf("%d",&n)!=EOF)
		input(root,n);
    find(root);
	return 0;
}