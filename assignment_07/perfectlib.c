
int SumOfFactors(int);

int IsPerfect(int iNo)
{
    int iResult = SumOfFactors(iNo);

    if (iResult == iNo)
        return 1;
    else
        return 0;
}

