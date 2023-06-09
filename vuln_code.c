#include <stdio.h>
#include <string.h>

/**
 * What is wrong in this code?
 * when the user passing the password the code uses strcmp which allow to create a simple buffer overflow.
 * passing the input of 26 characters when the last one is '1' will set localinfo.access to 1 which will allow
 * for root access regardless the password is correct or not.
*/
int main()
{
    typedef struct {
        char pass[25];
        char access;
    } local_info_t;

    local_info_t localinfo;
    localinfo.access = 0;
    char user_input[64] = {0};

    printf("What is the password? ");
    scanf("%s", user_input);
    strcpy(localinfo.pass, user_input);
    if (strcmp(localinfo.pass, "Sup3rDuper$ecretP4ssw0rd"))
        printf("Wrong password\n");
    else
        localinfo.access = 1;

    if (localinfo.access)
        printf("You are root\n");

    return 0;
}