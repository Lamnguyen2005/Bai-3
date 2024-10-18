using System;
using System.Collections.Generic;


class Program
{
    // kiểm tra số nguyên tố
    static bool IsPrime(int n)
    {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    // Hàm backtrack 
    static void Backtrack(int n, int start, List<int> factors)
    {
        if (n == 1)
        {
            // danh sách thừa số nguyên tố
            Console.WriteLine(string.Join(" * ", factors));
            return;
        }

        for (int i = start; i <= n; i++)
        {
            if (n % i == 0 && IsPrime(i))
            {
                factors.Add(i); 
                Backtrack(n / i, i, factors); 
                factors.RemoveAt(factors.Count - 1);
            }
        }
    }

    // Hàm gọi để phân tích thừa số nguyên tố
    static void PrimeFactorization(int N)
    {
        Console.WriteLine($"Phan tich {N} thanh thua so nguyen to:");
        Backtrack(N, 2, new List<int>());
    }

    static void Main(string[] args)
    {
        // nhập số N
        Console.Write("Nhap so tu nhien N: ");
        int N;
        while (!int.TryParse(Console.ReadLine(), out N) || N <= 1)
        {
            Console.WriteLine("Vui long nhap mot so tu nhien lon hon 1.");
            Console.Write("Nhap lai so tu nhien N: ");
        }

        // hàm phân tích thừa số nguyên tố
        PrimeFactorization(N);
    }
}
