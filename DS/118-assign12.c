/*
 * Author: DHERRAJ.CHAPPIDI  
 * Purpose: Searching algorithms.
 * Language: Only C
 */

//Recursive C function to search for patient details based on  given disease 
void SearchByDiseaseName(HEALTH *health,char *disease){
	if(health!=NULL){
		if(strcmp(health->D.P.disease,disease)==0){
			printf("Patient Name:- %s  ",health->D.P.patientname);
			printf("Age:- %d  ",health->D.P.age);
			printf("Gender:- %s  ",health->D.P.patient_gender);
			printf("Phone no:-%s  ",health->D.P.patient_phoneno);
			printf("Martial Status:-%s  ",health->D.P.martial);
			printf("Guardian:-%s  ",health->D.P.guardian);
			printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
			printf("City:- %s  \n",health->D.P.patient_city);
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
				printf("Patient Name:- %s  ",health->D.P.patientname);
				printf("Age:- %d  ",health->D.P.age);
				printf("Gender:- %s  ",health->D.P.patient_gender);
				printf("Phone no:-%s  ",health->D.P.patient_phoneno);
				printf("Martial Status:-%s  ",health->D.P.martial);
				printf("Guardian:-%s  ",health->D.P.guardian);
				printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
				printf("City:- %s  \n",health->D.P.patient_city);
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
				printf("Patient Name:- %s  ",health->D.P.patientname);
				printf("Age:- %d  ",health->D.P.age);
				printf("Gender:- %s  ",health->D.P.patient_gender);
				printf("Phone no:-%s  ",health->D.P.patient_phoneno);
				printf("Martial Status:-%s  ",health->D.P.martial);
				printf("Guardian:-%s  ",health->D.P.guardian);
				printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
				printf("City:- %s  \n",health->D.P.patient_city);
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
			printf("Patient Name:- %s  ",health->D.P.patientname);
			printf("Age:- %d  ",health->D.P.age);
			printf("Gender:- %s  ",health->D.P.patient_gender);
			printf("Phone no:-%s  ",health->D.P.patient_phoneno);
			printf("Martial Status:-%s  ",health->D.P.martial);
			printf("Guardian:-%s  ",health->D.P.guardian);
			printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
			printf("City:- %s  \n",health->D.P.patient_city);
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
				printf("Patient Name:- %s  ",health->D.P.patientname);
				printf("Age:- %d  ",health->D.P.age);
				printf("Gender:- %s  ",health->D.P.patient_gender);
				printf("Phone no:-%s  ",health->D.P.patient_phoneno);
				printf("Martial Status:-%s  ",health->D.P.martial);
				printf("Guardian:-%s  ",health->D.P.guardian);
				printf("Guardian phonenum:-%s  ",health->D.P.guardian_phoneno);
				printf("City:- %s  \n",health->D.P.patient_city);
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
			printf("Doctor Name:- %s  ",health->D.doctorname);
			printf("Phone no:-%s  ",health->D.doctor_phoneno);
			printf("City:- %s  ",health->D.doctor_city);
			printf("Gender:- %s  ",health->D.doctor_gender);
			printf("Specialization:- %s  \n\n",health->D.spec);
		}
		nodoctors(health->left,patient);
		nodoctors(health->right,patient);
	}
}
