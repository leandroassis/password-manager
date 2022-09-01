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
#include <openssl/rsa.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#include "console_parser.h"
#include "types.h"

void sigint_handler(int signum){
    signal(SIGINT, sigint_handler);
    printf("Encerrando o programa.\n");
    fflush(stdout);
    // destroi chaves
    // limpa memoria
    // sai
}

int main(int argc, char **argv){
    
    bool CONSOLE_ON = false, AUTO_CONFIRM = false;
    char opt;
    char username[MAX_USERNAME_SIZE] = {0}, passname[MAX_KEYNAME_SIZE] = {0};
    char user_password[8] = {0};
    unsigned short passsize;
    op oper;
    rTypes nRet;

    if(argc == 1) CONSOLE_ON = true;
    
    nRet = ParseConsoleCall(argc, argv, &CONSOLE_ON, &AUTO_CONFIRM, &passname, &username, &passsize, &oper);
    if(nRet != 0){
        printf("An error %d ocurred during ParseConsoleCall execution.\n", nRet);
        exit(nRet);
    }

    // show app name and info
    while(1){
        if(CONSOLE_ON){
            if(username[0] == 0){
                printf("Select an option:\n\
                        a - Log In\n\
                        b - Create new user\n\
                        Option: ");
                
                if(!fgets(opt, 1, stdin)){
                    prinf("Error: Not a valid option.\n");
                    exit(INVALID_OPTION);
                }

                switch(opt){
                    case 'a':
                        nRet = LogIn(&username, &user_password);
                        if(nRet){
                            printf("Error: LogIn fuction returned %d", nRet);
                            exit(nRet);
                        }
                        //goto task;
                        break;
                    case 'b':
                        nRet = CreateNewUser(&username);
                        if(nRet){
                            printf("Error: CreateNewUser fuction returned %d", nRet);
                            exit(nRet);
                        }
                        break;
                    default:
                        prinf("Error: Not a valid option.\n");
                        exit(INVALID_OPTION);
                        break;
                }
            }
            else{
                nRet = LogIn(&username, &user_password);
                if(nRet){
                            printf("Error: LogIn fuction returned %d", nRet);
                            exit(nRet);
                }
                //goto task;
            }        
    }
    
    return 0;
}

