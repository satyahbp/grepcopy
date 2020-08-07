#include "stdio.h"

//prototype of grepcopy function
void grepcopy(const char *,const char *);

int main()
{
	//declarations
	char a[100],b[100];

	//input of strings
	printf("Enter the main string:");
	scanf("%[^\n]s",a);
	printf("Enter string to search:");
	scanf(" %[^\n]s",b);

	//execution of grepcopy function
	grepcopy(a,b);
	
	return 0;
}

//grepcopy function
void grepcopy(const char *a,const char *b)
{
	//i is for main string
	//j is for the small string to be searched
	int i=0,j=0;

	//enter the loop where we compare
	while(a[i]!='\0')
	{
		//if first characters match
		if(a[i]==b[j])
		{
			//pointers shift to next characters
			i++;j++;

			//comparing both the strings till the end of b
			while(b[j]!='\0')
			{
				//if other characters match
				if(a[i]==b[j])
				{
					i++;j++;
				}
				//if some character doesn't match
				else 
				{
					//comparision starts again with next characters
					//of the main string
					j==0;
					break;
				}
			}

			//if some string matches
			if(b[j]=='\0')
			{
				printf("%d:\t%s\n",(i-j)+1,b);
				j=0;
			}
		}

		//if any character doesn't match
		else
			i++;
	}

}
