#include "heap.h"

heap* init_heap(int key,int size){
	heap* new_heap = (heap*)malloc(sizeof(heap)*1);
	new_heap->key=key;
	new_heap->array=(process*)malloc(sizeof(process)*size);
	return new_heap;
}

void Is_leaf(heap* root,int idx){
	if(idx*2+1>=root->last)return 1;
	return 0;
}

void min_idx(int left,int right,int cur,int idx){
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
			process* tmp=root->array[mini];
			root->array[mini]=root->array[idx];
			root->array[idx]=tmp;
			downop(root,mini);
		}
	}
}
void upop(heap* root,int idx){
	if(idx==0)return;
	if(root->array[idx] < root->array[(idx-1)/2]){
		process* tmp=root->array[idx];
		root->array[idx]=root->array[(idx-1)/2];
		root->array[(idx-1)/2]=tmp;
		upop(root,(idx-1)/2);
	}
}

void heap_pop(heap* root){
	if(root->last==0)return;
	process* tmp = root->array[0];
	root->array[0]=root->array[root->last-1];
		ray
	free(tmp);
	downop(root,0);
}

process* heap_first(heap* root){
	return root->array[0];
}

void heap_insert(heap *root,process* newp){
	root->array[root->last++]=newp;
	upop(root,last-1);
}

