#include<stdio.h>

void concatstr(char str1[],char str2[]){

    int i=0;
    int j =0;

    while(str1[i] != '\0'){
        i++;
    }
      while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++;
        j++;
    }
    
    str1[i] = '\0';

    printf("the concatenated string is %s",str1);
}

int main(){
    char str1[100] = "HELLO";
    char str2[100] = "RONALDO";

    concatstr(str1,str2);
    return 0;


}