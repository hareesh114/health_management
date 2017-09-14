/*
 * Author: 2016-17 IIITS DS Group-12 Students 
 * Purpose: Health Monitoring System.
 * Language: Only C
 */

/*GROUP MEMBERS:-Group-012

  Venkata Sai Krishna.Deshineni
  Hareesh.T
  Sai Manoj.Gurram
  Dheeraj.Chappidi*/


// Include Standard Libraries
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<string.h>
#include<unistd.h>


/*
 * Author: VenkataSaiKrishna.Deshineni
 * Purpose: Patients details.
 * Language: Only C
 */

// Define an patient structure 
typedef struct patient{ 
	char patientname[10],aptmntdate[11],patient_city[10],patient_phoneno[11],disease[12],hospital[20],patient_gender[7],martial[11];
	char guardian[20],guardian_phoneno[11],doctorsuggestions[100],tablets[70],nurse[3];
	int bill,balance,age,health,healthdetails,patient_ID;
}PATIENT;

// Define an doctor structure 
typedef struct doctor{
	char doctorname[10],doctor_phoneno[11],doctor_city[10],doctor_gender[7],spec[20];
	PATIENT P;
}DOCTOR;

// Define an element of a BINARY SEARCH TREE 
typedef struct node{ 
	DOCTOR D;
	struct node *right,*left;
}HEALTH;

HEALTH *head=NULL;	

//BST insertion based on age of patient
HEALTH* search(HEALTH *head,HEALTH *bst){
	if(head->D.P.age <= bst->D.P.age && head->left!=NULL){
		search(head->left,bst);
	}
	else if(head->D.P.age <= bst->D.P.age && head->left==NULL){
		head->left=bst;
	}
	else if(head->D.P.age > bst->D.P.age && head->right!=NULL){
		search(head->right,bst);
	}
	else if(head->D.P.age > bst->D.P.age && head->right==NULL){	
		head->right=bst;
	}
}

// insert patient details into the Binary Search Tree 
HEALTH* insert(HEALTH *bst){
	if(head==NULL){
		head=bst;
	}	
	else{
		search(head,bst);		
	}
	return head;
}

//generating a binary search tree..taking input from input.txt file
HEALTH *genHealthDataset(FILE *fp){
	char ch[5000];	
	fp;
	HEALTH *p;
	while(fgets(ch,sizeof(ch),fp)!=NULL){//taking line be line from the file
		char A[50][1000];
		int i,j,k;
		i=0;
		j=0;
		k=0;
		while(ch[i]!='\0'){       
			if(ch[i]!='+'){ //separted by character '+'
				A[j][k]=ch[i];//storing the elements into a 2D array 
				k++;
			}
			else if(ch[i]=='+'){
				A[j][k]='\0'; 
				j++;
				k=0;
			}
			i++;
		}

		p = (HEALTH *)malloc(sizeof(HEALTH));

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

		p->left=NULL;
		p->right=NULL;
		head=insert(p);			
	}
	return head;
} 

char p[30][30];
int sum;

//Recursive function to take patient names into p[][] ...array willnot contain any identical patient names
void patients(HEALTH *health){
	//int size value will be changing globally
	static int size=0;
	int i=0;
	if(health!=NULL){
		for(i=0;i<size;i++){
			if(strcmp(p[i],health->D.P.patientname)==0){
				break;
			}
		}
		if(i==size){
			strcpy(p[size],health->D.P.patientname);
			size++;
		}
		patients(health->left);
		patients(health->right);	
	}
}

//Recursive function to print the list of patients 
void listofpatients(HEALTH *health){

	patients(health);

	if(health!=NULL){
		//to print the details of patients for only one time,if there are more than one entry for him in input.txt file
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;

			printf(" %s\n",health->D.P.patientname);
			listofpatients(health->left);
			listofpatients(health->right);		
		}
	}
} 

