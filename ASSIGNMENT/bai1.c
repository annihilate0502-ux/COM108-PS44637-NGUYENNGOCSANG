#include <stdio.h>

int main() {
    int n;
    long long tong = 0;
    int coSoChan = 0;

    printf("Nhap so nguyen duong n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }

    printf("Cac so chan: ");
    for (int i = 2; i <= n; i += 2) {
        if (coSoChan) {
            printf(", ");
        }
        printf("%d", i);
        tong += i;
        coSoChan = 1;
    }

    if (!coSoChan) {
        printf("khong co");
    }

    printf("\nTong = %lld\n", tong);
    return 0;
}