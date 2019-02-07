#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int power = 9;
const int base = 1000000000;
char con[1050];
 
class bign
{
private:
    long long int d[1050];
public:
    bign() {memset(d, 0, sizeof(d));}
    bign(int d) 	{ *this = d; } 
	bign(const char* d) { *this = d; }
    bign operator = (const char *s)
    {
        int len = strlen(s), p, bit;
        memset(d, 0, sizeof(d));
        d[0] = (len + power - 1) / power;
        for(int i = 0, bit = 0; i < len; p *= 10, ++i)
        {
            if(i % power == 0)
            {
                p = 1;
                ++bit;
            }
            d[bit] += p * (s[i] - '0');
        }
        return *this;
    }
    bign(const bign &obj)
    {
        memset(d, 0, sizeof(d));
        for(int i = 0; i <= obj.d[0]; ++i)
        {
            d[i] = obj.d[i];
        }
    }
    bign &operator=(const bign &right)
    {
        if(this == &right) return *this;
        memset(d, 0, sizeof(d));
        for(int i = 0; i <= right.d[0]; ++i)
        {
            d[i] = right.d[i];
        }
        return *this;
    }
    void addNumber(long long int k)
    {
        if(k != 0 || d[0] != 0)
            d[++d[0]] = k;
    }
    void re()
    {
        long long int len = d[0];
        long long int tmp[1050];
        for(long long int i = 1; i <= len; ++i)
        {
            tmp[len - i + 1] = d[i];
        }
        for(long long int i = 1; i <= len; ++i)
        {
            d[i] = tmp[i];
        }
    }
    bool isEven()
    {
        if(d[1] % 2)return false;
        else return true;
    }
    void operator/=(const long long int &a)
    {
        for(int i = d[0]; i > 1; --i)
        {
            d[i - 1] += (d[i] % a * base);
            d[i] /= a;
        }
        d[1] /= a;
        while(d[0] > 0 && d[d[0]] <= 0)
            --d[0];
    }
 
    bign operator/(const long long int &a)const
    {
        bign temp = *this;
        temp /= a;
        return temp;
    }
    void operator *= (const long long int &a)
    {
        for(int i = 1; i <= d[0]; ++i)
            d[i] *= a;
        for(int i = 1; i <= d[0]; ++i)
        {
            d[i + 1] += d[i] / base;
            d[i] %= base;
        }
    }
 
    bign operator * (const long long int &a)const
    {
        bign temp = *this;
        temp *= a;
        return temp;
    }
    friend ostream &operator<<(ostream &out, const bign &obj);
    bool operator>=(const bign &tmp)
    {
        return !(*this < tmp);
    }
    bool operator<(const bign &tmp)
    {
        if(d[0] < tmp.d[0])
            return true;
        if(d[0] > tmp.d[0])
            return false;
        for(int i = d[0]; i > 0; --i)
        {
            if(d[i] != tmp.d[i])
                return d[i] < tmp.d[i];
        }
        return false;
    }
    bool operator==(const bign &tmp)
    {
        if(d[0] != tmp.d[0])
            return false;
        for(int i = d[0]; i > 0; --i)
        {
            if(d[i] != tmp.d[i])
                return false;
        }
        return true;
    }
    bign operator+(const bign &tmp)
    {
        bign result;
        result.d[0] = (d[0] > tmp.d[0]) ? d[0] : tmp.d[0];
        for(long long int i = 1; i <= result.d[0]; ++i)
        {
            result.d[i] += d[i] + tmp.d[i];
            result.d[i + 1] += result.d[i] / base;
            result.d[i] %= base;
        }
        if(result.d[result.d[0] + 1] != 0)
            ++result.d[0];
        return result;
    }
    bign operator-(const bign &tmp)
    {
        bign result = *this;
        for(long long int i = 1; i <= result.d[0]; ++i)
        {
            result.d[i] -= tmp.d[i];
            if(result.d[i] < 0)
            {
                result.d[i] += base;
                --result.d[i + 1];
            }
        }
        while(result.d[0] > 0 && !result.d[result.d[0]])
            --result.d[0];
        return result;
    }
    bign operator*(const bign &tmp)
    {
        bign result;
        result.d[0] = d[0] + tmp.d[0] - 1;
        for(long long int i = 1; i <= d[0]; ++i)
        {
            for(long long int j = 1; j <= tmp.d[0]; ++j)
            {
                result.d[i + j - 1] += d[i] * tmp.d[j];
                result.d[i + j] += result.d[i + j - 1] / base;
                result.d[i + j - 1] %= base;
            }
        }
        if(result.d[result.d[0] + 1])
            ++result.d[0];
        return result;
    }
    bign operator/(const bign &tmp)
    {
        bign x, y;
        if(*this == tmp)
        {
            x.d[0] = 1;
            x.d[1] = 1;
            return x;
        }
        for(long long int i = d[0]; i >= 1; --i)
        {
            y.addNumber(d[i]);
            y.re();
            while(!(y < tmp))
            {
                y = y - tmp;
                ++x.d[i];
            }
            y.re();
        }
        x.d[0] = d[0];
        while(x.d[0] > 0 && !x.d[x.d[0]])
            --x.d[0];
        return x;
    }
};
 
ostream &operator<<(ostream &out, const bign &obj)
{
    out << obj.d[obj.d[0]];
    for(long long int i = obj.d[0] - 1; i > 0; --i)
    {
        long long int len = 0, tmp = obj.d[i];
        while(tmp != 0)
        {
            tmp /= 10;
            len++;
        }
        for(long long int j = 0; j < power - len; ++j)
        {
            out << 0;
        }
        if(obj.d[i] != 0)
            out << obj.d[i];
    }
    return out;
}
 
void reverse(char *d)
{
    int length = strlen(d);
    char *number = new char[length];
    for (int i = 0; i < length; ++i)
	{
        number[length - i - 1] = d[i];
	}
	for (int i = 0; i < length; ++i)
	{
        d[i] = number[i];
	}
    delete [] number;
}
 
int main()
{
    cin >> con;
    char upper[1050];
    reverse(con);
    memset(upper,'0',sizeof(upper));
    upper[strlen(con)/2+1]='2';
    upper[strlen(con)/2+2]='\0';
    bign d=con;
	bign left("1"),right=upper;
	bign two("2"), one("1"), count, mid, val;
    while(right >= left + one)
    {
        mid=(left+right)/2;
        val=mid*(mid+one)/2;
        if(d<val)
            right = mid;
        else
        {
            if(val<con)
                left=mid+one;
            else
            {
                left=mid;
                break;
            }
        }
    }
    left = left - one;
    count = (left + one) * left / 2;
    if(!left.isEven())
        cout << d - count << '/' << left + two + count - d ;
    else
        cout << left + two + count - d << '/' << d - count ;
 
    cout << flush;
    return 0;
}
