#include <stdio.h>

void menu();
void chucNang1();
void chucNang2();
void chucNang3();

int main() {
    int chon;

    do {
        menu();
        printf("Chon chuc nang: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                chucNang1();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Chuc nang nay chua co. Vui long chon lai.\n");
                break;
        }
    } while (chon != 0);

    return 0;
}

void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Kiem tra so nguyen\n");
    printf("2. Tim UCLN va BCNN\n");
    printf("3. Tinh tien Karaoke\n");
    printf("0. Thoat\n");
}

void chucNang1() {
    int x;
    int laSoNguyenTo = 1;
    int laSoChinhPhuong = 0;

    printf("Nhap vao mot so nguyen x: ");
    scanf("%d", &x);

    printf("%d la so nguyen.\n", x);

    if (x < 2) {
        laSoNguyenTo = 0;
    } else {
        for (int i = 2; i <= x / 2; i++) {
            if (x % i == 0) {
                laSoNguyenTo = 0;
                break;
            }
        }
    }

    if (laSoNguyenTo == 1) {
        printf("%d la so nguyen to.\n", x);
    } else {
        printf("%d khong phai la so nguyen to.\n", x);
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

void chucNang2() {
    int x, y;
    int a, b;
    int ucln, bcnn;

    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Nhap y: ");
    scanf("%d", &y);

    a = x;
    b = y;

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    ucln = a;
    bcnn = (x * y) / ucln;

    printf("Uoc so chung lon nhat: %d\n", ucln);
    printf("Boi so chung nho nhat: %d\n", bcnn);
}

void chucNang3() {
    int gioBatDau, gioKetThuc;
    int soGio;
    const float giaGioDau = 150000.0f;
    float tongTien;
    float giamGia = 0.0f;

    printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Quan chi hoat dong trong khoang gio 12 den 23 va gio ket thuc phai lon hon gio bat dau.\n");
        return;
    }

    soGio = gioKetThuc - gioBatDau;
    tongTien = soGio * giaGioDau;

    if (soGio > 3) {
        tongTien = 3 * giaGioDau + (soGio - 3) * giaGioDau * 0.7f;
    }

    if (gioBatDau >= 14 && gioBatDau <= 17) {
        giamGia = tongTien * 0.10f;
        tongTien = tongTien - giamGia;
    }

    printf("So gio: %d\n", soGio);
    printf("Tong tien thanh toan: %.2f\n", tongTien);
}
