/*
 * main.c
 *
 *  Created on: ٣١‏/٠٧‏/٢٠٢٣
 *      Author:Ali Mustafa Enaya
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DPRINTF(...)     {fflush(stdout); \
		fflush(stdin);  \
		printf(__VA_ARGS__);\
		fflush(stdout); \
		fflush(stdin);}

struct Sdata
{
	char name[40];
	int id;
	float height;
};
struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextstudent;
};

struct SStudent* gpFirststudent = NULL;

void addStudent ()
{
	struct SStudent* PNewstudent ; // local pointer to navigate to book memo of new record
	struct SStudent* PLaststudent ; // local pointer to navigate to know the last record
	char temp[40];
	//check if empty

	if(gpFirststudent==NULL)
	{
		//book a new memo for a new record
		PNewstudent = (struct SStudent*) malloc(sizeof(struct SStudent)); //if linkedlist is empty ---> book a memory of new record by malloc
		gpFirststudent = PNewstudent;

	}
	else
	{
		//check is not empty
		PLaststudent = gpFirststudent;
		while(PLaststudent->PNextstudent)
			PLaststudent=PLaststudent->PNextstudent;

		PNewstudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		PLaststudent->PNextstudent =PNewstudent ;
	}

	//=====fill new record=====
	//id
	DPRINTF( "Enter ID : ");
	gets(temp);
	PNewstudent-> student.id = atoi (temp);
	//name
	DPRINTF( "Enter Student Full Name : ");
	gets(PNewstudent-> student.name);
	//height
	DPRINTF( "Enter Your Height: ");
	gets(temp);
	PNewstudent-> student.height = atoi (temp);

	//assign NULL to Pnewstudent
	PNewstudent-> PNextstudent = NULL;
}


int delete_student()
{
	if(gpFirststudent==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============");
		return 0;
	}
	struct SStudent* Prevstudent =NULL;
	struct SStudent* Pselectedstudent = gpFirststudent ;
	//get the selected id
	char temp[40];
	int selectedId;
	DPRINTF("\nEnter The selected ID : ");
	gets(temp);
	selectedId = atoi(temp);
	if(gpFirststudent)   //check if empty
	{
		//loop
		while(Pselectedstudent) //
		{
			if (Pselectedstudent -> student.id == selectedId)
			{
				if(Prevstudent) //The selected id is not 1st
				{
					Prevstudent->PNextstudent = Pselectedstudent->PNextstudent;
					free(Pselectedstudent);
					return 1 ;
				}
				else  //The selected id is 1st
				{
					gpFirststudent = Pselectedstudent->PNextstudent;
					free(Pselectedstudent);
					DPRINTF("\n\tStudent is deleted\n");
					return 1 ;
				}


			}
			Prevstudent = Pselectedstudent;
			Pselectedstudent= Pselectedstudent->PNextstudent;  //related with while( Pselectedstudent )
		}
		DPRINTF("Can not find student ID");
		return 0 ;
	}
}

void delete_all()
{
	struct SStudent* PCurrentstudent = gpFirststudent ;
	struct SStudent* Ptempstudent;

	if(gpFirststudent==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============");
	}
	else
	{
		while (PCurrentstudent)
		{
			Ptempstudent=PCurrentstudent;
			free(Ptempstudent);
			PCurrentstudent = PCurrentstudent->PNextstudent;
		}
	}
	gpFirststudent = NULL;
}


void view_all()
{
	struct SStudent* PCurrentstudent = gpFirststudent ;
	int count=0;
	if(gpFirststudent==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============\n");

	}
	else
	{
		while (PCurrentstudent)
		{
			DPRINTF("\nRecord Number %d ",count+1);
			DPRINTF("\n\tID : %d", PCurrentstudent->student.id);
			DPRINTF("\n\tName : %s", PCurrentstudent->student.name);
			DPRINTF("\n\tHeight : %0.2f\n\n", PCurrentstudent->student.height);

			PCurrentstudent = PCurrentstudent->PNextstudent;
			count++;
		}
	}
}

void Reverse(){
	struct SStudent* PCurrentstudent = gpFirststudent;
	struct SStudent* Pnext = NULL;
	struct SStudent* Pprev = NULL;
	while (PCurrentstudent)
	{
		Pnext = PCurrentstudent->PNextstudent;
		PCurrentstudent->PNextstudent = Pprev;
		Pprev = PCurrentstudent;
		PCurrentstudent = Pnext;
	}
	gpFirststudent = Pprev;
}

void Nth_from_End(int index){
	int i;
	struct SStudent* Pmain = gpFirststudent;
	struct SStudent* Preference = gpFirststudent ;
	for(i=0 ; i<index ;i++){
		Preference=Preference->PNextstudent;
	}
	while(Preference){
		Preference=Preference->PNextstudent;
		Pmain=Pmain->PNextstudent;
	}
	DPRINTF("\nRecord Number %d ",index);
	DPRINTF("\n\tID : %d", Pmain->student.id);
	DPRINTF("\n\tName : %s", Pmain->student.name);
	DPRINTF("\n\tHeight : %0.2f\n\n", Pmain->student.height);
}


int length(struct SStudent* gpFirststudent){

	/* ############Iterative Way way##########*/
	/*
	int count=0;
	struct SStudent* Pcurrentstudent = gpFirststudent;
	while(Pcurrentstudent){
		Pcurrentstudent = Pcurrentstudent->PNextstudent;
		count++;
	}
	DPRINTF("\nLength of Data Base : %d ",count);
	 */
	//gpFirststudent = gpFirststudent->PNextstudent;
	/*##############Recursion Way##############*/
	if(gpFirststudent == NULL)
		return 0;
	else
		return 1+length(gpFirststudent ->PNextstudent);

}

