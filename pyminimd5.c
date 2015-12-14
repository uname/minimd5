#include "md5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *md5sum(const char *const file)
{
    int i;
    size_t size = 0;
    unsigned char buff[1024];
    unsigned char digest[16];
	static char hex_digest[33];
    
    MD5_CTX md5Ctx;
    FILE *fp;
    
    if(file == NULL || (fp = fopen(file, "rb")) == NULL) {
        printf("open file error\n");
        return NULL;
    }
    
    MD5Init(&md5Ctx);
    while((size = fread(buff, 1, sizeof(buff) , fp)) > 0) {
        MD5Update(&md5Ctx, buff, size);
    }
    
    MD5Final(digest, &md5Ctx);
    
    for(i = 0; i < 16; i++) {
        snprintf(&hex_digest[i * 2], sizeof(hex_digest), "%02x", digest[i]);
    }
	hex_digest[32] = '\0';

    return hex_digest;
}

