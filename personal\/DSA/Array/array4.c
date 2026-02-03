int main(){
        int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        int i=0,j=0;

        printf("ROW][1] Column[1] = %d\n",arr[1][1]);
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%d\t",arr[i][j]);
            }
            printf("\n");
        }
}