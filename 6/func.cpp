#include <iostream>
#include "Header.h"

namespace sk {
    void read(int &n, int &m, int matrix[100][100])
    {
        std::cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                std::cin >> matrix[i][j];
            }
    }

    int masPrime[100] = {0};

    void primeNumbers(int n, int m, int matrix[100][100])
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                bool isPrime = true;
                if (matrix[i][j] <= 1)
                {
                    isPrime = false;
                }
                for (int d = 2; d <= sqrt(matrix[i][j]); d++)
                {
                    if (matrix[i][j] % d == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime)
                {
                    masPrime[i]++;
                    std::cout << matrix[i][j] << " ";
                }
            }
            std::cout << masPrime[i] << std::endl;
        }
    }

    void maxInMatrix(int n, int m, int matrix[100][100])
    {
        int max = INT_MIN;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] > max)
                {
                    max = matrix[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == max)
                {
                    count++;
                }
            }
        }
        if (count == 2)
        {
            sort(n, m, matrix);
        }
        if (count != 2)
        {
            std::cout << "ERROR";
        }
    }

    void sort(int n, int m, int matrix[100][100]) 
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (masPrime[i] < masPrime[j])
                {
                    std::swap(masPrime[i], masPrime[j]);
                    for (int k = 0; k < m; k++)
                    {
                        std::swap(matrix[i][k], matrix[j][k]);
                    }
                }
            }
        }
    }

    void write(int n, int m, int matrix[100][100])
    {
        std::cout << std::endl;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}