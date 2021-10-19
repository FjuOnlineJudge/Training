double trinary_search(double L, double R)
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}