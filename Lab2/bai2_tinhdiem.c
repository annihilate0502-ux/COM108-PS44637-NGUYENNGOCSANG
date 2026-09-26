#include <stdio.h>

int main() {
	float diemToan, diemAnh, diemVan;
	float diemTrungBinh;

	printf("Nhap diem Toan: ");
	scanf("%f", &diemToan);

	printf("Nhap diem Anh: ");
	scanf("%f", &diemAnh);

	printf("Nhap diem Van: ");
	scanf("%f", &diemVan);

	diemTrungBinh = (diemToan * 2 + diemAnh + diemVan) / 4;

	printf("Diem trung binh: %.2f\n", diemTrungBinh);

	return 0;
}
