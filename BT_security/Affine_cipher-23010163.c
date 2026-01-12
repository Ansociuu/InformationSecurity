#include <stdio.h>

// Hàm tìm ước chung lớn nhất
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tìm nghịch đảo modulo m
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // Không có nghịch đảo
}

// Hàm mã hóa Affine
void mahoa(char p[])
{
    int a, b;
    fflush(stdin);
    printf("Nhap van ban can ma hoa (Plaintext): ");
    fgets(p, 1000, stdin);

    printf("Nhap khoa a (gcd(a,26)=1): ");
    scanf("%d", &a);
    printf("Nhap khoa b (0-25): ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1 || b < 0 || b > 25)
    {
        printf("Khoa khong hop le!\n");
        return;
    }

    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] = ((a * (p[i] - 'a') + b) % 26) + 'a'; //Công thức có khác hơn một chút so với Caesar
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            p[i] = ((a * (p[i] - 'A') + b) % 26) + 'A';
        }
    }
    printf("-> Ciphertext: %s", p);
}

// Hàm giải mã Affine
void giaima(char p[])
{
    int a, b;
    fflush(stdin);
    printf("Nhap van ban can giai ma (Ciphertext): ");
    fgets(p, 1000, stdin);
    printf("Nhap khoa a: ");
    scanf("%d", &a);
    printf("Nhap khoa b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1 || b < 0 || b > 25)
    {
        printf("Khoa khong hop le!\n");
        return;
    }
    int a_inv = modInverse(a, 26);
    if (a_inv == -1)
    {
        printf("Khong tim duoc nghich dao cua a!\n");
        return;
    }
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] = ((a_inv * ((p[i] - 'a') - b + 26)) % 26) + 'a';
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            p[i] = ((a_inv * ((p[i] - 'A') - b + 26)) % 26) + 'A';
        }
    }
    printf("-> Plaintext: %s", p);
}

int main()
{
    char p[1000];
    int choice;
    do {
        printf("\nHello world, day la Affine cipher!!\n\n");
        printf("\t----- o0o -----\n");
        printf("Ban can lam gi?\n");
        printf("1. Ma hoa\n");
        printf("2. Giai ma\n");
        printf("3. Ket thuc chuong trinh\n");
        printf("Lua chon cua ban: ");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                mahoa(p);
                break;
            case 2:
                giaima(p);
                break;
            case 3:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (choice != 3);
    return 0;
}
