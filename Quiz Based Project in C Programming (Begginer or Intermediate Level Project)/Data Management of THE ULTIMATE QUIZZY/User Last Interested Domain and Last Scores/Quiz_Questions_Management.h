#ifndef Quiz_Questions_Management
#define Quiz_Questions_Management
#include<string.h>                                                                                             // For Using the String Manipulation Functions 
#include<windows.h>                                                                                            // For Changing the Color of the CLI that is the Output Window
#include<stdbool.h>                                                                                            // For USing Boolean datatype in C 
#include<stdlib.h>                                                                                             // For Applying the Sytsem Level Operations such as Cobverting Ascii or String to Integer and Vice Versa or forClearing the Output Screen 
#include<conio.h>                                                                                              // For Asking the Unformatted Input Of Chrcater from User While Asking Choice for Submenu and Further 
#include<unistd.h>                                                                                             // For Adding a Pause at Some Point in the Program or Project 
#include<time.h>
#include<ctype.h>
#include "Quiz_Things.h"

char LoggedIn_Username[40];                                                                                    // Charcater Array or String For SToring the USername of the User Globally which Recived from the Caller Side 
char LoggedIn_UserID[35];                                                                                      // Charcater Array or StringFor Storing the USer_ID of the User Globally Which recieved from the Caller side 
char LoggedIn_Name[40];                                                                                        // Charcater Array or StringFor Storing the NAme of the USer Aftrer Ensuring It is a Returned Login User of New Login  User 
bool LoggedIn_Status_RON = false;                                                                              // Boolean Variable For Checking That User is a Returned Login Suer or It is a New Logged In User 
char Details_FilePath[40];                                                                                     // For Making the Path for Opening the File for Fetching the Last Interested Domain and the LAst Scores of ther User 
char Last_Interested_Domain[40];                                                                               // For Storing the LAst Intersted Domain of the USer 
int Last_Achieved_Scores;                                                                                      // For Storing the Last Achived Scores After Fetch It From the File uisng Unique_UserID.txt
char Current_Choosen_Domain[50];                                                                               // For Storing the Domain In Which User Want to Play Quiz Now, This Time or Current Time Interested Domain of the Quiz 
char System_Date_Time[50];                                                                                     // Global Charcater Array or String That Actually Stores the Right Date and Time of the System 

struct Questionarrie
{
	char Question_Description[1500];
	char Option_A[850];
	char Option_B[850];
	char Option_C[850];
	char Option_D[850];
	char Correct_Option;
	char Difficulty_Level[115];
	int Score_For_Correct_Answer;
}Question[50];

void Display_Returned_User_Details()                                                                           // This Function Display the Details of the Returned User Like such as Their Last Scores , Their Name and Their Last Interested Domain
{
	printf("\n\n ---------------------------");
	printf("\n\n\t Logged In ");
	printf("\n\n ---------------------------");
    	
	
	printf("\n\n\n\n\n\t\t\t\t\t\t\t *-_-*-_ *-_-*-_ *-_ *-_-*- *-_-*-_-*-_ *-_-*-_ *-_-*-_ *-_-*-_");
	printf("\n\n\t\t\t\t\t\t\t\t\t    'THE ULTIMATE QUIZZY'");
	printf("\n\n\t\t\t\t\t\t\t *-_-*-_ *-_-*-_ *-_ *-_-*- *-_-*-_-*-_ *-_-*-_ *-_-*-_ *-_-*-_");
	
	
	printf("\n\n\n\n\n\t\t Hey , %s",LoggedIn_Name);
	
	printf("\n\n\n\t\t\t Welcome Back in 'THE ULTIMATE QUIZZY'. We are thrilled to have you back in 'THE ULTIMATE QUIZZY'.We Hope , It was Great Experience \n\n\t\t\t for You during Last Time with 'THE ULTIMATE QUIZZY'.We Appreciate the Tech Geeks like You who is very  Passionate About the Top Tech \n\n\t\t\t Domains and Always Ready to Improve their  Knowledge and Skillset in this Vast tech Industry .");
	
	printf("\n\n\n\t\t\t Your previous progress shows that you were interested in the [%s] domain, and your last quiz scores were [%d].",Last_Interested_Domain,Last_Achieved_Scores);
    
    printf("\n\n\t\t\t We Hope that ,You Will Played Well this Time, With More Enthusiasm and Great Knowledge Releated to your Interested Domain than the Last Time.");
    
	printf("\n\n\t\t\t Either you like to challenge yourself further in the [%s] domain or explore new domains in 'THE ULTIMATE QUIZZY'?",Last_Interested_Domain);
	
	
	printf("\n\n\n\n\n\t\t Best Wishes To You from 'THE ULTIMATE QUIZZY'");
	printf("\n\n\t\t Thank You ");
	printf("\n\n\t\t 'THE ULTIMATE QUIZZY' Team");
}

