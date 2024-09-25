#include <stdio.h>
#define N 10 
#define M 10
int arr[N][M]; 
int n,m; 
int l_min=0;
void f(int r, int min){
    if(r==n){
        if(min>l_min)
            l_min=min;
        return;
	}
    for(int j=0;j<m;j++){
        int n_min;
	if (arr[r][j]<min)
    	n_min=arr[r][j]; 
	else n_min=min; 
    f(r+1,n_min);
    }
}
int main(){
    printf("행의 수(n)와 열의 수(m)를 입력하시오 : ");
    scanf("%d %d",&n,&m);
    printf("배열의 요소를 입력하시오 : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
    	}
    }
    for(int j=0;j<m;j++){
    	f(1,arr[0][j]); 
    }
    printf("모든 최솟값들 중 최댓값: %d\n",l_min);
    return 0;
}
