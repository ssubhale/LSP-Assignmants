#include <stdio.h>


int Mystrlen(char *szStr)
{
    if (szStr == NULL)
        return 0;

    int count = 0;
    while (szStr[count] != '\0')
        count++;
    return count;
}


void Mystrcpy(char *szDest, char *szSrc)
{
    while (*szSrc != '\0')
    {
        *szDest = *szSrc;
        szDest++;
        szSrc++;
    }
    *szDest = '\0';
}


void Mystrncpy(char *szDest, char *szSrc, int iNo)
{
    int i;
    for (i = 0; i < iNo && szSrc[i] != '\0'; i++)
        szDest[i] = szSrc[i];

    for (; i < iNo; i++)
        szDest[i] = '\0';
}


void Mystrcat(char *szDest, char *szSrc)
{
    while (*szDest != '\0')
        szDest++;

    while (*szSrc != '\0')
    {
        *szDest = *szSrc;
        szDest++;
        szSrc++;
    }
    *szDest = '\0';
}


int Mystrcmp(char *szStr1, char *szStr2)
{
    while (*szStr1 && *szStr2)
    {
        if (*szStr1 != *szStr2)
            return *szStr1 - *szStr2;
        szStr1++; szStr2++;
    }
    return *szStr1 - *szStr2;
}


int Mystrncmp(char *szStr1, char *szStr2, int iNo)
{
    for (int i = 0; i < iNo; i++)
    {
        if (szStr1[i] != szStr2[i])
            return szStr1[i] - szStr2[i];
        if (szStr1[i] == '\0')
            return 0;
    }
    return 0;
}


void Mystrrev(char *szStr)
{
    int len = Mystrlen(szStr);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = szStr[i];
        szStr[i] = szStr[len - i - 1];
        szStr[len - i - 1] = temp;
    }
}


char* Mystrstr(char *szStr, char *subszStr)
{
    if (szStr == NULL || subszStr == NULL)
        return NULL;

    int i, j;
    for (i = 0; szStr[i] != '\0'; i++)
    {
        for (j = 0; subszStr[j] != '\0'; j++)
        {
            if (szStr[i + j] != subszStr[j])
                break;
        }
        if (subszStr[j] == '\0')
            return &szStr[i];
    }
    return NULL;
}
