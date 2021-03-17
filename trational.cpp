#include "trational.h"

TRational::TRational()
{
    TRational::a=0;
    TRational::b=1;
}

TRational::TRational(int inp_a, int inp_b)
{
    TRational::a = inp_a;
    TRational::b = inp_b;
}

void TRational::norm()
{
    int nod = std::gcd(TRational::a,TRational::b);
    TRational::a=TRational::a/nod;
    TRational::b=TRational::b/nod;
    if (TRational::b < 0)
    {
        TRational::a *= -1;
        TRational::b *= -1;
    }
    return;
}


std::ostream& operator <<(std::ostream& ost, TRational const& r)
{
    TRational tmp=r;
    tmp.norm();
    if (tmp < 0)
        ost << "-";
    else
        ost << "+";
    ost <<std::noshowpos << "(" << abs(tmp.a) << '/' << tmp.b << ")";
    return ost;
}

std::istream& operator>>(std::istream& ist, TRational& r) // формат  123/456
{
    std::string s;
    std::getline(ist, s, '\n');
    std::string::size_type ind;
    if ((ind = s.find("/")) != std::string::npos)
        s.replace(ind,1," ");
    std::istringstream iss(s);
    iss >> r.a >> r.b ;
    return ist;
}


TRational& TRational::operator= (const int& right)
{
    TRational::a=right;
    TRational::b=1;
    return *this;
}

TRational TRational::operator-() const
{
    return TRational(-TRational::a,TRational::b);
}

TRational const operator* (TRational const& left, TRational const& right)
{
    return TRational(left.a*right.a,left.b*right.b);
}

TRational const operator* (int const& left, TRational const& right)
{
    return TRational(left*right.a,right.b);
}

TRational const operator+ (TRational const& left, TRational const& right)
{
    return TRational(left.a * right.b + right.a * left.b, left.b * right.b);
}

TRational const operator- (TRational const& left, TRational const& right)
{
    return left + TRational(-right.a, right.b);
}

TRational const operator/ (TRational const& left, TRational const& right)
{
    return left * TRational(right.b, right.a);
}

bool operator< (TRational const& left, int const& right)
{
    return double(left.a) / left.b < right;
}

bool operator< (int const& left, TRational const& right)
{
    return left < double(right.a) / right.b;
}

bool operator== (TRational const& lhs, int const& rhs)
{
    return !(lhs < rhs || rhs < lhs);
}

TRational sqrt(TRational const& t)
{
    return TRational(sqrt(t.a),sqrt(t.b));
}
