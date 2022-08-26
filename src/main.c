/**
 * @file main.c
 * @author Leandro Assis dos Santos (assissantosleandro@gmail.com)
 * @brief An password generator to manage my personal passwords
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <opencryptoki/pkcs11.h>
#include <errno.h>

#include "console_parser.h"
#include "types.h"

int main(int argc, char **argv){
    
    bool CONSOLE_ON = false, AUTO_CONFIRM = false;
    char username[MAX_USERNAME_SIZE] = {0}, keyname[MAX_KEYNAME_SIZE] = {0};
    unsigned short keysize;
    op oper;
    rTypes nRet;

    if(argc == 1) CONSOLE_ON = true;
    
    nRet = ParseConsoleCall(argc, argv, &CONSOLE_ON, &AUTO_CONFIRM, &keyname, &username, &keysize, &oper);
    if(nRet != 0){
        printf("An error %d ocurred during ParseConsoleCall execution.\n", nRet);
        exit(nRet);
    }

    return 0;
}

