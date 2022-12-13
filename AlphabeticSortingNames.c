#include <stdio.h>
#include <string.h>

int alpha_sort(char *list[], int min_sub, int max_sub);
void select_sort(char *list[], int n);

int main(){
    char list1[50][100], *list2[50];
    int i,n;

    printf("Enter the number of applicants:\n");
    scanf("%d",&n);

    if(n<50){

        printf("Enter applicants in the order they applied:\n");
        getchar();
        for(i = 0; i < n; i++) {
            gets(list1[i]);												
        }
        for(i = 0; i < n; i++) {
            list2[i] = list1[i];
        }
	    select_sort(list2, n);

        printf("\nApplication order\t\tAlphabetical order\n");
        for(i = 0; i < n; i++) {
    	    printf("\n");
            printf("%s\t\t\t%s", list1[i],list2[i]);
    }

    }
    else{
        printf("Enter a number between 1-50.\n");
    }
    return 0;
}

int alpha_sort(char *list[], int min_sub, int max_sub){
    int index = min_sub;
    int i;
    for (i=min_sub+1; i<= max_sub; i++){
        if(strcmp(list[i], list[index])<0)
            index = i;
    }
    return index;
}

void select_sort(char *arr[], int num){
    int index,i;
    char *temp;

    for(i=0; i<=num; i++){
        index = alpha_sort(arr, i, num-1);
        if (index!=i) {
            temp= arr[i];
            arr[i]= arr[index];
            arr[index]= temp;
        }
    }
}
 