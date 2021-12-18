#include<stdio.h>
typedef struct {
	char left;
	char right;
} node;
node tree[27];
int front(char node) {
	if (node == '.') return 0;
	printf("%c", node);
	front(tree[node].left);
	front(tree[node].right);
    return 0;
}
int mid(char node) {
	if (node == '.') return 0;
	mid(tree[node].left);
	printf("%c", node);
	mid(tree[node].right);
    return 0;
}
int end(char node) {
	if (node == '.') return 0;
	end(tree[node].left);
	end(tree[node].right);
	printf("%c", node);
    return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	char root, l, r; // root, left, right
	for (int i = 0; i < n; i++) {
		scanf(" %1c %1c %1c", &root, &l, &r);
		tree[root].left = l;
		tree[root].right = r;
	}
	front('A');
	printf("\n");
	mid('A');
	printf("\n");
	end('A');
	printf("\n");
	return 0;
}