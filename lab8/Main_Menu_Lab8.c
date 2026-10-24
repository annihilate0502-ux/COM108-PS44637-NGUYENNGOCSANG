#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SINH_VIEN 50

struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

static struct SinhVien danhSachSinhVien[MAX_SINH_VIEN];
static int soLuongSinhVien;

void nhapVaXuatDanhSachSinhVien(void);
void sapXepSinhVienTheoDiem(void);
void timKiemSinhVienTheoMSSV(void);
void xuatSinhVienNhanHocBongTheoNganh(void);
static int docDong(const char *loiNhac, char *noiDung, size_t kichThuoc);
static int docSoLuongSinhVien(int *soLuong);
static int docDiemTrungBinh(float *diem);

int main(void) {
    char dongNhap[32];
    char *ketThuc;
    long luaChon;
    int kyTu;

    do {
        printf("+------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 8      |\n");
        printf("+------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien      |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan  |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV          |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh|\n");
        printf("| 5. Thoat chuong trinh                    |\n");
        printf("+------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");

        if (fgets(dongNhap, sizeof(dongNhap), stdin) == NULL) {
            printf("\nKhong doc duoc lua chon. Ket thuc chuong trinh.\n");
            return 1;
        }

        if (strchr(dongNhap, '\n') == NULL && !feof(stdin)) {
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            luaChon = 0;
        } else {
            luaChon = strtol(dongNhap, &ketThuc, 10);
            while (*ketThuc == ' ' || *ketThuc == '\t' ||
                   *ketThuc == '\r' || *ketThuc == '\n') {
                ketThuc++;
            }
            if (ketThuc == dongNhap || *ketThuc != '\0') {
                luaChon = 0;
            }
        }

        switch (luaChon) {
            case 1:
                nhapVaXuatDanhSachSinhVien();
                break;
            case 2:
                if (soLuongSinhVien == 0) {
                    printf("Vui long nhap danh sach sinh vien truoc.\n");
                } else {
                    sapXepSinhVienTheoDiem();
                }
                break;
            case 3:
                if (soLuongSinhVien == 0) {
                    printf("Vui long nhap danh sach sinh vien truoc.\n");
                } else {
                    timKiemSinhVienTheoMSSV();
                }
                break;
            case 4:
                if (soLuongSinhVien == 0) {
                    printf("Vui long nhap danh sach sinh vien truoc.\n");
                } else {
                    xuatSinhVienNhanHocBongTheoNganh();
                }
                break;
            case 5:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon tu 1 den 5.\n");
        }
    } while (luaChon != 5);

    return 0;
}

void nhapVaXuatDanhSachSinhVien(void) {
    int i;

    if (!docSoLuongSinhVien(&soLuongSinhVien)) {
        return;
    }

    for (i = 0; i < soLuongSinhVien; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        if (!docDong("MSSV: ", danhSachSinhVien[i].mssv,
                     sizeof(danhSachSinhVien[i].mssv)) ||
            !docDong("Ten SV: ", danhSachSinhVien[i].tenSV,
                     sizeof(danhSachSinhVien[i].tenSV)) ||
            !docDong("Nganh hoc: ", danhSachSinhVien[i].nganhHoc,
                     sizeof(danhSachSinhVien[i].nganhHoc)) ||
            !docDiemTrungBinh(&danhSachSinhVien[i].diemTB)) {
            soLuongSinhVien = 0;
            return;
        }
    }

    printf("\nDanh sach sinh vien:\n");
    for (i = 0; i < soLuongSinhVien; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("MSSV: %s\n", danhSachSinhVien[i].mssv);
        printf("Ten SV: %s\n", danhSachSinhVien[i].tenSV);
        printf("Nganh hoc: %s\n", danhSachSinhVien[i].nganhHoc);
        printf("Diem TB: %.2f\n", danhSachSinhVien[i].diemTB);
    }
}

static int docDong(const char *loiNhac, char *noiDung, size_t kichThuoc) {
    int kyTu;
    size_t doDai;

    for (;;) {
        printf("%s", loiNhac);
        if (fgets(noiDung, (int)kichThuoc, stdin) == NULL) {
            printf("\nKhong doc duoc du lieu.\n");
            return 0;
        }

        doDai = strcspn(noiDung, "\r\n");
        if (noiDung[doDai] == '\0' &&
            strchr(noiDung, '\n') == NULL &&
            strchr(noiDung, '\r') == NULL && !feof(stdin)) {
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            printf("Du lieu qua dai (toi da %zu ky tu). Vui long nhap lai.\n",
                   kichThuoc - 1);
            continue;
        }
        noiDung[doDai] = '\0';
        return 1;
    }
}

