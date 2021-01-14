#include "utils.h"

void mainMenu();
void regis();
void login();

int main(){
    mainMenu();
    
    return 0;
}

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
    puts("ini regis");
    return;
}
void login(){
    puts("ini login");
    return;
}

