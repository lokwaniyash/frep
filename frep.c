#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftAF(char * string,int num){
	int i=strlen(string);
	for(i;i>=num-1;i--){
		string[i+1]=string[i];
	}
}
void shiftAB(char * string, int num){
	int i,len=strlen(string);

	for(i=num-1;i<len;i++){
		string[i]=string[i+1];
	}

}
void fAndR(char * string, char * find, char * repl){
	int i,j=0,k=0,flag=0,len,len1,len2,x,y;
	len=strlen(string);
	len1=strlen(find);
	len2=strlen(repl);

	for(i=0;i<=len;i++){

		if(string[i]==find[j]){
			j++;
		}
		else
			j=0;
		if(j==len1){
			k=i;
			flag++;
			if(len2>len1){
				for(x=0;x<len2-len1;x++){
					shiftAF(string,(i+x));
					k++;
				}
			} else if(len1>len2){
				for(x=0;x<len1-len2;x++){
					shiftAB(string,(i-x));
					k--;
				}
			}
			for(x=i-len1+1,y=0;y<len2;x++,y++){
				string[x]=repl[y];
			}
			j=0;
			i=k;
		}
		len=strlen(string);
	}

}
void main(){
	char string[500],find[500],repl[500],len;

	puts("Enter the string: ");
	gets(string);
	puts("Enter what you want to replace: ");
	gets(find);
	puts("Enter what you want to replace with: ");
	gets(repl);
	fAndR(string,find,repl);

	printf("%s\n",string);
	getch();
}
