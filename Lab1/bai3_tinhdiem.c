#include <stdio.h>

int main() {
    char mssv[20] = "PS44637";
    char hoVaTen[50] = "Nguyen Ngoc Sang";
    float diemToan = 8.0f;
    float diemLy = 7.5f;
    float diemHoa = 8.5f;
    float diemTrungBinh;

    diemTrungBinh = (diemToan * 2 + diemLy + diemHoa) / 4.0f;

    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoVaTen);
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh);

    return 0;
}
