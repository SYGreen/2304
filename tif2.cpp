#include <stdio.h>
int n;
int main(){
	char i='()';
	char j='{}';
	char k='[]';
	scanf("%c",&n);
	if(n==i) printf("True");
	else if(n==j) printf("True");
	else if(n==k) printf("True");
	else if(n==i&&j) printf("True");
	else if(n==i&&k) printf("True");
	else if(n==j&&k) printf("True");
	else if(n==i&&j&&k) printf("True");
	else printf("False");
	
}




