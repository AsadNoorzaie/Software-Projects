#include<stdio.h>
#include<stdlib.h>


#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node * left;
	struct Node * right;
};

void Insert(struct Node ** root, int data, int height);
struct Node * InorderNode(struct Node * root);
void Search(struct Node ** root, int target, int height);
struct Node * DeleteNode(struct Node * root, int target);


struct Node * root;


int main(int argc, char *argv[]){

	

	FILE* file = fopen(argv[1],"r");
	if (file==NULL) 
	{
		printf("error"); 
		return 0;
	}

	root = NULL;
	int height = 0;

	char op;
	int value;

	while(fscanf(file, "%c %d\n", &op, &value) == 2){

		if(op=='i'){
			Insert(&root, value, 1);
		}
		else if(op=='s'){
			Search(&root, value, 1);
		}
		else{
			// TOOD Delete
			root = DeleteNode(root, value);
		}

	}

	fclose(file);

	if(root==NULL){
		return 0;
	}

	//printf("%d\n", root->data);
	// TODO: free up memory


	return 0;
}

struct Node * DeleteNode(struct Node * root, int target){
	if(root == NULL){
		printf("fail\n");
		return root;
	}
	if(target > root->data){
		root->right = DeleteNode(root->right, target);
		return root;
	}
	else if(target < root->data){
		root->left = DeleteNode(root->left, target);
		return root;
	}
	else{
		// match has been found, check if either one of the child nodes are null
		if(root->right == NULL){
			struct Node * new_node = root->left;
			printf("success\n");
			return new_node;
		}
		else if (root->left == NULL){
			struct Node * new_node = root->right;
			printf("success\n");
			return new_node;
		}

		// since both of the children are not null, we have to find the inorder predecessor
	struct Node * node_to_replace = InorderNode(root->right);

	// now that we have found the node to replace the current root, we will swap data points
	root->data = node_to_replace->data;

	// now we call delete on root->left since we still have that leaf node in the tree

	root->right = DeleteNode(root->right, node_to_replace->data);
	return root;
	}

	


}


struct Node * InorderNode(struct Node * root){
	struct Node * ptr = root;
	while(ptr->left != NULL){
		ptr = ptr->left;
	}

	return ptr;
}

void Search(struct Node ** root, int target, int height){
	if(*root == NULL){
		printf("absent\n");
		return;
	}
	if((*root)->data == target){
		printf("present %d\n", height);
		return;
	}

	if(target < (*root)->data){
		// go down the right subtree
		height++;
		Search(&((*root)->left), target, height);
		return;
		
	}
	else{
		height++;
		Search(&((*root)->right), target, height);
		return;
	}
}


void Insert(struct Node ** root, int data, int height){
	if(*root == NULL){
		// creat root and return
		*root = (struct Node *)malloc(sizeof(struct Node));

		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
		printf("inserted %d\n", 1);
		return;
	}
	// check if duplicate
	if((*root)->data == data){
		printf("duplicate\n");
		return;
	}

	// check which side to go

	if(data > (*root)->data){
		// check if right side is null, if it is then insert and print height

		if((*root)->right == NULL){
			struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
			temp->data = data;
			temp->right = NULL;
			temp->left = NULL;
			(*root)->right = temp;
			height++;
			printf("inserted %d\n", height);
			return;
		}

		// if not call root->right and increment height
		else{
			height++;
			Insert(&((*root))->right, data, height);
			return;
		}
	}
	// go down left subtree
	else{
		if((*root)->left == NULL){
			struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
			temp->data = data;
			temp->right = NULL;
			temp->left = NULL;
			(*root)->left = temp;
			height ++;
			printf("inserted %d\n", height);
			return;
		}
		else{
			height++;
			Insert(&(*root)->left, data, height);
			return;
		}
	}
}
















