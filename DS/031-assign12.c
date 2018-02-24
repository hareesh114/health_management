/*
 * Author:Manoj.G
 * Purpose: Deleting the data of the expired patients.
 * Language: Only C
 */

//Define Linked list node
typedef struct node1{ 
	DOCTOR D;
	struct node1 *next;
}HEALTHL;

HEALTHL *temp1=NULL;

//Inserting a node from back.
HEALTHL *insertl(HEALTHL *healthl){
	healthl->next=temp1;
	temp1=healthl;

	return healthl;
}

HEALTHL *tail=NULL;

//Reversing the Linkedlist ..So as to get the output details in correct order
HEALTHL *reverselist(HEALTHL *head){
	HEALTHL *next=NULL;
	HEALTHL *tail=NULL;
	int count=0;
	while(head!=NULL){
		next=head->next;
		head->next=tail;
		tail=head;
		head=next;
	}
	return tail;
}

//Loading All The deatils from input.txt file into the linkedlist
HEALTHL *genHealthDataset1(FILE *fp){
	char ch[5000];	
	fp;
	HEALTHL *p;
	HEALTHL *healthl = NULL;
	while(fgets(ch,sizeof(ch),fp)!=NULL){//taking line by line..from the inputfile
		char A[50][1000];
		int i,j,k;
		i=0;
		j=0;
		k=0;
		while(ch[i]!='\0'){       
			if(ch[i]!='+'){
				A[j][k]=ch[i];//storing the elements into a 2D array separted by character '+'
				k++;
			}
			else if(ch[i]=='+'){
				A[j][k]='\0'; 
				j++;
				k=0;
			}
			i++;
		}

		p = (HEALTHL *)malloc(sizeof(HEALTHL));

		strcpy((p->D.P.patientname),A[0]);
		strcpy((p->D.P.aptmntdate),A[1]);
		strcpy((p->D.P.patient_city),A[2]);
		strcpy((p->D.P.patient_phoneno),A[3]);
		strcpy((p->D.P.disease),A[4]);
		strcpy((p->D.doctorname),A[5]);
		p->D.P.age=atoi(A[6]);//converting character-string into integer datatype
		strcpy((p->D.P.hospital),A[7]);
		strcpy((p->D.doctor_phoneno),A[8]);
		strcpy((p->D.doctor_city),A[9]);
		strcpy((p->D.P.patient_gender),A[10]);
		strcpy((p->D.doctor_gender),A[11]);
		strcpy((p->D.spec),A[12]);
		strcpy((p->D.P.martial),A[13]);
		strcpy((p->D.P.guardian),A[14]);
		strcpy((p->D.P.guardian_phoneno),A[15]);
		strcpy((p->D.P.doctorsuggestions),A[16]);
		strcpy((p->D.P.tablets),A[17]);
		p->D.P.bill=atoi(A[18]);
		strcpy((p->D.P.nurse),A[19]);
		p->D.P.patient_ID=atoi(A[20]);


		p->next=NULL;

		//Calling insert function Inserting A Node into Linkedlist
		healthl=insertl(p);			
	}
	//Calling A Function for reversing the entire so generated Linkedlist
	healthl=reverselist(healthl);
	//returing the head pointer of the linkedlist
	return healthl;
} 


//Function to remove the details of patient from the database permanently using the given ID
//And the deleted Data goes into a history.txt file
void Removeexpiredpatientdetails1(char filename[],int patient){
	FILE *fileptr1,*fileptr2,*fileptr3;
	char ch,a[1000],b[1000][1000];
	int delete_line, temp = 1,i,count=1,j,k;
	fileptr1 = fopen(filename, "r");
	while(fgets(a,sizeof(a),fileptr1)!=NULL){
		i=0;
		j=0;
		k=0;
		while(a[i] != '\0'){
			if(a[i]!='+'){			
				b[j][k]=a[i];
				k++;
			}
			else{
				b[j][k] = '\0';
				j++;
				k=0;
			}
			i++;
		}
		if(patient==atoi(b[20])){
			delete_line=count;
			break;	
		}
		count++;
	}
	rewind(fileptr1);
	//internally this function is creating the replica.txt file and history.txt file
	fileptr2=fopen("replica.txt", "w+");
	fileptr3=fopen("history.txt","a");
	ch=getc(fileptr1);
	//Taking character by character from the input file
	while (ch!=EOF){
		//If we donot want to delete the entry this character goes into replica.txt file
		if(temp!=delete_line){
			putc(ch,fileptr2);
		}
		//If we want to delete the entry this character goes into history.txt file
		else if(temp==delete_line){
			putc(ch,fileptr3);
		}
		if(ch=='\n'){ 
			temp++;
		}
		ch = getc(fileptr1);
	}
	//closing the input.txt file and history.txt file and replica.txt file
	fclose(fileptr1);
	fclose(fileptr2);
	fclose(fileptr3);
	//deleting the input.txt file
	remove(filename);
	//renaming the replica.txt file to input.txt file
	rename("replica.txt", filename);
}

//C Function to delete the expired patient details from the file  
void Removeexpiredpatientdetails(HEALTHL *health1,char filename[],int patient){
	while(health1!=NULL){
		//if our given ID matcches with the entry's ID in file..
		if(health1->D.P.patient_ID==patient){
			//Calling a C function which deletes the entry in the file
			Removeexpiredpatientdetails1(filename,patient);
		}
		health1=health1->next;
	}
}

