#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TABLE_SIZE 10

struct node{
    char name[20];
    int ID;
    int day,month,year;
    int score;
    struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;

int hash_function(char str[],int CAPACITY) {
    int i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

void insert(char myname[],int myID,int myDay,int myMonth,int myYear,int myScore){
    int i;
    i= hash_function(myname ,TABLE_SIZE);
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    strcpy(newNode->name,myname);
    newNode->ID = myID;
    newNode->day = myDay;
    newNode->month = myMonth;
    newNode->year = myYear;
    newNode->score = myScore;

    newNode->next = NULL;
    if(head[i] == NULL)
        head[i] = newNode;
    else
    {
        c=head[i];
        while(c->next != NULL)
        {
           c=c->next;
        }
        c->next=newNode;
    }
}
void search(int myKey){
    int key,index;
    key=myKey;
    index=key%TABLE_SIZE;
    if(head[index] == NULL)
        printf("\n Search element not found the slot is empty\n");
    else
        printf("search element found\n");
}
void print(){
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nentries at index: %d\n",i);
               if(head[i] == NULL)
               {
               printf("No Hash Entry");

               }
               else
               {
                              for(c=head[i];c!=NULL;c=c->next)
                              {
                                     printf("name: %s\n",c->name);
                                     printf("ID: %d \n",c->ID);
                                     printf("Date of birth: %d/%d/%d \n",c->day,c->month,c->year);
                                     printf("Score: %d \n",c->score);
                                     printf("********************************\n");
                              }
               }
          }

}
void deletee(int value)
{
    int key = value % TABLE_SIZE;
    if(head[key] == NULL)
        printf("element is not there to delete\n");
    else
        head[key]= NULL;
        printf("element deleted\n");
}
int main(){

    //test insertion:
    /*insert("mohamed",1,15,6,2000,90);     //mohamed:731
    insert("ahmed",2,15,6,2000,90);         //ahmed:511
    insert("abdallah",9,15,6,2000,90);      //abdallah:809
    print();*/

    //test search:
    /*insert("mohamed",1,15,6,2000,90);       //mohamed:731       731%10=1
    insert("ahmed",2,15,6,2000,90);           //ahmed:511         511%10=1
    insert("abdallah",9,15,6,2000,90);        //abdallah:809      809%10=9
    search(1);
    search(3);
    search(2);
    search(9);*/

    //test delete:
    insert("mohamed",1,15,6,2000,90);       //mohamed:731
    insert("ahmed",2,15,6,2000,90);           //ahmed:511
    insert("abdallah",9,15,6,2000,90);        //abdallah:809
    deletee(1);
    print();

    return 0;
}
