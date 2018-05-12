#include "heap.h"


heap* init_heap(int key,int size){
	heap* new_heap = (heap*)malloc(sizeof(heap)*1);
	new_heap->key = key;
	new_heap->array=(process**)malloc(sizeof(process*)*size);
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

int getKey(process* target,int key){
	//smaller -> better
	if(key==GETTINGT)
		return target->gettingT;
	else if(key==PRIORITY)
		return target->priority;
	else if(key==LEFTCPU)
		return target->CpuIO.LeftCpu;
	else if(key==SLEFTCPU)
		return target->CpuIO.TurnArray[target->CpuIO.Index];
}

void downop(heap* root,int idx,int key){
	int left,right,cur;
	if(Is_leaf(root,idx))return;
	else{
		//getting key value of each process;
		left=getKey(root->array[idx*2+1],key);
		cur=getKey(root->array[idx],key);

		
		if(root->last<=idx*2+2)right=9999999;//only one child : a left child 
		else right=getKey(root->array[idx*2+2],key);
		
		int mini=min_idx(left,right,cur,idx);//find index of process having minimum key
		
		if(mini==idx)return;//nothing to do
		else{
			process* tmp=root->array[mini];
			root->array[mini]=root->array[idx];
			root->array[idx]=tmp;
			downop(root,mini,key);
		}
	}
}
void upop(heap* root,int idx,int key){
	if(idx==0)return;
	if(getKey(root->array[idx],key) < getKey(root->array[(idx-1)/2],key)){
		process* tmp=root->array[idx];
		root->array[idx]=root->array[(idx-1)/2];
		root->array[(idx-1)/2]=tmp;
		upop(root,(idx-1)/2,key);
	}
}

void heap_pop(heap* root){
	if(root->last==0)return;
	root->array[0]=root->array[root->last-1];
	downop(root,0,root->key);
}

process* heap_first(heap* root){
	return root->array[0];
}

void heap_insert(heap *root,process* newp){
	root->array[root->last++]=newp;
	upop(root,root->last-1,root->key);
}

void heap_free(heap* target){
	if(target==NULL)return;
	while(heap_first(target)!=NULL){
		process* tmp = heap_first(target);
		heap_pop(target);
		process_free(tmp);
	}
	if(target->array!=NULL)free(target->array);
	free(target);
}
