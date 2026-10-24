#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define SCAN_LLONG "%I64d"
#define PRINT_LLONG "%I64d"
#else
#define SCAN_LLONG "%lld"
#define PRINT_LLONG "%lld"
#endif

void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();
static long long uclnPhanSo(long long a, long long b);
static void inPhanSo(long long tu, long long mau);

struct SinhVien {
    char hoTen[100];
    float diem;
};

int main() {
    int chon;
    srand((unsigned int)time(NULL));

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
            case 4:
                chucNang4();
                break;
            case 5:
                chucNang5();
                break;
            case 6:
                chucNang6();
                break;
            case 7:
                chucNang7();
                break;
            case 8:
                chucNang8();
                break;
            case 9:
                chucNang9();
                break;
            case 10:
                chucNang10();
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
    printf("\n+------------------------------------------------------+\n");
    printf("|                 MENU CHUONG TRINH ASM                |\n");
    printf("+------------------------------------------------------+\n");
    printf("|  1. Kiem tra so nguyen                               |\n");
    printf("|  2. Tim UCLN va BCNN                                 |\n");
    printf("|  3. Tinh tien Karaoke                                |\n");
    printf("|  4. Tinh tien dien                                   |\n");
    printf("|  5. Doi tien                                         |\n");
    printf("|  6. Lai suat vay tra gop 12 thang                    |\n");
    printf("|  7. Vay tien mua xe                                  |\n");
    printf("|  8. Sap xep thong tin sinh vien                      |\n");
    printf("|  9. Game FPOLY-LOTT (2/15)                           |\n");
    printf("| 10. Tinh toan phan so                                |\n");
    printf("|  0. Thoat                                            |\n");
    printf("+------------------------------------------------------+\n");
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

void chucNang4() {
    double soKwh;
    double tongTien;

    printf("Nhap so kWh dien su dung: ");
    if (scanf("%lf", &soKwh) != 1 || !isfinite(soKwh) || soKwh < 0.0) {
        printf("So kWh khong hop le.\n");
        return;
    }

    if (soKwh <= 50.0) {
        tongTien = soKwh * 1678.0;
    } else if (soKwh <= 100.0) {
        tongTien = 50.0 * 1678.0 + (soKwh - 50.0) * 1734.0;
    } else if (soKwh <= 200.0) {
        tongTien = 50.0 * 1678.0 + 50.0 * 1734.0 +
                   (soKwh - 100.0) * 2014.0;
    } else if (soKwh <= 300.0) {
        tongTien = 50.0 * 1678.0 + 50.0 * 1734.0 + 100.0 * 2014.0 +
                   (soKwh - 200.0) * 2536.0;
    } else if (soKwh <= 400.0) {
        tongTien = 50.0 * 1678.0 + 50.0 * 1734.0 + 100.0 * 2014.0 +
                   100.0 * 2536.0 + (soKwh - 300.0) * 2834.0;
    } else {
        tongTien = 50.0 * 1678.0 + 50.0 * 1734.0 + 100.0 * 2014.0 +
                   100.0 * 2536.0 + 100.0 * 2834.0 +
                   (soKwh - 400.0) * 2927.0;
    }

    printf("So tien dien can thanh toan: %.0f dong\n", tongTien);
}

void chucNang5() {
    const int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    const int soMenhGia = (int)(sizeof(menhGia) / sizeof(menhGia[0]));
    int soTien;
    int i;

    printf("Nhap so tien can doi: ");
    if (scanf("%d", &soTien) != 1 || soTien < 0) {
        printf("So tien khong hop le.\n");
        return;
    }

    printf("Ket qua doi tien:\n");
    for (i = 0; i < soMenhGia; i++) {
        int soTo = soTien / menhGia[i];
        if (soTo > 0) {
            printf("%d to menh gia %d\n", soTo, menhGia[i]);
            soTien %= menhGia[i];
        }
    }
}

void chucNang6() {
    double tienVay;
    double duNo;
    double gocHangThang;
    int thang;

    printf("Nhap so tien muon vay: ");
    if (scanf("%lf", &tienVay) != 1 ||
        !isfinite(tienVay) || tienVay <= 0.0) {
        printf("So tien vay khong hop le.\n");
        return;
    }

    duNo = tienVay;
    gocHangThang = tienVay / 12.0;
    printf("\nKy han | Lai phai tra | Goc phai tra | So tien phai tra | So tien con lai\n");
    for (thang = 1; thang <= 12; thang++) {
        double goc = thang == 12 ? duNo : gocHangThang;
        double lai = duNo * 0.05;
        double tongTra = goc + lai;
        duNo -= goc;
        printf("%6d | %12.0f | %12.0f | %16.0f | %15.0f\n",
               thang, lai, goc, tongTra, duNo);
    }
}

void chucNang7() {
    const double giaXe = 500000000.0;
    const int soThangVay = 24 * 12;
    double phanTramVay;
    double tienVay;
    double tienTraTruoc;
    double duNo;
    double gocHangThang;
    int thang;

    printf("Nhap phan tram gia tri xe muon vay (1-100): ");
    if (scanf("%lf", &phanTramVay) != 1 || !isfinite(phanTramVay) ||
        phanTramVay < 1.0 || phanTramVay > 100.0) {
        printf("Phan tram vay khong hop le.\n");
        return;
    }

    tienVay = giaXe * phanTramVay / 100.0;
    tienTraTruoc = giaXe - tienVay;
    duNo = tienVay;
    gocHangThang = tienVay / soThangVay;

    printf("Gia tri xe: %.0f dong\n", giaXe);
    printf("So tien vay: %.0f dong\n", tienVay);
    printf("So tien tra truoc: %.0f dong\n", tienTraTruoc);
    printf("Lai suat: 7.2%%/nam; ky han: 24 nam (%d thang)\n", soThangVay);
    printf("\nThang | Goc phai tra | Lai phai tra | Tong thanh toan | Du no con lai\n");

    for (thang = 1; thang <= soThangVay; thang++) {
        double goc = thang == soThangVay ? duNo : gocHangThang;
        double lai = duNo * 0.072 / 12.0;
        double tongTra = goc + lai;
        duNo -= goc;
        printf("%5d | %12.0f | %12.0f | %15.0f | %13.0f\n",
               thang, goc, lai, tongTra, duNo);
    }
}

void chucNang8() {
    struct SinhVien danhSach[50];
    struct SinhVien tam;
    int soLuong;
    int i;
    int j;

    printf("Nhap so luong sinh vien (1-50): ");
    if (scanf("%d", &soLuong) != 1 || soLuong < 1 || soLuong > 50) {
        printf("So luong sinh vien khong hop le.\n");
        return;
    }

    for (i = 0; i < soLuong; i++) {
        printf("Nhap ho ten sinh vien thu %d: ", i + 1);
        if (scanf(" %99[^\n]", danhSach[i].hoTen) != 1) {
            printf("Khong doc duoc ho ten sinh vien.\n");
            return;
        }
        printf("Nhap diem sinh vien thu %d (0-10): ", i + 1);
        if (scanf("%f", &danhSach[i].diem) != 1 ||
            !isfinite(danhSach[i].diem) ||
            danhSach[i].diem < 0.0f || danhSach[i].diem > 10.0f) {
            printf("Diem khong hop le.\n");
            return;
        }
    }

    for (i = 0; i < soLuong - 1; i++) {
        for (j = 0; j < soLuong - i - 1; j++) {
            if (danhSach[j].diem < danhSach[j + 1].diem) {
                tam = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = tam;
            }
        }
    }

    printf("\nDanh sach sinh vien theo diem giam dan:\n");
    for (i = 0; i < soLuong; i++) {
        const char *hocLuc;
        if (danhSach[i].diem >= 9.0f) {
            hocLuc = "Xuat sac";
        } else if (danhSach[i].diem >= 8.0f) {
            hocLuc = "Gioi";
        } else if (danhSach[i].diem >= 6.5f) {
            hocLuc = "Kha";
        } else if (danhSach[i].diem >= 5.0f) {
            hocLuc = "Trung binh";
        } else {
            hocLuc = "Yeu";
        }
        printf("%s - Diem: %.2f - Hoc luc: %s\n",
               danhSach[i].hoTen, danhSach[i].diem, hocLuc);
    }
}

void chucNang9() {
    int so1;
    int so2;
    int ketQua1;
    int ketQua2;
    int soTrung;

    printf("Nhap 2 so khac nhau tu 01 den 15: ");
    if (scanf("%d %d", &so1, &so2) != 2 ||
        so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15 || so1 == so2) {
        printf("Vui long nhap hai so khac nhau trong khoang 01-15.\n");
        return;
    }

    ketQua1 = rand() % 15 + 1;
    do {
        ketQua2 = rand() % 15 + 1;
    } while (ketQua2 == ketQua1);

    printf("Hai so trung thuong: %02d va %02d\n", ketQua1, ketQua2);
    soTrung = (so1 == ketQua1 || so1 == ketQua2) +
              (so2 == ketQua1 || so2 == ketQua2);

    if (soTrung == 2) {
        printf("Chuc mung ban da trung giai nhat!\n");
    } else if (soTrung == 1) {
        printf("Chuc mung ban da trung giai nhi!\n");
    } else {
        printf("Chuc ban may man lan sau.\n");
    }
}

static long long uclnPhanSo(long long a, long long b) {
    long long tam;

    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (b != 0) {
        tam = a % b;
        a = b;
        b = tam;
    }
    return a == 0 ? 1 : a;
}

static void inPhanSo(long long tu, long long mau) {
    long long ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    ucln = uclnPhanSo(tu, mau);
    tu /= ucln;
    mau /= ucln;
    if (mau == 1) {
        printf(PRINT_LLONG, tu);
    } else {
        printf(PRINT_LLONG "/" PRINT_LLONG, tu, mau);
    }
}

void chucNang10() {
    long long tu1;
    long long mau1;
    long long tu2;
    long long mau2;

    printf("Nhap phan so thu nhat (tu so mau so): ");
    if (scanf(SCAN_LLONG " " SCAN_LLONG, &tu1, &mau1) != 2 || mau1 == 0) {
        printf("Phan so khong hop le (mau so phai khac 0).\n");
        return;
    }
    printf("Nhap phan so thu hai (tu so mau so): ");
    if (scanf(SCAN_LLONG " " SCAN_LLONG, &tu2, &mau2) != 2 || mau2 == 0) {
        printf("Phan so khong hop le (mau so phai khac 0).\n");
        return;
    }

    printf("Tong: ");
    inPhanSo(tu1 * mau2 + tu2 * mau1, mau1 * mau2);
    printf("\nHieu: ");
    inPhanSo(tu1 * mau2 - tu2 * mau1, mau1 * mau2);
    printf("\nTich: ");
    inPhanSo(tu1 * tu2, mau1 * mau2);
    printf("\nThuong: ");
    if (tu2 == 0) {
        printf("Khong the chia cho 0");
    } else {
        inPhanSo(tu1 * mau2, mau1 * tu2);
    }
    printf("\n");
}
