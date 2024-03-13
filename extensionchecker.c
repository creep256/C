#include<stdio.h>
#include<string.h>
const char* extension1(const char* file_name)
{
    const char* dot=strchr(file_name,'.');

    if(!dot )
    {
        return "";
    }
    return dot +1;
}

int main ()
{
    const char *file_name="example.html";
    const char *extension=extension1(file_name);

    printf("File extension:%s\n",extension);
}