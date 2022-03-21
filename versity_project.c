#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int wrong=1, count;//global variable for login function of int type
int i=0, valid=0;
char choice=0 ;

char answer;
char doctor_user_id[20],doctor_name[20];
int target=0,found=0;

void main() // declare main function
{
    welcome(); // call welcome screen
    login();// call login screen
}
void welcome()
{

    gotoxy(25,6);
    printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    gotoxy(25,7);
    printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    gotoxy(25,8);
    printf("                         WELCOME                   ");
    gotoxy(25,9);
    printf("                           TO                      ");
    gotoxy(25,10);
    printf("                       HEALTHCARE                  ");
    gotoxy(25,11);
    printf("                   CONSULTATION CENTER             ");
    gotoxy(25,12);
    printf("                       MANAGEMENT                  ");
    gotoxy(25,13);
    printf("                         SYSTEM                    ");
    gotoxy(25,14);
    printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    gotoxy(25,15);
    printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    gotoxy(28,16);
    gotoxy(28,17);
    printf("Enter any key to continue.....");
    getch();
}
void gotoxy(short x, short y)// declare the gotoxy function
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void login()
{
    system("cls");
    int L=0;
    int a;
    char u[30], p[30];
    system("cls");



    printf("------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tLogin Option");
    printf("\n------------------------------------------------------------------------------------------------");
   /* do
    {*/
        printf("\n\t\t\t\t1/ Login as Staff");

        printf("\n\t\t\t\t2/ Login as Doctor\n");
        scanf("%d",&a);



    switch(a)
    {
    case 1:
        printf("\n\t\t\t\t1/ Login as Staff");
        printf("\n\t\t\t\tEnter Username and Password");
        do{
        printf("\n\t\t\t\tUsername:");
        scanf("%s",u);

        printf("\n\t\t\t\tPassword:");
        scanf("%s",p);
        if((strcmp(u,"s")==0)&& (strcmp(p,"1")==0))
        {
            printf("\n\t\t\t\tLogged Into System.");
            printf("\n\t\t\t\tPress any key to go next.....");
            printf("\n------------------------------------------------------------------------------------------------");
            getch();
            mainmenu();
            break;
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password \n\n");
            L++;

        }
        }while(L<=10);
        getch();
        break;
    case 2:
        printf("\n\t\t\t\t1/ Login as doctor");
        printf("\n\t\t\t\tEnter Username or Phone and Password");
        do{
        printf("\n\t\t\t\tUsername or Phone:");
        scanf("%s",u);

        printf("\n\t\t\t\tPassword:");
        scanf("%s",p);
        if(doctorlogin(u,p) == 1)
        {
            printf("\n\t\t\t\tLogged Into System.");
            printf("\n\t\t\t\tPress any key to go next.....");
            printf("\n------------------------------------------------------------------------------------------------");
            getch();
            doctor_menu();
            break;
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password \n\n");
            L++;

        }
        }while(L<=10);
        getch();
        break;
    }

    }

void mainmenu(void)
{
    int choice;

    system("cls");
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(20,2);
    printf("MAIN MENU");
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(20,5);
    printf("1. Add Doctor");
    gotoxy(20,7);
    printf("2. Doctor List");
    gotoxy(20,9);
    printf("3. Add Patient");
    gotoxy(20,11);
    printf("4. Appointment List");
    //gotoxy(20,13);
    //printf("5. Appointment List");
    //gotoxy(20,11);
    //printf("4. Prescription");
    gotoxy(20,13);
    printf("5. Login Option");
    gotoxy(20,15);
    printf("6. Close Application");
    gotoxy(20,17);
    printf("Please Enter a choice[1-6]:");
    scanf("%i",&choice);
    switch(choice)
    {
    case 1:
        add_doctor();
        break;
    case 2:
        view_doctor();
        break;
    case 3:
        add_patient();
        break;
    case 4:
        view_patient();
        break;
    case 5:
        login();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Wrong Entry!!");
        exit(0);


    }
}

