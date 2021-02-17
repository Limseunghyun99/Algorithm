#include <stdio.h>

int main() {
	int a=0;
    int b=0;
	
	while(scanf("%d %d",&a , &b)!=EOF){
		if((a==0) && (b==0))
			break;
		else
			printf("%d\n",a+b);
	}
  return 0;
}
