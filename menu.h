#include "utils.h"

char loggedIn[25];
char loggedInTime[50];

void mainMenu();
void loginMenu();
void regis();
void login();
void logout();

void printLine(){
    puts("----------------------------");
}

void header(){ // print heading
    puts("=============================================");
    puts("                STUDY NETWORK                ");
    puts("=============================================");
    puts("");
}

void welcome(const char *name){
    puts("=============================================");
    printf("Welcome, %s\n",name);
    puts("=============================================");
    printf("Logged in: %s",loggedInTime);
    printLine();
}

void mainMenu(){

    int menu = -1;
    
    do{
        system("cls");
        header();
        PrintUser();

        puts("");
        printLine();

        puts("[1] Register");
        puts("[2] Login");
        puts("[3] Exit");
        printLine();
        puts("Press 0 and enter to abort an operation");
        printLine();
        printf(">> ");
        scanf("%d",&menu);
    }while(menu < 0 || menu > 3);

    switch(menu){
        case 1: regis(); break;
        case 2: login(); break;
        case 3: return; break;
        case 0: return; break;
        default: break;
    }
}

void loginMenu(){

    puts("=============================================");
    printf("    Welcome, %s\n",loggedIn);
    puts("=============================================");
    puts("");

    int menu = -1;
    
    do{
        system("cls");
        welcome(loggedIn); //tampilkan login header

        printLine();
        puts("         >> Menu <<         ");
        printLine();

        puts("[1] Add Friend");
        puts("[2] Remove Friend");
        puts("[3] View Inbox");
        puts("[4] View Sent Request");
        puts("[5] Add, Edit, Announce, Delete Note");
        puts("[6] Logout");
        printLine();
        puts("Press 0 and enter to abort an operation");
        printLine();
        printf(">> ");
        scanf("%d",&menu);
    }while(menu < 0 || menu > 6);

    switch(menu){
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: logout(); break;
        case 0: loginMenu(); break;
        default: break;
    }
}

void regis(){
    char username[40], password[40];

    do{
        printf("Please type in your username [lowercase || 1..24]: ");
        scanf("%s",username); getchar();
        printf("Please type in your password [lowercase || 1..24]: ");
        scanf("%s",password); getchar();

        if(CheckUsername(username)){ // if username exists
            int temp = 0;
            puts("Username already used");
            printf("Try again [ 1 = yes / 0 = no] ? ");
            scanf("%d",&temp); getchar();
            if(temp != 1){
                mainMenu();
            }
        }
    }while(CheckUsername(username));

    pushAcc(username,password);

    puts("");
    puts("--- Registration Successful ---");
    printf("Press enter to continue");
    getchar();
    mainMenu();
    return;
}

void login(){
    char username[40], password[40];

    do{
        printf("Please type in your username [lowercase || 1..24]: ");
        scanf("%s",username); getchar();
        printf("Please type in your password [lowercase || 1..24]: ");
        scanf("%s",password); getchar();

        //VALIDATE USERNAME PASSWORD

        if(!CheckLogin(username,password)){
            int temp;
            puts("Invalid username or password");
            printf("Try again [ 1 = yes / 0 = no] ? ");
            scanf("%d",&temp); getchar();
            if(temp != 1){
                strcpy(loggedIn, username);
                mainMenu();
            }
        }
    }while(!CheckLogin(username,password));

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(loggedInTime,asctime (timeinfo));

    loginMenu();
    return;
}

void logout(){
    strcpy(loggedIn,"");
    strcpy(loggedInTime,"");

    mainMenu();
}