void doctor_menu(void)
{
    int choice;

    system("cls");
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(20,2);
    printf("DOCTOR MENU");
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(20,5);
    printf("1. Appointment");
    gotoxy(20,7);
    printf("2. Prescription Generate");
    gotoxy(20,9);
    printf("3. Login Option");
    gotoxy(20,11);
    printf("4. Old Prescription");
    gotoxy(20,13);
    printf("5. Close Application");

    printf("Please Enter a choice[1-5]:");
    scanf("%i",&choice);
    switch(choice)
    {
    case 1:
        view_patient_for_doctor();
        break;
    case 2:
        prescription();
        break;
    case 3:
        login();
        break;
    case 4:
        prescription_view();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Wrong Entry!!");
        exit(0);

    }
}

struct doctor
{
    char doctors_id[20];
    char d_name[20];
    char d_phone[20];
    char d_pass[20];

} d;

struct patient
{
    int patient_id;
    char doctor_id[20];
    char p_name[20];
    char p_phone[20];
    char p_age[20];
    char p_symptom[50];

} p;

struct medicine_l
{
    char medicine_name[100];
    char note[150];

} m[50];

void add_patient(){
    system("cls");
    FILE *sfile;
    sfile = fopen("PatientRecord.txt","a");
    printf("\n\t\t****************************************************");
    printf("\n\t*********************ADD NEW PATIENT*********************");
    printf("\n\t\t******************************************************");
    printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
    printf("\n\t\t------------------------------");
    printf("\n\t\tPatient ID NO.\t\t:");
    fflush(stdin);
    scanf("%i",&p.patient_id);
    do
    {
        printf("\n\t\tPatient Name\t\t:");
        fflush(stdin);
        gets(p.p_name);
        p.p_name[0]=toupper(p.p_name[0]);
        for (i=0; i<strlen(p.p_name); ++i)
        {
            if(isalpha(p.p_name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nName contain invalid character. Please enter again.");
        }
    }
    while(!valid);

    do
    {
        printf("\n\t\tPhone\t\t:");
        fflush(stdin);
        gets(p.p_phone);
        p.p_phone[0]=toupper(p.p_phone[0]);
        for (i=0; i<strlen(p.p_phone); ++i)
        {
            if(!isalpha(p.p_phone[i]))
                valid = 1;
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nPhone contain invalid character. Please enter again.");
        }
    }
    while(!valid);

    do
    {
        printf("\n\t\tAge\t\t:");
        fflush(stdin);
        gets(p.p_age);
        p.p_age[0]=toupper(p.p_age[0]);
        for (i=0; i<strlen(p.p_age); ++i)
        {
            if(!isalpha(p.p_age[i]))
                valid = 1;
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nAge contain invalid character. Please enter again.");
        }
    }
    while(!valid);

    printf("\n\t\tCommon Symptom\t\t:");
    fflush(stdin);
    gets(p.p_symptom);

        printf("\n\t\tDoctor ID\t\t:");
        fflush(stdin);
        gets(p.doctor_id);
        //p.doctor_id[0]=toupper(p.doctor_id[0]);



    fprintf(sfile,"%i  %s  %s  %s  %s  %s\n\n",p.patient_id, p.p_name, p.p_phone,p.p_age,p.p_symptom,p.doctor_id);
    fclose(sfile);
    printf("\n\t SUCCESFULLY RECORDED.\n");
    getch();
    printf("\n\t\t Do you want to add more?[Y/N]:");
    scanf("%s",&answer);
    while(toupper(answer)!='Y'&& toupper(answer)!='N')
    {
        printf("Invalid!\n\tDo you want to add more?[Y/N]:");
        scanf("%s",&answer);
    }
    if(toupper(answer)=='Y')
    {
        add_patient();
    }
    else
    {
        printf("\n\t\tPress any key to go to mainmenu.....");
        mainmenu();
    }
}

void add_doctor()
{
    system("cls");
    FILE *sfile;
    sfile = fopen("DoctorRecord.txt","a");
    printf("\n\t\t****************************************************");
    printf("\n\t*********************ADD NEW DOCTOR*********************");
    printf("\n\t\t******************************************************");
    printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
    printf("\n\t\t------------------------------");
    do{
        printf("\n\t\tDoctor ID NO.\t\t:");
        fflush(stdin);
        gets(d.doctors_id);
        //d.doctors_id[0]=toupper(d.doctors_id[0]);
        for (i=0; i<strlen(d.doctors_id); ++i)
        {
            if(!isalpha(d.doctors_id[i]))
                valid = 1;
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nDoctor ID contain invalid character. Please enter again.");
        }
    }
    while(!valid);


    do
    {
        printf("\n\t\tDoctor Name\t\t:");
        fflush(stdin);
        gets(d.d_name);
        //d.d_name[0]=toupper(d.d_name[0]);
        for (i=0; i<strlen(d.d_name); ++i)
        {
            if(isalpha(d.d_name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nName contain invalid character. Please enter again.");
        }
    }
    while(!valid);

    printf("\n\t\tPassword\t\t:");
    fflush(stdin);
    gets(d.d_pass);

    do
    {
        printf("\n\t\tPhone\t\t:");
        fflush(stdin);
        gets(d.d_phone);
        //d.d_phone[0]=toupper(d.d_phone[0]);
        for (i=0; i<strlen(d.d_phone); ++i)
        {
            if(!isalpha(d.d_phone[i]))
                valid = 1;
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nPhone contain invalid character. Please enter again.");
        }
    }
    while(!valid);


    fprintf(sfile,"%s  %s  %s  %s\n\n",d.doctors_id, d.d_name, d.d_phone,d.d_pass);
    fclose(sfile);
    printf("\n\t SUCCESFULLY RECORDED.\n");
    getch();
    printf("\n\t\t Do you want to add more?[Y/N]:");
    scanf("%s",&answer);
    while(toupper(answer)!='Y'&& toupper(answer)!='N')
    {
        printf("Invalid!\n\tDo you want to add more?[Y/N]:");
        scanf("%s",&answer);
    }
    if(toupper(answer)=='Y')
    {
        add_doctor();
    }
    else
    {
        printf("\n\t\tPress any key to go to mainmenu.....");
        mainmenu();
    }

}
void view_patient()
{
    int i,e;
    FILE*sfile;
    system("cls");
    sfile=fopen("PatientRecord.txt","r");
    printf("\n\t\t\t*********************************************************");
    printf("\n\t\t\t**************** VIEW ALL APPOINTMENT RECORDS *****************");
    printf("\n\t\t\t*********************************************************");
    if(sfile==NULL)
    {
        printf("\n\n\t\t RECORD EMPTY");
        getch();
    }
    else
    {
        gotoxy(1,6);
        printf("Patient Id NO.");
        gotoxy(13,6);
        printf("Patient Name");
        gotoxy(30,6);
        printf("Phone");
        gotoxy(45,6);
        printf("Age\n");
        gotoxy(63,6);
        printf("Symptom\n");
        gotoxy(83,6);
        printf("Doctor ID\n");
        for(i=0; i<95; i++)
        {
            printf("-");
        }
        e=8;
        while((fscanf(sfile,"%i  %s  %s  %s  %s  %s\n\n",&p.patient_id, p.p_name, p.p_phone,p.p_age,p.p_symptom,p.doctor_id)) != EOF)
        {
            gotoxy(1,e);
            printf("%i",p.patient_id);
            gotoxy(13,e);
            printf("%s",p.p_name);
            gotoxy(30,e);
            printf("%s",p.p_phone);
            gotoxy(45,e);
            printf("%s",p.p_age);
            gotoxy(63,e);
            printf("%s",p.p_symptom);
            gotoxy(83,e);
            printf("%s",p.doctor_id);
            e++;
        }
        printf("\n");
        for(i=0; i<95; i++)
            printf("-");
    }
    printf("\n\n\t Press any key for main menu........");
    fclose(sfile);
    getch();
    mainmenu();

}

void view_patient_for_doctor()
{
    int i,e;
    FILE*sfile;
    system("cls");
    sfile=fopen("PatientRecord.txt","r");
    printf("\n\t\t\t*********************************************************");
    printf("\n\t\t\t**************** VIEW ALL APPOINTMENT RECORDS *****************");
    printf("\n\t\t\t*********************************************************");
    if(sfile==NULL)
    {
        printf("\n\n\t\t RECORD EMPTY");
        getch();
    }
    else
    {
        gotoxy(1,6);
        printf("Patient Id NO.");
        gotoxy(13,6);
        printf("Patient Name");
        gotoxy(30,6);
        printf("Phone");
        gotoxy(45,6);
        printf("Age\n");
        gotoxy(63,6);
        printf("Symptom\n");
        gotoxy(83,6);
        printf("Doctor ID\n");
        for(i=0; i<95; i++)
        {
            printf("-");
        }
        e=8;
        while((fscanf(sfile,"%i  %s  %s  %s  %s  %s\n\n",&p.patient_id, p.p_name, p.p_phone,p.p_age,p.p_symptom,p.doctor_id)) != EOF)
        {


            if(strcmp(doctor_user_id,p.doctor_id) == 0)
            {
            gotoxy(1,e);
            printf("%i",p.patient_id);
            gotoxy(13,e);
            printf("%s",p.p_name);
            gotoxy(30,e);
            printf("%s",p.p_phone);
            gotoxy(45,e);
            printf("%s",p.p_age);
            gotoxy(63,e);
            printf("%s",p.p_symptom);
            gotoxy(83,e);
            printf("%s",p.doctor_id);
            e++;
            }
        }
        printf("\n");
        for(i=0; i<95; i++)
            printf("-");
    }
    printf("\n\n\t Press any key for main menu........");
    fclose(sfile);
    getch();
    doctor_menu();

}

void view_doctor()
{
    int i,e;
    FILE*sfile;
    system("cls");
    sfile=fopen("DoctorRecord.txt","r");
    printf("\n\t\t\t*********************************************************");
    printf("\n\t\t\t**************** VIEW ALL DOCTOR RECORDS *****************");
    printf("\n\t\t\t*********************************************************");
    if(sfile==NULL)
    {
        printf("\n\n\t\t RECORD EMPTY");
        getch();
    }
    else
    {
        gotoxy(1,6);
        printf("Doctor Id NO.");
        gotoxy(13,6);
        printf("Doctor Name");
        gotoxy(30,6);
        printf("Phone");
        gotoxy(45,6);
        printf("Password\n");
        for(i=0; i<95; i++)
        {
            printf("-");
        }
        e=8;
        while((fscanf(sfile,"%s  %s  %s  %s\n\n",&d.doctors_id,d.d_name,d.d_phone,d.d_pass)) != EOF)
        {
            gotoxy(1,e);
            printf("%s",d.doctors_id);
            gotoxy(13,e);
            printf("%s",d.d_name);
            gotoxy(30,e);
            printf("%s",d.d_phone);
            gotoxy(45,e);
            printf("%s",d.d_pass);
            e++;
        }
        printf("\n");
        for(i=0; i<95; i++)
            printf("-");
    }
    printf("\n\n\t Press any key for main menu........");
    fclose(sfile);
    getch();
    mainmenu();

}

int doctorlogin(char* user_name,char* password)
{
    FILE*sfile;
    sfile=fopen("DoctorRecord.txt","r");

    if(sfile==NULL)
    {
        printf("\n\n\t\t User not found!");
        getch();
    }
    else
    {
        while((fscanf(sfile,"%s  %s  %s  %s\n\n",&d.doctors_id,d.d_name,d.d_phone,d.d_pass)) != EOF)
        {

            if((strcmp(tolower(user_name),tolower(d.d_name)) == 0 || strcmp(user_name,d.d_phone) == 0) && strcmp(tolower(password),tolower(d.d_pass)) == 0){
                strcpy(doctor_user_id,d.doctors_id);
                strcpy(doctor_name,d.d_name);
                //doctor_user_id = d.doctors_id;
               // printf(doctor_user_id);
                return 1;
        }
        }
    }
}

void prescription(){
    int patientid,status=0,medicine,count=1;
    system("cls");
    gotoxy(16,2);
    printf("HEALTHCARE CONSULTATION CENTER MANAGEMENT SYSTEM");
    gotoxy(16,3);
    printf("Dr. %s",doctor_name);
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(16,5);
    printf("PRESCRIPTION");
    printf("\n------------------------------------------------------------------------------------------------");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char date[10],file_name[20];
    gotoxy(16,7);
    printf("Date: %02d-%02d-%d \n", tm.tm_mday ,tm.tm_mon + 1, tm.tm_year + 1900);
    gotoxy(16,8);
    do{
    FILE*sfile;
    sfile=fopen("PatientRecord.txt","r");
    printf("\n\t\tEnter Patient ID: ");
    scanf("%i",&patientid);
    printf("\n\t\tEnter Again: ");
    scanf("%s",&file_name);

    if(sfile==NULL)
    {
        printf("\n\n\t\t Empty Record!");
        getch();
    }else{
        while((fscanf(sfile,"%i  %s  %s  %s  %s  %s",&p.patient_id, p.p_name, p.p_phone,p.p_age,p.p_symptom,p.doctor_id)) != EOF)
        {
            if(p.patient_id == patientid && strcmp(doctor_user_id,p.doctor_id) == 0){
                printf("\n\t\tPatient Name: %s",p.p_name);
                printf("\n\t\tPatient Age: %s",p.p_age);
                printf("\n\t\tSymptom: %s",p.p_symptom);
                status=1;
                break;
            }
        }
        if(status!=1)
            printf("\t\tPatient not found!");
    }
    }while(status!=1);
    printf("\n\t\tEnter Medicine Quantity: ");
    scanf("%i",&medicine);
    while(medicine>=count){
        printf("\n\t\tEnter Medicine Name: ");
        fflush(stdin);
        gets(m[count].medicine_name);
        //scanf("%s",&);
        printf("\n\t\tEnter Note: ");
        fflush(stdin);
        gets(m[count].note);
        //scanf("%s",&m[count].note);
        count++;
    }
    count = 1;
    FILE*pfile;
    strcat(file_name,".txt");
    pfile = fopen(file_name,"a");
    fprintf(pfile,"\t\tDate: %02d-%02d-%d \n\t\tPatient Name: %s\n\t\tPatient Age: %s\n\t\tSymptom: %s\n\n\t\tMedicine:", tm.tm_mday ,tm.tm_mon + 1, tm.tm_year + 1900,p.p_name,p.p_age,p.p_symptom);
    while(medicine>=count){
        fprintf(pfile,"\n\t\t%i.Medicine Name: %s",count,m[count].medicine_name);
        fprintf(pfile,"\n\t\tNote: %s",m[count].note);
        count++;
    }
    fclose(pfile);
    printf("\n\n\tSuccess");
    printf("\n\n\tPress any key for main menu........");
    getch();
    doctor_menu();
}

void prescription_view(){
    FILE*sfile;
    int patientid,status=0,medicine,count=1;
    char file_name[20], text[1000];
    system("cls");
    gotoxy(16,2);
    printf("HEALTHCARE CONSULTATION CENTER MANAGEMENT SYSTEM");
    gotoxy(16,3);
    printf("Dr. %s",doctor_name);
    printf("\n------------------------------------------------------------------------------------------------");
    gotoxy(16,5);
    printf("PRESCRIPTION");
    printf("\n------------------------------------------------------------------------------------------------");

    do{

    printf("\n\t\tEnter Patient ID: ");
    scanf("%s",&file_name);
    strcat(file_name,".txt");
    sfile=fopen(file_name,"r");
    printf("\n");
    if(sfile==NULL)
    {
        printf("\n\n\t\t Not Found!");
        getch();
    }else{status=1;
        while((fgets(text,sizeof(text),sfile)))
        {
                printf("%s",text);
            }
        }
    }
    while(status!=1);
    fclose(sfile);
    printf("\n\n\t Press any key for main menu........");
    getch();
    doctor_menu();
}
