#include <stdio.h>
void menu();

int main(){
    int chon;
    do{
        menu();
        printf("Chon chuc nang: ");
        scanf("%d",&chon);
        switch (chon)
        {
        case 0:
            /* code */
            printf("Tam biet\n");
            break;
        case 1:
            /* code */
            printf("Ban vua chon chuc nang 1\n");
            break;
        case 2:
            /* code */
            printf("Ban vua chon chuc nang 2\n");
            break;
        case 3:
            /* code */
            printf("Ban vua chon chuc nang 3\n");
            break;
        default:
            printf("Chuc nang nay chua co\n");
            break;
        }
    }while(chon !=0 );
    
    return 0;
}

void menu(){
    printf("Menu\n");
    printf("Chức năng 1\n");
    printf("Chức năng 2\n");
    printf("Chức năng 3\n");
}