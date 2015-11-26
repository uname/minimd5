#include "md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    size_t size = 0;
    unsigned long magic = 0;
    unsigned char buff[1024];
    unsigned char digest[16];
    
    MD5_CTX md5Ctx;
    FILE *fp;
    
    if(argc < 2) {
        printf("Usage: minimd5 file\n");
        return -1;
    }
    
    if((fp = fopen(argv[1], "rb")) == NULL) {
        printf("open file error\n");
        return -2;
    }
    
    MD5Init(&md5Ctx);
    while((size = fread(buff, 1, sizeof(buff) , fp)) > 0) {
        MD5Update(&md5Ctx, buff, size);
    }
    
    MD5Final(digest, &md5Ctx);
    
    for(i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
#ifdef GEN_MAGIC_NUM
        if(i < 4) {
            magic += digest[i] << (24 - 8 * i);
        }
#endif
    }
    printf(" *%s\n", argv[1]);

#ifdef GEN_MAGIC_NUM
    printf("magic = %lu\n", magic);
#endif

    return 0;
}