static int docSoLuongSinhVien(int *soLuong) {
    char dongNhap[64];
    char *ketThuc;
    long giaTri;
    int kyTu;

    for (;;) {
        printf("Nhap so luong sinh vien (0-%d): ", MAX_SINH_VIEN);
        if (fgets(dongNhap, sizeof(dongNhap), stdin) == NULL) {
            printf("\nKhong doc duoc so luong sinh vien.\n");
            return 0;
        }
        if (strchr(dongNhap, '\n') == NULL && !feof(stdin)) {
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            printf("So luong khong hop le. Vui long nhap tu 0 den %d.\n",
                   MAX_SINH_VIEN);
            continue;
        }

        errno = 0;
        giaTri = strtol(dongNhap, &ketThuc, 10);
        while (*ketThuc == ' ' || *ketThuc == '\t' ||
               *ketThuc == '\r' || *ketThuc == '\n') {
            ketThuc++;
        }
        if (ketThuc == dongNhap || *ketThuc != '\0' || errno == ERANGE ||
            giaTri < 0 || giaTri > MAX_SINH_VIEN) {
            printf("So luong khong hop le. Vui long nhap tu 0 den %d.\n",
                   MAX_SINH_VIEN);
            continue;
        }

        *soLuong = (int)giaTri;
        return 1;
    }
}

static int docDiemTrungBinh(float *diem) {
    char dongNhap[64];
    char *ketThuc;
    float giaTri;
    int kyTu;

    for (;;) {
        printf("Diem TB (0.0-10.0): ");
        if (fgets(dongNhap, sizeof(dongNhap), stdin) == NULL) {
            printf("\nKhong doc duoc diem trung binh.\n");
            return 0;
        }
        if (strchr(dongNhap, '\n') == NULL && !feof(stdin)) {
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            printf("Diem khong hop le. Vui long nhap diem tu 0.0 den 10.0.\n");
            continue;
        }

        errno = 0;
        giaTri = strtof(dongNhap, &ketThuc);
        while (*ketThuc == ' ' || *ketThuc == '\t' ||
               *ketThuc == '\r' || *ketThuc == '\n') {
            ketThuc++;
        }
        if (ketThuc == dongNhap || *ketThuc != '\0' || errno == ERANGE ||
            !isfinite(giaTri) ||
            giaTri < 0.0f || giaTri > 10.0f) {
            printf("Diem khong hop le. Vui long nhap diem tu 0.0 den 10.0.\n");
            continue;
        }

        *diem = giaTri;
        return 1;
    }
}

void sapXepSinhVienTheoDiem(void) {
    struct SinhVien tam;
    int i;
    int j;

    for (i = 0; i < soLuongSinhVien - 1; i++) {
        for (j = 0; j < soLuongSinhVien - i - 1; j++) {
            if (danhSachSinhVien[j].diemTB >
                danhSachSinhVien[j + 1].diemTB) {
                tam = danhSachSinhVien[j];
                danhSachSinhVien[j] = danhSachSinhVien[j + 1];
                danhSachSinhVien[j + 1] = tam;
            }
        }
    }

    printf("\nDanh sach sinh vien sau khi sap xep theo diem tang dan:\n");
    for (i = 0; i < soLuongSinhVien; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("MSSV: %s\n", danhSachSinhVien[i].mssv);
        printf("Ten SV: %s\n", danhSachSinhVien[i].tenSV);
        printf("Nganh hoc: %s\n", danhSachSinhVien[i].nganhHoc);
        printf("Diem TB: %.2f\n", danhSachSinhVien[i].diemTB);
    }
}

void timKiemSinhVienTheoMSSV(void) {
    char mssvCanTim[50];
    int i;

    if (!docDong("Nhap MSSV can tim: ", mssvCanTim, sizeof(mssvCanTim))) {
        return;
    }

    for (i = 0; i < soLuongSinhVien; i++) {
        if (strcmp(danhSachSinhVien[i].mssv, mssvCanTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", danhSachSinhVien[i].mssv);
            printf("Ten SV: %s\n", danhSachSinhVien[i].tenSV);
            printf("Nganh hoc: %s\n", danhSachSinhVien[i].nganhHoc);
            printf("Diem TB: %.2f\n", danhSachSinhVien[i].diemTB);
            return;
        }
    }

    printf("Khong tim thay sinh vien co MSSV: %s\n", mssvCanTim);
}

void xuatSinhVienNhanHocBongTheoNganh(void) {
    int i;
    int j;
    int coHocBong = 0;

    for (i = 0; i < soLuongSinhVien; i++) {
        int daInNganh = 0;

        if (danhSachSinhVien[i].diemTB < 8.0f) {
            continue;
        }

        for (j = 0; j < i; j++) {
            if (danhSachSinhVien[j].diemTB >= 8.0f &&
                strcmp(danhSachSinhVien[j].nganhHoc,
                       danhSachSinhVien[i].nganhHoc) == 0) {
                daInNganh = 1;
                break;
            }
        }
        if (daInNganh) {
            continue;
        }

        coHocBong = 1;
        printf("\nNganh: %s\n", danhSachSinhVien[i].nganhHoc);
        for (j = i; j < soLuongSinhVien; j++) {
            if (danhSachSinhVien[j].diemTB >= 8.0f &&
                strcmp(danhSachSinhVien[j].nganhHoc,
                       danhSachSinhVien[i].nganhHoc) == 0) {
                printf("- [%s] - [%s] - Diem TB: %.2f\n",
                       danhSachSinhVien[j].mssv,
                       danhSachSinhVien[j].tenSV,
                       danhSachSinhVien[j].diemTB);
            }
        }
    }

    if (!coHocBong) {
        printf("Khong co sinh vien nao dat hoc bong.\n");
    }
}