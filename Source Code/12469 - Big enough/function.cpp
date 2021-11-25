#include "function.h"
#include<iostream>
#include<string>
using namespace std;

istream& operator>>(istream& in, BigInt& bigi)
{
    string s;
    in >> s;
    int i;
    int len_s = s.length();
    //cout << s[0];
    if(s[0] == '-')
    {
        bigi.sign = 0;
        s.erase(0,1);
        len_s--;
    }
    else
    {
        bigi.sign = 1;
    }
    int zero = 5000 - len_s;
    bigi.l = len_s;
    for(i=0;i<zero;i++)
    {
        s.insert(s.begin(),'0');
    }
    for(i=0;i<5000;i=i+5)
    {
        bigi.m[i/5] = stoi(s.substr(i,5));
    }
    /*
    for(i=0;i<1000;i++)
    {
        cout << "Line" << i << ": "<< bigi.m[i] << endl;
    }
    */
    return in;
}
ostream& operator<<(ostream& out, BigInt bigi)
{
    int i;
    int item = 5000 - bigi.l;
    if(bigi.sign == 0)
    {
        out << "-";
    }
    i=item/5;
    out << bigi.m[i];
    i++;
    for(;i<1000;i++)
    {
        string s = to_string(bigi.m[i]);
        int len_s = s.length();
        //cout  << len_s;
        int zero = 5 - len_s;
        while(zero != 0)
        {
            s.insert(s.begin(),'0');
            zero--;
        }
        out << s;
    }
    return out;
}
BigInt BigInt::operator +( const BigInt &y )
{
    BigInt result;
    int i;
    int extended = 0;
    long long carry_out = 0;
    int larger = 0;
    long long borrow = 0;
    if(this->sign == y.sign)
    {
        result.sign = this->sign;
        for(i=999;i>=0;i--)
        {
            if(this->m[i]== 0 && y.m[i] == 0 && carry_out == 1)
            {
                extended = 1;
            }
            result.m[i] = this->m[i] + y.m[i] + carry_out;
            carry_out = 0;
            if(result.m[i] > 100000)
            {
                carry_out = 1;
                result.m[i] = result.m[i] - 100000;
            }
        }
        result.l = max(this->l, y.l);
        if(extended == 1)
        {
            result.l = result.l + 1;
        }
    }
    else
    {
        for(i=0;i<1000;i++)
        {
            if(this->m[i] != 0 && this->m[i] > y.m[i])
            {
                larger = 1;
                break;
            }
            else if(y.m[i] != 0 && y.m[i] > this->m[i])
            {
                larger = 2;
                break;
            }
        }
        if(larger == 1)
        {
            result.sign = this->sign;
            for(i=999;i>=0;i--)
            {
                if(this->m[i]== 1 && y.m[i] == 0 && borrow == 1)
                {
                    extended = 1;
                }
                result.m[i] = this->m[i] - y.m[i] - borrow;
                borrow = 0;
                if(result.m[i] < 0)
                {
                    borrow = 1;
                    result.m[i] = result.m[i] + 100000;
                }
            }
            result.l = this->l;
            if(extended == 1)
            {
                result.l = result.l - 1;
            }
        }
        else if(larger == 2)
        {
            result.sign = y.sign;
            for(i=999;i>=0;i--)
            {
                if(this->m[i]== 0 && y.m[i] == 1 && borrow == 1)
                {
                    extended = 1;
                }
                result.m[i] = y.m[i] - this->m[i] - borrow;
                borrow = 0;
                if(result.m[i] < 0)
                {
                    borrow = 1;
                    result.m[i] = result.m[i] + 100000;
                }
                //cout << "line" << i << ": " << result.m[i] << endl;
            }
            result.l = y.l;
            if(extended == 1)
            {
                result.l = result.l - 1;
            }
        }
        else
        {
            result.l = 1;
            result.sign = 1;
            result.m[999] = 0;
        }
    }
    return result;
}
BigInt BigInt::operator -( const BigInt &y )
{
    BigInt result;
    int i;
    int extended = 0;
    long long carry_out = 0;
    int larger = 0;
    long long borrow = 0;
    if(this->sign == y.sign)
    {
        for(i=0;i<1000;i++)
        {
            if(this->m[i] != 0 && this->m[i] > y.m[i])
            {
                larger = 1;
                break;
            }
            else if(y.m[i] != 0 && y.m[i] > this->m[i])
            {
                larger = 2;
                break;
            }
        }
        if(larger == 1)
        {
            result.sign = this->sign;
            for(i=999;i>=0;i--)
            {
                if(this->m[i]== 1 && y.m[i] == 0 && borrow == 1)
                {
                    extended = 1;
                }
                result.m[i] = this->m[i] - y.m[i] - borrow;
                borrow = 0;
                if(result.m[i] < 0)
                {
                    borrow = 1;
                    result.m[i] = result.m[i] + 100000;
                }
            }
            result.l = this->l;
            if(extended == 1)
            {
                result.l = result.l - 1;
            }
        }
        else if(larger == 2)
        {
            if(y.sign == 0)
            {
                result.sign = 1;
            }
            else
            {
                result.sign = 0;
            }
            for(i=999;i>=0;i--)
            {
                if(this->m[i]== 0 && y.m[i] == 1 && borrow == 1)
                {
                    extended = 1;
                }
                result.m[i] = y.m[i] - this->m[i] - borrow;
                borrow = 0;
                if(result.m[i] < 0)
                {
                    borrow = 1;
                    result.m[i] = result.m[i] + 100000;
                }
            }
            result.l = y.l;
            if(extended == 1)
            {
                result.l = result.l - 1;
            }
        }
        else
        {
            result.l = 1;
            result.sign = 1;
            result.m[999] = 0;
        }
    }
    else
    {
        result.sign = this->sign;
        for(i=999;i>=0;i--)
        {
            if(this->m[i]== 0 && y.m[i] == 0 && carry_out == 1)
            {
                extended = 1;
            }
            result.m[i] = this->m[i] + y.m[i] + carry_out;
            carry_out = 0;
            if(result.m[i] > 100000)
            {
                carry_out = 1;
                result.m[i] = result.m[i] - 100000;
            }
        }
        result.l = max(this->l, y.l);
        if(extended == 1)
        {
            result.l = result.l + 1;
        }
    }
    return result;
}
