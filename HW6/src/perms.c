#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include "../include/perms.h"


int main()
{
    char str[15];

    fprintf(stdout, "Enter the file permission: ");
    fgets(str, 10, stdin);
    printf("%ld\n" , strlen(str));
    if (strlen(str) == 9)
        fprintf(stdout, "This is the permission for chmod: %s\n", permissionString(str));
    else
        fprintf(stdout, "%s is not a valid permission. Permissions should be 9 characters long.\n", str);

    return 0;
}

char* permissionString(char * perms)
{
    char* permission;
    int len = strlen(perms);
    char userPerm, groupPerm, otherPerm;
    char *u, *g, *o;

    permission= (char*)malloc(len*sizeof(char));
    u= (char*)malloc(3*sizeof(char));
    strncpy(u, perms, 3);

    g= (char*)malloc(3*sizeof(char));
    strncpy(g, perms+3, 3);

    o= (char*)malloc(3*sizeof(char));
    strncpy(o, perms+6, 3);
    
    userPerm = onePermission(u);
    groupPerm = onePermission(g);
    otherPerm = onePermission(o);

    permission[0] = userPerm;
    permission[1] = groupPerm;
    permission[2] = otherPerm;

    return permission;
}

char onePermission(char *perms)
{
    char onePerm;

    if (strcmp(perms , "rwx") == 0)
        onePerm = '7';
    else if (strcmp(perms , "rw-") == 0)
        onePerm = '6';
    else if (strcmp(perms , "r-x") == 0)
        onePerm = '5';
    else if (strcmp(perms , "r--") == 0)
        onePerm = '4';
    else if (strcmp(perms , "-wx") == 0)
        onePerm = '3';
    else if (strcmp(perms , "-w-") == 0)
        onePerm = '2';
    else if (strcmp(perms , "--x") == 0)
        onePerm = '1';
    else if (strcmp(perms , "---") == 0)
        onePerm = '0';
    else
        onePerm = *perms;

    return onePerm;
}

