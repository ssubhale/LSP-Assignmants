
int MyStrLen(char *szStr)
{
    int iCount = 0;

    while (szStr[iCount] != '\0')
    {
        iCount++;
    }

    return iCount;
}
