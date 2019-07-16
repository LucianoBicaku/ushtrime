#include <stdio.h>
#include <string.h>
int mesatare_kursi(int m, int n,int mat[m][n]){
   int i,j,max=0,index;
   for(i=0;i<m;i++){
      int s=0;
      for(j=0;j<n;j++){
         s+=mat[j][i];
      }
      if(s>max){
         max=s;
         index=i;
      }
   }
   return index;
}
int main (){
 FILE * sk1,*sk2;
 sk1=fopen("file1.txt","r");
 if(sk1==NULL){
 printf("Skedari nuk mund te hapet");
 return 0;
 }
 sk2=fopen("file2.txt","r");
 if(sk2==NULL){
 printf("Skedari nuk mund te hapet");
 return 0;
 }
 int m,n,i,j;
 fscanf(sk1,"%d",&m);
 fscanf(sk1,"%d",&n);
   struct student{
 char emri[4];
 } st[m];
 struct kod_kursi{
    char kod[4];
 } krs[n];
	int notat[m][n];
 for(i=0;i<m;i++){
   fscanf(sk1,"%s",&st[i].emri);
   for(j=0;j<n;j++)
   fscanf(sk1,"%d",&notat[i][j]);
 }
 for(j=0;j<n;j++){
    fscanf(sk2,"%s",&krs[j].kod);
 }
	
 int index=mesatare_kursi(m,n,notat);
 printf("%s\n",krs[index].kod);
 printf("Mbaroi me sukses\n");
 fclose(sk1);
 fclose(sk2);
 
 return 0;
}
