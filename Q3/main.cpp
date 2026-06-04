#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0;
}

int main()
{
    string data = "1010101000011010";

    int m = data.length();
    int r = 0;

    while (pow(2, r) < m + r + 1)
        r++;

    int n = m + r;

    vector<int> hamming(n + 1);

    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!isPowerOfTwo(i))
        {
            hamming[i] = data[j] - '0';
            j++;
        }
    }

    for (int p = 1; p <= n; p *= 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
                parity ^= hamming[i];
        }

        hamming[p] = parity;
    }

    cout << "Encoded Hamming Code: ";

    for (int i = 1; i <= n; i++)
        cout << hamming[i];

    cout << endl;

    return 0;
}