#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include "../include/perms.h"


int main()
{
    char str[15];

    fprintf(stdout, "Enter the file permission: ");
    fgets(str, 10, stdin);
    printf("%d\n" , strlen(str));
    if (strlen(str) == 9)
        fprintf(stdout, "This is the permission for chmod: %s", permissionString(str));
    else
        fprintf(stdout, "%s is not a valid permission. Permissions should be 9 characters long.", str);

    return 0;
}

char* permissionString(char * perms)
{
    char* permission;
    printf("%s\n", perms);
    char userPerm, groupPerm, otherPerm;
    char u[3];
    strncpy(u, perms, 3);
    printf("%s\n", u);
    char g[3];
    strncpy(g, perms+3, 3);
    printf("%s\n", g);
    char o[3];
    strncpy(o, perms+6, 3);

    printf("%s\n", o);
    
    userPerm = onePermission(u);
    groupPerm = onePermission(g);
    otherPerm = onePermission(o);
    printf("%c%c%c\n", userPerm, groupPerm, otherPerm);

    permission[0] = userPerm;
    permission[1] = groupPerm;
    permission[2] = otherPerm;
    //permission = userPerm + groupPerm + otherPerm;
    printf("%s\n", permission);
    return permission;
}

char onePermission(char perms[])
{
    char onePerm;

    if (strcmp(perms , "rwx"))
        onePerm = '7';
    else if (strcmp(perms , "rw-"))
        onePerm = '6';
    else if (strcmp(perms , "r-x"))
        onePerm = '5';
    else if (strcmp(perms , "r--"))
        onePerm = '4';
    else if (strcmp(perms , "-wx"))
        onePerm = '3';
    else if (strcmp(perms , "-w-"))
        onePerm = '2';
    else if (strcmp(perms , "--x"))
        onePerm = '1';
    else if (strcmp(perms , "---"))
        onePerm = '0';
    else
        onePerm = perms;

    return onePerm;
}

