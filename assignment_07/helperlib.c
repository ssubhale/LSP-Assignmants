int IsFactor(int iNo, int i)
{
    if(i == 0)
    {
        return 0;
    }
    else
    {
        return (iNo % i == 0);
    }
}

int SumOfFactors(int iNo)
{
    int iSum = 0;
    int i;

    for(i = 1; i <= iNo / 2; i++)
    {
        if(IsFactor(iNo, i))
        {
            iSum += i;
        }
    }
    return iSum;
}
