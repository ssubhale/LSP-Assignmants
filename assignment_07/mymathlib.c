
int Myabs(int iNo)
{
    return (iNo < 0) ? -iNo : iNo;
}


int Mymax(int iNo1, int iNo2)
{
    return (iNo1 > iNo2) ? iNo1 : iNo2;
}


int Mymin(int iNo1, int iNo2)
{
    return (iNo1 < iNo2) ? iNo1 : iNo2;
}


long Myfactorial(int iNo)
{
    long lFact = 1;
    for (int iCounter = 1; iCounter <= iNo; iCounter++)
        lFact *= iCounter;
    return lFact;
}


int Mygcd(int iNo1, int iNo2)
{
    while (iNo2 != 0)
    {
        int iTemp = iNo2;
        iNo2 = iNo1 % iNo2;
        iNo1 = iTemp;
    }
    return iNo1;
}


int Mylcm(int iNo1, int iNo2)
{
    return (iNo1 * iNo2) / Mygcd(iNo1, iNo2);
}


double Mypow(double dNo, int iExp)
{
    double dResult = 1;
    for (int iCounter = 0; iCounter < iExp; iCounter++)
        dResult *= dNo;
    return dResult;
}


double Mysqrt(double dNo)
{
    double dNo1 = dNo;
    double dNo2 = 1;
    double dNo3 = 0.00001;

    while (dNo1 - dNo2 > dNo3)
    {
        dNo1 = (dNo1 + dNo2) / 2;
        dNo2 = dNo / dNo1;
    }
    return dNo1;
}
