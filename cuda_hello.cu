#include <iostream>
#include "book.h"

__global__ void kernel (void) {
}

__global__ void adder(int a, int b, int *c) {
    *c = a + b;
}

int main ( void ) {
    kernel<<<1,1>>>();
    printf("Hello World!\n");
    
    int c;
    int *dev_c;
    
    HANDLE_ERROR(cudaMalloc((void**) &dev_c, sizeof(int) ));
    
    adder<<<1,1>>>(2, 7, dev_c);
    
    HANDLE_ERROR(cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost ));
    
    printf("2 + 7 = %d\n", c);
    
    cudaFree(dev_c);
    
    return 0;
}