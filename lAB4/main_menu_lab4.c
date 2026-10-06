#include <stdio.h>

void tinhTrungBinhChan() {
    int min, max;
    int tong = 0;
    int dem = 0;
    float trungBinh;

    printf("Nhap min: ");
    scanf("%d", &min);

    printf("Nhap max: ");
    scanf("%d", &max);

    if (min > max) {
        printf("Khong co so nao chia het cho 2 trong khoang da nhap.\n");
        return;
    }

    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) {
            tong += i;
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so nao chia het cho 2 trong khoang da nhap.\n");
        return;
    }

    trungBinh = (float)tong / dem;

    printf("Tong cac so chia het cho 2: %d\n", tong);
    printf("So luong cac so chia het cho 2: %d\n", dem);
    printf("Trung binh cong: %.2f\n", trungBinh);
}

void chucNang2() {
    int x;
    int laSoNguyenTo = 1;

    printf("Nhap mot so nguyen x: ");
    scanf("%d", &x);

    if (x < 2) {
        printf("%d khong phai la so nguyen to.\n", x);
        return;
    }

    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            laSoNguyenTo = 0;
            break;
        }
    }

    if (laSoNguyenTo == 1) {
        printf("%d la so nguyen to.\n", x);
    } else {
        printf("%d khong phai la so nguyen to.\n", x);
    }
}

void chucNang3() {
    int x;
    int laSoChinhPhuong = 0;

    printf("Nhap mot so nguyen x: ");
    scanf("%d", &x);

    if (x < 0) {
        printf("%d khong phai la so chinh phuong.\n", x);
        return;
    }

    for (int i = 0; i <= x; i++) {
        if (i * i == x) {
            laSoChinhPhuong = 1;
            break;
        }
    }

    if (laSoChinhPhuong == 1) {
        printf("%d la so chinh phuong.\n", x);
    } else {
        printf("%d khong phai la so chinh phuong.\n", x);
    }
}

void chucNang4() {
    printf("Chuc nang 4 chua duoc hoan thien.\n");
}

int main() {
    int luaChon;

    do {
        printf("\n===== MENU LAB 4 =====\n");
        printf("1. Tinh trung binh cong cac so chia het cho 2\n");
        printf("2. Chuc nang 2\n");
        printf("3. Chuc nang 3\n");
        printf("4. Chuc nang 4\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                tinhTrungBinhChan();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 4:
                chucNang4();
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}
