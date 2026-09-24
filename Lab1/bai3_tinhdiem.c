#include <stdio.h>
int main() {
    char mssv[20] = "PS44637";
    char hoVaTen[50] = "Nguyen Ngoc Sang";
    float diemToan = 8.5;
    float diemAnh = 10.0;
    float diemVan = 7.0;
    float diemTrungBinh;

    diemTrungBinh = (diemToan*2 + diemAnh + diemVan)/4.0f;
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho va ten: %s\n", hoVaTen);
    printf("Diem trung binh: %.2f\n", diemTrungBinh);
    return 0; 

}