#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct system
{
   int choice ;
   int portNumber;
   char sysName[10];
};

struct system s;  //structure variable 
void Read()
 {  FILE *ptr;

   ptr = fopen( "eui2prc.txt","r");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file\n");
      return;
   }
   else
   { 
    fread(&s,sizeof(int),1 , ptr);
    printf("%d\n",s.choice);
   }

 fclose(ptr);

}


void Display()
 {  FILE *ptr;
   ptr = fopen( "dbfile.txt","r");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   while(fread(&s,sizeof(s),1,ptr)==1)
   {
      printf("%d\t%s\n",s.portNumber,s.sysName);
   }

 fclose(ptr);

 
   ptr = fopen( "prc2eui.txt","w");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file\n");
      return;
   }
   else
   {
   fwrite(&s,sizeof(s),1,ptr);

   printf("Value Entered\n");
    }  
   fclose(ptr);
  
}

void searchPortno()
{
   int port , flag=0;
   FILE *ptr;
   ptr = fopen("dbfile.txt","r");
   if(ptr == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   printf(" Enter the port number you want to search:  ");
   scanf("%d",&port);
   while(fread(&s,sizeof(s),1,ptr)>0 && flag==0);
   {
      if(s.portNumber == port)
      {
         flag=1;
         printf("Search Successful\n");
         printf("%d\t%s\n",s.portNumber,s.sysName);
      }
   }
   if(flag == 0)
      {
         printf(" No Such Port Number found\n");
      }

      fclose(ptr);

}

void searchSystemName()
{
   char sname[10];
   int flag=0;
   FILE *ptr;
   ptr = fopen("dbfile.txt","r");
   if(ptr == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   Display();
   printf(" Enter the system name you want to search:  ");
   scanf("%s",sname);
   while(fread(&s,sizeof(s),1,ptr)==1)
   {
      if(strcmp(s.sysName,sname)==0)
      { 
       flag =1;
       printf("search Successful \n");
       printf("%d\t%s\n",s.portNumber,s.sysName);
       
       }
   if(flag == 0)
      {
       printf(" No Such System Name found\n");
      }

      fclose(ptr);

   }
}

void insert()
{
   FILE *ptr;
   ptr = fopen( "dbfile.txt","a+");

   if(ptr == NULL)
   {
      printf("\n Error cannot open the file\n");
      return;
   }
   printf("\n Enter the Port Number: ");
   scanf("%d",&s.portNumber);
   fflush(stdin);
   printf("\n Enter the System Name: ");
   scanf("%s",s.sysName);

   fwrite(&s,sizeof(s),1,ptr);

   printf("Value Entered\n");
   fclose(ptr);
   Display();

 }

 void modify()
{
   int port , flag=0;
   FILE *ptr,*ptr2 ;
   ptr = fopen("dbfile.txt","r");
   if(ptr  == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   printf(" Enter the port number you want to update:  ");
   scanf("%d",&port);
   while(fread(&s,sizeof(s),1,ptr)>0 && flag==0);
   {
      if(s.portNumber == port)
      {
         flag=1;
         printf("Search Successful\n");
         printf("%d\t%s\n",s.portNumber,s.sysName);
         printf("Enter new record\n");
         printf("update port number\n");
         scanf("%d",&s.portNumber);
         printf("\nupdate new sysName\n");
         scanf("%s\n", s.sysName);

         fseek(ptr,-(long)sizeof(s),1);
         ptr2 = fopen("prc2eui.txt","w");
         fwrite(&s,sizeof(s),1,ptr2);
         printf("values are updated\n");

      }fread(&s,sizeof(int),1 , ptr);
    printf("%d\n",s.choice);
   }
   if(flag == 0)
      {
         printf(" No Such Port Number found\n");
      }

      fclose(ptr);
}


void delete()
{
   char sname[10];
   unsigned flag=0;
   FILE *ptr1,*ptr2;
   ptr1 = fopen("dbfile.txt","rb");

   if(ptr1  == NULL)
   {
      printf("\n Error cannot open the file");
      return;
   }
   Display();
   printf(" Enter the system name you want to search:  ");
   scanf("%s",sname);
   ptr2 = fopen("dbfile1.txt","ab+");

   while(fread(&s,sizeof(s),1,ptr1)==1)
   {
      if(strcmp(s.sysName,sname)!=0)
      {
       printf("Record Deleted \n");
       fwrite(&s,sizeof(s),1,ptr2);
      }
    else
      flag=1;
   }

   if(flag == 0)
      {
         printf(" No Such record found\n");
      }
      fclose(ptr1);
      fclose(ptr2);
      remove("dbfile.txt");
      rename("dbfile1.txt","dbfile.txt");
      printf("record updated");
      Display();
} 


void main()
{  
   int ch ;
   while(1)
 { 

   Read();
   switch (s.choice)
   {
      case 1:
      searchPortno();
      break; 
      case 2:
      searchSystemName();
      break;
      case 3:
      insert();
      break;          
      case 4:
      modify();
      break;
      case 5:
      delete();
      break;
      default:
     {
      printf("Entered choice is wrong:\n");
      break;
     }

   }
  printf( " Now first Enter the Choice in EUI then");
  printf(" \n enter choice for  continue? Yes = 1 / No = 0:\n");
  scanf("%d",&ch);
  if(ch==0)
  {
   return;
  }

  
 }


}