#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;


int hasPairs(char* fname) {
    FILE* file = fopen(fname, "r");  
    if (file == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    char str[100];

    while (fgets(str, 100, file) != NULL) 
    {
        int length = strlen(str);
        for (int i = 0; i < length - 1; i++)
        {
            if ((str[i] == 'a' && str[i + 1] == 'a') ||
                (str[i] == 'b' && str[i + 1] == 'b') ||
                (str[i] == 'c' && str[i + 1] == 'c')) 
            {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file); 
    return 0;
} 


int main() 
{
    char fname[100];
    printf("Type filename: ");
    scanf("%s", fname);

    int result = hasPairs(fname);  
    if (result == -1)
    {
        printf("Cannot open file.\n");
    }
    else if (result == 1) 
    {
        printf("File contains adjacent pairs 'aa', 'bb' or 'cc'.\n");
    }
    else
    {
        printf("File does not contain adjacent pairs 'aa', 'bb' or 'cc'.\n");
    }

    return 0;

}