void GetMiddleOfList(){
	struct SStudent* Pslow = gpFirststudent;
	struct SStudent* Pfast = gpFirststudent ;
	if(Pslow==NULL)
	{
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============\n");
	}
	else //not empty
	{
		int count =1;
		while(Pfast && Pfast->PNextstudent)
		{
			Pfast = Pfast->PNextstudent->PNextstudent;
			Pslow = Pslow->PNextstudent;
			count++;
		}
		DPRINTF("\nRecord Number %d ",count);
		DPRINTF("\n\tID : %d", Pslow->student.id);
		DPRINTF("\n\tName : %s", Pslow->student.name);
		DPRINTF("\n\tHeight : %0.2f\n\n", Pslow->student.height);
	}
}

void main()
{
	int index;
	char temp[40];
	while (1)
	{
		DPRINTF("\n\nchoose on of the following options:\n");
		DPRINTF("\t1: Add Student \n");
		DPRINTF("\t2: Delete Student \n");
		DPRINTF("\t3: view Students \n");
		DPRINTF("\t4: Delete all \n");
		DPRINTF("\t5:Get the Nth from End \n");
		DPRINTF("\t6:Get the Length of Data Base \n");
		DPRINTF("\t7:Get the Middle of Data Base \n");
		DPRINTF("\t8:To reverse the list \n");
		DPRINTF("==============================\n");
		gets (temp);

		switch(atoi(temp))
		{
		case 1: addStudent ();
		break;
		case 2: delete_student();
		break;
		case 3: view_all();
		break;
		case 4: delete_all();
		break;
		case 5: DPRINTF("\n\tEnter The index : \n");
		gets(temp);
		index= atoi(temp);
		Nth_from_End(index);
		break;
		case 6:DPRINTF("\n\t Length is %d\n" , length(gpFirststudent));
		break;
		case 7:GetMiddleOfList();
		break;
		case 8:Reverse();
		DPRINTF("\n\tList is Reversed\n");
		break;
		default : DPRINTF("wrong option !");
		break;
		}
	}
}
