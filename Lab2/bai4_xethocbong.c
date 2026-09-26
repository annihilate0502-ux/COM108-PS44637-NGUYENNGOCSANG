#include <stdio.h>

int main() {
	float diemTrungBinh;
	int hanhKiem;
	int dieuKienDiem;
	int dieuKienHanhKiem;
	int ketQua;

	printf("Nhap diem trung binh: ");
	scanf("%f", &diemTrungBinh);

	printf("Nhap hanh kiem (1 - Tot, 0 - Khac): ");
	scanf("%d", &hanhKiem);

	dieuKienDiem = diemTrungBinh >= 8;
	dieuKienHanhKiem = hanhKiem == 1;
	ketQua = dieuKienDiem && dieuKienHanhKiem;

	printf("Dieu kien diem trung binh >= 8: %d\n", dieuKienDiem);
	printf("Dieu kien hanh kiem tot: %d\n", dieuKienHanhKiem);
	printf("Ket qua xet hoc bong (1: Dat, 0: Khong dat): %d\n", ketQua);

	return 0;
}