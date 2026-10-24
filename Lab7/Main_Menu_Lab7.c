#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void demNguyenAmVaPhuAm(void);
void dangNhap(void);
void sapXepChuoi(void);
void doiThapPhanSangThapLucPhan(void);

static int docKyTuAn(void);

int main(void) {
    char dongNhap[64];
    char *ketThuc;
    long luaChon;
    int kyTu;

    do {
        printf("+------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 7      |\n");
        printf("+------------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi     |\n");
        printf("| 2. Dang nhap bang Username va Password   |\n");
        printf("| 3. Sap xep chuoi theo chu cai            |\n");
        printf("| 4. Doi so thap phan sang thap luc phan   |\n");
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
            while (isspace((unsigned char)*ketThuc)) {
                ketThuc++;
            }
            if (ketThuc == dongNhap || *ketThuc != '\0') {
                luaChon = 0;
            }
        }

        switch (luaChon) {
            case 1:
                demNguyenAmVaPhuAm();
                break;
            case 2:
                dangNhap();
                break;
            case 3:
                sapXepChuoi();
                break;
            case 4:
                doiThapPhanSangThapLucPhan();
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

void demNguyenAmVaPhuAm(void) {
    char chuoi[256];
    int nguyenAm = 0;
    int phuAm = 0;
    int kyTu;
    size_t i;

    printf("Nhap chuoi: ");
    if (fgets(chuoi, sizeof(chuoi), stdin) == NULL) {
        printf("Khong doc duoc chuoi.\n");
        return;
    }

    if (strchr(chuoi, '\n') == NULL && !feof(stdin)) {
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        printf("Chuoi qua dai (toi da %zu ky tu). Vui long thu lai.\n",
               sizeof(chuoi) - 1);
        return;
    }
    chuoi[strcspn(chuoi, "\n")] = '\0';

    for (i = 0; chuoi[i] != '\0'; i++) {
        unsigned char kyTuChuoi = (unsigned char)chuoi[i];

        if ((kyTuChuoi >= 'a' && kyTuChuoi <= 'z') ||
            (kyTuChuoi >= 'A' && kyTuChuoi <= 'Z')) {
            int kyTuThuong = tolower(kyTuChuoi);

            if (kyTuThuong == 'a' || kyTuThuong == 'e' ||
                kyTuThuong == 'i' || kyTuThuong == 'o' ||
                kyTuThuong == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n",
           chuoi, nguyenAm, phuAm);
}

static int docKyTuAn(void) {
#ifdef _WIN32
    int kyTu = _getch();

    if (kyTu == 0 || kyTu == 224) {
        (void)_getch();
        return 0;
    }
    return kyTu;
#else
    struct termios cauHinhCu;
    struct termios cauHinhMoi;
    int kyTu;

    if (tcgetattr(STDIN_FILENO, &cauHinhCu) == -1) {
        return EOF;
    }

    cauHinhMoi = cauHinhCu;
    cauHinhMoi.c_lflag &= (tcflag_t)~(ICANON | ECHO);
    cauHinhMoi.c_cc[VMIN] = 1;
    cauHinhMoi.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &cauHinhMoi) == -1) {
        return EOF;
    }

    kyTu = getchar();
    if (tcsetattr(STDIN_FILENO, TCSANOW, &cauHinhCu) == -1) {
        return EOF;
    }
    return kyTu;
#endif
}

void dangNhap(void) {
    const char tenTaiKhoanDung[] = "admin";
    const char matKhauDung[] = "12345";
    char tenTaiKhoan[64];
    char matKhau[64];
    size_t doDaiMatKhau = 0;
    int kyTu;

    printf("Username: ");
    if (fgets(tenTaiKhoan, sizeof(tenTaiKhoan), stdin) == NULL) {
        printf("Khong doc duoc username.\n");
        return;
    }
    if (strchr(tenTaiKhoan, '\n') == NULL && !feof(stdin)) {
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        printf("Username qua dai.\n");
        return;
    }
    tenTaiKhoan[strcspn(tenTaiKhoan, "\n")] = '\0';

    printf("Password: ");
    fflush(stdout);
    while ((kyTu = docKyTuAn()) != EOF && kyTu != '\n' && kyTu != '\r') {
        if ((kyTu == '\b' || kyTu == 127) && doDaiMatKhau > 0) {
            doDaiMatKhau--;
            printf("\b \b");
        } else if (kyTu >= 32 && kyTu <= 126 &&
                   doDaiMatKhau < sizeof(matKhau) - 1) {
            matKhau[doDaiMatKhau++] = (char)kyTu;
            putchar('*');
        }
        fflush(stdout);
    }
    matKhau[doDaiMatKhau] = '\0';
    printf("\n");

    if (kyTu == EOF) {
        printf("Khong doc duoc password.\n");
        return;
    }

    if (strcmp(tenTaiKhoan, tenTaiKhoanDung) == 0 &&
        strcmp(matKhau, matKhauDung) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

void sapXepChuoi(void) {
    char chuoi[5][20];
    char tam[20];
    int i;
    int j;
    int kyTu;

    for (i = 0; i < 5; i++) {
        printf("Nhap chuoi thu %d: ", i + 1);
        if (fgets(chuoi[i], sizeof(chuoi[i]), stdin) == NULL) {
            printf("Khong doc duoc chuoi.\n");
            return;
        }
        if (strchr(chuoi[i], '\n') == NULL && !feof(stdin)) {
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            printf("Chuoi qua dai (toi da %zu ky tu). Vui long chay lai chuc nang.\n",
                   sizeof(chuoi[i]) - 1);
            return;
        }
        chuoi[i][strcspn(chuoi[i], "\n")] = '\0';
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(chuoi[i], chuoi[j]) > 0) {
                strcpy(tam, chuoi[i]);
                strcpy(chuoi[i], chuoi[j]);
                strcpy(chuoi[j], tam);
            }
        }
    }

    printf("Cac chuoi sau khi sap xep:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", chuoi[i]);
    }
}

void doiThapPhanSangThapLucPhan(void) {
    char dongNhap[128];
    char *batDau;
    char *ketThuc;
    char chuoiHex[sizeof(unsigned long) * 2 + 1];
    unsigned long giaTri;
    size_t doDai = 0;
    size_t i;
    int kyTu;

    printf("Nhap so thap phan khong am: ");
    if (fgets(dongNhap, sizeof(dongNhap), stdin) == NULL) {
        printf("Khong doc duoc so.\n");
        return;
    }
    if (strchr(dongNhap, '\n') == NULL && !feof(stdin)) {
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        printf("So nhap vao khong hop le!\n");
        return;
    }
    dongNhap[strcspn(dongNhap, "\r\n")] = '\0';

    batDau = dongNhap;
    while (isspace((unsigned char)*batDau)) {
        batDau++;
    }
    if (*batDau == '-') {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    errno = 0;
    giaTri = strtoul(batDau, &ketThuc, 10);
    while (isspace((unsigned char)*ketThuc)) {
        ketThuc++;
    }
    if (batDau == ketThuc || *ketThuc != '\0' || errno == ERANGE) {
        printf("So nhap vao khong hop le!\n");
        return;
    }
    *ketThuc = '\0';

    do {
        unsigned int chuSo = (unsigned int)(giaTri % 16);
        chuoiHex[doDai++] = (char)(chuSo < 10 ? '0' + chuSo : 'A' + chuSo - 10);
        giaTri /= 16;
    } while (giaTri > 0);
    chuoiHex[doDai] = '\0';

    for (i = 0; i < doDai / 2; i++) {
        char tam = chuoiHex[i];
        chuoiHex[i] = chuoiHex[doDai - i - 1];
        chuoiHex[doDai - i - 1] = tam;
    }

    printf("So thap luc phan cua %s la: %s\n", batDau, chuoiHex);
}