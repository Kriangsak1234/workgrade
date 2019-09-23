#include<stdio.h>
#include<string.h>
#define MXSTD 50
#define LENSTD 50
#define MXSJ 50
#define LENSJ 50
int getstudent(char id[MXSJ][LENSTD],char name[MXSTD][LENSTD]){
	int ns;
	printf("ENTER STUDENT :");
	scanf("%d",&ns);
	for(int i=0 ; i<ns ;i++){
		printf("ENTER ID AND NAME :");
		scanf("%s %s",id[i],name[i]);
	}return ns ;
}
int getsubject(char subject[MXSJ][LENSJ]){
	int nsj;
	printf("ENTER SUBJECT :");
	scanf("%d",&nsj);
	for(int i=0 ; i<nsj ; i++){
		printf("ENTER NAME SUBJECT :");
		scanf("%s",subject[i]);
	}
	return nsj;
}

 void getscore(int x,int y,char name[MXSTD][LENSTD],char subject[MXSJ][LENSJ] ,int score[MXSTD][LENSTD]){
	for(int i=0 ; i<x ; i++){
		for(int j=0 ; j<y ; j++){
			printf("%s %s score : ",name[i],subject[j]);
			scanf("%d",&score[i][j]);
		}
	}
}
 void setgrade(int x,int y,int score[MXSTD][LENSTD],char* grade[MXSTD][LENSTD]){
 	for(int i=0 ;i<x ; i++){
 		for(int j=0 ; j<y ; j++){
 			if(score[i][j]>=80){
 				grade[i][j] = "A";
			 }else if(score[i][j]>=75){
			 	grade[i][j] = "B+";
			 }else if(score[i][j]>=70){
			 	grade[i][j] = "B";
			 }else if(score[i][j]>=65){
			 	grade[i][j] = "C+";
			 }else if(score[i][j]>=60){
			 	grade[i][j] = "C";
			 }else if(score[i][j]>=55){
			 	grade[i][j] = "D+";
			 }else if(score[i][j]>=50){
			 	grade[i][j] = "D";
			 }else
			 	grade[i][j] = "F";
			 	 
			 
		 }
	 }
 	
 }void showheader(int y,char subject[MXSJ][LENSJ]){
 		printf("%10s %10s ","ID","NAME");
 		for(int i=0 ; i<y ; i++){
 			printf("%10s",subject[i]);
		 }
		 printf("\n");
 	
 }
 void showall(int x,int y,char id[MXSJ][LENSTD],char name[MXSTD][LENSTD],char*grade[MXSTD][LENSTD]){
 	for(int i=0 ; i<x ; i++){
 		printf("%10s %10s ",id[i],name[i]);
 		for(int j=0 ;j<y ;j++){
 			printf("%10s",grade[i][j]);
		 }
		 printf("\n");
	 }
 }
 
 int checkF(int x,int y,int  score[MXSTD][LENSTD]){
 	int countf=0;
 	for(int i= 0 ;i<x ; i++){
 		for(int j=0 ;j<y ;j++){
 			if(score[i][j]<50)
 			countf=countf+1;
		 }
	 }return countf;
 }
 int checkFID (int x,int y, char id[MXSJ][LENSTD],int  score[MXSTD][LENSTD]){
 	char scf[MXSJ];
 	int count=0 ;
 	printf("Enter you ID :");
 	scanf("%s",scf);
 	
	for(int i=0 ;i<x;i++){
		for(int j=0 ;j<y;j++){
			if(strcmp(scf,id[i])==0){
			
			if (score[i][j]<50){
				count=count+1;
			}}
			
		
	}
} return count;
 }
 
 


main(){
	char id[MXSJ][LENSTD],name[MXSTD][LENSTD];
	char subject[MXSJ][LENSJ];
	int  score[MXSTD][LENSTD];
	char* grade[MXSTD][LENSTD];
	int  x=getstudent(id,name);
	int  y=getsubject(subject);
	getscore(x,y,name,subject,score);
	setgrade(x,y,score,grade);
	showheader(y,subject);
	showall(x,y,id,name,grade);
	int F=checkF(x,y,score);
	printf("in classroom F =  %d\n",F);
    
	printf("stdent F = %d",checkFID(x,y,id,score));
	
}
