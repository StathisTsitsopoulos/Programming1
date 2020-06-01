#include <stdio.h>
#include <string.h>

int main (int argc, char * argv[]){
	
	int i;
	char a[100][38];
	

	
	for (i=0; i<100; i++){
		fgets(a[i],38,stdin);
		printf("%s",a[i]);
	}
		
	return 0;
}