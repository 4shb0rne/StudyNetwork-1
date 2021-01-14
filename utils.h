#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Friends{
    char username[25];
    Friends *next;
}*start;
struct Account{
    char username[25];
    char password[25];
    Friends *start;
    Account *next;
} *head, *tail, *curr;
Account *createNode(char *username, char *password){
    Account *temp = (Account*)malloc(sizeof(Account));
    strcpy(temp->username , username);
    strcpy(temp->password , password);
    temp->next = NULL;
    return temp;
}
Friends *createNode(char *username){
    Friends *temp = (Friends*)malloc(sizeof(Friends));
    strcpy(temp->username , username);
    temp->next = NULL;
    return temp;
}
void pushTail(char *username, char *password) {
  Account *temp = createNode(username, password);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
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
int CheckPassword(char *password)
{
    while(head != NULL)
    {
        if(strcmp(password, head->password) == 0)
        {
            return 1; //barti ada yang sama
        }
        head = head->next;
    }
    return 0; // aman boleh dipake
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
