#include <stdio.h>

void mahoa(char p[], char k[], int m)
{
    fflush(stdin);
    int n=0;
    int j=0;
    printf("Nhap van ban can ma hoa: ");
    fgets(p, 1000, stdin);
    printf("Nhap m: ");
    scanf("%d", &m);
    fflush(stdin);
    printf("Nhap tu khoa k: ");
    fgets(k, 1000, stdin);

    for (int i=0;  p[i]!='\0'; i++)
    {
        if (j<m)
        {
            if (k[n]>='a' && k[n]<='z')
            {
                k[n] = (k[n] - 97) % 26;
            }
            else if (k[n]>='A' && k[n]<='Z')
            {
                k[n] = (k[n] - 65) % 26;
            }
            j++;
        }
        if (p[i]>='a' && p[i]<='z')
        {
            p[i] = (p[i] - 97 + k[n]) % 26 + 97;     //Trong bảng mã ASCII thì 'a' bắt đầu từ 97, 'A' bắt đầu từ 65.
        }
        else if (p[i]>='A' && p[i]<='Z')
        {
            p[i] = (p[i] - 65 + k[n]) % 26 + 65;
        }
        n++;
        if (n==m) {n=0;}
    }
    printf("-> Ciphertext: %s", p);
}

void giaima()
{

}

int main()
{

    int choice, m;
    char k[1000];
    char p[1000];
    do
    {
        printf("\nHello world, day la he ma khoa Vigenere!\n");
        printf("\t------o0o-----\t\n");
        printf("Ban can lam gi?\n");
        printf("1. Ma hoa\n");
        printf("2. Giai ma\n");
        printf("3. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                mahoa(p,k,m);
                break;
            case 2:
                giaima();
                break;
            case 3:
                printf("Thoat chuong trinh!");
                break;
            default:
                printf("Lua chon khong hop le, moi nhap lai!\n");
        }
    } while (choice != 3);
    return 0;
}
