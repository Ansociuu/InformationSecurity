#include <stdio.h>

//Hàm mã hóa
void mahoa(char p[], int k)
{
    fflush(stdin);
    printf("Nhap van ban can ma hoa (Plaintext): ");
    fgets(p, 1000, stdin);
    printf("Nhap khoa k: ");
    scanf("%d", &k);
    if (k < 0 || k > 25) {
        printf("Khoa khong hop le!\n");
        return;
    }
    for (int i=0; p[i]!='\0'; i++)
    {
        if (p[i]>='a' && p[i]<='z')
        {
            p[i] = (p[i] - 97 + k) % 26 + 97;     //Trong bảng mã ASCII thì 'a' bắt đầu từ 97, 'A' bắt đầu từ 65.
            //Công thức này dùng để chuyển giá trị chữ cái ASCII về giá trị từ 0-25, sau đó thực hiện dịch và chuyển lại sang ASCII để in ra.
        }
        else if (p[i]>='A' && p[i]<='Z')
        {
            p[i] = (p[i] - 65 + k) % 26 + 65;
        }
    }
    printf("-> Ciphertext: %s", p);
}

//Hàm giải mã
void giaima(char p[], int k)
{
    fflush(stdin);
    printf("Nhap van ban can giai ma (Ciphertext): ");
    fgets(p, 1000, stdin);
    printf("Nhap khoa k: ");
    scanf("%d", &k);
    if (k < 0 || k > 25) {
        printf("Khoa khong hop le!\n");
        return;
    }
    for (int i=0; p[i]!='\0'; i++)
    {
        if (p[i]>='a' && p[i]<='z')
        {
            p[i] = (p[i] - 97 - k + 26) % 26 + 97;   //Tương tự công thức trên phần mã hóa.
            //Khi mã hóa cộng thêm k thì giải mã ta trừ k để quay lại và cộng thêm 26 để tránh trường hợp phép tính âm dẫn đến sai kết quả.
        }
        else if (p[i]>='A' && p[i]<='Z')
        {
            p[i] = (p[i] - 65 - k + 26) % 26 + 65;
        }
    }
    printf("-> Plaintext: %s", p);
}

int main()
{
    char p[1000];
    int k, choice;
    do
    {
        printf("\nHello world, day la Caesar cipher!!\n\n");
        printf("\t----- o0o -----\t");
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
                mahoa(p,k);
                break;
            case 2:
                giaima(p,k);
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
