#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
int main() {
    char s[MAX_LEN];
    fgets(s, sizeof(s), stdin);  //we can also use gets(s); but it can lead to buffer overflow
    printf("String: %s\n", s);
    int i;
    for(i=0;s[i]!='\0';i++){
        
    }
    printf("Length is %d\n",i); //includes the '\0'  
    for(i=0;s[i]!='\0';i++){ //changing to lowercase if the input is Uppercase eg: A-65  65+32=97 (a-97)
        if(s[i]>=65 && s[i]<=90){  //changing to lowercase
            s[i]+=32;
        }
        else if(s[i]>=97 && s[i]<=122){ //changing to uppercase
            s[i]-=32;
        }    
    }
    printf("String: %s\n", s);
    char sentence[100]; 
    char source[] = "This is another sentence.";
    strcpy(sentence, source);  //included in #include <string.h>
    return 0;
}

int number_of_words(char *var)  //fn to count the no of words in a sentence
{
	int i = 0;
	int numberOfWords = 0;
	while(var[i] != '\0')
	{
		if ( ((var[i] != ' ') && (var[i+1] == ' ')) || ((var[i] != ' ') && (var[i+1] == '\0')) )
		{
			numberOfWords++;
		}
		i++;
	}
	return numberOfWords;
}

#include <iostream>
#include <string>
int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << "String: " << s <<"length: "<<s.length()<< std::endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
char change_case(char c) {
    if (isupper(c))
        return tolower(c);
    else
        return toupper(c);
}
int main() {
    string str = "hEllo world";
    transform(str.begin(), str.end(), str.begin(), change_case);
    cout << str << endl;
    transform(str.begin(), str.end(), str.begin(), toupper);  //full string to uppercase and vice-verse for lowercase
    cout << str << endl;
    return 0;
}