void New_LoggedIn_User_Details()                                                                                // This is a Function Responsible for Displaying the Content For Those Users that Are NewLogged_In Users With THE ULTIMATE QUIZZY, Asking Name of New User Is also Done In This Function 
{
	char Temp_Name[40];
	printf("\n\n ---------------------------");
	printf("\n\n\t Logged In ");
	printf("\n\n ---------------------------");
	
	
	printf("\n\n\n\n\n\t\t\t\t\t\t *-_-*-_ *-_-*-_ *-_ *-_-*- *-_-*-_-*-_ *-_-*-_ *-_-*-_ *-_-*-_");
	printf("\n\n\t\t\t\t\t\t\t\t WELCOME to 'THE ULTIMATE QUIZZY'");
	printf("\n\n\t\t\t\t\t\t *-_-*-_ *-_-*-_ *-_ *-_-*- *-_-*-_-*-_ *-_-*-_ *-_-*-_ *-_-*-_");
	
	printf("\n\n\n\n\n\n\t\t\t\t %c Hey  Hello there, %c  Newbie New User! Welcome to THE ULTIMATE QUIZZY! You are logging in as a new user %c\n\n",17,1,16);
	
	printf("\n\n\t\t Your gateway to a world of tech knowledge and challenges. We're delighted to have you join our community of passionate tech enthusiasts who share \n\n\t\t a common love for Computer Science and Engineering. To get started, we'd like to know your Name:- \n\n\n\t\t * Please Enter Your Name * :");
    scanf("%s",&Temp_Name);

    strcpy(LoggedIn_Name,Temp_Name);                                                                             // Copy the Asking Name of USer from Temp_Chracter ARray to Global Charactcter Array LoggedIn_Name
    
    printf("\n\n\n\t\t Great to meet you [ %s ] , !%c",LoggedIn_Name,1);
    printf("\n\n\t\t At THE ULTIMATE QUIZZY, we appreciate the passion for technology and the quest for knowledge that you bring with you. Here's what you can look forward to: \n\n\t\t\t * Diverse Quizzes: Explore a wide range of quizzes covering various tech domains, from programming to web development, cybersecurity, and more. \n\n\t\t\t * Learning and Fun: Challenge yourself, learn something new with each question, and have fun while doing it! \n\n\t\t\t * Progress Tracking: Keep track of your scores, challenge yourself to improve Day by Day. \n\n\n\t\t Your journey with us is just beginning, and we can't wait to see you grow and succeed. So, let's embark on this exciting adventure together! \n\n\t\t Thank you for choosing THE ULTIMATE QUIZZY. We're here to support your quest for knowledge every step of the way. Happy quizzing!");
 
   printf("\n\n\n\t Warm regards %c , \n\n\t THE ULTIMATE QUIZZY Team \n\n ===========================================",3);
}

void SubMenu()
{
	printf("\n\n\n\n\n\t\t\t\t\t\t ---_---_ --_---_---_---_---_---_---_---_---_---_---_---_---_---_");
	printf("\n\n\t\t\t\t\t\t\t\t SubMenu : 'THE ULTIMATE QUIZZY' ");
	printf("\n\n\t\t\t\t\t\t ---_---_---_---_---_---_---_---_---_---_---_---_---_---_---_---_");
   
   
   printf("\n\n\n\t\t\t\t * Note: Once The Quiz is Started User Will Not Able to Logout , The Only Option is to Exit the Quiz while Prompted *");
   printf("\n\n\n\n\t\t\t\t\t 1. Start the QUIZ");
   printf("\n\n\t\t\t\t\t 2. Domains ");
   printf("\n\n\t\t\t\t\t 3. About Us");
   printf("\n\n\t\t\t\t\t 4. Rules of 'THE ULTIMATE QUIZZY'");
   printf("\n\n\t\t\t\t\t 5. Logout");
} 

