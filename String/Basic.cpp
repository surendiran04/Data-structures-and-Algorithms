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
    printf("Length is %d",i); //includes the '\0' 
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
