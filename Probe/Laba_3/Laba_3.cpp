#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Enter 6, 8 or 10: ";

        unsigned int N;
        cin >> N;
        // n = 10;

        cout << endl;

        // vector<vector<int>> v(n, vector<int>(n));
        int v[10][10] = {0};

        size_t i = 0, j = N - 1;

        int value = 1;
        unsigned int n = N;

        while (n != 0)
        {
            size_t k = 0;
            do { v[i][j--] = value++; } while (++k < n - 1);
            for (k = 0; k < n - 1; k++) v[i++][j] = value++;
            for (k = 0; k < n - 1; k++) v[i][j++] = value++;
            for (k = 0; k < n - 1; k++) v[i--][j] = value++;

            ++i; --j;
            n = n < 2 ? 0 : n - 2;
        }

        for (int a = 0; a < N; a++)
        {
            for (int b = 0; b < N; b++)
            {
                cout << setw(4) << v[a][b];
            }
            cout << endl;
        }

        cout << endl;
    }
}
