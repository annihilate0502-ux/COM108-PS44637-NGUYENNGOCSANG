#include <stdio.h>
#include <math.h>

void tinhHocLuc() {
    float diem;

    printf("Nhap diem so cua sinh vien (0.0 den 10.0): ");
    scanf("%f", &diem);

    if (diem < 0.0 || diem > 10.0) {
        printf("Diem khong hop le. Vui long nhap trong khoang 0.0 den 10.0.\n");
    } else if (diem >= 9.0) {
        printf("Hoc luc: Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Hoc luc: Gioi\n");
    } else if (diem >= 6.5) {
        printf("Hoc luc: Kha\n");
    } else if (diem >= 5.0) {
        printf("Hoc luc: Trung binh\n");
    } else if (diem >= 3.5) {
        printf("Hoc luc: Yeu\n");
    } else {
        printf("Hoc luc: Kem\n");
    }
}

void giaiPTBacHai() {
    float a, b, c;
    float delta, x1, x2;

    printf("Nhap he so a: ");
    scanf("%f", &a);
    printf("Nhap he so b: ");
    scanf("%f", &b);
    printf("Nhap he so c: ");
    scanf("%f", &c);

    if (a == 0) {
        if (b == 0 && c == 0) {
            printf("Phuong trinh vo so nghiem.\n");
        } else if (b == 0 && c != 0) {
            printf("Phuong trinh vo nghiem.\n");
        } else {
            x1 = -c / b;
            printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", x1);
        }
    } else {
        delta = b * b - 4 * a * c;

        if (delta < 0) {
            printf("Phuong trinh vo nghiem.\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
    }
}

void tinhTienDien() {
    float soKwh;
    float tongTien = 0;

    printf("Nhap so kWh dien tieu thu trong thang: ");
    scanf("%f", &soKwh);

    if (soKwh < 0) {
        printf("So kWh khong hop le. Vui long nhap so duong.\n");
        return;
    }

    if (soKwh <= 50) {
        tongTien = soKwh * 1.678;
    } else if (soKwh <= 100) {
        tongTien = 50 * 1.678 + (soKwh - 50) * 1.734;
    } else if (soKwh <= 200) {
        tongTien = 50 * 1.678 + 50 * 1.734 + (soKwh - 100) * 2.014;
    } else if (soKwh <= 300) {
        tongTien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (soKwh - 200) * 2.536;
    } else if (soKwh <= 400) {
        tongTien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (soKwh - 300) * 2.834;
    } else {
        tongTien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (soKwh - 400) * 2.927;
    }

    printf("Tong tien dien phai tra: %.2f\n", tongTien);
}

int main() {
	int luaChon;

	do {
		printf("\n===== MENU LAB 3 =====\n");
		printf("1. Tinh hoc luc\n");
		printf("2. Giai phuong trinh bac hai\n");
		printf("3. Tinh tien dien\n");
		printf("0. Thoat\n");
		printf("Moi ban chon: ");
		scanf("%d", &luaChon);

		switch (luaChon) {
			case 1:
				tinhHocLuc();
				break;
			case 2:
				giaiPTBacHai();
				break;
			case 3:
				tinhTienDien();
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