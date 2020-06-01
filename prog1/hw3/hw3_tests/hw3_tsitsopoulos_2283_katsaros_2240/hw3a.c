#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ROWS 100
#define COLS 38
#define MAX_AEM 5
#define MAXL_ONOMA 25

//Eimaste Oi Euastathios Tsitsopoulos(2283) kai Christos Katsaros2240

int main(int argc, char* argv[]) {
	char table[ROWS][COLS],*space_ptr,*ptr,*n_ptr,*grade_ptr;
	int i=0,j,d=0,used_rows,l,grade_table[11],metritis;
	float grade,average_grade=0,sum=0;
	for (i=0; i<=10; i++) { 					//midenizw ton pinaka me tous ba8mous pou 8a xrisimopoisw meta
		grade_table[i]=0;
	}
	
	
	for (i=0; i<ROWS; i++){
		for (j=0; j<COLS; j++){
			table[i][j]='a';
		}
	}
	fgets(table[0],COLS,stdin);
	i=1;
	while (i!=ROWS && table[i-1][0]!='-') {		//Arxikopoioume ton pinaka mexri na broume to simbolo '-' stin 1i 8esi.(simatodotei arnitiko aem
		fgets(table[i],COLS,stdin);
		if (table[i][0]=='-') {
			break;
		}
		i++;
	}
	used_rows=i;
	
	for (j=0; j<used_rows; j++) {						//Kanoume tis aparaitites allages ston pinaka
		space_ptr= strchr(table[j], '\n');
		*space_ptr='\0';
		ptr=&table[j][MAX_AEM+MAXL_ONOMA];
		*ptr='\0';
	}
	d=0;	
	
	for (j=0; j<used_rows; j++) {					//Ektipwnoume ta zitoumena
		n_ptr=strchr(table[j],',');		
		printf("%c. ", *(n_ptr+1));
		d=0;
		while (table[j][MAX_AEM+1+d]!=',') {
			printf("%c",table[j][MAX_AEM+1+d]);
			d++;
		}
		printf(" ");							//Ektipwsi AEM
		for (l=0; l<5; l++) {
			if (table[j][l]!=' ') {
				printf("%c", table[j][l]);
			}
		}
		printf(" ");
		if (table[j][MAX_AEM+MAXL_ONOMA+2]!='\0') {
			grade_ptr=&table[j][MAX_AEM+MAXL_ONOMA+2];	//ektipwsi telikou zitoumenou(ba8mou)
			grade=atof(grade_ptr);
			printf("%2.1f",grade);
		}
		else {
			grade_ptr=&table[j][MAX_AEM+MAXL_ONOMA+1];	//ektipwsi telikou zitoumenou(ba8mou)
			grade=atof(grade_ptr);
			printf("%2.1f",grade);
		}
	printf("\n");
		if (grade==0.0) {						//Gemizoume ton pinaka pli8ous foititwn pou piran 0,1..10.
			grade_table[0]++;
		}
		else if (grade<=1.0) {
			grade_table[1]++;
			
		}
		else if (grade<=2.0) {
			grade_table[2]++;
			
		}
		else if (grade<=3.0) {
			grade_table[3]++;
			
		}
		else if (grade<=4.0) {
			grade_table[4]++;
			
		}
		else if (grade<=5.0) {
			grade_table[5]++;
			
		}
		else if (grade<=6.0) {
			grade_table[6]++;
			
		}
		else if (grade<=7.0) {
			grade_table[7]++;
			
		}
		else if (grade<=8.0) {
			grade_table[8]++;
			
		}
		else if (grade<=9.0) {
			grade_table[9]++;
			
		}
		else if (grade<=10.0) {
			grade_table[10]++;
			
		}
		sum=sum+grade;
	
	}
	average_grade=sum/used_rows;
	metritis=0;
	for (i=0; i<+11; i++) {				//Edw ginetai i ektipwsi twn grammwn klp.
		if (i==0) {
		printf("[ %d,	%d]: ",i,i);
		}
		else if (i<=10) {
			printf("( %d,% 5d]: ",i-1,i);
		}
		for (j=0; j<grade_table[metritis]; j++) {
			printf("-");
		} 
		printf("\n");
		metritis++;
	}
	printf("\n");
	printf("Average: %.2f\n",average_grade);
	return(0);
}
