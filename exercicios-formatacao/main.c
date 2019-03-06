#include <stdio.h>
#include <stdlib.h>

int main()
{

    typedef struct PERSON {
        char* name;
        int age;
        float height;
    } PERSON;

    PERSON lucas = {"Lucas Konrath Damaceno", 22, 1.78};

    char stars[] =  "********";

    for(int i = 0; i < 5; i++){
        printf("HI! My name is %s. \n", lucas.name);
    }

    printf("Chikka chikka Slim Shady.\n");

    printf("Arr! I am %d years ole.\n", lucas.age);
    printf("I stand at a whopping %.2f meters.\n", lucas.height);

    for(int i = 0; i < 4; i++){
        printf("\n%s", stars);
    }

    printf("\n\n%s\n%s\n%s\n%s\n", stars, stars, stars, stars);

    return 0;
}
