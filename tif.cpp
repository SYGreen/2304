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
    printf("���� ��(n)�� ���� ��(m)�� �Է��Ͻÿ� : ");
    scanf("%d %d",&n,&m);
    printf("�迭�� ��Ҹ� �Է��Ͻÿ� : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
    	}
    }
    for(int j=0;j<m;j++){
    	f(1,arr[0][j]); 
    }
    printf("��� �ּڰ��� �� �ִ�: %d\n",l_min);
    return 0;
}
