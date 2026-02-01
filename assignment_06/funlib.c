int Addition(int iNo1, int iNo2)
{
    return iNo1 + iNo2;
}


int Subtraction(int iNo1, int iNo2)
{
    return iNo1 - iNo2;
}


int Multiplication(int iNo1, int iNo2)
{
    return iNo1 * iNo2;
}


int Division(int iNo1, int iNo2)
{
    return iNo1 / iNo2;
}


int CountLowercase(char *szStr)
{
    int iCount = 0;

    while (*szStr)
    {
        if ((*szStr >= 'a') && (*szStr <= 'z'))
        {
            iCount++;
        }
        szStr++;
    }

    return iCount;
}

int CountUppercase(char *szStr)
{
    int iCount = 0;

    while (*szStr)
    {
        if ((*szStr >= 'A') && (*szStr <= 'Z'))
        {
            iCount++;
        }
        szStr++;
    }

    return iCount;
}

int CountDigits(char *szStr)
{
    int iCount = 0;

    while (*szStr)
    {
        if ((*szStr >= '0') && (*szStr <= '9'))
        {
            iCount++;
        }
        szStr++;
    }

    return iCount;
}
