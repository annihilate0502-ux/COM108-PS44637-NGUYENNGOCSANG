#include <stdio.h>
#include <string.h>

typedef struct {
    char maSanPham[21];
    char tenSanPham[51];
    float donGia;
    int soLuong;
} SanPham;

int docDong(char *chuoi, int kichThuoc) {
    if (fgets(chuoi, kichThuoc, stdin) == NULL) {
        return 0;
    }

    char *xuongDong = strchr(chuoi, '\n');
    if (xuongDong != NULL) {
        *xuongDong = '\0';
        return 1;
    }

    int kyTu = getchar();
    if (kyTu == '\n' || kyTu == EOF) {
        return 1;
    }

    while (kyTu != '\n' && kyTu != EOF) {
        kyTu = getchar();
    }
    return 0;
}

int main() {
    SanPham danhSach[3];
    char dongNhap[100];
    char kyTuThua;

    for (int i = 0; i < 3; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);

        printf("Ma san pham (toi da 20 ky tu): ");
        if (!docDong(danhSach[i].maSanPham, sizeof(danhSach[i].maSanPham))) {
            printf("Ma san pham qua dai hoac khong hop le.\n");
            return 1;
        }

        printf("Ten san pham (toi da 50 ky tu): ");
        if (!docDong(danhSach[i].tenSanPham, sizeof(danhSach[i].tenSanPham))) {
            printf("Ten san pham qua dai hoac khong hop le.\n");
            return 1;
        }

        printf("Don gia: ");
        if (!docDong(dongNhap, sizeof(dongNhap)) ||
            sscanf(dongNhap, " %f %c", &danhSach[i].donGia, &kyTuThua) != 1) {
            printf("Don gia khong hop le.\n");
            return 1;
        }

        printf("So luong: ");
        if (!docDong(dongNhap, sizeof(dongNhap)) ||
            sscanf(dongNhap, " %d %c", &danhSach[i].soLuong, &kyTuThua) != 1) {
            printf("So luong khong hop le.\n");
            return 1;
        }
    }

    printf("\nDanh sach 3 san pham:\n");
    printf("%-22s %-52s %-12s %-10s\n",
           "Ma san pham", "Ten san pham", "Don gia", "So luong");
    for (int i = 0; i < 3; i++) {
        printf("%-22s %-52s %-12.2f %-10d\n",
               danhSach[i].maSanPham,
               danhSach[i].tenSanPham,
               danhSach[i].donGia,
               danhSach[i].soLuong);
    }

    double tongThanhTien = 0;
    int viTriNhoNhat = 0;
    double thanhTienNhoNhat =
        (double)danhSach[0].donGia * danhSach[0].soLuong;

    for (int i = 0; i < 3; i++) {
        double thanhTien = (double)danhSach[i].donGia * danhSach[i].soLuong;
        tongThanhTien += thanhTien;

        if (thanhTien < thanhTienNhoNhat) {
            thanhTienNhoNhat = thanhTien;
            viTriNhoNhat = i;
        }
    }

    printf("\nTong thanh tien cua 3 san pham: %.2f\n", tongThanhTien);
    printf("San pham co thanh tien nho nhat:\n");
    printf("Ma san pham: %s\n", danhSach[viTriNhoNhat].maSanPham);
    printf("Ten san pham: %s\n", danhSach[viTriNhoNhat].tenSanPham);
    printf("Don gia: %.2f\n", danhSach[viTriNhoNhat].donGia);
    printf("So luong: %d\n", danhSach[viTriNhoNhat].soLuong);
    printf("Thanh tien: %.2f\n", thanhTienNhoNhat);

    return 0;
}