//Recursive function to know the appointment dates of patients
void appointmentdate(HEALTH *health){
	if(health!=NULL){
		printf("  %s	      ",health->D.P.patientname);
		printf("%s	      ",health->D.doctorname);
		printf("%s\n",health->D.P.aptmntdate);
		appointmentdate(health->left);
		appointmentdate(health->right);		
	}
} 

//Recursive function to print the details of every patient
void patientdetails(HEALTH *health){
	patients(health);
	if(health!=NULL){
		//to print the details of patients for only one time,if there are more than one entry for him in input.txt file
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			printf("  %s	   ",health->D.P.patientname);
			printf("%d	",health->D.P.age);
			printf("%s	",health->D.P.patient_gender);
			printf("%s	",health->D.P.patient_phoneno);
			printf("%10s",health->D.P.patient_city);
			printf("%20s	    ",health->D.P.guardian);
			printf("%s\n",health->D.P.guardian_phoneno);
			patientdetails(health->left);	
			patientdetails(health->right);
		}	
	}
} 

//Recursive function to know which disease a patient is effected from
void healthdetails(HEALTH *health){
	if(health!=NULL){
		printf("  %s		",health->D.P.patientname);
		printf("%s  \n",health->D.P.disease);
		healthdetails(health->left);
		healthdetails(health->right);		
	}
}

//Recursive function to print the patient details based on special diseases like cancer,brain tumor...
void Specialpatientslistbasedondisease(HEALTH *health){
	if(health!=NULL){
		//prints the patient details only if he is suffering from cancer or braintumor
		if((strcmp(health->D.P.disease,"cancer")==0)||(strcmp(health->D.P.disease,"brain tumor")==0)){
			printf("  %s	    ",health->D.P.patientname);
			printf("%d	    ",health->D.P.age);
			printf("%s	",health->D.P.patient_phoneno);
			printf("%10s	",health->D.P.patient_city);
			printf("%s	\n",health->D.P.disease);
		}
		Specialpatientslistbasedondisease(health->left);
		Specialpatientslistbasedondisease(health->right);
	}
}

//Recursive function to print the nurse name who is being alloted to a patient
void nurseappointed(HEALTH *health){
	patients(health);
	//tranverse through the entire tree untill every node is visited
	if(health!=NULL){
		//to print the details of patients for only one time,if there are more than one entry for him in input.txt file
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			nurseappointed(health->left);
			printf("  %s		",health->D.P.patientname);
			printf("%s  \n",health->D.P.nurse);
			nurseappointed(health->right);		
		}
	}
}   



/*
 * Author: Hareesh.T
 * Purpose: Doctors Deatils.
 * Language: Only C
 */

//defing a character array D[][] globally which contains the doctors names
char D[20][20];

int siz=0,num,sum;

//Recursive function to take doctor names into D[][] ...array willnot contain any identical doctor names
void doctors(HEALTH *health){
	int i=0;
	if(health!=NULL){
		for(i=0;i<siz;i++){
			if(strcmp(D[i],health->D.doctorname)==0){
				break;
			}
		}
		if(i==siz){
			strcpy(D[siz],health->D.doctorname);
			siz++;
		}
		doctors(health->left);
		doctors(health->right);	
	}
}

//Recursive function to print the details of doctor
int doctordetails(HEALTH *health){
	doctors(health);
	if(health!=NULL){
		//to print the details of a doctor for only one time,if there are more than one entry for him in input.txt file
		if(strcmp(D[num],health->D.doctorname)==0){	
			num++;
			printf("  %s	",health->D.doctorname);
			printf("%s	",health->D.doctor_phoneno);
			printf("%s		",health->D.doctor_city);
			printf("%s  \n\n",health->D.spec);
			doctordetails(health->left);
			doctordetails(health->right);					
		}
	}
	return num;
}

