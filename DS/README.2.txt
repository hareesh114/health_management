<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

						HEALTH MONITORING SYSTEM
						------------------------
							DS-PROJECT
							- - - - - -

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

Group Members:-
~~~~~~~~~~~~~~~

	*Venkata Sai Krishna.Deshineni (201611158--ECE) venkatasaikrishna.d16@iiits.in   
	*Hareesh.T (201601098--CSE)  hareesh.t16@iiits.in
	*Manoj.Gurram (201601031--CSE)  saimanoj.g16@iiits.in
	*Dheeraj.Chappidi (201611118--ECE)  dheeraj.c16@iiits.in

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

At Health Monitoring Systems (HMS), our goal is to provide Public Health officials with the tools that will help them to know the health details of the communities they serve.


The Tools We Have Constructed Using C language are:-
	->Patients details.
	->Doctors Deatils.
	->Searching algorithms.
	->Deleting the data of the expired patients(Only For Special Management People).

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	
==>>Patients Details<<==  (VenkataSaiKrishna.Deshineni)
^^^^^^^^^^^^^^^^^^^^^^^^

			***Inserting The Details Into A BINARY SEARCH TREE from input.txt file***
			-> HEALTH *genHealthDataset(FILE *fp);
	
	1.) List Of Patients
		prints the list of patinets along with their unique ID's
		->void listofpatients(HEALTH *health);
		
	2.) Appointment Dates Of each Patient 
		prints the appointment dates of patients to one or more doctors 
		->void appointmentdate(HEALTH *health);
	
	3.) Regarding Health Details Of Every Patient 
		prints the patient name and the disease he is suffering from.
		->void patientdetails(HEALTH *health);
	
	4.) Patients Details 
		Prints the all patients details like patientname,gender,age,married/notmarried,phonenumber,city,guardian.
		->void healthdetails(HEALTH *health);
	
	5.) Special Patients List Based On Disease
		prints the details of patients only if he is considered that he is facing a special disease like cancer,brain tumor,e.t.c.
		->void Specialpatientslistbasedondisease(HEALTH *health);
	
	6.) Nurse Appointed To Each Patient 
		prints the name of the nurse who has been appointed to takecare of patient.
		->void nurseappointed(HEALTH *health);
		
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	
==>>Doctors Details<<== (Hareesh.T)
^^^^^^^^^^^^^^^^^^^^^^^

	1.) Doctor's Details
		prints the All Doctors details like doctorname,phonenum,speciality,gender,city.	
		->
	
	2.) DOCTOR'S APPOINMENT DATES
		prints the appointment dates given to patients of all doctors.
		->
	
	3.) Health Report
		It Is Actually Done by taking a random number[0,1]
		If random number generated is 1->Patient Is taking his pills regularly as prescribed by doctor
		Else If random number generated is 0->Patient is not taking the tablets on regular basis as prescribed by doctor 
	
	4.) Doctors Suggestions to patients
		prints the all the patient's names and thier corresponding doctornames with the suggestions given to them 
	
	5.) Patients Bill Details
		prints the Bill details of the patinets randomly.
		if random number generated is 
			1,then..it prints the bill is paid.
			else, the balance amount to be paid is printed which is taken from the input.txt file
	
	6.) Tablet Schedule Of Patients
		prints the patient's names along with their doctor names and tablet schedule given to them

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

==>>Seacrhing Tools<<==   (Dheeraj.CH)
^^^^^^^^^^^^^^^^^^^^^^^

	1.) SEARCH OF PATIENT DETAILS BY DISEASE
		prints the all patients details who are suffering from a common disease by taking diseasename as input
	
	2.)SEARCH OF PATIENT DETAILS BY HOSPITAL
		prints the all patients details who are getting treated from a common hospital by taking hospitalname as input
		
	3.)SEARCH OF PATIENT DETAILS BY CITY
		prints the all patients details who are in a city by taking cityname as input
		
	4.)SEARCH OF PATIENT DETAILS BY DOCTOR
		prints the all patients details who are under a doctor by taking the doctorname as input
	
	5.)SEARCH OF PATIENT DETAILS BY PATIENT NAME
		prints the patient details by taking the patient name as input
		
	6.) SEARCH OF PATIENTS WHOSE AGE IS IN RANGE
		prints the all patients details who are between the two agelimits, which are taken from input as min.age and max.age
	
	7.)SEARCH OF DOCTOR DETAILS BY PATIENT NAME
		prints all the doctor details who are treating a patient by taking patientname as input
			
		
		
	
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

==>>MANGEMENT<<==    (Manoj.G)
^^^^^^^^^^^^^^^^^

				***Inserting The Details Into A LINKED LIST from input.txt file***

	******This Tool is accessible only to the particular management members,which opens only by typing the correct password.******
	
	1.)Loading the list of patients under a doctor into .txt file , which are each named under the doctor name.
	
	2.)Printing The Patient Details In The DataBase(patient Name And Thier ID)
		prints the patients details multipe times if the patient is taking treatment from multiple doctors
	
	3.)Deletion Of The Node in Linked List..in which the patient has been expired.(by Taking The Input As Patient ID)
		deletes more than one node if same patient is present in them (patient has been taking treatment from multiple doctors.so 			multiple entires in database.)

	4.)printing The deleted node Details.
		prints the details of the patient who has been expired.
		
	5.)Updating the doctor-patient details files after deleting the details of patients who has been expired(which has been done in 	subtask (1) )

	6.)Removing The Patients details Permanently From The DataBase if he has been expired.And keeping those Deleted Entires into 		history.txt file so that we can view the deleted history after a while.

<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
.............................................................................................................................................
