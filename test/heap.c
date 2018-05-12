
#include <stdio.h>


typedef struct _heap{
	int key;//key value used when sorting
	int* array;
	int last;//+1 of last element
}heap;

heap* init_heap(int key,int size);
void heap_pop(heap* root);
int heap_first(heap* root);
void heap_insert(heap* root,int newp);


heap* init_heap(int key,int size){
	heap* new_heap = (heap*)malloc(sizeof(heap)*1);
	new_heap->key=key;
	new_heap->array=(int*)malloc(sizeof(int)*size);
	return new_heap;
}

int Is_leaf(heap* root,int idx){
	if(idx*2+1>=root->last)return 1;
	return 0;
}

int min_idx(int left,int right,int cur,int idx){
	int min=(left<right)?left:right;
	min=(min<cur)? min:cur;
	if(min==right)return idx*2+2;
	else if(min==left)return idx*2+1;
	else return idx;

}

void downop(heap* root,int idx){
	int left,right,cur;
	if(Is_leaf(root,idx))return;
	else{
		//****************insert here value 
		left=root->array[idx*2+1];
		cur=root->array[idx];
		//only one child;left
		if(root->last<=idx*2+2)right=9999999;
		else right=root->array[idx*2+2];
		int mini=min_idx(left,right,cur,idx);
		if(mini==idx)return;
		else{
			int tmp=root->array[mini];
			root->array[mini]=root->array[idx];
			root->array[idx]=tmp;
			downop(root,mini);
		}
	}
}
void upop(heap* root,int idx){
	if(idx==0)return;
	if(root->array[idx] < root->array[(idx-1)/2]){
		int tmp=root->array[idx];
		root->array[idx]=root->array[(idx-1)/2];
		root->array[(idx-1)/2]=tmp;
		upop(root,(idx-1)/2);
	}
}

void heap_pop(heap* root){
	if(root->last==0)return;
	int tmp = root->array[0];
	root->array[0]=root->array[root->last-1];
	//free(tmp);
	downop(root,0);
	root->last--;
}

int heap_first(heap* root){
	return root->array[0];
}

void heap_insert(heap *root,int newp){
	root->array[root->last++]=newp;
	upop(root,root->last-1);
}

int main(){
	heap* a=init_heap(1,3);
	heap_insert(a,2);
	heap_insert(a,3);
	heap_insert(a,1);
	printf("%d\n",heap_first(a));
	heap_pop(a);
	printf("%d\n",heap_first(a));
	heap_pop(a);
	printf("%d\n",heap_first(a));
	heap_pop(a);
	return 0;
}
