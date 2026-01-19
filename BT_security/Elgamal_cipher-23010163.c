#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Lũy thừa modulo
long long mod_pow(long long a, long long b, long long p)
{
    long long result = 1;
    a %= p;

    while (b > 0)
    {
        if (b % 2 == 1) result = (result * a) % p;
        b /= 2;
        a = (a * a) % p;
    }
    return result;
}

//Nghịch đảo modulo (p là số nguyên tố)
long long mod_inverse(long long a, long long p)
{
    return mod_pow(a, p - 2, p);
}

//Hàm sinh khóa
void keygen(long long *p, long long *g, long long *x, long long *y)
{

    *p = 467;   //số nguyên tố
    *g = 2;     //phần tử sinh

    *x = rand() % (*p - 2) + 1;   //private key
    *y = mod_pow(*g, *x, *p);     //public key

    printf("\t=== SINH KHOA ===\n");
    printf("Public key (p, g, y): (%lld, %lld, %lld)\n", *p, *g, *y);
    printf("Private key x: %lld\n\n", *x);
}

//Hàm mã hóa
void encrypt(long long p, long long g, long long y, long long m, long long *c1, long long *c2)
{

    long long k = rand() % (p - 2) + 1; //k ngẫu nhiên

    *c1 = mod_pow(g, k, p);
    *c2 = (m * mod_pow(y, k, p)) % p;

    printf("\n\t=== MA HOA ===\n");
    printf("k = %lld\n", k);
    printf("Ban ma (c1, c2): (%lld, %lld)\n\n", *c1, *c2);
}

//Hàm giải mã
long long decrypt(long long p, long long x, long long c1, long long c2)
{

    long long s = mod_pow(c1, x, p);
    long long s_inv = mod_inverse(s, p);

    long long decrypted_m = (c2 * s_inv) % p;
    printf("\t=== GIAI MA ===\n");
    printf("Ban ro sau giai ma: %lld\n", decrypted_m);
}

int main()
{
    long long p, g, x, y;
    long long m;
    long long c1, c2;
    long long decrypted_m;

    srand(time(NULL));

    //1. Sinh khóa
    keygen(&p, &g, &x, &y);

    //2. Nhập bản rõ
    do
    {
        printf("Nhap ban ro m (m < p): ");
        scanf("%lld", &m);
        if (m >= p) printf("Khong hop le, moi nhap lai!\n\n");
        fflush(stdin);
    } while (m >= p);

    //3. Mã hóa (người gửi)
    encrypt(p, g, y, m, &c1, &c2);

    //4. Giải mã (người nhận)
    decrypt(p, x, c1, c2);

    return 0;
}