//Loading all the doctor-patient details into a file named under each doctor name
void Loadlistofpatientsunderdoctor(HEALTHL *healthl,FILE *fp1,FILE *fp2,FILE *fp3,FILE *fp4){
	char ch[5000]; 
	while(healthl!=NULL){
		if(strcmp(healthl->D.doctorname,"D1")==0){
			fputs(healthl->D.P.patientname,fp1);
			fputs(" ",fp1);
			fputs(healthl->D.P.aptmntdate,fp1);
			fputs(" ",fp1);
			fputs(healthl->D.P.patient_city,fp1);
			fputs(" ",fp1);
			fputs(healthl->D.P.patient_phoneno,fp1);
			fputs(" ",fp1);
			fputs(healthl->D.P.patient_gender,fp1);
			fputs(" ",fp1);
			fputs(healthl->D.P.disease,fp1);
			fputs("\n",fp1);
		}
		else if(strcmp(healthl->D.doctorname,"D2")==0){
			fputs(healthl->D.P.patientname,fp2);
			fputs(" ",fp2);
			fputs(healthl->D.P.aptmntdate,fp2);
			fputs(" ",fp2);
			fputs(healthl->D.P.patient_city,fp2);
			fputs(" ",fp2);
			fputs(healthl->D.P.patient_phoneno,fp2);
			fputs(" ",fp2);
			fputs(healthl->D.P.patient_gender,fp2);
			fputs(" ",fp2);
			fputs(healthl->D.P.disease,fp2);
			fputs("\n",fp2);
		}
		else if(strcmp(healthl->D.doctorname,"D3")==0){
			fputs(healthl->D.P.patientname,fp3);
			fputs(" ",fp3);
			fputs(healthl->D.P.aptmntdate,fp3);
			fputs(" ",fp3);
			fputs(healthl->D.P.patient_city,fp3);
			fputs(" ",fp3);
			fputs(healthl->D.P.patient_phoneno,fp3);
			fputs(" ",fp3);
			fputs(healthl->D.P.patient_gender,fp3);
			fputs(" ",fp3);
			fputs(healthl->D.P.disease,fp3);
			fputs("\n",fp3);
		} 
		else if(strcmp(healthl->D.doctorname,"D4")==0){
			fputs(healthl->D.P.patientname,fp4);
			fputs(" ",fp4);
			fputs(healthl->D.P.aptmntdate,fp4);
			fputs(" ",fp4);
			fputs(healthl->D.P.patient_city,fp4);
			fputs(" ",fp4);
			fputs(healthl->D.P.patient_phoneno,fp4);
			fputs(" ",fp4);
			fputs(healthl->D.P.patient_gender,fp4);
			fputs(" ",fp4);
			fputs(healthl->D.P.disease,fp4);
			fputs("\n",fp4);
		}	
		healthl=healthl->next;
	}
} 


//Deleting a node from linkedlist
HEALTHL* deletenode(HEALTHL *health,int ID){
	HEALTHL *temp1=health;
	HEALTHL *temp;

	if(health==NULL){	
		return health;
	}

	if(health->D.P.patient_ID==ID){
		temp=health;
		health=health->next;
		free(temp);
		return health;
	}
	else{
		while(health->next!=NULL && (health->next)->D.P.patient_ID!=ID){	
			health=health->next;
		}
		if(health->next->next==NULL){
			temp=health->next;
			health->next=NULL;
			free(temp);
			return temp1;	
		}
		else{
			temp=health->next;
			health->next=health->next->next;
			free(temp);
			return temp1;
		}
	}
}

//Deleting the patient node from Linkedlist who has been expired 
HEALTHL* deleteexpiredpatient(HEALTHL *health,int ID){
	HEALTHL *temp2=health;
	HEALTHL *temp1;

	while(temp2!=NULL){
		if(temp2->D.P.patient_ID==ID){
			temp2=health=deletenode(health,ID);
		}
		temp2=temp2->next;
	}

	return health;
}

//printing the patient details
void print(HEALTHL *health){
	while(health!=NULL){
		printf("Patient Name:-%s  ",health->D.P.patientname);
		printf("Patient ID:-%d\n",health->D.P.patient_ID);
		health=health->next;
	}
} 

int flag;
//Printing Of the Details Of the patient who has been expired
void expiredpatient(HEALTHL *healthl,int ID){
	HEALTHL *health1=healthl;
	while(health1!=NULL){
		if(flag!=1){
			if(health1->D.P.patient_ID==ID){
				flag=1;
				printf("Patient Name:-%s\n",health1->D.P.patientname);
				printf("Age:- %d  ",health1->D.P.age);
				printf("sex:-%s  ",health1->D.P.patient_gender);
				printf("Phone no:-%s  ",health1->D.P.patient_phoneno);
				printf("City:- %s  ",health1->D.P.patient_city);
				printf("martial status:- %s  ",health1->D.P.martial);
				printf("guardian/parent:- %s  ",health1->D.P.guardian);
				printf("guardian/parent phonenum:- %s  \n",health1->D.P.guardian_phoneno);
			}
		}
		health1=health1->next;
	}
	//If The given ID doesn't Match with any ID in database..
	if(flag==0){
		printf("\n\nNo Patient Is In DataBase With The Given ID\n\n");
		printf("	$$$$--EXIT--$$$$\n");
		exit(-1);
	}
} 
