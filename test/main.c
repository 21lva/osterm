#include "heap.h"

int main(){
	heap a=init_heap(1,3);
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
