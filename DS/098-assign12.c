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
			printf("Doctor Name:- %s  ",health->D.doctorname);
			printf("Phone no:-%s  ",health->D.doctor_phoneno);
			printf("City:- %s  ",health->D.doctor_city);
			printf("Gender:- %s  ",health->D.doctor_gender);
			printf("Specialization:- %s  \n\n",health->D.spec);
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
			printf("Patient Name:- %s  ",health->D.P.patientname);
			printf("Appointment Date:- %s\n",health->D.P.aptmntdate);
		}
		printingappointments(health->left,D);
		printingappointments(health->right,D);
	}
}

//Function To print the appointment dates given by all doctors
void doctorsappointmentdates(HEALTH *health,int num){
	for(int i=0;i<num;i++){
		printf("\n%s\n",D[i]);
		//calling a Recursive function to print the appointment dates of a doctor
		printingappointments(health,D[i]);
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
		printf("%s ",health->D.P.patientname);
		printf("from %s ",health->D.doctorname);
		printf("because of %s\n",health->D.P.disease);
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
			printf("Patient Name:- %s  ",health->D.P.patientname);
			printf("Bill Amount:- %d  ",health->D.P.bill);
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
