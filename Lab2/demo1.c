#include<stdio.h>
#define PI 3.14159
int main() {
    const float PII = 3.14159;
    float r = 5.5, cv1, cv2, dt;
    cv1 = 2 * PI * r;
    cv2 = 2 * PII * r;
    printf("Chu vi hinh tron (dung PI): %.2f\n", cv1);
    printf("Chu vi hinh tron (dung PII): %.2f\n", cv2);
    return 0;
}