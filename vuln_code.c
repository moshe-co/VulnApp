#include <stdio.h>
#include <string.h>

/**
 * What is wrong in this code?
 * when the user passing the password the code uses strcmp which allow to create a simple buffer overflow.
 * passing the input of 17 characters when the last one is '1' will set localinfo.access to 1 which will allow
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

    printf("What is the password? ");
    scanf("%s", localinfo.pass);

    int ret = strcmp(localinfo.pass, "SupoerDuperSecretPassword");
    if (ret)
        printf("Wrong password\n");
    else
        localinfo.access = 1;

    if (localinfo.access)
        printf("You are root\n");

    return 0;
}