#include<stdio.h>
int iskeyword(char a[]);
void main();
{
   int i;
   char ch,operator[]="+-*/%$^";
   char filename[15],temp[20];
   printf("Enter the filename present inside this directory\n");
   scanf("%s",filename);
   fp=fopen(filename,"r");
   if(fp==EOF)
   {
     printf("This file is not exist\n");
     exit(0);
   }
   while((ch=getchar(fp))!=EOF)
   {
      for(i=0;i<7;i++)
      {
        if(ch==operator[i])
        {
           printf("%c is an operator\n",operator[i]);
           break;
        }
      }
      if(isalnum(ch))
      {
        temp[i++]=ch;
      }
      else if((ch==' '||ch=='\n')&&i!=0)
        {
           temp[i]='\0';
           if(iskeyword(temp)==1)
           printf(" %s is an keyword \n");
           else
           printf("%s is an identifier\n",temp);
           for(j=0;j<i;j++)
           temp[j]="";
        }   
        i=0;
    }
}

int iskeyword(char a[])
{
   char keyword[]={"while","for","if","else","void","auto","break","continue","goto","volatile","switch","case","typedef","static",
                   "sizeof","return","do","enum","union","struct","default"};
   int i;
   for(i=0;i<21;i++)
   {
      if(strcmp(keyword,a)==0)
      return 1;
   }
   return 0;
}
      
      
      
     