void After_Start_Quiz_Description()                                                                                                   //This Function actually displays the details such as the current date and time with the user chosen domain 
{
	time_t Current_Date_Time;
	
	time(&Current_Date_Time);
	strcpy(System_Date_Time,ctime(&Current_Date_Time));
	
	system("cls");
	   
	  printf("\n\n\n\n\t\t\t\t\t ** Quiz is Going To Be Started %s . Be Ready To Challenge Yourself in the Tech.**",LoggedIn_Name);
	
	  printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t --------------------------------------------------");
	  printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t               Date and Time :  %s",System_Date_Time);
	  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t --------------------------------------------------");
	
	  printf("\n\n\n\t\t\t      %c Make Sure To Play The Quiz of 'THE ULTIMATE QUIZZY' Ahead the Rules . So That You Achieved a Lot from this Quiz %c",17,16);
	
	
	
      printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t     ** Domain : %s **\n\n\n\n",Current_Choosen_Domain);

}

// Fetch_Questions_Data Function Actaully Fetch the Corresponding Domain Questions from the corresponding CSV and store in the Array of structure Varible and HEre Each Index Of array of Structure Represents a Single Question Having the Other Columns Values such as Option A,B, C , D and Correct Option etc.
void Fetch_Questions_Data(char Questions_File_Path[])  
{
	 char Temp_Question_Description[1500];
	 char Temp_Option_A[850];
	 char Temp_Option_B[850];
	 char Temp_Option_C[850];
	 char Temp_Option_D[850];
	 char Temp_Correct_Option[3];
	 char Temp_Difficulty_Level[115];
	 char Temp_Score[3];
	 
	 int Cnt=0;
	 char Headers[1000];                                                                                                                         // Use THis Charcater ARray for Skipping the HEaders of The Name of the Columns of the CSV That is Going to be Opened
	 FILE *Quiz_Questions_Data;
	 
	 Quiz_Questions_Data = fopen(Questions_File_Path,"r");                                                                                                 //Open the Corresponding Domain CSV and STore the Quetsions Data In Array of STructure After Fetch  
	 
	 fscanf(Quiz_Questions_Data, "%[^\n]\n", Headers);                                                                                                     //%[^\n] Defines that read the Header or Read The Each Charcetr From this Line Until New Line is Encountered or When All re Finsih , and \n After That Tells that To Reach in the New Line Also From Where Actual Data is Started
	 
	 while(fscanf(Quiz_Questions_Data,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",Temp_Question_Description,Temp_Option_A,Temp_Option_B,Temp_Option_C,Temp_Option_D,Temp_Correct_Option,Temp_Difficulty_Level,Temp_Score)==8)                                                //Read the QUestions Data from the CSV in thhses 8 Charcater Array THat is basically Temproeily For raeding teh Data from the CSV  
	 {
	 	strcpy(Question[Cnt].Question_Description,Temp_Question_Description);                                                                                                    // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	strcpy(Question[Cnt].Option_A,Temp_Option_A);                                                                                                                            // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	strcpy(Question[Cnt].Option_B,Temp_Option_B);                                                                                                                            // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	strcpy(Question[Cnt].Option_C,Temp_Option_C);                                                                                                                            // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index                                                                                                                          
	 	strcpy(Question[Cnt].Option_D,Temp_Option_D);                                                                                                                            // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	strcpy(Question[Cnt].Difficulty_Level,Temp_Difficulty_Level);                                                                                                            // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	
	 	Question[Cnt].Correct_Option = Temp_Correct_Option[0];                                                                                                                   // Store or Copy the Data from Temprorily Charcater Array's Index 0 to the Orginal Memeber of Array of Structure of any Specifc Index 
	 	Question[Cnt].Score_For_Correct_Answer = atoi(Temp_Score);                                                                                                               // Store or Copy the Data from Temprorily Charcater ARray to the Orginal Memeber of Array of Structure of any Specifc Index , Here we also Converst from ASCII to Integer or From String to Integer
	 	
		Cnt+=1;
	 }
	 
}
// Store recent data function actually store this time progress in the separate text file in backend basically a progress stores in the text file is this time chosen domain that becomes now last interested domain and this time Achieved Scores that becomes now last achieved scores 
void Store_Recent_Data()                                                                                                            
{
	FILE *Recent_User_Details;
	FILE *LoggedIn_Status_Details;
	char Full_Path_With_File_Name[150]="Data Management of THE ULTIMATE QUIZZY\\User Last Interested Domain and Last Scores\\"; 
	
	strcat(Full_Path_With_File_Name,Details_FilePath);

	Recent_User_Details = fopen(Full_Path_With_File_Name,"w");                                                                                    // Overwrite text file with the new data progress of the user which is basically Time time Scores Achived and this time chosen domain which now becomes the last interested domain and the last achieved scores 
	fprintf(Recent_User_Details,"%s\n%d",Last_Interested_Domain,Last_Achieved_Scores);                                                            // Stores the data. in the first line We actually stores the last interested domain in second line we actually stores the scores achieved 
	
	fclose(Recent_User_Details);
	
	if(LoggedIn_Status_RON == false)                                                                                                             // Store details in the login status file to represent that user is now a returned login user is only if user Logged in as new Login User otherwise  Details not stores every time if it is return login user already 
	{
	
	LoggedIn_Status_Details = fopen("Data Management of THE ULTIMATE QUIZZY\\User Last Interested Domain and Last Scores\\Login_Status.csv","a+");
	fprintf(LoggedIn_Status_Details,"%s,%s\n",LoggedIn_Username,LoggedIn_Name);
	
	fclose(LoggedIn_Status_Details);
    }
}

// This Function Display The Questions in front of the USer of the Corresponding Damin of Which data is Present in Array of structure. This Function Also Make Sure that All The Questions Must Covered , Everytime Questiosn Must Displayed in the RAndom Order , and No Question can Be Reapated and Once Thay Are Already Displayed and Each and Every Question Answer is Must to Answered in the Time of 30 Seconds By the USer Othwise Score for the Question Will Not Be counted
void Display_Questions_To_User()                                                                                                         
{
   	int Random_Question_Number_Index;                                                                                                   // For storing the random number So that random question is displayed every time to the user 
	bool Quit_Check = false;                                                                                                            // To quit the quiz when after receiving the not continue command from the user side 
	char Stop_Y_N;                                                                                                                      //In this way actually asking the to continue or look with the quiz by receiving the options from Y or N 
	int Cover_Question_Number_Flag[50]={0};                                                                                             // Basically it is a character array that hole initially initialize to 0 on each index basically this array ensures that already displayed question is not displayed again by setting a flag to on if the question is displayed to the corresponding index It actually Sets that corresponding index to one when the corresponding index question is displayed from the array of structure 
	int Total_Displayed_Questions = 0;                                                                                                  // It keeps tracking of the number of questions to be displayed to the user then all the questions are displayed that is 50 then loopy stop and quizzes automatically quit 
	int Question_Time_Limit = 30;                                                                                                       // Setting a time of 30 seconds to answer each question of the ways that is displayed to the user for asking answer from him or her 
	time_t Start_Time,End_Time;                                                                                                         // Declares two time variables start time and end time to keep tracking of the the total time taken by the user to answer the question so that if the time is reached to answer the question then score for that question will not be counted 
	char User_Answer_Of_Question;                                                                                                       // It actually stores the answer of every question while asking in terms of the option A or B or C or D 
	
	int Score_For_Last_Question = 0;                                                                                                   // It actually keeps track the score for the last question 
	int Total_Scores_Achieved = 0;                                                                                                     // It Actually keeps track of the total scores achieved of the right answers from each question and at the end total score is displayed 
	int Right_Answers = 0;                                                                                                             // It actually keeps track of the number of right answers Given by the user in overall or in the whole quiz Journey 
	int Wrong_Answers = 0;                                                                                                             // It actually keeps track of the number of wrong answers given by the user in the overall quiz        
	int Time_Up_Answers = 0;                                                                                                           // It actually keeps track of the number of answers when the time is reached to answer the question in the whole quiz 
	char Answer_Check_Status[250];                                                                                                     // It actually stores the Status of the answer of each question given by the user means the answer given by the user of the last question is of time reached is wrong or it is right and its purpose is only to display the feedback about the status of every question answer given by the user 
	
	srand(time(0));                                                                                                                    // It ensures to generate the random number every time with every run 
	do
	{
		Random_Question_Number_Index = rand()%50;                                                                                          // Ensures Everytime Random Question is Displayed , Not Proper any Order or Sequnce , It generates a Random Number and Store in the Varible 
		
		if(Cover_Question_Number_Flag[Random_Question_Number_Index]==1)                                                                   // Check the Generated Random Number Question is Already Displayed , If YEs Then Again And Again generate the Random Number Continuouly Inside the Loop Until the that Index Number Generated of Which Corresponding Question is Not Displyed 
		{
			while(Cover_Question_Number_Flag[Random_Question_Number_Index]!=0)                                                           // Rule Lopez run continuously to generate the random number 4 forming an index until the I need that random number index not find which is which corresponding index position is not displayed to the user from the array of structure 
			{
				Random_Question_Number_Index = rand()%50;                                                                                // Generate the Random Number from 0 to 49 Only Every time 
			}
		}
		
		if(Cover_Question_Number_Flag[Random_Question_Number_Index]==0)                                                                 // Text when bad corresponding random number index is find whose corresponding  index Question is not displayed to the user then Display that corresponding index question to user and ask answer
		{
			printf("\n\n\n\n\n       %s",Question[Random_Question_Number_Index].Question_Description);                                 // Display that random number index question description to the user 
			printf("\n\n\n\t\t %s",Question[Random_Question_Number_Index].Option_A);                                                   //Display that random number index question's option a 
			printf("\n\n\t\t %s",Question[Random_Question_Number_Index].Option_B);                                                     //Display that random number index question's option b
			printf("\n\n\t\t %s",Question[Random_Question_Number_Index].Option_C);                                                     //Display that random number index question's option c
			printf("\n\n\t\t %s",Question[Random_Question_Number_Index].Option_D);                                                     //Display that random number index question's option d
			
			time(&Start_Time);                                                                                                         // Note the time note the start time actually when we are goinng to asking the answer of the question from the user that is displayed on the screen 
			
			printf("\n\n\n\n\n\t\t\t  * Please Choose Your Answer By Selecting a Option * ---> ");                              
            User_Answer_Of_Question = toupper(getche());                                                                                // Taking the input of answer from user of the question (in terms of Option) that is displayed to the user above 
            
            time(&End_Time);                                                                                                            // Note the End time means when actually user input  there answer in terms of the option of question to it and submit it 
            
            Cover_Question_Number_Flag[Random_Question_Number_Index]=1;                                                                 // Set that corresponding random number index is to 1 in the flag array to represent that This corresponding random number index question is already displayed 
            Total_Displayed_Questions+=1;
            
            if(difftime(End_Time,Start_Time)<=Question_Time_Limit)                                                                     // Check that the actual time takes by the user to answer the question and compare it with Question Time Limit that if it is less than or equal to the actual  time limit that it is okay otherwise  the status is to be declared as the time reached 
            {
            	if(Question[Random_Question_Number_Index].Correct_Option==User_Answer_Of_Question)                                     // Check That  the answer is also correct Ahead the time limit in which Answer of a Question answered the user  
            	{
				
            	Score_For_Last_Question = Question[Random_Question_Number_Index].Score_For_Correct_Answer;                             //If the user give the answer of the question ahead the time limit and answer is also correct then what is given to the user 
            	Total_Scores_Achieved+=Question[Random_Question_Number_Index].Score_For_Correct_Answer;                                //Corresponding score is also counted if the answer given by the user is correct and it is done in the ahead of the time limit
            	Right_Answers+=1;                                                                                                       // Add one to the Right   answers counter 
            	strcpy(Answer_Check_Status,"Right Answer Within Time Limit"); 
			}
			else                                                                                                                      // This describes that if user give the answer ahead  the time limit but the answer given by the user is not match with the actual answer then it is to be declared as the wrong answer 
			{
				Wrong_Answers+=1;                                                                                                    // Add one to the Wrong answers counter 
				Score_For_Last_Question = 0;
				strcpy(Answer_Check_Status,"Wrong  Answer"); 
			}
		}
			else                                                                                                                   // If the answer given by the user is it wrong or either it is right but if the answer given by the user is not a ahead time limit means the time is reached then score for that question is also not counting and it is directly declared as the time reached status 
			{
				
			    Time_Up_Answers+=1;
			    Score_For_Last_Question=0;
			    strcpy(Answer_Check_Status,"Time Reached"); 
			}
			
			printf("\n\n\n\t\t <-> Answer Checking  ...............");
			sleep(5);
			
		}
		
			printf("\n\n\n\n\t\t\t\t\t * Score You Achieved for This Question --%c %d",16,Score_For_Last_Question);                                                                //The Below 4 lines  of code actually display the feedback of the question's answer given by the user 
			printf("\n\n\t\t\t\t\t * Right / Wrong Status for This Question --%c %s",16,Answer_Check_Status);
			printf("\n\n\t\t\t\t\t * Correct Answer For This Question --%c ' Option %c ' ",16,Question[Random_Question_Number_Index].Correct_Option);
			printf("\n\n\t\t\t\t\t * Difficulty Level Of This Question --%c %s",16,Question[Random_Question_Number_Index].Difficulty_Level);
				
			
			Back_Here:	
				printf("\n\n\n\t\t\t Do You Want To Continue Your Quiz Further or Want Quit (Y | N) --->  ");                                     // Asked from the user is user want to continue the quiz or it want to quit the here Answer can be received from the user in terms of Y_N or if any other option is enter then it is declared as the Invalid Choice and again asking from the user to enter RIght option using the go to statement which actually transfer the control of program directly to the Label  
				Stop_Y_N = tolower(getche());
				 
			if(Stop_Y_N=='y')                                                                                                                     // If the option received from user is y then loop is continue or again asking a question for User 
			{
				continue;
			}
			else if(Stop_Y_N=='n')                                                                                                              // If the Option received from user is no that is n then the loap is stopped immediately by the break statement Which actually terminates the control of Loop and transfer the control to the Out of Loop 
			{
				Quit_Check = true;
				break;
			}
			else
			{
				printf("\n\n\n\t\t\t Invalid Operation , Please Enter the Right Choice from (Y | N) !");
				goto Back_Here;
			}
		  
     }
     while(Quit_Check==false && Total_Displayed_Questions<50);                                                                                  //Check if any of the condition mentioned becomes true that means if Quit_check is not equal to false means it becomes True or the total displayed questions is equal to 50 or greater than 50 then loop Will Stop Immediately
     
     strcpy(Last_Interested_Domain,Current_Choosen_Domain);                                                                                    // Store the this time choose domain of the user in the last interested domain so that it can be stored 
     Last_Achieved_Scores = Total_Scores_Achieved;                                                                                             // Store the total achieved Scores this time in the last achieved scores so that it can be stored 
     		 
     Store_Recent_Data();                                                                                                                      // Store recent data function actually stored the currently progress of the user in a separate text file and details store in the text file will the score Achived This Time and this time chosen domain                         
	 		 
	printf("\n\n\n\n\n\t\t\t\t Please Wait ..................!");
	sleep(5);
	system("color 4F");
	system("cls");
	
	 		 
	printf("\n\n\n\n\n\t\t\t\t\t\t *--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*");                                  // Below full code actually displays the messages or lines for display the overall quiz progress or feedback to the user 
	printf("\n\n\t\t\t\t\t\t\t\t    Recent Progress : %s ",LoggedIn_Name);
	printf("\n\n\t\t\t\t\t\t *--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*");
	 
	 printf("\n\n\n\n\n\t\t\t * Total Scores You Achieved This Time -> %d",Total_Scores_Achieved);
     printf("\n\n\t\t\t * Total Right Answers -> %d",Right_Answers);
     printf("\n\n\t\t\t * Total Wrong Answers -> %d",Wrong_Answers);
     printf("\n\n\t\t\t * Time Up Answers -> %d",Time_Up_Answers);
     printf("\n\n\t\t\t * Total Questions Asked This Time -> %d",Total_Displayed_Questions);
     
     printf("\n\n\n\n\n\t\t %c We hope you had a great time with THE ULTIMATE QUIZZY and improved your knowledge in Tech!",2);
     printf("\n\n\t\t We hope You Come Again in THE ULTIMATE QUIZZY to improve your Knowledege in Tech");
     
	 printf("\n\n\n\n\n\t %c Thank You , Had a Great Journey With you During Quiz %c",17,16);
     
	 printf("\n\n\n\t Regards");
     printf("\n\n\t'THE ULTIMATE QUIZZY' Team");
     printf("\n\n\t %c Good Bye!",3);
     
     exit(1);                 //Exit or Stop  means actually the quiz is quit the here  either  user enters no to continue or either total number of questions is displayed that is 50 then automatically store the application of quiz                                                                                                            // 
	
}

void Login_Further(char UserNm[],char UserID[])                                                                            //Function For Managing the Further Process AFter LoggedIn By User , In This We Ensure that User is a Returned Login User or It is a New Login User Based on That We Will Manage their Details and Process Further                                       
{
	
	system("color E0");
	system("cls");                                                                                                        // For Clearing the Whole Screen and Chnage The Color of the Screen AFter WHne the User is LoggedIn With Us
	
	strcpy(LoggedIn_Username,UserNm);                                                                                     // Copy the UserName of User Which is recived From the Caller Side in the UserNm Pointer to (Charcater) Array in the LoggedIn_Username Global String or Chracter Array 
	strcpy(LoggedIn_UserID,UserID);                                                                                       // Copy the UserID of User Which is recived From the Caller Side in the UserID Pointer to (Charcater)Array in the LoggedIn_UserID Global String or Chracter Array 
	
	FILE *Login_Status;                                                                                                   // File Ppointer for Opeining the Login_Status.csv File for Ensuring that IT is a Retuned Login USer nEw LoggedIn_User
	char Temp_Fetch_Username[40],Temp_Fetch_Name[40];                                                                     // Two Charcater Arrays That Actually Taking the Data In It While Reading the File 
    
		
	Login_Status = fopen("Data Management of THE ULTIMATE QUIZZY\\User Last Interested Domain and Last Scores\\Login_Status.csv","r");                                                                         // Open the Login_Status File for Ensuring that Whether the LoggedIn_User is a Returned Logged_In User or It is a New LoggedIn_User 
	
	while(fscanf(Login_Status,"%[^,],%s\n",Temp_Fetch_Username,Temp_Fetch_Name)==2)                                      // Reading the Data such as Username and Name In These Two Charcater Arrays and Check LoggedIn_Username Matches Withn Current Reading USerName From the Login_Status File, If Yes then Means It is a Returned Login User , Now We Have To Copy the Name of The User In Global Charcater Array LoggedIn_Name  
	{
		if(strcmp(Temp_Fetch_Username,LoggedIn_Username)==0)                                                             // Check or Comapre that Reading Username from File in Temp_Username Match With the LoggedIn_Username , Menas Then It Represents that User is a Returned Login User 
		{
			strcpy(LoggedIn_Name,Temp_Fetch_Name);
            LoggedIn_Status_RON=true;     
			fclose(Login_Status);                                                                                        // Set True to Boolean Varible To represents that the User is a Returned Login User 		
			break;                                                                                                       // Stop When We Found that LoggedIn_Username MEtch Inside the File With Any Username , Measn then  User is a Returned LoggedIn_User
		}
	}
	
	
	
	if(LoggedIn_Status_RON)
	{
		char Main_Path[150] = "Data Management of THE ULTIMATE QUIZZY\\User Last Interested Domain and Last Scores\\";
		
		strcpy(Details_FilePath,LoggedIn_UserID);                                                                          // Copy UnqiueUserID of USer in Global Charcater array Details_FilePath So That Maiing the Path of That File That Have the Details of the User such as Their Last Intered Domain and   
		strcat(Details_FilePath,".txt");                                                                                   // Concatenate the .txt Extension With the Unique_UserID of User So that It Will Become the File Path
		strcat(Main_Path,Details_FilePath);
		
		FILE *User_Last_Details;                                                                                           // File Pointer for Opening the File of USer That Have the Details such as Last Interested Domain and Last Scores of Quiz of The User  
	    char Scrs_Temp[5];                                                                                                 // For Fteching And Storing the Scores in Charcter Array Temprorily
	    char Interested_Domain_Temp[40];                                                                                   // For Temprorily Fetching and Storing the Last Interested Domain of User In It 
	    
	    User_Last_Details = fopen(Main_Path,"r");                                                                    // Open the File 
	    fscanf(User_Last_Details,"%s\n%s",Interested_Domain_Temp,Scrs_Temp);                                                // Read the Data such as Last Interested Domain and Scores from the File 
	    
	    fclose(User_Last_Details);
	    
		strcpy(Last_Interested_Domain,Interested_Domain_Temp);                                                              // Copy the Last Interested Domain into the global Array Last_Interested_Domain 
		Last_Achieved_Scores = atoi(Scrs_Temp);                                                                             // For Storing the Scores Globally After Converting It Into Integer Type 
		
		Display_Returned_User_Details();	                                                                                // Call the Function That Actully Display the Deatils of USer suach as Their NAme , Last_Interested_Domain and Scores  Which LoggedIn as Retuned Login User 
	}
	else
	{
		strcpy(Details_FilePath,LoggedIn_UserID);
		strcat(Details_FilePath,".txt");
		New_LoggedIn_User_Details();                                                                                        // If the LoggedIn_Status_RON is Still False Means User is a New LoggedIn_User So, Another Function Is Being Called for the NEw LoggedIn Users and Function is New_LoggedIn_User_Details
	}
	
	
	bool Stop_Submenu_Check = true;                                                                                         //For Stop Asking the Choice from SUbmennu When User Tell Us to Logout or It Starts the Quiz 
	char Choice;
	
// Submenu Printing Code and Ask from User To Start the Quiz or Display About Us or Rules or Domains or They Want to Quit , If Wrong Choice Then Again Continue to As From User To Enter Choice Again from the SUbemnu
		
		while(Stop_Submenu_Check==true)                                                                                                   //Asking and Printing Subemenu Till The User Not Choose the Option 1 That is Start the Quiz 
		{
			SubMenu();
			printf("\n\n\n\t\t\t * Please Enter a Choice from the Above Menu * --> ");
			Choice = getche();                   
		
			if(Choice=='1')                                                                                              
			{
				Stop_Submenu_Check = false;                                                                                                     // Make the Variable to false so that Loop Will be Stop Now
			}
			else if(Choice=='2')
			{
				Domains();
			}
			else if(Choice=='3')
			{
				About_Us();                                                                      
			}
			else if(Choice=='4')
			{
			    Rules_The_Ultimate_Quizzy();	
			}
			else if(Choice=='5')
			{
				system("cls");
				printf("\n\n\n\n\t\t\t <-> You Are Successfully Logged Out From Your Account %s! <->\n\n\n",LoggedIn_Name);
				Stop_Submenu_Check = false;
				return;                                                                                                                     // To Stop the Execution of the Code from the Function 
			}
			else
			{
				printf("\n\n\n\t\t Invalid! , Please Enter the Right Choice According to the Above Menu. \n\n");
				continue;
			}
		
	}
	
		
		printf("\n\n\n\n\n\t\t\t\t %c Get ready to challenge your tech knowledge! The quiz is about to begin. \n\n\t\t\t    Prepare yourself for exciting questions from various tech domains. Best of luck! %c %c",17,3,16);
	    printf("\n\n\n\n\t\t Wait , Loading.............");
		sleep(8);
	    system("cls");
	    
//This Below Code is For Actully Start the Quiz After When Option 1 is Sleected By the USer Above , So Now Ask the Domain From User in Which They Want To Play the QUiz 
	   bool Stop_Check = false;
	   char Domain_No;
	   
	   while(Stop_Check!=true)                                                                                                                  // Loop is Asking Run Until Right Domin is Not Selected By the USer , When Selecte than The Stop_Check Variable is Set to True So that Will Fetch the QUestions Data and Diaplsy Now of that Choosen Domain
	   {
	   	Start_Quiz_Description();
	   	
	   	printf("\n\n\n\n\t\t\t * Please Choose a Domain By Enter the Mentioned Domain No. * --> ");
	   	Domain_No = getche();
	   	
	   	  if(Domain_No=='1')
	   	  {
	   		strcpy(Current_Choosen_Domain,"Software_Development");                                                                              // Corresponding Domain NAme is Copy in the Charcater Array When A Corresponding Dmaoin Number SLecetd By the USer
	   		Stop_Check = true;
		  }
		  else if(Domain_No=='2')
		  {
		    strcpy(Current_Choosen_Domain,"Web_Development");
			Stop_Check = true;	
		  }
		  else if(Domain_No=='3')
		  {
		  	strcpy(Current_Choosen_Domain,"Cyber_Security");
			Stop_Check = true;	
		  }
		  else if(Domain_No=='4')
		  {
		    strcpy(Current_Choosen_Domain,"Cloud_Computing");
			Stop_Check = true;		
		  }
		  else
		  {
		  	printf("\n\n\n\t\t Invalid! , Please Enter the Right Choice According to the Above Given Choices. \n\n");
			continue;
		  }  
	   }
	   
	  printf("\n\n\n\t\t\t <-> Please Wait! <->");
	  sleep(7);
	  
// From Here We Are Going To Start the Quiz and Now We ACtually Display The QUestions In fornt of the User Of their Choosen Corresponding Domain	  
	  
	  After_Start_Quiz_Description(); 
	  
	  char Questions_File_Path[1000]="Data Management of THE ULTIMATE QUIZZY\\Questions CSV Files For Quiz\\";
	   
	  strcat(Questions_File_Path,Current_Choosen_Domain);
	  strcat(Questions_File_Path,".csv");
	  
	  Fetch_Questions_Data(Questions_File_Path);                                                                                            //Calling to the Fetch Questions Function By Passing the LOcation and NAme of the File of the Sv inside the Function as String or a Charcater Array
	  
	  printf("\n\n\n\n\n\t\t\t\t\t\t --^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^");
	  printf("\n\n\t\t\t\t\t\t\t\t    'THE ULTIMATE QUIZZY' ");
	  printf("\n\n\t\t\t\t\t\t --^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^");
	  
	  Display_Questions_To_User();                                                                                                         // Call to the Function for Displaying the Questions in Front of USer One By One With the Constratints
	  
	   

}


#endif