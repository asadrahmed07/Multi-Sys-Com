#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct system
{
    int userChoice;
    int portNumber;
    char sysName[10];
};

struct system s;  //structure variable 



void insert()
{
   FILE *ptr;
   ptr = fopen( "eui2prc.txt","w");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file\n");
      return;
   }
   printf("\n Enter your choice : ");
   scanf("%d",&s.userChoice);
   fflush(stdin);
   fwrite(&s, sizeof(int*) , 1 , ptr);
   printf("\n");
   printf("\n");
   fclose(ptr);
 }


 void displayDatabase()
{
FILE *ptr;
   ptr = fopen( "dbfile.txt","r");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   printf("--------------------------------------\n");
   printf("The DataBase stored up until now is \n");
   while(fread(&s,sizeof(s),1,ptr)==1)
   {  
      printf("%d\t%s\n",s.portNumber,s.sysName);
   }

 fclose(ptr);
}


void Read()
{
   FILE *ptr;
   ptr = fopen( "prc2eui.txt","r");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   while(fread(&s,sizeof(s),1,ptr)==1)
   {  printf("The Last Entered entry was :\n");
      printf("%d\t%s\n",s.portNumber,s.sysName);
   }

 fclose(ptr);

}


int main()
{ int ch;
   do{
   printf("\n1. Search Port Number.");
   printf("\n2. Search System Name.");
   printf("\n3. Insert record.");
   printf("\n4. Modify record.");
   printf("\n5. Delete record.");
   printf("\n6. Display DATABASE record.");
 
   insert();
   printf("Now Enter the process in PRC then choice for \n");
   printf("For displaying DataBase just press 1\n");
   printf("Do you want to continue? 1=Y/0=N:\n ");
   scanf("%d",&ch);
   if(s.userChoice == 6)
   {
      displayDatabase();
   }
   else if(ch!=0)
   {
      Read();
   }
  }while(ch!=0);

}