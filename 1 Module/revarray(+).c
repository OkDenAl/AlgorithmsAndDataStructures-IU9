#include <stdio.h>
#pragma warning (disable: 4996)



void revarray(void* base, size_t nel, size_t width)
{
    unsigned char temp = '0';

    for (size_t i = 0; i < nel / 2; i++)
    {
        for (size_t j=0;j<width;j++){

        temp = *((unsigned char*)base + i*width + j);
        *((unsigned char*)base+i*width +j) = *((unsigned char*)base + (nel - i - 1) * width+j);
        *((unsigned char*)base + (nel - i - 1) * width+j) = temp;

        }
    }
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[5] = { 400, 450, 570, 600, 890 };
    print_array(arr, 5);
    revarray(arr, 5, sizeof(int));
    print_array(arr, 5);

}
