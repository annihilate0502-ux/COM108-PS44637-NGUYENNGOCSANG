#include <stdio.h>
#define PI 3.14159

int main() {
    float chieuDai, chieuRong, banKinh;
    float chuViHCN, dienTichHCN;
    float chuViHT, dienTichHT;

    printf("Nhap chieu dai hinh chu nhat: ");
    scanf("%f", &chieuDai);

    printf("Nhap chieu rong hinh chu nhat: ");
    scanf("%f", &chieuRong);

    chuViHCN = 2 * (chieuDai + chieuRong);
    dienTichHCN = chieuDai * chieuRong;

    printf("\nNhap ban kinh hinh tron: ");
    scanf("%f", &banKinh);

    chuViHT = 2 * PI * banKinh;
    dienTichHT = PI * banKinh * banKinh;

    printf("\n--- Ket qua ---\n");
    printf("Chu vi hinh chu nhat: %.2f\n", chuViHCN);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTichHCN);
    printf("Chu vi hinh tron: %.2f\n", chuViHT);
    printf("Dien tich hinh tron: %.2f\n", dienTichHT);

    return 0;
}

