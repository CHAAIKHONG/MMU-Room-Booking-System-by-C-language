#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
#include<unistd.h>
#define max_booking 100

// Define a struct for user information
struct User {
    char name[50];
    int contactNumber;
    int studentID;
    char password[30];
};struct User u;

// Define a struct for user login
struct login{
	char spass[30];
    int ssid;
};struct login l;

// Define a struct for room information
struct rname{
	char rname[50];
	int date;
	int timein;
	int timeout;
	char location[50];
	int number;
};struct rname r;

struct rname booking[max_booking];
int numbooking = 0;


void get_login();
void get_register();
int menu();
void booking_room();
void personal_information();
void history();
void room_melaka();
void room_cyber();
void dfacility();
void facility_id_c();
void facility_id_m();
void clearinput();
void add_print();
void print_result();
void password(char[]);
void edit_information();
void all_exit();
void first_page();

int main() {
    int choice,c1=0;
	// Set console color to light gray on white 
	system("color F0");
	// Call function first_page() 
	first_page();
	// Display a message and wait for user input
	printf("\t\t\t\t\t");
	system("pause");
	do{
		// Main loop for the menu
		do {
			// Clear the console screen
		    system("cls || clear");
		    printf("\t\t\t   ============================================================\n");
		    printf("\t\t\t                         MMU BOOKING ROOM                      \n");
		    printf("\t\t\t   ============================================================\n");
		    printf("\t\t\t\t\t\t   1. Login\n");
		    printf("\t\t\t\t\t\t   2. Register\n");
		    printf("\t\t\t\t\t\t   0. Exit System\n");
		    printf("\t\t\t   ============================================================\n\n");
		    printf("\t\t\t   Enter your choice : ");
		    scanf("%d", &choice);
		    fflush(stdin);
			
			//Process user choice
		    if (choice == 1) {
		    	//If user chooses option 1, than call funtion get_login()
		        get_login();
		        l.ssid = u.studentID;
		    } 
			else if (choice == 2) {
				//If user chooses option 2, than call funtion get_register()
		        get_register();
		    }
		    else if(choice == 0){
		    	//If user chooses option 3, than call funtion all_exit()
		    	system("cls || clear");
		    	all_exit();
			}
		} while (choice == 2);
		
		if(choice !=1 && choice !=2 && choice !=0){
			system("cls || clear");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t\a   x  Input error, please choose again  x\n");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t   ");
			system("pause");
		}
		else{
			break;
		}
	}while(1);
	// Call the function menu() after the loop 
	c1 = menu();
}