//Recursive function to print the appointment dates of a doctor
void printingappointments(HEALTH *health,char D[]){
	if(health!=NULL){
		if(strcmp(D,health->D.doctorname)==0){		
			printf("	%s		",health->D.P.patientname);
			printf("%s\n",health->D.P.aptmntdate);
		}
		printingappointments(health->left,D);
		printingappointments(health->right,D);
	}
}


//Function To print the appointment dates given by all doctors
void doctorsappointmentdates(HEALTH *health,int num){
	for(int i=0;i<num;i++){
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n%s		\n",D[i]);
		//calling a Recursive function to print the appointment dates of a doctor
		printingappointments(health,D[i]);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
}

//Recursive function to know whether a patient is taking his pills on time
void patientHealth(HEALTH *health){
	patients(health);
	if(health!=NULL){
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			health->D.P.healthdetails=rand()%2;
			if(health->D.P.healthdetails==1){
				printf("Patient , %s  is alright,Taking Prescribed Medcines Regularly\n",health->D.P.patientname);
			}
			else if(health->D.P.healthdetails==0){
				printf("Patient , %s  Should Take Care Of Helath,Take Medicines On Regular Basis..!!!\n",health->D.P.patientname);
			}
			patientHealth(health->left);
			patientHealth(health->right);
		}
	}
}

//Recursive function to print the suggestions given by doctors to their patients
void DoctorsSuggestions(HEALTH *health){
	if(health!=NULL){
		DoctorsSuggestions(health->right);
		printf("%s to  ",health->D.doctorname);
		printf("%s  \n",health->D.P.patientname);
		printf("%s\n\n",health->D.P.doctorsuggestions);
		DoctorsSuggestions(health->left);
	}
}

//Recursive function to print tablet schedule of every patient 
void TabletSchedule(HEALTH *health){
	if(health!=NULL){
		printf("%s	",health->D.P.patientname);
		printf("%s	",health->D.doctorname);
		printf("%s\n",health->D.P.disease);
		printf("%s\n\n",health->D.P.tablets);
		TabletSchedule(health->left);
		TabletSchedule(health->right);
	}
}

//Recursive function to print the balance amount of the patient to be paid
void Bill(HEALTH *health){
	patients(health);
	if(health!=NULL){
		//to print the details of patients for only one time,if there are more than one entry for him in input.txt file
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			printf("  %s	  ",health->D.P.patientname);
			printf("%d		",health->D.P.bill);
			health->D.P.balance=rand()%2;		
			if(health->D.P.balance==1){
				printf("Balance Not Yet Cleared\n\n");
			}
			else if(health->D.P.balance==0){
				printf("----Paid----\n\n");
			}
			Bill(health->left);
			Bill(health->right);
		}
	}
} 

/*
 * Author: DHERRAJ.CHAPPIDI  
 * Purpose: Searching algorithms.
 * Language: Only C
 */

//Recursive C function to search for patient details based on  given disease 
void SearchByDiseaseName(HEALTH *health,char *disease){
	if(health!=NULL){
		if(strcmp(health->D.P.disease,disease)==0){
			printf("  %s	   ",health->D.P.patientname);
			printf("%d	",health->D.P.age);
			printf("%s	",health->D.P.patient_gender);
			printf("%s	",health->D.P.patient_phoneno);
			printf("%10s",health->D.P.patient_city);
			printf("%20s	    ",health->D.P.guardian);
			printf("%s\n",health->D.P.guardian_phoneno);
			patientdetails(health->left);	
			patientdetails(health->right);
		}
		SearchByDiseaseName(health->left,disease);
		SearchByDiseaseName(health->right,disease);
	}
} 

//defing a character array p[][] globally which contains the patients names
char p[30][30];
int sum,flag;

