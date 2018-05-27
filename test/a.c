#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ra(int k){
	
	int x=(rand()%10);
	int y=rand()%10;
	if(k==0)return x;
	return y;
}

int main(){
	srand(time(NULL));

	printf("%d\n",ra(0));
	printf("%d\n",ra(0));
	printf("%d\n",ra(1));
	printf("%d\n",ra(1));

	return 0;
}
