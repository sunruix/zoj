#include <stdio.h>
#include <string.h>
char d[1<<12], r[1<<12];
int n;
 int L(){
     int i,j,k;
     for(i=n-1; i>=(n>>1); i--)
         if (d[i] == '0')
             d[i] = '9';
     else{
         d[i]--;
         break;
     }
    if((i<<1)<n)
        return 0;
     for(i=j=0; (i<<1)<n; i++){
         k=r[i]+d[i]+j-96;
         //j=k/10;
         j = k >= 10;
         //r[i]=k%10+48;
         r[i] = (k >= 10 ? k - 10 : k) + 48;
    }
     while(j){

        k=r[i]+j-48;
         //j=k/10;
         j = k >= 10;
        //r[i]=k%10+48;
         r[i] = (k >= 10 ? k - 10 : k) + 48;
         i++;
    }
     return 1;
}
void O(){
    int i,j,k;
    for(i=(1<<12) -1; i && r[i] == '0'; i--);
    i=i<0?0:i;

    while(i >= 0){
        printf("%c",r[i]);
         i--;
    }
    printf("\n");
}
int main(){
    int i,j,k;
    while((scanf("%s", d) != (-1))){
        n=strlen(d);
        d[--n]=0;
        if(n > (1<<12) -2){

            printf("0\n");
            continue;
        }
        if(n-(n>>1)-(n>>1)){
            d[n++]='0';
            d[n]=0;
        }
        memset(r,'0',sizeof(r));
        while(L());
            O();
    }
}
