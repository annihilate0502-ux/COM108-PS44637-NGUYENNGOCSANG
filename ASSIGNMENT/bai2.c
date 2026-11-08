#include <stdio.h>

int main() {
    int n;
    int mang[50];
    int soLuongSoDuong = 0;

    printf("Nhap so luong phan tu n (1-50): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        if (scanf("%d", &mang[i]) != 1) {
            printf("Phan tu khong hop le.\n");
            return 1;
        }

        if (mang[i] > 0) {
            soLuongSoDuong++;
        }
    }

    printf("Mang vua nhap: ");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", mang[i]);
    }

    printf("\nSo luong so duong trong mang: %d\n", soLuongSoDuong);
    return 0;
}