//Recursive C function to search for all patients details in a given hospital
void SearchByHospital(HEALTH *health,char *hospital){
	patients(health);
	if(health!=NULL){
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			if(strcmp(health->D.P.hospital,hospital)==0){
				printf("  %s	   ",health->D.P.patientname);
				printf("%d	",health->D.P.age);
				printf("%s	",health->D.P.patient_gender);
				printf("%s	",health->D.P.patient_phoneno);
				printf("%10s",health->D.P.patient_city);
				printf("%20s			",health->D.P.guardian);
				printf("%s	\n",health->D.P.guardian_phoneno);
			}
			SearchByHospital(health->left,hospital);
			SearchByHospital(health->right,hospital);
		}
	}
} 

//Recursive C function to search for all patients details in given city
void SearchByCity(HEALTH *health,char *patient_city){
	patients(health);
	if(health!=NULL){
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			if(strcmp(health->D.P.patient_city,patient_city)==0){
				printf("  %s	   ",health->D.P.patientname);
				printf("%d	",health->D.P.age);
				printf("%s	",health->D.P.patient_gender);
				printf("%s	",health->D.P.patient_phoneno);
				printf("%10s",health->D.P.patient_city);
				printf("%20s			",health->D.P.guardian);
				printf("%s	\n",health->D.P.guardian_phoneno);

			}
			SearchByCity(health->left,patient_city);
			SearchByCity(health->right,patient_city);
		}
	}
} 

//Recursive C function to search for all patients details under a given doctor
void SearchByDoctor(HEALTH *health,char *doctor){
	if(health!=NULL){
		if(!strcmp(health->D.doctorname,doctor)){
			printf("  %s	   ",health->D.P.patientname);
			printf("%d	",health->D.P.age);
			printf("%s	",health->D.P.patient_gender);
			printf("%s	",health->D.P.patient_phoneno);
			printf("%10s",health->D.P.patient_city);
			printf("%20s			",health->D.P.guardian);
			printf("%s	\n",health->D.P.guardian_phoneno);

		}
		SearchByDoctor(health->left,doctor);
		SearchByDoctor(health->right,doctor);
	}
} 

//Recursive C function to search for patient details based on  given patientname
void SearchByPatientName(HEALTH *health,char *patient){
	if(health!=NULL){
		if(!flag){
			if(!strcmp(health->D.P.patientname,patient)){
				flag=1;
				printf("Patient Name:- %s  ",health->D.P.patientname);
				printf("Age:- %d  ",health->D.P.age);
				printf("Gender:- %s  ",health->D.P.patient_gender);
				printf("Phone no:-%s  ",health->D.P.patient_phoneno);
				printf("Martial Status:-%s  ",health->D.P.martial);
				printf("Guardian:-%s  ",health->D.P.guardian);
				printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
				printf("City:- %s  \n",health->D.P.patient_city);

			}
		}
		SearchByPatientName(health->left,patient);
		SearchByPatientName(health->right,patient);
	}
} 

//Recursive C function to search for all patient details whose age lies betwn given input age1 and age2 ranges
void SearchByAge(HEALTH *health,int min,int max){
	patients(health);
	if(health!=NULL){
		if(strcmp(p[sum],health->D.P.patientname)==0){	
			sum++;
			if((health->D.P.age>=min)&&(health->D.P.age<=max)){
				printf("  %s	    ",health->D.P.patientname);
				printf("%d	",health->D.P.age);
				printf("%s	",health->D.P.patient_gender);
				printf("%s	",health->D.P.patient_phoneno);
				printf("%10s",health->D.P.patient_city);
				printf("%20s			",health->D.P.guardian);
				printf("%s	\n",health->D.P.guardian_phoneno);
			}
			SearchByAge(health->left,min,max);
			SearchByAge(health->right,min,max);
		}
	}
}

//Recursive C function to search for all doctors details to whom a given patient is consulted
void nodoctors(HEALTH *health,char *patient){
	if(health!=NULL){
		if(strcmp(health->D.P.patientname,patient)==0){
			printf("  %s	   ",health->D.P.patientname);
			printf("%d	    ",health->D.P.age);
			printf("%s	",health->D.P.patient_phoneno);
			printf("%10s	",health->D.P.patient_city);
			printf("%s	\n",health->D.P.disease);
		}
		nodoctors(health->left,patient);
		nodoctors(health->right,patient);
	}
}


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
		printf("	%s	",health->D.P.patientname);
		printf("%d\n",health->D.P.patient_ID);
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

