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

#include <iostream>
#include <string>
int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << "String: " << s <<"length: "<<s.length()<< std::endl;
    return 0;
}
