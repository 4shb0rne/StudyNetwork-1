#include "utils.h"

void mainMenu();
void loginMenu();
void regis();
void login();

void header(){ // print heading
    puts("=============================================");
    puts("                STUDY NETWORK                ");
    puts("=============================================");
    puts("");
}

void printLine(){
    puts("-----------------------");
}

void allUser(){ // print all users
    puts("[All User]");
    puts("No.     Username");
    printLine();
}

void mainMenu(){

    int menu = -1;
    
    do{
        system("cls");
        header();
        allUser();

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

void regis(){
    char username[40], password[40];

    do{
        printf("Please type in your username [lowercase || 1..24]: ");
        scanf("%s",username); getchar();
        printf("Please type in your password [lowercase || 1..24]: ");
        scanf("%s",password); getchar();

        if(!CheckUsername(username)){
            int temp;
            puts("Username already used");
            printf("Try again [ 1 = yes / 0 = no] ? ");
            scanf("%d",&temp); getchar();
            if(temp != 1){
                mainMenu();
            }
        }
    }while(!CheckUsername(username));

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

        if(!CheckPassword(username,password)){
            int temp;
            puts("Invalid username or password");
            printf("Try again [ 1 = yes / 0 = no] ? ");
            scanf("%d",&temp); getchar();
            if(temp != 1){
                mainMenu();
            }
        }
    }while(!CheckPassword(username,password));

    loginMenu();
}

