/* Hello, This is a C Programming Quiz Based Project. The Project is For Computer Science and Engineering Geeks Not Only for Beginners
But Also For the Experienced Persons of CSE. This Project Covers Undertsanding of All Things of C Programming Including Structures , 
File Handling , Making Own Header Files and Much More. 

Everytime User must Login To Start the Quiz , if They are are Registered With us. If User is Not Registered With us Then Must Register First and 
Login With us.  User Can Have the Ability to Choose Its Interested Domain , So That Only That Domain Related Questions (MCQ) will then Displyed 
in the Quiz.

Within the Answer Given of the Questions of Quiz , Scores Will be Given To the User According to the Diffuclty and the Complexity of the 
Question and the Level of Quiz.*/



#include<stdio.h>                                                                                       // for Standard Input and Output (Input from User and Output on Screen)
#include<conio.h>                                                                                       // For Using Unformatted Input Function , for Taking Input of Character from User 
#include<ctype.h>                                                                                       // for Chnaging Inputted Charcater into lowercase ot to uppercase
#include "Quiz_Things.h"                                                                                // For Using Our Own Inbuild Functions 
#include "Registration_Login.h"                                                                         // This is the Another User Edfeined Header File , For Registration and Login Tasks & Manage All Further Process  
#include<windows.h>                                                                                     //for Setting Color on Ouput Screen
int main()
{
	system("color 0E");
	
	printf("\n\n\n\n\n\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t         THE ULTIMATE QUIZZY                 ");
	
	printf("\n\n\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

	Project_Description();                                                                               // ---> Call the Function from the Quiz_Things.h Header File 
	
	After_Welcome();                                                                                        // ---> Call the After_Welcome Function from the Quiz_Things.h Header File 
	Main_Menu();
	
//----------------------------------------------------------------------------------------------------------------------------

char Choice=NULL;                                                                                  // ---> Intilally Choice Initialize To NULL , So That Loop Condition Will True At Least One Time, To Run and Ask Choice From User and Perform the Choose Choice or Option (Even if that It is Of Quit/Exit)

while(Choice!='5')                                                                                          // ---> Condition Set if User Will Enter the Choice =='5' (As Character Input) then Ask from User To Sure Quit the Application
{
	
    system("color 0E");
    
	printf("\n\n\n\n\t\t\t ** Enter Your Choice Option By Choose a Option No. From Above Menu ** ----> ");	               // ---> Continuoulsy in Loop Ask the Choice From User of Any Option From Menu 
	Choice = getche();                                                                                                // Using Unformatted Charcater Input Function to Ask Choice From User Continuosly Unitilo User Enters Choice as '5' which is Quit or Exit. (No Need To Press Enter in getche() Character Input Function after Entering Charcater Unlike scanf() or getchar())
	
	if(Choice=='1')                                          // ---- Instructions---
	{
		Instructions();                                                                                               // ---> When Choice is 1 then Instructions Function will Call of Quiz_Things.h Header file 
	}
	else if(Choice=='2')                                    // ---- Registration ---
	{
		Register_Description();                                                                                    // Calling To Register_Description() Function Of the Quiz_Things.h Header File
	    
		char Reg_Ensure;
		
	    printf("\n\n\n\n\n\t\t\t\t * Are You Want To Register with 'THE ULTIMATE QUIZZY' (Enter Choice in Y/N) * ---> ");
		Reg_Ensure = tolower(getche());                                                                                // Ask About To Sure Register With Us By USing Unformatted Charcater Input Function and Also Converts Enter Charcater Into Lowercase to Avoid Conflicts B/W Upper or Lower case Alphabet ,and User Not need To Press Enter After Input Charcater 
	    
	    if(Reg_Ensure=='y')
	    {
	    	Registration();                                                                                                                                 // Call to the Registartion Function of Registration_Login.h Header File
	    	Main_Menu();                                                                                                                                    // Call the Main_Menu Function to Display the Menu Again After Registration to User oN Screen 
		}
		else if(Reg_Ensure=='n')                                                                                                        // If Choice is No Then Nothing
		{
			printf("\n\n\n\n\t\t Ok, Go and Login !");
		}
		else
		{
		   printf("\n\n\n\n\t\t\t\t\t Wrong Choice!  Enter Only From (Y/N) By Again Choose Choice Option 2 .");                             // If Wrong Choice then Tell Enter the Right Choice 
		}
	}
	else if(Choice=='3')                                 // ------- Login --------                                              
	{
		Login_Description();
		
		char Login_Ensure;
		
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t * Are You Want To Login With 'THE ULTIMATE QUIZZY' Using your Registered Username and Password (Y/N) * ---> ");
		Login_Ensure = tolower(getche());                                                                          // Asking About the Login With Y/N with Single Charcater using Unformaatted Character Input Function to ask the Single Charcater From User and Without Pressing the ENter Key and Also Converts the Charcater into the Lowercase using tolower() function of <ctype.h> Header File 
		
		if(Login_Ensure=='y')
		{
			Login();                                                                                                         // Call To Login Function for Aksing Login Creanedtials from USer ANd Make Able to User To Logged in With Their Account
			Main_Menu();                                                                                                     
		}
		else if(Login_Ensure=='n')
		{
			printf("\n\n\n\n\n\t\t\t\t Ok, Go and Register You With 'THE ULTIMATE QUIZZY'!");
		}
		else
		{
			printf("\n\n\n\n\n\t\t\t\t Wrong Choice , Enter Your Choice from Y/N Only by again Choose the Option 3");
		}
	}
	else if(Choice=='4')                                   // Tell About Various Domains to the User  
	{
	    Domains();	
	    
	    printf("\n\n\n\n\n\n\n\t\t\t\t");
	    Main_Menu();
	}
	else if(Choice=='5')                       // ---- Quit / Exit the Application---
	{
		char Quit;
		
		printf("\n\n\n\n\n\n\t\t\t\t * Are You Sure You Want To Exit/Quit the Application (Give Answer in Y or N ) * ---> ");
	  	Quit = tolower(getche());                                                                                         //Also Convert Enter Charcater into Lowercase , Either its Lowercase or Uppercase While Taking Input           //---> Using Unformatted Input Charcater Function to Take iNput Of Charcter From User , for Quit or Not 
		
 	    if(Quit=='y')                                                                                                  // If Quit==y then Quit the Aplication or Break the Loop After Print the Quit Description
		{
			Quit_Description();                                                                                                  // Calling To Function from Quiz_Things.h Header File                                                                  
			exit(1);                                                                  
		}
		else if(Quit=='n')
		{
			Choice=NULL;                                                                      //Menas if Choice is n (No) , Then Also Choice Intilize to NULL , SO That Loop WIll Continue Agin rather then Stop Because Choice has 5 this time , So to Avoid Stopness of Loop We Overwrite the Choice To Null So That Loop Will Not Stop and Again Continue the same Loop                      
			printf("\n\n\n\n\t Ok, Application is Not Quit!");                                                                          
		}
		else
		{
			printf("\n\n\n\n\t\t\t\t\t Wrong Choice! Enter Only From (Y/N) By Again Choose Choice Option 5.");
			Choice=NULL;                                                                                         // ---> Menas if Choice is Wrong from Y/N then Again Continue the Application or Loop , Because To Continue Again the Loop We Must Change Choice 5 to NULL So That Loop Will Still Continue , Rather Then the Stop According To Condition We Give ABove ,that While Choice!=5 		                                                                                                    //Again Continues the Loop , After Intialize Choice To NULL , So That Rather Than Stop Loop Will Still Continue After Give NULL To Choice Because if Don't Do this Then According to Condition Loop Will Stop that Choice !=5 , And This Time Choice is 5 , So Stop 
	    }
    }
    else
    {
    
	printf("\n\n\n\t WRONG CHOICE !!, Enter the Choice From Above Menu Only (By Write the Choice No. which is provided in the Menu ) . \n\n");                           // ---> If Main Choice is Also Not From 1 to 5 Then Agin Continue the Loop To Ask Again the Choice from User from 1 to 5
    }

}
	
	
	
	return 0;

}