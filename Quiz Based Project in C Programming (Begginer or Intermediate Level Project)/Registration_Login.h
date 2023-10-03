#ifndef Registration_Login
#define Registration_Login
#include<stdbool.h>
#include<string.h>
#include<unistd.h>                                       // For Adding Pause or Sleep for Sometime at Any Point in our Program 
#include<stdlib.h>                                       // For Random Number Generation 
#include<time.h>                                         // For Managing Generate Random Number Evertime
#include<ctype.h>                                        // For Converting Lowercase to Upper or  Uppercase to Lowercase 
#include "Data Management of THE ULTIMATE QUIZZY\\User Last Interested Domain and Last Scores\\Quiz_Questions_Management.h"



void Registration()
{
	char Name[40] , Username[38] , Password[28] , Stream[30];                                              // 4 Charcater Arrays (Strings) To Store the Details Like : Name,Username,Password,Stream                                           
	char Education_Level[15];
	char Age[4];	
	
	                                                                                               printf("\n\n\n\n\n\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
	
	                                                                                               printf("\n\n\t\t\t\t\t\t\t\t\t\t Registration 'THE ULTIMATE QUIZZY'");

                                                                                                   printf("\n\n\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");


//-------------------------------------- Asking Name from User and Validation On Name -----------------------------------------------------------
    
	bool Name_Check = false;

	printf("\n\n\n\n\n\n\t\t\t\t * Enter Your Name For Registration * ---> ");
    scanf("%s",&Name);
    
    for(int Cnt=0; Cnt<strlen(Name); ++Cnt)                                                                                             // ----> Iterate Over the Each and Every Charcater of Name or We Can traverse over the each and Every Character of Name through this for loop 
    {
    	if( (Name[Cnt]>='0' && Name[Cnt]<='9') || (Name[Cnt]>='!' && Name[Cnt]<='&') || (Name[Cnt]>=':' && Name[Cnt]<='@') || (Name[Cnt]>=123 && Name[Cnt]<=126) || (Name[Cnt]>='[' && Name[Cnt]<='^') || (Name[Cnt]>='(' && Name[Cnt]<=')') || (Name[Cnt]>='*' && Name[Cnt]<='/') || (Name[Cnt]=='.') )    
		                                                                                                                     /* ------> this Ensures that If Any Iterated or Traversed Charcater is any Number , Any Special Charcater Like !"#$%&()-/:;<=>?@[\]^_{|}~ from this then Stop 
																															 the Loop (using Break Statement) and Intialize the Name_Check Boolean Varible value to true which represents that User Does Not Enter the Name in a Correct Format ,
																															  So Now at Out of Loop Condition is True that is If Name_Check==true , So Ask the All Details of Registration from User Again . And Process Continues Untill Correct 
																															  Format for All the Details Has not Been Met with our Correct Detils Format */
	   {
		Name_Check = true;
		break;
	   }
	}
	
	if(Name_Check==true)                                                                                               // Check if the Boolean Varible Name_Check is True then Again Ask All the Details from User By Call the Regsitrartion Function Again & Again (Recursively) , Until Not All the correct Details has been Entered  
	{
		printf("\n\n\n\n\t\t\t Wrong Format For Name (Because Your Format for Name Does not Match With Our Format of Name) , Kindly Enter the Correct Details Again !");
		Registration();                                                                                                 // Again Call the Regsitration Function To ask the All Deatisl WithnCorrect Format Again , Again and Again .... Call Until All The Correct Deatils Has Not Been Entered 
		return ;                                                                                                       // Here EMpty Return Statement Controls that , the Code is Not Executed After When the Correct Details Has been Entered , Because Program Control Recursively at Here , So If We Not Use Return then They Again Exceute the All Pending Code After Asking All the Deatils Correctly, This Only Stops When User Enters All the Correct Format Details  
	}                                                                                                                   // When Registration is Call recusively then They Ask ALl the deatils Again , And If At this Time Corrct Fomar Details are Not Presnst then Again Same Process Continues, and Until User Enters the Correct Deatils in a Proper Format
     

//--------------------------------------------- Asking Username/Email from User and Validation on Username ------------------------------------------------    
     
    bool Username_Spl = false,Username_Dig = false, Username_Dot = false;                                                          // Here We Applied Validation Username Must have any no. of Digits from 0 to 9 and @ and .
	 
	printf("\n\n\n\n\t\t\t\t * Enter Your Username (Email) For Registration * ---> ");
    scanf("%s",&Username);
     
// --------- Validation that Check Email/Username Must have Digit , @ and . -----------------------------------------
	 
    for(int C=0; C<strlen(Username); ++C)
    { 
     	Username[C] = tolower(Username[C]);                                                                               //Converting Each and Every Charcater of Username into Loweracse After TAking Input of Username or Email from User & Stores in the Same Location Every Charcater
	}
	
	 
    for(int Cnt = 0; Cnt<strlen(Username); Cnt++)                                                                        // ---> This Loop Iterteres Over the or Traverse Over the Each and Every Charcater of Username 
    {
     	if(Username[Cnt]>='0' && Username[Cnt]<='9')                                                                     // Checks If the Username Any Traversed or Iterated Charcater is a Digit then Set Username_Dig to true 
     	{
     	 Username_Dig = true;	
		}
		else if(Username[Cnt]=='.')
		{
			Username_Dot = true;
		}
		else if(Username[Cnt]=='@')                                                                                    // Checks If the Username Any Traversed or Iterated Charcater is '@' then Set Username_Spl to true
		{
			Username_Spl = true;
		}
	}
	 
	if(Username_Spl == false || Username_Dig==false || Username_Dot==false )                                                // If Anything is Not Oresent in Username and Anyone Validtaion is Not true then Again and Again Asking the All Details for Regsiatration from User
	{
	 	printf("\n\n\n\n\t\t\t Wrong Format For Username (Because Your Format for Username Does not Match With Our Format of Username) , Kindly Enter the Correct Details Again !");
        Registration();                                                                                                   // Registartion Function Call To Ask All the Details AGian If Correct Details is Not Present , and call Until All Correct Details is Not Entered By User
        return ;
	} 
	 
	//---------- Validation that Ensures Must be a Valid Email/Username and Must Have the our Supported Email Provider name -------------------
	
	char *Dot_Loc , *Rate_Loc , *SMTP_Loc;                                                                                 // 2 Pointer Vars of Char Type for Finding Location of . , @ and Third one for Finding First Character of SMTP as Substring inside Username  
	bool Format = true , SMTP_Check = false;                                                                               // Boolean Varibles For Ensuring that Valid Format Username and Msut have the Our Supported SMTP
	char SMTPs[4][12] = {"gmail" , "outlook" , "yahoo" , "microsoft"};
	 
	Dot_Loc = strchr(Username,'.');                                                                                   // Find the Memory Location of Dot in the Username 
	Rate_Loc = strchr(Username,'@');                                                                                  // Find the Memory Location of At_Rate in the Username 
	 
	if ((Dot_Loc-Username) < (Rate_Loc-Username))                                                                      // Check if the Dot is Before the @ or SMTP Name then Means Username Formt is Not Right :like -> abc123.gmail@com
	{
	    Format = false;
	}
	
	for(int Cnt = 0; Cnt<4 ; Cnt++)                                                                                     // Cnt Traverse Over Each SMTP name in Charcater 2D Array SMTPs
	{
		SMTP_Loc = strstr(Username,SMTPs[Cnt]);                                                                          // Match or Check if Iterated SMTP Name from SMTPs 2D Array, is Present in USername as Substring , and Check Using String Manipulation Function strstr() that is for Finding Fisrt Index of Substring in a String  
		
		if(SMTP_Loc!=NULL)                                                                                               // SMTP_Loc is a Boolean Varible , Must have True if Our Supported SMTP / Email Provider is used Otheriwse False that rrepsents Invalid Email Provider name 
		{
			SMTP_Check = true;
			break;                                                                                                       // Means Where they Found that Iterated SMTP is Present in Username or Email as Substring then STop and Set SMTP_Chcek to true , Represents that Supported SMTP Have in Username 
		}
	}
	
	if(!SMTP_Check)                                                                                                      //Means If the False , means  Not a Valid (Supported) SMTP or Email Provider Name  in the USername , So Now Again Ask All the Deatils from User 
	{
		printf("\n\n\n\n\t\t\t Invalid SMTP (Email Provider) Name For Username , We Support only these SMTPs : \n\n\n\t\t\t\t 1. 'gmail' \n\n\t\t\t\t 2. 'yahoo' \n\n\t\t\t\t 3. 'microsoft' \n\n\t\t\t\t 4. 'outlook' \n\n\n\t\t\t Kindly Enter the Correct Deatils Again!");
        Registration();                                                                                                  // Registartion Function Call To Ask All the Details AGian If Correct Details is Not Present , and call Until All Correct Details is Not Entered By User
        return ;
	}
	if(!Format)                                                                                                           // Foramt is false if the "." is before the "@" , Means Invalid Format like:abc123.@gmailcom
	{
		printf("\n\n\n\n\t\t\t Invalid Format For Username , Kindly Enter the Correct Details Again !");
        Registration();                                                                                             // Registartion Function Call To Ask All the Details AGian If Correct Details is Not Present , and call Until All Correct Details is Not Entered By User
        return ;
	}
    
	  
//--------------------------------------------- Asking Password from User and Validation on Password ------------------------------------------------    
    
     bool Password_Upper = false, Password_Dig = false , Password_Spl = false , Password_Len = false;                     // For Applying the Validation on Password that , Passwor dmUst have a Digit , a uppercase Aplhabet , a Special Charcater and Password Must have the 8 or More than 8 Charcaters Long Upto 25 
	    
	 
	printf("\n\n\n\n\t\t\t\t * Enter the Password For Your Registration * ---> ");
	scanf("%s",&Password);   
	
	if(strlen(Password)>=8 && strlen(Password)<=25)                                                                        // Check If the password Length is Correct Then Set Pasword_len to true 
	{
		Password_Len = true;
	}
	
	for(int Cnt=0; Cnt<strlen(Password); ++Cnt)                                                                            // Iterate or Traverse Over the Each and Every Character of password 
	{
		if(Password[Cnt]>='A' && Password[Cnt]<='Z')                                                                      // Check if the Password Have the Uppercase Alphabet from A to Z Any then Set Password_Upper to true
		{
			Password_Upper = true;
		}
		else if(Password[Cnt]>='0' && Password[Cnt]<='9')                                                                    // Check if the Password Have a Digit from 0 to 9 Any then Set Password_Dig to true
		{
			Password_Dig = true;
		}
		else if ((Password[Cnt]>='!' && Password[Cnt]<='&') || (Password[Cnt]>=':' && Password[Cnt]<='@') || (Password[Cnt]>=123 && Password[Cnt]<=126) || (Password[Cnt]>=94 && Password[Cnt]<=95) )   // Check if the Password Have Any Special Charcater from Number of Special Characters the Setn Password_Spl to true 
	    {
	    	Password_Spl = true;
		}
	}
	
	if(Password_Spl==false || Password_Len==false || Password_Dig==false || Password_Upper==false)                              // If Any of the Validation is Not Being Met or Means If Any Of the Thing is False or if Anything is Not Present Either Uppercase Alphabet , Digit , Special Charcater and Length is Not Correct then Again Call the Registration Function and Ask ALl the etrails AGain and Until User Enters ALl the Correct Details 
	{
		printf("\n\n\n\n\t\t\t Wrong Format For Password (Because Your Format for Password Does not Match With Our Format of Password) , Kindly Enter the Correct Details Again !");
        Registration();
        return ;                                                                                                                // Avoid To Run the Code Further When in a Recursive Call of Regsitration Function User enter All the Correct details , Because Control was at Here , So There have the Code After That , So We USe return as Break to Avoid Exceution of Code Further, Because All Correct Deatils are Get! 
	}
//--------------------------------------------- Asking Stream from User ------------------------------------------------    

   printf("\n\n\n\n\t\t\t\t * Enter the Stream (Field) From Where You Belong * ---> ");
   scanf("%s",&Stream);
   
//--------------------------------------------- Asking About Education Level and Validation on Education Level ------------------------------------------------    
 
   char Took_Ed_Level;
   
   printf("\n\n\n\n\t\t\t\t ** Choose Your Education Level By Press a Option No ** ");
   printf("\n\n\n\t\t\t\t 1. Schooling               2. UG (Under Grdauation)          3. PG (Post Graduation)");
   printf("\n\n\n\t\t\t\t\t * Enter Option No. * ---> ");
   Took_Ed_Level = getche();
   
   if(!(Took_Ed_Level>='1' && Took_Ed_Level<='3'))                                                                           // Means Check if Wrong Choice Enter Not from 1 to 3 inside the Took_Ed_Level Varible then Recursiverly Call the Registration Function
   {
   	    printf("\n\n\n\n\t\t\t Wrong Option , Kindly Choose Right Option from The Available Options! (Enter the Correct Deatils Again) ");
   	    Registration();
   	    return ;
   }
   
   
   if(Took_Ed_Level=='1')
   {
   	strcpy(Education_Level,"Schooling");                                                          // Agr Option 1 Select Hua hai , To Schholing Krde Enter
   }
   else if(Took_Ed_Level=='2')
   {
   	strcpy(Education_Level,"UG");                                                               // Agr Option 2 Select Hua hai , then Copy the UG in Education Level Chracter Array or String
   }
   else if(Took_Ed_Level=='3')
   {
   	strcpy(Education_Level,"PG");                                                               // Agr Option 3 Select Hua hai , then Copy the PG in Education Level Chracter Array or String
   }
   
    
    
// -------------------------------------- Asking Age From User and Validation On Age-------------------------------------------------------

	
	bool Wrong_Age = false;
	
	printf("\n\n\n\n\t\t\t\t * Enter Your Age For Registration * ---> ");
	scanf("%s",Age);
	
	for(int Cnt=0;Cnt<strlen(Age);++Cnt)
	{
		if(!(Age[Cnt]>='0' && Age[Cnt]<='9'))                                                                        // Apply Validation that If Any Digit of Age is Not From 0 to 9 then Set Wrong_Age To True so that Gaian Ask the Details of Resgiratration thet is Correct 
		{
			Wrong_Age=true;                                                                                           // Wrong_Age Boolean Will True if Not the Numeric Value for Age 
			break;
		}
	}
	
	if(Wrong_Age)
	{
		printf("\n\n\n\n\t\t\t (Invalid Age) Kindly Enter Age Only in Numeric Format! (Enter the Correct Details Again)");
		Registration();                                                                                                   // Call the Registration Function , So that We Have to take ONly the GAe in Numeric Format , and Call Again and GAian Until Correct Deatils Have Not Entered BY User 
		return;
	}


      
//-----------------------------Further Process After Asking Details for Registration from User-----------------------------


    
    
    printf("\n\n\n\n\n\n\t\t\t\t\t ===> Please Wait While We Are Verifying and Processing Your Details  %c ",2);
    printf("\n\n\n\t\t\t\t\t ===> You Will Get a Unique User Id After Processing!");
    printf("\n\n\n\t\t\t\t\t PROCESSING.....................");
    
    sleep(10);                                                                                                    // Basically It Pause the Program Execution for the Specifed Seconds inside It
    
    
//----------------------------------User Id Assigning Process ----------------------------------------------------

   
   char Unique_User_Id[30]="UL_QZY-";                                                                           //Basically We Assign Firtly the Prefix for User_Id
   char Name_S[3];
   char Name_First_Char = Name[0];
   char Name_Last_Char = Name[(strlen(Name)-1)];
   char Str_Random_Num[4];
   
   Name_S[0] = toupper(Name_First_Char);                                                // First Chrcater of Name                                                                               // Store Chrarcater Fisrt of Name After converting Into Uppercase Into Name_S So that Become Suffix for UserID
   Name_S[1] = toupper(Name_Last_Char);                                   //Second Charcater of Name                                                      // Store Last Charcater of Name After converting Into Uppercase Into Name_S So that Become Suffix for UserID
   
    
   srand(time(0));                                                                                                   // Enusures that Everytime of Running , It Will Generate a Random Number;
   
   int Random_Num = rand() % 900 + 100;                                                                                   // Rand Function Here Enables us to generate a Random Number Between 0 to 999 (Calculate According to the Modulus Opertaor )                                                         
   sprintf(Str_Random_Num,"%d",Random_Num);
   
   strcat(Unique_User_Id,Name_S);
   strcat(Unique_User_Id,".");
   strcat(Unique_User_Id,Str_Random_Num);                                                                                   // Concatenete the Prefix of Unique User id With Name_S(Which is Basically Having First and Last Charcaters of Name) at the Backend , We STore UserID With a Random Generated NUmber as Suffix  ---> After Concatnation result Stores in Unqiue_User_ID
      
      
//-----------------------Actual Registration (Store The User Entered Data for Regsiration at Backend in CSV's)-------------------------

 
 
   FILE *Registration , *Login;                                                                                         // Declare Two file Pointers for File Handling (Regisatrtion.csv and Login.csv)
   char Fetch_Name[40], Fetch_Username[38] , Fetch_Password[28] , Fetch_UserID[27] , Fetch_EDLevel[12] , Fetch_Stream[25] , Fetch_Age[5];                                              // For Fteching Data of Each and Every Column of Regisration.csv in Every Iteration in Different Strings or Charcater Arrays 
   bool Reg_Check = false;                                                                                               // To Check or Validate That User Must Not Already Registered With Us 
   
   
   Registration = fopen("Data Management of THE ULTIMATE QUIZZY\\Registration.csv","r");
 
   while(fscanf(Registration,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",Fetch_Username,Fetch_Password,Fetch_UserID,Fetch_Name,Fetch_Age,Fetch_EDLevel,Fetch_Stream)==7)                                    // read the Data of Seven Differnet Columns of Registration.csv in Various Strings or Charcter Arrays and Until the Size of Reciving data of Columns ==7
   {
    
    
    //printf("\n\n%s",Fetch_Username);
	
   	if(strcmp(Username ,Fetch_Username)==0)                                                                                 // Check If the Iterated or Fteched USername at That Time or Iteration is Match with the User ENtered USername than Means User is LAreday Resgiatered with us , SO Tell the USer and Stop 
   	 {
   		printf("\n\n\n\n\n\n\t\t Hey , %s",Name);
  		printf("\n\n\n\t\t Sorry! According to Our Records You Are Already Registered With Us , Kindly Go and Login With Your Registered Username/Unique_UserID and Password , So that You'll Continue Further With Us. ");
  		printf("\n\n\n\t\t From : 'THE ULTIMATE QUIZZY'\n\n\n\n\n");
  		fclose(Registration);
  		Reg_Check = true;
  		return;                                                                                                            // Stop  the Registartion Process if the USer is Already Registered With Us   , Here Return Statement Works as the Break Statement to Stop Execution of Loop and Comes out of Function also 
	 }
   }
    
   if(!Reg_Check)                                                                                                           // Means If Reg_Check Boolean Varible is Still False Means No Match Found or User is Not Already Resgitered WIth Us , So Store the Registarion Details in registartion ,csv and Some Details also in Login.csv                                                                    
   {
   	 
   	 Registration = fopen("Data Management of THE ULTIMATE QUIZZY\\Registration.csv","a");                                              //Open the Registartion.csv in append mode for Storing Registration Details in It 
   	 fprintf(Registration,"%s,%s,%s,%s,%s,%s,%s\n",Username,Password,Unique_User_Id,Name,Age,Education_Level,Stream);                                                                                                                                                                // Appending the Regsiatration Details into the Registration.csv File
     
     Login = fopen("Data Management of THE ULTIMATE QUIZZY\\Login.csv","a");                                                            //Open the Login.csv in Append Mode for Storing Some Details of Resgiatration that Entered By User Also in Login.csv
     fprintf(Login,"%s,%s,%s\n",Username,Unique_User_Id,Password);                                                                                                                                                                                                                   // Appending Some Details of Registration also into the Login.csv File             
     
	 printf("\n\n\n\n\n\n\t\t\t Hey , %s",Name);  
  	 printf("\n\n\n\t\t\t Congratulations ! , You are Successfully Registered With Us. Now You Also Become the Part of 'THE ULTIMATE QUIZZY' .");
     printf("\n\n\n\t\t\t Generated Unique User Id For Your Account is: %s ",Unique_User_Id);
     printf("\n\n\n\t\t\t Now You Easily Login With Us , Either With Your Username , Password & Either With the Generated Unqiue UserID , Password.");
    
     printf("\n\n\n\n\n\n\t\t 'THANK YOU' for Register With Us!");
     printf("\n\n\n\t\t Regards ");
     printf("\n\n\n\t\t From : 'THE ULTIMATE QUIZZY' TEAM\n\n\n\n\n");
   }
    
   fclose(Registration);                                                           // To Make the Chnages Permanenet of Appending Data of registartion into the File Must required to Close the File
   fclose(Login);                                                                  // To Make the Chnages Permanenet of Appending Data of registartion into the File Must required to Close the File
     
}


void Login()
{
	char Username_UserID[38] , Password[30];                                                             // Declare Two Chrcater Arrays , or Strings in which Asking about the Username and password From User for Login
	                                                                                               printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
	
	                                                                                               printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Login 'THE ULTIMATE QUIZZY'");

                                                                                                   printf("\n\n\t\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

    
    printf("\n\n\n\t\t\t\t\t\t ------- Note: If You are using Username for Login With Us then Must have all the Alphabets in lowercase only  -------\n\n");
    printf("\n\n\n\n\n\n\t\t\t\t\t ** Enter Your Username/Unique UserID For Login With 'THE ULTIMATE QUIZZY' ** ---> ");
    scanf("%s",&Username_UserID);
    
    printf("\n\n\n\t\t\t\t\t ** Enter Your Password For Login With 'THE ULTIMATE QUIZZY' ** ---> ");
    scanf("%s",&Password);
    
    
    
    FILE *Login_UQ;                                                                                                              // Declare a File Pointer for Login.csv File Handling 
    char Fetch_Username[38] , Fetch_UserID[27] , Fetch_Password[30];                                                             // Charcater Arrays or Strings that Everytime reccives the data from Login.csv in it and Check It Match With Username/Unique_UserID and PAssword , If Match Founbd then Stop and Tell USer Login Otheriwse Give Error of Wrong Login Credentials 
    bool Login_Check = false;                                                                                                    // To Check User is Already Regsitered With Us , if Yes then Login Process Successfull ended And Account of User is Open Otheriwse Not and Error Message is Displayed To User 
    
    Login_UQ = fopen("Data Management of THE ULTIMATE QUIZZY\\Login.csv","r");                                           // Open the Login.csv File for Login Process and In read Mode File is Open 				                
    
    while(fscanf(Login_UQ,"%[^,],%[^,],%s\n",Fetch_Username,Fetch_UserID,Fetch_Password)==3)                                          // Read the Each Column Data of Login.csv in Sequnce and Store in 3 Charcater Arrays 
    {
    	if ( (strcmp(Username_UserID,Fetch_Username)==0 && strcmp(Password,Fetch_Password)==0) || (strcmp(Username_UserID,Fetch_UserID)==0 && strcmp(Password,Fetch_Password)==0) )             // Matching is Done that If the Iterated Username and Password or USerID or Password is Match With User Entered Username/UserID and password Then Stop using break and Set Login_Check to true that represnet Login successfull and Accoubt of User is Open Otheriwse If Not Match Loop Continues and Check , and If not Anywhere in CSV user Entered Credentials are Not Found then Give Error Message to User Check Your Creddentials or ENter Again or Regsiter With Us First Before Login  
	    {
	        	Login_Check = true;
	        	fclose(Login_UQ);
	        	break;
		} 
	}
	
	
	printf("\n\n\n\n\n\t\t\t Processing.............");
	sleep(7);                                    
	
	if(Login_Check==true)                                                                                                          // Means User Entered Credentials are Found in Login.csv then Means Login Successfull
	{
		
		Login_Further(Fetch_Username,Fetch_UserID);                                                                         // Beasically Ftech_Username and Fetch_UserID Will have the Last Details That is Got from the File Login.csv and This Deatils is Passing Becuase User is Logged In Now , Means Entered Creadentials of User is Correct Or We can Say that It is a Registered User 
	}
	else                                                                                                                      //Means Creaddentils Are Not Found or Login_Check is Still false so Means Eitehr Credentials are Wrong or User is Not Registered With US , So Tell To User With a Error MEssage on Screen 
	{
		printf("\n\n\n\n\n\n\n\t\t\t ----     Wrong Login Credentials Error     ----");
		printf("\n\n\n\t\t\t ----     According to our Records , Your Login Credentials are Not Found     ----");
		printf("\n\n\n\t\t\t ----     Check Your Credentials and Enter the Correct Details If You are Already Registered , Otherwise Firstly Register With 'THE ULTIMATE QUIZZY' !     ----");
	    printf("\n\n\n\t\t\t FROM : 'THE ULTIMATE QUIZZY' \n\n\n\n\n");
	    fclose(Login_UQ);
	}
}




#endif