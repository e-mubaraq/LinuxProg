
#include <cstring>
#include <string>
#include "../include/perms.h"

using namespace std;
int main()
{
    string str;
    cout << "Enter the file permission: ";
    cin >> str;

    if (str.length() == 9)
        cout << "This is the permission for chmod: " << permissionString(str);
    else
        cout << str << " is not a valid permission. Permissions should be 9 characters long.";

    return 0;
}

string permissionString(string perms)
{
    string permission;
    string userPerm = perms.substr(0, 3);
    string groupPerm = perms.substr(3, 3);
    string otherPerm = perms.substr(6, 3);

    userPerm = onePermission(userPerm);
    groupPerm = onePermission(groupPerm);
    otherPerm = onePermission(otherPerm);

    permission = userPerm + groupPerm + otherPerm;
    return permission;
}

string onePermission(string perms)
{
    string onePerm;

    if (perms.compare("rwx") == 0)
        onePerm = "7";
    else if (perms.compare("rw-") == 0)
        onePerm = "6";
    else if (perms.compare("r-x") == 0)
        onePerm = "5";
    else if (perms.compare("r--") == 0)
        onePerm = "4";
    else if (perms.compare("-wx") == 0)
        onePerm = "3";
    else if (perms.compare("-w-") == 0)
        onePerm = "2";
    else if (perms.compare("--x") == 0)
        onePerm = "1";
    else if (perms.compare("---") == 0)
        onePerm = "0";
    else
        onePerm = perms;

    return onePerm;
}

