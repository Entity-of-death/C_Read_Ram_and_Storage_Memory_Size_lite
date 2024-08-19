#include <stdio.h>
#include "../include/dffos.h"

int main(){
    printf("Total RAM size:%luGB\nfree RAM size:%luGB\n", get_total_ram(3), get_free_ram(3));
    printf("Total Drive size::%lluGB\nfree drive size:%lluGB\n",get_total_storage_memory(3), get_free_storage_memory(3));
    getchar();
    return 0;
}