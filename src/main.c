#include <stdio.h>
#include <opencryptoki/pkcs11.h>
#include <errno.h>

int main(int argc, char **argv){

    CK_RV C_Initialize(CK_VOID_PTR pInitArgs);
    
    printf("Criptoki ok\n");
    return 0;
}