int main(int argc,char *argv[]){

	printf("\n\n		 				       HEALTH MONITORING SYSTEM\n");	
	printf("						       ------------------------\n\n");
	HEALTH *health;
	FILE *fp;
	fp=(argc>1)?fopen(argv[1],"r+"):fopen("input.txt","r+");

	//Generating A Binary Search Tree DATASTRUCTURE By Loading details from input.txt file
	health=genHealthDataset(fp);
	fclose(fp);

					printf("\nPATIENTS\n\n");
					listofpatients(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("PATIENTS    DOCTORS       APPOINTMENT DATES\n\n");
					appointmentdate(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("PATIENTS       DISEASES\n\n");
					healthdetails(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					
					sum=0;
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("PATIENTS   AGE   SEX     PHN.NO.           CITY       PATIENT/GAURDIAN    PATIENT/GAURDIAN P.NO\n\n");
					patientdetails(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("PATIENTS   AGE        PHN.NO.       CITY         DISEASE\n\n");
					Specialpatientslistbasedondisease(health);
					printf("\n\n--------------------------------------------------------------\n\n");
				
					sum=0;
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("PATIENTS      NURSE\n\n");
					nurseappointed(health);
					printf("\n\n--------------------------------------------------------------\n\n");
				
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("		DOCTOR DEATAILS:- \n\n");
					num=0;
					printf("DOCTOR    PHN.NO.        CITY           SPEACIALIZATION\n\n");
					int k=doctordetails(health);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("DOCTOR	PATIENT		APPOINTMENT-DATE\n");
					doctorsappointmentdates(health,k);
					printf("\n\n--------------------------------------------------------------\n\n");
					sum=0;
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("		 Report:-\n\n");
					patientHealth(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("		Doctors Suggestions to patients\n\n");
					DoctorsSuggestions(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					sum=0;
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("	Patients Bill Details\n\n");
					printf("  NAME	  AMOUNT	        STATUS\n");
					Bill(health);
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("		Tablet Schedule Of Patients\n\n");
					TabletSchedule(health);
					printf("\n\n--------------------------------------------------------------\n\n");
			
			
					printf("SEARCH OF PATIENT DETAILS BY PATIENT NAME:- \n\n");
					char paname[10];
					flag=0;
					printf("Give The Patient Name:-\n\n");
					scanf("%[^\n]s",paname);
					getchar();
					SearchByPatientName(health,paname);	
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("SEARCH OF PATIENT DETAILS BY DOCTOR:- \n\n");
					char doname[10];
					printf("Give The Doctor Name:-\n");
					scanf("%[^\n]s",doname);
					getchar();
					printf("PATIENTS   AGE   SEX     PHN.NO.           CITY           PARENT/GAURDIAN         PARENT/GAURDIAN P.NO\n\n");
					SearchByDoctor(health,doname);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("SEARCH OF PATIENT DETAILS BY DISEASE:- \n\n");
					char dis[20];
					printf("Give The Disease Name:-\n");
					scanf("%[^\n]s",dis);
					getchar();
					printf("PATIENTS   AGE   SEX     PHN.NO.           CITY              GAURDIAN      GAURDIAN P.NO\n\n");
					SearchByDiseaseName(health,dis);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("SEARCH OF PATIENT DETAILS BY HOSPITAL:- \n\n");
					char hos[20];
					sum=0;
					printf("Give The Hospital Name:-\n");
					scanf("%[^\n]s",hos);
					getchar();
					printf("PATIENTS   AGE   SEX     PHN.NO.             CITY           PARENT/GAURDIAN         PARENT/GAURDIAN P.NO\n\n");
					SearchByHospital(health,hos);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("SEARCH OF PATIENT DETAILS BY CITY:- \n\n");
					char cit[10];
					printf("Give The City Name:-\n");
					sum=0;
					scanf("%[^\n]s",cit);
					getchar();
					printf("PATIENTS   AGE   SEX     PHN.NO.             CITY           PARENT/GAURDIAN         PARENT/GAURDIAN P.NO\n\n");
					SearchByCity(health,cit);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("		Doctors Patient Is Consulting\n\n");
					char paname[10];
					printf("Give The Patient Name:-\n");
					scanf("%[^\n]s",paname);
					getchar();
					printf("PATIENTS   AGE       PHN.NO.      CITY          DISEASE\n\n");
					nodoctors(health,paname);
					printf("\n\n--------------------------------------------------------------\n\n");
			
					printf("\n\n--------------------------------------------------------------\n\n");
					printf("\nSEARCH OF PATIENTS BY SELECTING RANGE OF THEIR AGE:- \n\n");
					int age1,age2;
					sum=0;
					printf("Min Age:-\n");
					scanf("%d",&age1);
					printf("Max Age:-\n");
					scanf("%d",&age2);
					printf("PATIENTS   AGE   SEX     PHN.NO.             CITY           PARENT/GAURDIAN         PARENT/GAURDIAN P.NO\n\n");
					SearchByAge(health,age1,age2);
					printf("\n--------------------------------------------------------------\n\n");			
			
			HEALTHL *healthl;
			FILE *fp10;
			fp10=(argc>1)?fopen(argv[1],"r+"):fopen("input.txt","r+");

			//Generating A LinkedList DATASTRUCTURE By Loading details from input.txt file
			healthl=genHealthDataset1(fp10);
			fclose(fp10);

			printf("\n\n		DATABASE MANAGEMENT\n\n");

			

				printf("\n->->->Details Of Every Doctor Are Loaded In A File On Doctor Name<-<-<-\n\n");
				printf("	DETAILS OF D1 CAN BE VIEWED IN D1.txt\n");
				printf("	DETAILS OF D2 CAN BE VIEWED IN D2.txt\n");
				printf("	DETAILS OF D3 CAN BE VIEWED IN D3.txt\n");
				printf("	DETAILS OF D4 CAN BE VIEWED IN D4.txt\n\n");	
				FILE *fp1 = fopen("D1.txt", "w+");
				FILE *fp2 = fopen("D2.txt", "w+");
				FILE *fp3 = fopen("D3.txt", "w+");
				FILE *fp4 = fopen("D4.txt", "w+");
				Loadlistofpatientsunderdoctor(healthl,fp1,fp2,fp3,fp4);	
				fclose(fp1);
				fclose(fp2);
				fclose(fp3);
				fclose(fp4);

				printf("     Patients In DataBase\n\n");
				printf("       NAME	ID\n");
				printf("      -------------\n");
				print(healthl);

					printf("\n	Details Of Expired Patient \n\n");
					flag=0;
					expiredpatient(healthl,1);

					printf("\n->->->->Patient Details Are Removed Permanently From DataBase");
					printf("\n\n****Deleted History Can Be Viewed In history.txt****\n\n");
					Removeexpiredpatientdetails(healthl,"input.txt",1);

					printf("\nDeleting The Expired Patient\n\n");
					healthl=deleteexpiredpatient(healthl,1);

					printf("\n<<The Doctor-Patient Lists Are Updated After Deleting The Details Of Expired Patient>>\n\n");
					FILE *fp5 = fopen("D1.txt", "w+");
					FILE *fp6 = fopen("D2.txt", "w+");
					FILE *fp7 = fopen("D3.txt", "w+");
					FILE *fp8 = fopen("D4.txt", "w+");
					Loadlistofpatientsunderdoctor(healthl,fp5,fp6,fp7,fp8);	
					fclose(fp5);
					fclose(fp6);
					fclose(fp7);
					fclose(fp8);

			
	
	return 0;
} 
