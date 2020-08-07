#include "stdio.h"

//prototype of grepcopy function
void grepcopy(FILE *,const char *,const char *);

//argc is the number of arguements in the commandline
//argv is the strings that are passed as arguements
int main(int argc, char *argv[])
{
	//pointer to point in the file
	FILE *p;

	//i to count the number of arguements
	int i;

	//i=2 because first arguement is name of program
	//and second arguement is string to be searched
	//files begin from 3rd arguments
	for(i=2;i<argc;i++)
	{
		//file opens and p points to first character
		p=fopen(argv[i],"r");
		//p, string to be searched and file name goes into
		//grepcopy function
		grepcopy(p,argv[1],argv[i]);
		fclose(p);
	}
	return 0;
}

//grepcopy function
//receives file, string to be searched and file name
//in the function arguements
void grepcopy(FILE *p,const char *b,const char *f)
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
				printf("%s: %d: %s\n",f,(i-j),b);
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