void get_login() {
    
    int match = 0,csid;
    char cof;
    char checkname[50],checkpassword[30];
    int checksid,checkcontectnumber;
    // Clear the console screen
    system("cls || clear");
    // File pointers for reading usernames and passwords
    FILE *fptr;
    FILE *file;
	// Open the file in read mode
    fptr = fopen("username.txt", "r");
    file = fopen("password.txt", "r");
    
    
    
    do {
    	// Reset file pointers to the begining of the files
    	rewind(fptr);
    	rewind(file);
    	// display for user input
    	printf("\t\t\t   =============================================================\n");
    	printf("\t\t\t                               LOGIN                            \n");
    	printf("\t\t\t   =============================================================\n\n");
        printf("\t\t\t   Enter your User Name(Student ID) : ");
        scanf("%d", &l.ssid);
        
        printf("\t\t\t   Enter your Password : ");
        password(l.spass);// A function to read a password securely
    	
		// Validate username and passsword from files
        while (fscanf(fptr, "%d", &u.studentID) == 1) {
            fscanf(file, "%s", u.password);
            // Check if the entered credentials match
            if (u.studentID == l.ssid && strcmp(u.password, l.spass) == 0) {
                match = 1;
                break;
            }
        }
        // Clear input buffer
		clearinput();
		// Clear the console screen
    	system ("cls || clear");
    	// Check if login was successful
        if (match) {
        	printf("\n\n\n\n\n\n\t\t\t\t**********************************************\n");
        	printf("\t\t\t\t*                                            *\n");
            printf("\t\t\t\t*              Login Successful              *\n");
            printf("\t\t\t\t*                                            *\n");
            printf("\t\t\t\t**********************************************\n");
            sleep(2);// Pause for 2 seconds
            break;
        } 
		else {
			// Login failed
        	do{
        		// Display an error message and option
        		printf("\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	            printf("\t\t\a                  The Username or Password is Wrong. Please try again.               \n");
	            printf("\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
	            // Prompt for user input : Continue(Y) or Forget Password(N)
	            printf("\t\t   Enter [Y] to continue, Enter [N] is forget password\t");
	            scanf("%c",&cof);
	            // Check the choice
	            if(cof == 'Y' || cof == 'y'){
	            	// Clear the console screen and break out of the loop
	            	system("cls || clear");
	            	break;
				}
				else if(cof == 'N' || cof == 'n'){
					system("cls || clear");
					clearinput();
					printf("\t\t\t\t   -----------------------------------\n");
					printf("\t\t\t\t             Forget Password          \n");
					printf("\t\t\t\t   -----------------------------------\n\n");
					// Prompt for Student ID to retrieve password
					printf("\t\t\t\t   Enter your Student ID : ");
					scanf("%d",&csid);
					// File pointer to check for the forgetten password
					FILE *check;
					check = fopen("n_cno.txt","r");
					// Check for the Student ID in the file
					while (fscanf(check,"%d\t %s\t %s\t %d",&checksid,checkpassword,checkname,&checkcontectnumber) == 4){
						if(csid == checksid){
							// Display the forgotten password
							printf("\t\t\t\t   Your password is %s\n\n",checkpassword);
							fclose(check);
							break;
						}
					}
					// Close the file
					fclose(check);
				}
				printf("\t\t\t\t   -----------------------------------\n");
				printf("\t\t\t\t   ");
				system("pause");
				system("cls || clear");
				break;
			}while(1);
        }
    } while (1);
	// Close the file
    fclose(fptr);
    fclose(file);
}


void get_register() {
	int ch,match=0;
	char c_password[50];
	// Clear the console screen
    system("cls || clear");
    do{
    	// Display registration interface
    	printf("\t\t\t   ================================================\n");
    	printf("\t\t\t                       REGISTER                    \n");
    	printf("\t\t\t   ================================================\n");
	    printf("\t\t\t   Enter your Name: ");
	    fgets(u.name,sizeof(u.name),stdin);
	    u.name[strcspn(u.name,"\n")] = 0;// Remove newline character if present
	    printf("\t\t\t   Enter your Contact Number: +60");
	    scanf("%d", &u.contactNumber);
	    printf("\t\t\t   Enter your Student ID: ");
	    scanf("%d", &u.studentID);
	    printf("\t\t\t   Enter your Password: ");
	    password(u.password);
	    printf("\n\t\t\t   Confirm Password : ");
	    password(c_password);
	    // Check if the passwords match
	    if(strcmp(c_password,u.password) == 0){
	    	system("cls || clear");
	    	printf("\n\n\n\n\n\n\t\t\t\t**********************************************\n");
        	printf("\t\t\t\t*                                            *\n");
            printf("\t\t\t\t*              Register Successful           *\n");
            printf("\t\t\t\t*                                            *\n");
            printf("\t\t\t\t**********************************************\n");
            sleep(2);// Pause for 2 seconds
	    	break; // Exit the loop if passwords match
		}
		else{
			// Clear the console screen and display an error message
			system("cls || clear");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t\a   x   Those passwords didn`t match. Try again.   x\n");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		}
		// Clear input buffer
		clearinput();
	}while(1);

	
	//File pointer for writing registration fdate to files
	FILE *fptr;
	FILE *file;
	FILE *name;
	// Openfile in append mode
	fptr = fopen("username.txt","a");
	fprintf(fptr,"%d\n",u.studentID);
	
	file = fopen("password.txt","a");
	fprintf(file,"%s\n",u.password);
	
	name = fopen("n_cno.txt","a");
	fprintf(name,"%d\t %s\t %s\t %d\n",u.studentID,u.password,u.name,u.contactNumber);
	// Close the file
	fclose(fptr);
	fclose(file);
	fclose(name);
	
}

int menu()
{
	int c;
	
	do{
		// Clear the console screen
		system("cls || clear");
		// Display menu option
		printf("\t\t\t\t                          MENU                        \n");
		printf("\t\t\t\t   --------------------------------------------------\n");
		printf("\t\t\t\t\t\t   1. Booking Room\n");
		printf("\t\t\t\t\t\t   2. Personal information\n");
		printf("\t\t\t\t\t\t   3. Historical Booking\n");
		printf("\t\t\t\t\t\t   4. Logout\n");
		printf("\t\t\t\t   --------------------------------------------------\n");
		printf("\t\t\t\t   Enter your choice : ");
		scanf("%d",&c);
		clearinput();// Clear input buffer
		// Switch based on user choice
		switch(c){
			case 1:
				// Clear the console screen and call the function booking_room()
				system("cls || clear");
				booking_room();
				break;
			case 2:
				// Clear the console screen and call the function personal_information()
				system("cls || clear");
				personal_information();
				break;
			case 3:
				// Clear the console screen and call the function history()
				system("cls || clear");
				history();
				break;
			case 4:
				// Clear the console screen and call the function all_exit()
				system("cls || clear");
				all_exit();
				break;
		}
	}while(1);
	
	return c;
}


void booking_room()
{
	int lot,c,x,recordexists = 0,studentID;
	char recod[50],rname[50];
	int timein,timeout,date;
	int rtimein,rtimeout,rdate,rcapacity;
	int count = 0;
	int input;
	char tin[5];
	char ymd[7],location[50];
	do{
		recordexists = 0;
		// Selct room location
		do{
			printf("\t\t\t   ============================================================\n");
			printf("\t\t\t                     BOOKING ROOM - Location                   \n");
			printf("\t\t\t   ============================================================\n");
			printf("\t\t\t   1. Melaka\n");
			printf("\t\t\t   2. Cyberjaya\n");
			printf("\t\t\t   0. Back\n");
			printf("\t\t\t   ------------------------------------------------------------\n");
			printf("\t\t\t   Enter your choice : ");
			scanf("%d",&lot);
		
			if(lot == 1){
				room_melaka();
				sprintf(r.location,"Melaka");
				break;
			}
			else if(lot == 2){
				room_cyber();
				sprintf(r.location,"Cyberjaya");
				break;
			}
			else{
				//Clear the console screen and display error message for incorrect choice
				system("cls || clear");
				printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
				printf("\t\t\t\a   x         Your choice is Wrong. Please try Enter again.         x\n");
				printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
			}
		}while (lot != 1 && lot != 2 && lot !=0);
		
		if(lot != 0){
			do{	
				do{
				// Input time for booking	
				system("cls || clear");
				printf("\t\t\t   --------------------------------\n");
				printf("\t\t\t                 TIME              \n");
				printf("\t\t\t   --------------------------------\n");
				printf("\t\t\t        Time limit is one hour     \n");
				printf("\t\t\t   Enter one of the following times\n");
				printf("\t\t\t   --------------------------------\n");
				// Displayavailable time slots
				for(x=6;x<22;x++){
					printf("\t\t\t   %02d00\n",x);
				}
				printf("\t\t\t   --------------------------------\n\n");
				printf("\t\t\t   Please Select Entry Time : ");
				scanf("%d",&timein);
				}while (timein<600 || timein>2100);
				
				
				snprintf(tin,sizeof(tin),"%04d",timein);
				
				if(strlen(tin) == 4){
					break;
				}
				else{
					// Display error message for invalid time input
					system("cls || clear");
					printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
					printf("\t\t\t\a   x      Invalid Input Time.     x\n");
					printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
				}
			}while(1);
			do{
				// Input date for booking
				system("cls || clear");
				printf("\t\t\t   ------------------------------------------------------------\n");
				printf("\t\t\t                DATE [Format: yymmdd (ex: 240113)]             \n");
				printf("\t\t\t   ------------------------------------------------------------\n");
				printf("\t\t\t   Enter your Date : ");
				scanf("%d",&date);
				
				snprintf(ymd,sizeof(ymd),"%d",date);
				
				if(strlen(ymd) == 6){
					break; 
				}
				else{
					// Display error message for invalid date input
					system("cls || clear");
					printf("\t\t\t   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
					printf("\t\t\t   x      Invalid Input date.     x\n");
					printf("\t\t\t   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
				}
			}while(1);
			
			timeout = timein + 100;
			// Check if the record already exists
			FILE *record;
			record = fopen("record.txt","r");
			while(fscanf(record,"%d %s %d %04d %04d %s %d",&u.studentID,rname,&rdate,&rtimein,&rtimeout,&location,&rcapacity) == 7){
				if(strcmp(r.rname,rname) == 0 && rdate== date && rtimein == timein){
					printf("%d %s %d %04d %04d %s %d",u.studentID,rname,rdate,rtimein,rtimeout,location,rcapacity);
					recordexists = 1;
					system("cls || clear");
					break; 
				}
			}
			fclose(record);
			
			if(recordexists){
				// Display message for existing record
				printf("\t\t\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
				printf("\t\t\t\t\t\a   x  The record already exists.  x\n");
				printf("\t\t\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
			}
			else{
				// Write the new booking record to the file
				record = fopen("record.txt","a");
				fprintf(record,"%d %s %d %d %d %s %d\n",l.ssid,r.rname,date,timein,timeout,r.location,r.number);
				fclose(record);
				// Update the booking array with the new booking details
				strcpy(booking[numbooking].rname, r.rname);
				booking[numbooking].date = date;
				booking[numbooking].timein = timein;
				booking[numbooking].timeout = timeout;
				strcpy(booking[numbooking].location, r.location);
				booking[numbooking].number = r.number;
				numbooking++;
				// Display success message and call function add_print()
				printf("\n\t\t\t\t\t   ********************************\n");
				printf("\t\t\t\t\t   *      Booking successful      *\n");
				printf("\t\t\t\t\t   ********************************\n");
				add_print();
			}
		}
		else if(lot == 0){
			c = menu();
			break;
		}
	}while (recordexists);
	

}

void add_print(){
	char ctn;
	int select;
	// Displat a message and wait for user input to continue
	printf("\t\t\t\t\t   ");
    system("pause");
    printf("\t\t\t   ------------------------------------------------------------\n");
	
	while(1){
		// Display option for the user
		printf("\t\t\t   1. Book one more room\n");
		printf("\t\t\t   2. Print Result\n\n");
		printf("\t\t\t   ------------------------------------------------------------\n\n");
		printf("\t\t\t   Select your number : ");
		scanf("%d",&select);
		// Check the user`s choice and take appropriate action
		if(select == 1){
			// Clear the console screen and call the fucntion booking_room()
			system("cls || clear");
			booking_room();
			break;
		}
		else if(select == 2){
			// Clear the console screen and call the fucntion print_result()
			system("cls || clear");
			print_result();
			break;
		}
		else {
			// Display an error message for invalid input
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t\a   x   Invalid input number. Please enter 1 or 2.   x\n");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		}
	}
}

void print_result()
{
	int i,c;
	int choicebb;
	// Display a header for the booking results
	printf("\t\t\t   ==========================================\n");
	printf("\t\t\t                  ALL Bookings               \n");
	printf("\t\t\t   ==========================================\n\n");
	// Print details for each booking in the array
	for(i = 0; i < numbooking; i++){
		printf("\t\t\t   Booking %d\n",i + 1);
		printf("\t\t\t   Room Name : %s\n",booking[i].rname);
		printf("\t\t\t   Date      : %d\n",booking[i].date);
		printf("\t\t\t   Time In   : %04d\n",booking[i].timein);
		printf("\t\t\t   Time Out  : %04d\n",booking[i].timeout);
		printf("\t\t\t   Location  : %s\n",booking[i].location);
		printf("\t\t\t   Capacity  : %d\n",booking[i].number);
		printf("\t\t\t   -----------------------------------------\n\n");
	}
	
	do{
		// Display option for the user
		printf("\t\t\t   1. Book one more room\n");
		printf("\t\t\t   0. Back to menu\n\n");
		printf("\t\t\t   ------------------------------------------\n\n");
		printf("\t\t\t   Please enter your choice : ");
		scanf("%d",&choicebb);
		// Check the user`s choice and take appropriate action
		if(choicebb != 1 || choicebb != 2){
			// Clear the console screen and display an error message for invalid input
			system("cls || clear");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t\a   x Invalid input number. Please enter 1 or 0. x\n");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
		}
		else{
			break; // Exit the loop if the input is valid
		}
		
		if(choicebb == 1){
				// Call function booking_room()
				booking_room();
				break;
			}
			else{
				// Clear input buffer 
				clearinput();
				c = menu();
				break;
			}
	}while(1);
}

void room_melaka()
{
	// Clear the console screen
	system("cls || clear");
	const char i[] = "maximum";
	int a = 1;
	// Display header for Melaka room capacity
	printf("\t\t\t   ==============================================\n");
	printf("\t\t\t                MELAKA - ROOM CAPACITY           \n");
	printf("\t\t\t   ==============================================\n");
	// Display room capaity option
	printf("\t\t\t   %d. %s 10\n",a++,i);
	printf("\t\t\t   %d. %s 40\n",a++,i);
	printf("\t\t\t   %d. %s 150\n",a++,i);
	printf("\t\t\t   %d. %s 300\n",a++,i);
	printf("\t\t\t   %d. %s 500\n",a++,i);
	printf("\t\t\t   %d. %s 1000\n",a++,i);
	printf("\t\t\t   0. Back\n");
	printf("\t\t\t   ----------------------------------------------\n\n");
	// Call function to display facility ID for Malaka
	facility_id_m();
	
}

void dfacility()
{
	printf("\t\t\t           Facility ID");
}

void facility_id_m()
{
	int rc;
	int x,y,q,c;
	const char con[]="\t\t\t   Enter your choice : ";
	char n;
	const char i[] = "maximum";
	// Prompt the user to ener room capacity choice
	printf("\t\t\t   Enter your room capacity choice : ");
	scanf("%d",&rc);
	system("cls || clear");
	// Display header for Melaka room facilities
	printf("\t\t\t   ==============================================\n");
	printf("\t\t\t                       MELAKA                    \n");
	printf("\t\t\t   ==============================================\n");

	switch(rc){
		case 1:
			q = 10;
			y=1;
			r.number = 10;
			dfacility();
			printf(" - %s 10 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x=1; x<23 ; x++){
				printf("\t\t\t   %d. MSME%04d-CLC_Concourse_Lot_%02d\n",y++,x,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c !=0){
				sprintf(r.rname,"MSME%04d-CLC_Concourse_Lot_%02d",c,c);
			}
			break;
		case 2:
			q = 40;
			y=1;
			r.number = 40;
			dfacility();
			printf(" - %s 40 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. MAMR3006-FOB_Computer_Lab_4\n",y++);
			printf("\t\t\t   %d. MAMR3007-FOB_Computer_Lab_5\n",y++);
			printf("\t\t\t   %d. MBME0001-CDP_Lobby\n",y++);
			printf("\t\t\t   %d. MSMR2009-CLC_Tutorial_Room_B1\n",y++);
			printf("\t\t\t   %d. MSMR3013-CLC_Tutorial_Room_B17\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				switch(c){
					case 1:
						strcpy(r.rname,"MAMR3006-FOB_Computer_Lab_4");
						break;
					case 2: 
						strcpy(r.rname,"MAMR3007-FOB_Computer_Lab_5");
						break;
					case 3:
						strcpy(r.rname,"MBME0001-CDP_Lobby");
						break;
					case 4:
						strcpy(r.rname,"MSMR2009-CLC_Tutorial_Room_B1");
						break;
					case 5:
						strcpy(r.rname,"MSMR3013-CLC Tutorial_Room_B17");
						break;
				}
			}
			break;
		case 3:
			q = 150;
			y=1;
			r.number = 150;
			dfacility();
			printf(" - %s 150 Person              \n",i);
			printf("\t\t\t   ==============================================\n"); 
			printf("\t\t\t   %d. MEME0001-SEC_Lobby_Main_Hall\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				strcpy(r.rname,"MEME0001-SEC_Lobby_Main_Hall");
			}
			break;
		case 4:
			q = 300; 
			y=1;
			r.number = 300;
			dfacility();
			printf(" - %s 300 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x = 1; x<13;x++){
				printf("\t\t\t   %d. FIST%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				sprintf(r.rname,"FIST%04d",c);
			}
			break;
		case 5:
			q = 500;
			y=1;
			r.number = 500;
			dfacility();
			printf(" - %s 500 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x = 1;x<=56;x++){
				printf("\t\t\t   %d. FBDV%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   99. Next Page\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0 && c!=99){
				sprintf(r.rname,"FBDV%04d",c);
			}
			if(c == 99){
				system("cls || clear");
				printf("\t\t\t   ==============================================\n");
				printf("\t\t\t                       MELAKA                    \n");
				printf("\t\t\t   ==============================================\n");
				dfacility();
				printf(" - %s 500 Person              \n",i);
				printf("\t\t\t   ==============================================\n");
				y = 1; 
				for(x=57;x<=112;x++){
					printf("\t\t\t   %d. FBDV%04d\n",y++,x);
				}
				printf("\n\t\t\t   0.  Back to Room Capacity\n");
				printf("\t\t\t   99. Next Page\n");
				printf("\t\t\t   ----------------------------------------------\n");
				printf("%s",con);
				scanf("%",&c);
				if(c!=0 && c!=99){
					sprintf(r.rname,"FBDV%04d",c + 56);
				}
				if(c == 99){
					system("cls || clear");
					printf("\t\t\t   ==============================================\n");
					printf("\t\t\t                       MELAKA                    \n");
					printf("\t\t\t   ==============================================\n");
					dfacility();
					printf(" - %s 500 Person              \n",i);
					printf("\t\t\t   ==============================================\n");
					y=1;
					for(x=1;x<=30;x++){
						printf("\t\t\t   %d. FBFV%04d\n",y++,x);
					}
					printf("\n\t\t\t   0.  Back to Room Capacity\n");
					printf("\t\t\t   99. Next Page\n");
					printf("\t\t\t   ----------------------------------------------\n");
					printf("%s",con);
					scanf("%d",&c);
					if(c!=0 && c!=99){
						sprintf(r.rname,"FBFV%04d",c);
					}
					if(c == 99){
						system("cls || clear");
						printf("\t\t\t   ==============================================\n");
						printf("\t\t\t                       MELAKA                    \n");
						printf("\t\t\t   ==============================================\n");
						dfacility();
						printf(" - %s 500 Person              \n",i);
						printf("\t\t\t   ==============================================\n");
						y=1;
						for(x=1;x<=40;x++){
							printf("\t\t\t   %d. FBUG%04d\n",y++,x);
						}
						printf("\n\t\t\t   0.  Back to Room Capacity\n");
						printf("\t\t\t   99. Next Page\n");
						printf("\t\t\t   ----------------------------------------------\n");
						printf("%s",con);
						scanf("%d",&c);
						if(c!=0 && c!=99){
							sprintf(r.rname,"FBUG%04d",c);
						}
						if(c == 99){
							system("cls || clear");
							printf("\t\t\t   ==============================================\n");
							printf("\t\t\t                       MELAKA                    \n");
							printf("\t\t\t   ==============================================\n");
							dfacility();
							printf(" - %s 500 Person              \n",i);
							printf("\t\t\t   ==============================================\n");
							y=1;
							printf("\t\t\t   %d. MRAR0001-Dataran_Permata\n",y++);
							for(x=1;x<=15;x++){
								printf("\t\t\t   %d. MXDM13%02d\n",y++,x);
							}
							printf("\n\t\t\t   0.  Back to Room Capacity\n");
							printf("\t\t\t   ----------------------------------------------\n");
							printf("%s",con);
							scanf("%d",&c);
							if(c!=0 ){
								if(c == 1){
									strcpy(r.rname,"MRAR0001-Dataran_Permata");
								}
								else {
								sprintf(r.rname,"MXDM13%02d",c);
								}
							}
						}
					}
				}
			}
			break;
		case 6:
			q = 1000;
			y = 1;
			r.number = 1000;
			dfacility();
			printf(" - %s 1000 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. FBU0001\n",y++);
			for(x=1;x<=45;x++){
				printf("\t\t\t   %d. FETV%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   99. Next Page\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0 && c!=99){
				if(c == 1){
					sprintf(r.rname,"FBU0001");
				}
				else{
					sprintf(r.rname,"FETV%04d",x);
				}
			}
			if(c == 99){
				y=1;
				system("cls || clear");
				printf("\t\t\t   ==============================================\n");
				printf("\t\t\t                       MELAKA                    \n");
				printf("\t\t\t   ==============================================\n");
				dfacility();
				printf(" - %s 1000 Person              \n",i);
				printf("\t\t\t   ==============================================\n");
				for(x=46;x<=90;x++){
					printf("\t\t\t   %d. FETV%04d\n",y++,x);
				}
				printf("\n\t\t\t   0.  Back to Room Capacity\n");
				printf("\t\t\t   ----------------------------------------------\n");
				printf("%s",con);
				scanf("%d",&c);
				if(c!=0){
					sprintf(r.rname,"FETV%04d",c + 45);
				}
			}
			break;
		default:
			// If an invalid room capacity is selected, clear the console screen and call function booking_room()
			system("cls || clear");
			booking_room();
			break;
	}
	// If the user chose to go back, clear the screen and display the Melaka room capacity menu again
	if(c==0){
		system("cls || clear");
		room_melaka();
	}
}

void room_cyber()
{
	// Clear the console screen
	system("cls || clear");
	const char i[] = "maximum";
	int rc,a = 1,p=0;
	// Display header for Cyberjaya room capacity
	printf("\t\t\t   ==============================================\n");
	printf("\t\t\t              CYBERJAYA - ROOM CAPACITY          \n");
	printf("\t\t\t   ==============================================\n");
	// Display room capacity options
	printf("\t\t\t   %d. %s 5\n",a++,i);
	printf("\t\t\t   %d. %s 30\n",a++,i);
	printf("\t\t\t   %d. %s 35\n",a++,i);
	printf("\t\t\t   %d. %s 40\n",a++,i);
	printf("\t\t\t   %d. %s 90\n",a++,i);
	printf("\t\t\t   %d. %s 180\n",a++,i);
	printf("\t\t\t   %d. %s 200\n",a++,i);
	printf("\t\t\t   %d. %s 500\n",a++,i);
	printf("\t\t\t   %d. %s 1000\n",a++,i);
	printf("\t\t\t   0. Back\n");
	printf("\t\t\t   ----------------------------------------------\n\n");
	// Call functionto display facility IDfor Cyberjaya
	facility_id_c();
}

void facility_id_c()
{
	int rc;
	int x,y,q,c;
	const char con[]="\t\t\t   Enter your choice : ";
	char n, i[] = "maximum";
	// Prompt the user to enter room capacity choice
	printf("\t\t\t   Enter your room capacity choice : ");
	scanf("%d",&rc);
	system("cls || clear");
	// Display header for Cyberjaya room facilities
	printf("\t\t\t   ==============================================\n");
	printf("\t\t\t                     CYBERJAYA                   \n");
	printf("\t\t\t   ==============================================\n");

	switch(rc){
		case 1:
			q = 5;
			y=1;
			r.number = 5;
			dfacility();
			printf(" - %s 5 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CJER0016-FCA_Depot\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c !=0){
				strcpy(r.rname,"CJER0016-FCA_Depot");
			} 
			break;
		case 2:
			q = 30;
			y=1;
			r.number = 30;
			dfacility();
			printf(" - %s 30 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CJD4018-EDU_HUB\n",y++);
			printf("\t\t\t   %d. CLAR2002-FOE_Machine_&_Drive_L\n",y++);
			printf("\t\t\t   %d. CLAR2004-FOE_Energy_Sytem_Lab\n",y++);
			printf("\t\t\t   %d. CLAR3005-FOE_Embedded_Sys_Lab\n",y++);
			printf("\t\t\t   %d. CLAR4020-FOE_Intel_MicroE_Lab\n",y++);
			printf("\t\t\t   %d. CLAR4021-FOE_Optical_Lab 1\n",y++);
			printf("\t\t\t   %d. CLAR4002-FOE_Telecom_Lab\n",y++);
			printf("\t\t\t   %d. CLAR4025-FOE_Applied_Elec_Lab\n",y++);
			printf("\t\t\t   %d. CLAR3051-FOE_Optical_Lab_2\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				switch(c){
					case 1:
						strcpy(r.rname,"CJD4018-EDU_HUB");
						break;
					case 2: 
						strcpy(r.rname,"CLAR2002-FOE_Machine_&_Drive_L");
						break;
					case 3:
						strcpy(r.rname,"CLAR2004-FOE_Energy_Sytem_Lab");
						break;
					case 4:
						strcpy(r.rname,"CLAR3005-FOE_Embedded_Sys_Lab");
						break;
					case 5:
						strcpy(r.rname,"CLAR4020-FOE_Intel_MicroE_Lab");
						break;
					case 6:
						strcpy(r.rname,"CLAR4021-FOE_Optical_Lab_1");
						break;
					case 7:
						strcpy(r.rname,"CLAR4002-FOE_Telecom_Lab");
						break;
					case 8:
						strcpy(r.rname,"CLAR4025-FOE_Applied_Elec_Lab");
						break;
					case 9:
						strcpy(r.rname,"CLAR3051-FOE_Optical_Lab_2");
						break;
				}
			}
			break;
		case 3:
			q = 35;
			y=1;
			r.number = 35;
			dfacility();
			printf(" - %s 35 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CJCR3011-FCA_Student_Lounge\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				strcpy(r.rname,"CJCR3011-FCA_Student_Lounge");
			}
			break;
		case 4:
			q = 40;
			y=1;
			r.number = 40;
			dfacility();
			printf(" - %s 40 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CLAR3001-FOE_Electronics_Lab1\n",y++);
			printf("\t\t\t   %d. CLAR2052-FOE_Huawei_Lab\n",y++);
			printf("\t\t\t   %d. CQAR4005-FCI_PG_Research_Lab_1\n",y++);
			printf("\t\t\t   %d. CQAR4006-FCI_PG_Research_Lab_2\n",y++);
			printf("\t\t\t   %d. CQAR4007-FCI_Tech_Support_Room\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0){
				switch(c){
					case 1:
						strcpy(r.rname,"CLAR3001-FOE_Electronics_Lab1");
						break;
					case 2: 
						strcpy(r.rname,"CLAR2052-FOE_Huawei_Lab");
						break;
					case 3:
						strcpy(r.rname,"CQAR4005-FCI_PG_Research_Lab_1");
						break;
					case 4:
						strcpy(r.rname,"CQAR4006-FCI_PG_Research_Lab_2");
						break;
					case 5:
						strcpy(r.rname,"CQAR4007-FCI_Tech_Support_Room");
						break;
				}
			}
			break;
		case 5:
			q = 90;
			y=1;
			r.number = 90;
			dfacility();
			printf(" - %s 90 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CLBR1002-FOE_Lecture_Room_6\n",y++);
			printf("\t\t\t   %d. CLCR3044-FOE_Lecture_Room_16\n",y++);
			printf("\t\t\t   %d. CLCR3045-FOE_Lecture_Room_15\n",y++);
			printf("\t\t\t   %d. CLCR3047-FOE_Lecture_Room_17\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c != 0){
				switch(c){
					case 1:
						strcpy(r.rname,"CLBR1002-FOE_Lecture_Room_6");
						break;
					case 2: 
						strcpy(r.rname,"CLCR3044-FOE_Lecture_Room_16");
						break;
					case 3:
						strcpy(r.rname,"CLCR3045-FOE_Lecture_Room_15");
						break;
					case 4:
						strcpy(r.rname,"CLCR3047-FOE_Lecture_Room_17");
						break;
				}
			}
			break;
		case 6:
			q = 180;
			y=1;
			r.number = 180;
			dfacility();
			printf(" - %s 180 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			printf("\t\t\t   %d. CNMX2005-CLC_Lexture_Theatre\n",y++);
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c != 0){
				strcpy(r.rname,"CNMX2005-CLC_Lexture_Theatre");
				
			}
			break;
		case 7:
			q = 300;
			y=1;
			r.number = 300;
			dfacility();
			printf(" - %s 300 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x=1;x<=10;x++){
				printf("\t\t\t   %d. FACV%04d\n",y++,x);
			}
			for(x=1;x<=20;x++){
				printf("\t\t\t   %d. FCIV%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   99. Next Page\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0 && c!=99){
				if(c >=1 && c<=10){
					sprintf(r.rname,"FACV%04d",c);
					
				}
				else if(c>=11 && c<= 20){
					sprintf(r.rname,"FCIV%04d",c-10);
				}
			}
			else if(c == 99){
				system("cls || clear");
				printf("\t\t\t   ==============================================\n");
				printf("\t\t\t                     CYBERJAYA                   \n");
				printf("\t\t\t   ==============================================\n");
				dfacility();
				printf(" - %s 300 Person              \n",i);
				printf("\t\t\t   ==============================================\n");
				y = 1; 
				for(x=1;x<=10;x++){
					printf("\t\t\t   %d. FCMV%04d\n",y++,x);
				}
				for(x=1;x<=10;x++){
					printf("\t\t\t   %d. FOEV%04d\n",y++,x);
				}
				for(x=1;x<=10;x++){
					printf("\t\t\t   %d. FOMV%04d\n",y++,x);
				}
				printf("\n\t\t\t   0.  Back to Room Capacity\n");
				printf("\t\t\t   -----------------------------------------------\n");
				printf("%s",con);
				scanf("%d",&c);
				if(c!=0 && c!=99){
					if(c>=1 && c<=10){
						sprintf(r.rname,"FCMV%04d",c);
					}
					else if(c>=11 && c<=20){
						sprintf(r.rname,"FOEV%04d",c-10);
					}
					else if(c>=21 && c<=30){
						sprintf(r.rname,"FOMV%04d",c-20);
					}
				}
			}
			break;
		case 8:
			q = 500;
			y = 1;
			r.number = 500;
			dfacility();
			printf(" - %s 500 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x=11;x<=15;x++){
				printf("\t\t\t   %d. FOMV%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0 && c!=99){
				sprintf(r.rname,"FOMV%04d",c+10);	
			}
			break;
		case 9:
			q = 1000;
			y=1;
			r.number = 1000;
			dfacility();
			printf(" - %s 1000 Person              \n",i);
			printf("\t\t\t   ==============================================\n");
			for(x=21;x<=50;x++){
				printf("\t\t\t   %d. FCIV%04d\n",y++,x);
			}
			printf("\n\t\t\t   0.  Back to Room Capacity\n");
			printf("\t\t\t   99. Next Page\n");
			printf("\t\t\t   ----------------------------------------------\n");
			printf("%s",con);
			scanf("%d",&c);
			if(c!=0 && c!=99){
					sprintf(r.rname,"FCIV%04d",c+20);
			}
			else if(c == 99){
				system("cls || clear");
				printf("\t\t\t   ==============================================\n");
				printf("\t\t\t                     CYBERJAYA                   \n");
				printf("\t\t\t   ==============================================\n");
				dfacility();
				printf(" - %s 1000 Person              \n",i);
				printf("\t\t\t   ==============================================\n");
				y = 1; 
				for(x=1;x<=12;x++){
					printf("\t\t\t   %d. FOEV%04d\n",y++,x);
				}
				for(x=16;x<=20;x++){
					printf("\t\t\t   %d. FOMV%04d\n",y++,x);
				}
				printf("\t\t\t   %d. FORVC0013\n",y++);
				for(x=1;x<=3;x++){
					printf("\t\t\t   %d. STADCY%02d\n",y++,x);
				}
				printf("\n\t\t\t   0.  Back to Room Capacity\n");
				printf("\t\t\t   ----------------------------------------------\n");
				printf("%s",con);
				scanf("%d",&c);
				if(c!=0 && c!=99){
					if(c>=1 && c<=12){
						sprintf(r.rname,"FOEV%04d",c);
					}
					else if(c>=13 && c<=17){
						sprintf(r.rname,"FOMV%04d",c+3);
					}
					else if(c>=18 && c<=21){
						sprintf(r.rname,"STADCY%04d",c-20);
					}
					break;
				}
			}
			break;
		default:
			// If an invalid room capacity is selected, clear the console screen and call function booking_room()
			system("cls || clear");
			booking_room();
			break;
	}
	// If the user chose to go back, clear the screen and display the Cyberjaya room capacity menu again
	if(c==0){
		system("cls || clear");
		room_cyber();
	}
}

void history()
{
	char fid[50],location[50],c;
	int ssid,date,timein,timeout,capacity,x,y;
	FILE *record;
	// Open the "record.txt" file in read mode
	record = fopen("record.txt","r");
	// Display header for the history section
	printf("\t =======================================================================================================\n");
	printf("\t                                                  HISTORY                                                \n");
	printf("\t =======================================================================================================\n");
	printf("\t | %-10s | %-35s | %-15s | %-8s | %-8s | %-8s |\n","Location","Facility ID","Room Capacity","Date","Time IN","Time Out");
    printf("\t -------------------------------------------------------------------------------------------------------\n");
	// Read reord form the file and display relevant information for the logged-in user
    while (fscanf(record, "%d %s %d %d %d %s %d", &ssid, fid, &date, &timein, &timeout, location,&capacity) == 7) {
        if (ssid == l.ssid) {
            printf("\t | %-10s | %-35s | %-15d | %-8d | %04d     | %04d     |\n", location, fid, capacity, date, timein, timeout);
            printf("\t -------------------------------------------------------------------------------------------------------\n");
        }
    }
    // Close the file after reading records
    fclose(record);
    // Display a pause message and wait for user input
    printf("\t\t\t   ");
    system("pause");
    
    c = menu();
}

void personal_information() 
{
	int E_D_B;
	char c;
	
	FILE *name;
	// Open the "n_cno.txt" file in read mode
    name = fopen("n_cno.txt", "r");
    // Display header for the personal information section
    printf("\t\t\t   ========================================\n");
    printf("\t\t\t             Personal Information          \n");
    printf("\t\t\t   ========================================\n");
	
	do{
		// Read records from the file and display personal information for the logged-in user
		while (fscanf(name,"%d %s %s %d\n",&u.studentID,u.password,u.name,&u.contactNumber) == 4){
			if(u.studentID == l.ssid){
			    printf("\t\t\t   Name           : %s\n", u.name);
			    printf("\t\t\t   Contact Number : +60%d\n", u.contactNumber);
			    printf("\t\t\t   Student ID     : %d\n", u.studentID);
			}
		}
		// Display options for editing personal information or going back to the main menu
		printf("\t\t\t   ----------------------------------------\n");
		printf("\t\t\t   1. Edit Your Personal Information\n");
		printf("\t\t\t   0. Back  to Menu\n");
		printf("\t\t\t   ----------------------------------------\n\n");
		printf("\t\t\t   Enter Your Number : ");
		scanf("%d",&E_D_B);
		fclose(name); 
		// Perform actions based on the user's choice
		if(E_D_B == 1){
			edit_information();
			break;
		}
		else if(E_D_B == 0){
			clearinput();
			c = menu();
			break;
		}
		else if(E_D_B !=1 || E_D_B !=0){
			system("cls || clear");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("\t\t\t\a   x Invalid input number. Please enter 1 or 0. x\n");
			printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
		}
	}while(1);
	// Colse the file after reading 
	fclose(name);
}

void edit_information()
{
	long int size = sizeof(u);
	system("cls || clear");
	int SID;
	char c;
	struct User newUser;
	do{
		// Prompt user to enter their username (Student ID)
		fflush(stdin); 
		printf("\t\t\t   ==============================================\n");
		printf("\t\t\t                  Edit Information               \n");
		printf("\t\t\t   ==============================================\n");
		printf("\t\t\t   Enter Your Username(Student ID) : ");
		scanf("%d",&SID);
		printf("\t\t\t   ----------------------------------------------\n\n");
		// Open the original file for reading and a temporary file for writing
		FILE *name;
		FILE *name2;
		name = fopen("n_cno.txt","rb+");
		name2 = fopen("ncno.txt","w");
		rewind(name);// Move the file pointer to the beginning of the file
		
		// Read records from the original file, allow the user to edit their information,
        // and write the updated information to the temporary file
		while (fscanf(name,"%d %s %s %d\n",&u.studentID,u.password,u.name,&u.contactNumber) == 4){  
			if (u.studentID == SID){
				clearinput();
				printf("\t\t\t   Enter new Name : ");
				fgets(newUser.name,sizeof(newUser.name),stdin);
				newUser.name[strcspn(newUser.name,"\n")] = 0;
				printf("\t\t\t   Enter new Contact Number : +60");
				scanf("%d",&newUser.contactNumber);
				strcpy(newUser.password,u.password);
				newUser.studentID = u.studentID;
				fprintf(name2,"%d %s %s %d\n",newUser.studentID,newUser.password,newUser.name,newUser.contactNumber);
			}
			else {
				fprintf(name2,"%d %s %s %d\n",u.studentID,u.password,u.name,u.contactNumber);
			}
		}
		 
		// Close the original and temporary files
		fclose(name);
		fclose(name2);
		
		// Remove the original file and rename the temporary file
		remove("n_cno.txt");
	    if (rename("ncno.txt", "n_cno.txt") == 0) {
	    	printf("\t\t\t   **********************************************\n");
	        printf("\t\t\t   *       The information already update.      *\n");
	        printf("\t\t\t   **********************************************\n\n\t\t\t   ");
	        break;
	    } else {
	    	printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	        printf("\t\t\t\a   x  The information cannot be update. Please try again.  x\n");
	        printf("\t\t\t\a   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\t\t\t   ");
	    }
	}while(1);
	// Pause and return to the main menu
    system("pause");
	c = menu();
}

void all_exit()
{
	printf("\n\n\n\n\n\t\t======================================================================================\n");
	printf("\t\t                         Thank you for choosing our services.                         \n");
	printf("\t\t     We truly appreciate your booking and look forward to serving you again soon.     \n");
	printf("\t\t======================================================================================\n\n\n\n\n\n");
	sleep(5);
	exit(0);
}

void first_page()
{
	printf("\t=========================================================================================================\n");
	printf("\t                                   Welcome to MMU Room Booking System                                    \n");
	printf("\t=========================================================================================================\n");
	printf("\t\tWe're delighted to introduce you to our streamlined and user-friendly booking platform\n");
	printf("\t\tdesigned to make your reservation experience hassle-free and efficient. Whether you're\n");
	printf("\t\tplanning a better study environment for lecturer, tutorial, laboratories or scheduling a huge\n");
	printf("\t\tevent, our system is here to simplify the process for you.\n");
	printf("\t\tThe opening booking time start from 6am until 9pm and each booking is allotted a\n");
	printf("\t\tone-hour time slot.\n\n");
	printf("\tPrecautions\n");
	printf("\t    1. If the room contains equipment or furnishings, handle them with care to prevent damage.\n");
	printf("\t    2. Ensure that any borrowed equipment is returned in good condition.\n");
	printf("\t    3. Leave the room in the same or better condition than you found it. Dispose of any trash\n");
	printf("\t       properly and report any damages to the relevant auth.\n");
	printf("\t    4. Follow proper exit procedures, such as turning off lights, locking doors, and returning\n");
	printf("\t       keys or access cards as required.\n\n");
	printf("\t\tThank you for your cooperation, we llok forward to serving you soon.\n");
	printf("\t\tShould you have any questions or need assistance, our support team is here to help.\n");
	printf("\t\tou may reach us via email [room.support@mmu.edu.my] or call us at 03-8312 1688.\n");
	printf("\t=========================================================================================================\n\n");
	
}

void clearinput()
{
	int ch;
	//  Continue reading charaters until a newline or end of file is encountered
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void password(char password[])
{	
int ch;
    int i = 0;

    while ((ch = _getch()) != '\r' && ch != '\n') {
        if (ch == 8) { // Backspace
            if (i > 0) {
                printf("\b \b"); // Move cursor back, overwrite with space, move cursor back again
                i--;
            }
        } else if (i < 29) {
            password[i++] = ch;
            putchar('*');
        }
    }

    password[i] = '\0'; // Null-terminate the password


}
