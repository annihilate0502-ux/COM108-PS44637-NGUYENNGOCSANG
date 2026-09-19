#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char mssv[20];
    char hoVaTen[50];
    int namSinh;
    float diemTrungBinh;
    int tuoi;
    time_t now = time(NULL);
    struct tm *lt = localtime(&now);

    printf("Nhap ma so sinh vien: ");
    scanf("%s", mssv);
    getchar();

    printf("Nhap ho va ten: ");
    fgets(hoVaTen, sizeof(hoVaTen), stdin);
    hoVaTen[strcspn(hoVaTen, "\n")] = '\0';

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTrungBinh);

    tuoi = lt->tm_year + 1900 - namSinh;

    printf("\nMa so sinh vien: %s\n", mssv);
    printf("Ho va ten: %s\n", hoVaTen);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem trung binh: %.2f\n", diemTrungBinh);

    return 0;
}
