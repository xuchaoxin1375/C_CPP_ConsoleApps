#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    extern float sqrt1(float x, int n);
    float res;

    res = sqrt1(3, 10);
    cout << "result:" << res << endl;
    // cout << (1.0 / 2) << endl;
    return 0;
}
bool print_process = true;
float e = 0.000001;
float sqrt1(float x, int n)
{
    // if(sqrt)

    if (n == 1)
    {
        return 1;
    }
    float t = sqrt1(x, n - 1);
    if (abs(t * t - x) < e)
    {
        // cout<<"get result"<<endl;
        print_process = false;
        return t;
    }
    float res = (1.0 / 2) * (t + x / t);
    if (print_process)
    {

        cout << setprecision(30) << res << endl;
    }
    return res;
}