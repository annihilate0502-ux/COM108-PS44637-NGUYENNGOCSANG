#include <stdio.h>
#include <string.h>

struct SinhVien {
    char mssv[10];
    char tenSV[30];
    float diem;
} sv1;

int main() {
    printf("Nhap ma sinh vien: ");
    fgets(sv1.mssv, sizeof(sv1.mssv), stdin);
    sv1.mssv[strcspn(sv1.mssv, "\n")] = '\0';

    printf("Nhap ten sinh vien: ");
    fgets(sv1.tenSV, sizeof(sv1.tenSV), stdin);
    sv1.tenSV[strcspn(sv1.tenSV, "\n")] = '\0';

    printf("Nhap diem: ");
    scanf("%f", &sv1.diem);
    
    printf("MSSV: %s\tTen SV: %s\tDiem: %.2f\n", sv1.mssv, sv1.tenSV, sv1.diem);
}