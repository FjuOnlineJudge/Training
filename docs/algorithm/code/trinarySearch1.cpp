const double EPS = 1e−7;
double trinary_search(double L, double R)
{
    while (R - L > EPS)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}