#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Friends{
    char username[25];
    Friends *next;
}*start, *end;
struct Account{
    char username[25];
    char password[25];
    Friends *start;
    Account *next;
} *head, *tail, *curr;
struct Notes{
    char note[256];
    int privatecheck; // 1 = public , 0 = private
    Notes *next;
} *head1;
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
    temp->next = NULL;
    return temp;
}
Friends *createFriend(char *username){
    Friends *temp = (Friends*)malloc(sizeof(Friends));
    strcpy(temp->username , username);
    temp->next = NULL;
    return temp;
}
void pushAcc(char *username, char *password) {
  Account *temp = createAcc(username, password);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
  }
}
void pushFriends(char *username)
{
    Friends *temp = createFriend(username);
    if(!head) 
    { 
        start = end = temp;
    } else 
    { 
        end->next = temp; 
        end = temp; 
    }
}
int CheckUsername(char *username)
{
    while(head != NULL)
    {
        if(strcmp(username, head->username) == 0)
        {
            return 1; //barti ada yang sama
        }
        head = head->next;
    }
    return 0; // aman boleh dipake
}
int CheckLogin(char *username, char *password)
{
    while(head != NULL)
    {
        if(strcmp(username, head->username) == 0 && strcmp(password, head->password) == 0)
        {
            return 1; //barti ada yang sama
        }
        head = head->next;
    }
    return 0; // aman boleh dipake
}
void PrintUser()
{
    printf("[All User]\n");
    printf("No.     Username\n");
    int i = 1;
    while(head != NULL)
    {
        printf("%2d     %s\n", i++, head->username);
        head = head->next;
    }
}
void PrintFriends(char *username)
{
    while(head != NULL)
    {
        if(strcmp(username, head->username) == 0)
        {
            int i = 1;
            while(head->start != NULL)
            {
                printf("%3d. %s\n", i++, head->start->username);
                head->start->next;
            }
        }
        head = head->next;
    }
}
void deleteFriend(char *username) 
{ 
    if (start == NULL) 
    {
        return; 
    }
    struct Friends* temp = start, *prev; 
    while(temp != NULL && strcmp(temp->username, username) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp); 
} 

