#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
#define COLS 38
#define NAME_SIZE 26
#define MAX_AEM 5
#define MAX_ONOMA 25
#define MAX_PAULES 20
#define ONOMA_AEM 31


struct studentData{
	
	int aem,thesi;
	char name[NAME_SIZE];
	float grade;
};

int metritis(struct studentData records[]);
void printer(struct studentData records[],int pli8os);
void printer_paulas();
void selection_sort(struct studentData records[],int pli8os);
void insertion_sort(struct studentData records[],int pli8os);
int find_name_aem(char onoma[],int aem,int used_rows,struct studentData records[]);
void  find_all_records(char onoma[],int used_rows,struct studentData records[]);

int main (int argc, char *argv[]){
	
	struct studentData data[LEN];
	int amount,aem_input,thesi;
	char onoma_input[NAME_SIZE],input[ONOMA_AEM],*ptr;
	
	amount=metritis(data);
	printer(data,amount);
	printer_paulas();
	
	selection_sort(data,amount);								//KLISI SINARTISIS selection_sort 
	printer(data,amount);
	printer_paulas();
	
	/*insertion_sort(data,amount);								//Ektipwnei ton pinaka meta tin taksinomisi apo tin insertion_sort
	printer(data,amount);
	printer_paulas();*/
	
	printf("Enter name: Enter ID: \n");
	fgets(input,ONOMA_AEM,stdin);
	ptr=strchr(input,' ');
	aem_input=atoi(ptr);
	*ptr='\0';
	strcpy(onoma_input,input);
	
	thesi=find_name_aem(onoma_input,aem_input,amount,data);
	if (thesi!=-1) {
		printf("%.1f\n",data[thesi].grade);
	}
	else {
		printf("%s, %d Not found\n",onoma_input,aem_input);
	}
	
	printf("Enter name: \n");
	fgets(input,ONOMA_AEM,stdin);
	ptr=strchr(input,'\n');
	*ptr='\0';
	strcpy(onoma_input,input);
	
	find_all_records(onoma_input,amount,data);
	
	return(0);
}

int metritis(struct studentData records[]) {						//EPISTREFEI POSOI FOITITES IPARXOUN (KAI ARXIKOPOIEI TON PINAKA)
	
	int i=0,count;
	char pinakas[COLS],*space_ptr1,*space_ptr2,*space_ptr3;
	float ba8mos;
	
	fgets(pinakas,COLS,stdin);
	while (i<LEN && pinakas[0]!='-') {
		space_ptr1=&pinakas[MAX_AEM];			//Bazoume pointer meta to aem kai to apo8ikeuoume sto prwto pedio tou struct
		*space_ptr1='\0';
		records[i].aem=atoi(pinakas);
		space_ptr2=strchr(space_ptr1+1,' ');
		*space_ptr2='\0';
		strcpy(records[i].name,space_ptr1+1);
		space_ptr3=&pinakas[MAX_AEM+MAX_ONOMA+2];
		ba8mos=atof(space_ptr3);
		records[i].grade=ba8mos;
		i++;
		fgets(pinakas,COLS,stdin);				// Edw diabazoume ta dedomena
	}
	
	count=i;
		
	for (i=count; i<=LEN; i++) {
		records[i].aem=-1;
		strcpy(records[i].name,"");
		records[i].grade=-1.0;
	}
	
	return(count);
}

void printer(struct studentData records[],int amount){			//SINARTISI POU EKTIPWNEI
	char *ptr;
	int i,j;
	
	for (i=0; i<amount; i++){
		ptr=strchr(records[i].name,',');
		printf("%c. ",*(ptr+1));
		j=0;
		while (j<MAX_ONOMA && records[i].name[j]!=','){
			printf("%c",records[i].name[j]);
			j++;
		}
		printf(" %d %.1f\n",records[i].aem,records[i].grade);
	}
	
	
	
}

void printer_paulas(){											//I SINARTISI POU BAZEI TIS PAULES KAI TA \n
	
	int i;
	
	printf("\n");
	for (i=0; i<MAX_PAULES; i++){
		printf("=");
	}
	printf("\n\n");
}

void selection_sort(struct studentData records[],int pli8os){
	
	int position,j,i,ghost_aem,note_count1=0;
	char ghost_name[NAME_SIZE];
	float ghost_grade;
	
	for (i=0; i<pli8os; i++){
		position=i;
		for (j=i; j<pli8os; j++){
			note_count1++;
			if (strcmp(records[j].name,records[position].name)<0){
				position=j;
			}
			else if(strcmp(records[j].name,records[position].name)==0){
				if (records[j].aem<records[position].aem){
					position=j;
				}
			}
		}
		ghost_aem=records[i].aem;
		records[i].aem=records[position].aem;
		records[position].aem=ghost_aem;
		strcpy(ghost_name,records[i].name);
		strcpy(records[i].name,records[position].name);
		strcpy(records[position].name,ghost_name);
		ghost_grade=records[i].grade;
		records[i].grade=records[position].grade;
		records[position].grade=ghost_grade;
	}
	printf("%d note_count1\n",note_count1);
}

void insertion_sort(struct studentData records[],int pli8os){		//I SINARTISI POU TAKSINOMEI SIMFWNA ME ONOMATEPWNIMO KAI AEM TON PINAKA
	
	int wall,pos,note_count2,aemSort,i,temp;
	float gradeSort;
	char nameSort[NAME_SIZE];
	
	for (wall=1; wall<pli8os; wall++){
		strcpy(nameSort,records[wall].name);
		aemSort=records[wall].aem;
		gradeSort=records[wall].grade;
		pos=wall-1;
		while (pos>=0 && strcmp(records[pos].name,nameSort)>0){
			note_count2++;
			strcpy(records[pos+1].name,records[pos].name);
			records[pos+1].aem=records[pos].aem;
			records[pos+1].grade=records[pos].grade;
			pos--;
		}
		strcpy(records[pos+1].name,nameSort);
		records[pos+1].aem=aemSort;
		records[pos+1].grade=gradeSort;
	}
	printf("%d note_count2\n",note_count2);
	for (i=0; i<pli8os-1; i++){
		if (strcmp(records[i].name,records[i+1].name)==0){
			if (records[i].aem>records[i+1].aem){
				temp=records[i].aem;
				records[i].aem=records[i+1].aem;
				records[i+1].aem=temp;
			}
		}
		note_count2++;
	}
}

int find_name_aem(char onoma[],int aem,int used_rows,struct studentData records[]){
	
	int begin,end,mid;
	
	begin=0;
	end=used_rows-1;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (strcmp(records[mid].name,onoma)==0) {
			//if (records[mid].aem==aem){
				return (mid);
			//}
		}
		else if (strcmp(records[mid].name,onoma)<0) {
			begin = mid + 1;
		} 
		else {  
			end = mid - 1;
		}
	}
	return (-1);
}

void  find_all_records(char onoma[],int used_rows,struct studentData records[]){
	
	int i=0;
	
	for (i=0; i<used_rows; i++) {
		if (strcmp(records[i].name,onoma)==0) {
			printf("%d ,%.1f\n", records[i].aem,records[i].grade);
		}
	}
}
