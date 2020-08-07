#include "stdio.h"

//prototype of grepcopy function
void grepcopy(FILE *,const char *);

//protype of read function
void read(FILE *);

int main()
{
	//pointer to point in the file
	FILE *p;
	//file opens and p points to first character
	p=fopen("letter.txt","r");

	//array to store the string to be searched
	char b[1000];
	//input of string
	printf("Enter string to search:");
	scanf("%[^\n]s",b);

	//function to read things in the file and print the content
	read(p);
	//file closes
	fclose(p);

	//file is opened again for search operation
	p=fopen("letter.txt","r");
	//grepcopy function is called
	grepcopy(p,b);
	//file closes
	fclose(p);
	return 0;
}

//grepcopy function
//the file pointer and the pointer of array is received as
//arguements.
void grepcopy(FILE *p,const char *b)
{
	//i is for main string
	//j is for the small string to be searched
	int i=1,j=0;
	//ch is there to use character pointed by p
	char ch;

	//getc(p) returns the character pointed by p
	//and shifts the pointer to next character
	ch=getc(p);

	//enter the loop where we compare
	//-1 means we have reached the end of file
	while(ch!=-1)
	{
		//if first characters match
		if(ch==b[j])
		{
			//pointers shift to next characters
			i++;j++;ch=getc(p);

			//comparing both the strings till the end of b
			while(b[j]!='\0')
			{
				//if other characters match
				if(ch==b[j])
				{
					ch=getc(p);
					i++;j++;
				}
				//if some character doesn't match
				else 
				{
					//comparision starts again with next characters
					//of the main string
					j=0;
					break;
				}
			}

			//if some string matches
			if(b[j]=='\0')
			{
				printf("%d:\t%s\n",(i-j),b);
				j=0;
			}
		}

		//if any character doesn't match
		else
		{	
			i++;
			//ch=getc(p) assigns the character to ch to be compared 
			//in loop and then p points to next character
			ch=getc(p);
		}

	}

}

//this function is just to read and print the
//contents of file
void read(FILE *p)
{
	char ch;
	while((ch=getc(p))!=-1)
		printf("%c",ch);
	
}
