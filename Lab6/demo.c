#include <stdio.h>
#include <string.h>
#include <time.h>

void removeArray(char * dsTen[],int index, int* size){
    for(int i = index; i < *size; i++){
        dsTen[i] = dsTen[i+1];
    }
    *size -= 1;
}

int main(){
    int size = 20;
    const char* dsTen[20] = {
    "An", "Hung", "Minh", "Sang", "Binh",
    "Cuong", "Dung", "Giang", "Hanh", "Khoa",
    "Lan", "Nam", "Phong", "Quan", "Son",
    "Thao", "Trang", "Tuan", "Viet", "Yen"};

    for(int i=0;i<size;i++){
        // if(i%4 == 0)
            printf("%8s ",dsTen[i]);
    }

    for(int i=0;i<5;i++){
        int index = (int)rand()%size;
        printf("%d\t%8s\n",index,dsTen[index]);
        removeArray(dsTen,index,&size);
    }
    
    // printf("\n");
    // for(int i=0;i<size;i++){
    //     // if(i%4 == 0)
    //         printf("%8s ",dsTen[i]);
    // }

    // for(int i=0;i<20;i++){
    //     if(i%4 == 0)
    //         printf("%7s \t",dsTen[i]);
    // }
    // printf("\n");
    // for(int i=0;i<20;i++){
    //     if(i%4 == 1)
    //         printf("%7s \t",dsTen[i]);
    // }
    // printf("\n");
    // for(int i=0;i<20;i++){
    //     if(i%4 == 2)
    //         printf("%7s \t",dsTen[i]);
    // }
    // printf("\n");
    // for(int i=0;i<20;i++){
    //     if(i%4 == 3)
    //         printf("%7s \t",dsTen[i]);
    // }
}