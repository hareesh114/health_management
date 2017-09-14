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
