#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Enter 6, 8 or 10: ";

        unsigned int n;
        cin >> n;
        // n = 10;

        cout << endl;

        vector<vector<int>> v(n, vector<int>(n));
        // int v[10][10];

        size_t i = 0, j = n - 1;

        int value = 1;

        while (n != 0)
        {
            size_t k = 0;
            do { v[i][j--] = value++; } while (++k < n - 1);
            for (k = 0; k < n - 1; k++) v[i++][j] = value++;
            for (k = 0; k < n - 1; k++) v[i][j++] = value++;
            for (k = 0; k < n - 1; k++) v[i--][j] = value++;

            ++i; --j; n = n < 2 ? 0 : n - 2;
        }

        for (const auto& row : v)
        {
            for (int x : row) cout << setw(3) << x << ' ';
            cout << endl;
        }

        cout << endl;
    }
}
