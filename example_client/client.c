#include <stdio.h>
#include "../include/dffos.h"

int main(){
    printf("Total RAM size:%luMB\nfree RAM size:%luMB\n", get_total_ram(2), get_free_ram(2));
    printf("Total Drive size::%lluMB\nfree drive size:%lluMB\n",get_total_storage_memory(2), get_free_storage_memory(2));
    getchar();
    return 0;
}