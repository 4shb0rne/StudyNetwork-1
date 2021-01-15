#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #################################### INITIALIZE STRUCT ####################################
struct Friends{
    char username[25];
    Friends *next;
};
struct Requests{
    char username[25];
    Requests *next;
};
struct Sents{
    char username[25];
    Sents *next;
};
struct Account{
    char username[25];
    char password[25];
    Friends *friendHead;
    Requests *reqHead;
    Sents *sentHead;
    Account *next;
} *head, *tail, *curr;
struct Notes{
    char note[256];
    int privatecheck; // 1 = public , 0 = private
    Notes *next;
} *head1;

// #################################### CREATE NODES ####################################
Notes *createNote(char *note)
{
    Notes *temp = (Notes*)malloc(sizeof(Notes));
    strcpy(temp->note, note);
    temp->next = NULL;
    return temp;
}
Account *createAcc(char *username, char *password){
    Account *temp = (Account*)malloc(sizeof(Account));
    strcpy(temp->username , username);
    strcpy(temp->password , password);
    temp->reqHead = NULL;
    temp->sentHead = NULL;
    temp->next = NULL;
    return temp;
}
Friends *createFriend(char *username){
    Friends *temp = (Friends*)malloc(sizeof(Friends));
    strcpy(temp->username , username);
    temp->next = NULL;
    return temp;
}
Requests *createRequest(char *username){
    Requests *temp = (Requests*)malloc(sizeof(Requests));
    strcpy(temp->username , username);
    temp->next = NULL;
    return temp;
}
Sents *createSent(char *username){
    Sents *temp = (Sents*)malloc(sizeof(Sents));
    strcpy(temp->username , username);
    temp->next = NULL;
    return temp;
}
// #################################### PRINT ALL'S ####################################

void PrintUser()
{
    Account *curr = head;

    printf("[All User]\n");
    printf("No.     Username\n");
    int i = 1;
    while(curr != NULL)
    {
        printf("%2d     %s\n", i++, curr->username);
        curr = curr->next;
    }
}
void PrintFriends(char *username)
{
    while(head != NULL)
    {
        if(strcmp(username, head->username) == 0)
        {
            int i = 1;
            while(head->friendHead != NULL)
            {
                printf("%3d. %s\n", i++, head->friendHead->username);
                head->friendHead->next;
            }
        }
        head = head->next;
    }
}
void PrintRequest(char *username){
    Account *curr = head;

    puts("[Friend Requests]");
    puts("No.     Username");

    while(curr)
    {
        if(strcmp(username, curr->username) == 0){
        Requests *curr2 = curr->reqHead;
            int i=1;
            while(curr2){
                printf("%2d     %s\n", i++, curr2->username);
                curr2 = curr2->next;
            }
            return;
        }
        curr = curr->next;
    }
}
void PrintSent(char *username){
    Account *curr = head;

    puts("[Friend Requests sent by you]");
    puts("No.     Username");

    while(curr)
    {
        if(strcmp(username, curr->username) == 0){
        Sents *curr2 = curr->sentHead;
            int i=1;
            while(curr2){
                printf("%2d     %s\n", i++, curr2->username);
                curr2 = curr2->next;
            }
            return;
        }
        curr = curr->next;
    }
}

// #################################### REGISTER & LOGIN ####################################

int CheckUsername(char *username)
{
    Account *curr = head;

    while(curr != NULL)
    {
        if(strcmp(username, curr->username) == 0)
        {
            return 1; //barti ada yang sama
        }
        curr = curr->next;
    }
    return 0; // aman boleh dipake
}
int CheckLogin(char *username, char *password)
{
    Account *curr = head;

    while(curr != NULL)
    {
        if(strcmp(username, curr->username) == 0 && strcmp(password, curr->password) == 0)
        {
            return 1; //barti ada yang sama
        }
        curr = curr->next;
    }
    return 0; // aman boleh dipake
}
void pushAcc(char *username, char *password) {
  Account *temp = createAcc(username, password);
  if(!head) 
  { 
    head = tail = temp;
  }
  else 
  {
    tail->next = temp;
    tail = temp; 
  }
}

// #################################### ADD FRIEND REQUESTS ####################################

int CheckRequest(char *sender, char *receiver){
    Account *curr = head;

    while(curr){
        if(strcmp(receiver, curr->username) == 0){
            Requests *curr2 = curr->reqHead;
            while(curr2){
                if(strcmp(sender, curr2->username) == 0){
                    return 1;
                }
                curr2 = curr2->next;
            }
        }
        curr = curr->next;
    }

    return 0;
}

void pushRequest(char *sender, char *receiver){
    
    Account *curr = head;

    while(curr){
        if(strcmp(receiver, curr->username) == 0){
            Requests *temp = createRequest(sender);

            if(!curr->reqHead) {  // ini push head
                curr->reqHead = temp;
            } else { 
                temp->next = curr->reqHead;
                curr->reqHead = temp;
            }
        }

        if(strcmp(sender, curr->username) == 0){
            Sents *temp2 = createSent(receiver);

            if(!curr->sentHead) {  // ini push head
                curr->sentHead = temp2;
            } else { 
                temp2->next = curr->sentHead;
                curr->sentHead = temp2;
            }
        }
        curr = curr->next;
    }
}


// #################################### FRIENDS ####################################

void pushFriends(char *sender, char *receiver)
{
    Account *curr = head;

    while(curr){
        if(strcmp(receiver, curr->username) == 0){
            Friends *curr2 = curr->friendHead;
            Friends *temp = createFriend(sender);

            if(!head) { 
                curr2 = temp;
            } else { 
                temp->next = curr2;
                curr2 = temp;
            }
        }
        curr = curr->next;
    }
}

// void deleteFriend(char *username) 
// { 
//     if (friendHead == NULL) 
//     {
//         return; 
//     }
//     struct Friends* temp = friendHead, *prev; 
//     while(temp != NULL && strcmp(temp->username, username) != 0)
//     {
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = temp->next;
//     free(temp); 
// }

