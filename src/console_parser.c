/**
 * @file console_parser.c
 * @author Leandro A. dos Santos
 * @brief Functions and types implementation for short and long option parser
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>

#include "types.h"
#include "console_parser.h"

/*!
 * @brief Function to read the short option command
 * @param[in] argc number of arguments received by program
 * @param[in] argv all arguments received by program
 * @param[out] en_console a pointer to an enable/disable console flag
 * @param[out] confirm a poiter to an enable/disable auto-confirm flag
 * @param[out] passwordname a pointer to keeps a password's name to look for, add or remove 
 * @param[out] username a pointer to keeps a user's name to log in
 * @param[out] passwordsize a pointer to the password's size which will be created
 * 
 * @return An error status code
 */
rTypes ParseConsoleCall(int argc,                     \
                        char **argv,                  \
                        bool *en_console,             \
                        bool *confirm,                \
                        char *passwordname,          \
                        char *username,              \
                        unsigned short *passwordsize, \
                        op *operation){
    
    int opt;
    const struct option longopts[] = {
        {"help", no_argument, 0, 'h'},
        {"console", no_argument, (int *) en_console, true},
        {"name", required_argument, 0, 'n'},
        {"login", required_argument, 0, 'l'},
        {"size", required_argument, 0, 's'},
        {"create", no_argument, (int *) operation, ADD},
        {"get", no_argument, (int *) operation, GET},
        {"remove", no_argument, (int *) operation, REMOVE},
        {"modify", no_argument, (int *) operation, MODIFY},
        {"yes-to-all", no_argument, (int *) confirm, true},
        {"change-pin", no_argument, (int *) operation, CHANGE_PIN},
        {"initialize", no_argument, (int *) operation, INIT_TOKEN},
        {0, 0, 0, 0}
    };

    while( (opt = getopt_long(argc, argv, "h:n:l:s:m:i:p:y:r:c:g:C", longopts, NULL)) > 0){
        switch(opt){
            case 'h':
                HelpCommand();
                exit(NO_ERROR_EXEC);
                break;
            case 'C':
                *en_console = true;
                break;
            case 'c':
                *operation = ADD;
                break;
            case 'g':
                *operation = GET;
                break;
            case 'r':
                *operation = REMOVE;
                break;
            case 'm':
                *operation = MODIFY;
                break;
            case 'p':
                *operation = CHANGE_PIN;
                break;
            case 'i':
                *operation = INIT_TOKEN;
                break;
            case 'y':
                *confirm = true;
                break;
            case 'n':
                strncpy(passwordname, optarg, MAX_KEYNAME_SIZE);
                break;
            case 'l':
                strncpy(username, optarg, MAX_USERNAME_SIZE);
                break;
            case 's':
                errno = 0;
                *passwordsize = (unsigned short) strtoul(optarg, NULL, 10);

                if(errno != 0){
                    printf("Error: Invalid numeric input given.\n");
                    exit(INVALID_OPTION);
                }

                break;
            default:
                UsageCommand();
                exit(INVALID_OPTION);
                break;
        }
    }

    return 0;
}

/**
 * @brief Prints on screen a little description and example of usage
 */
void UsageCommand(void){
   printf("This software has a console interface. To use it just execute with -C option.\n");
   printf("\nUsage: ./password-manager -C\n");
   printf("\nFor futher details see: --help or -h option.\n");
}

/**
 * @brief Prints on screen a manual of usage 
 */
void HelpCommand(void){
   printf("Usage: ./password-manager <options>\n\
           -h, --help                 show help and quit.\n\
           -C, --console              execute the console interface.\n\
           -c, --create               create new password.\n\
           -g, --get                  get a password.\n\
           -r, --remove               remove a password.\n\
           -m, --modify               change a password.\n\
           -p, --change-pin           change token PIN.\n\
           -i, --initialize           initialize the token.\n\
           -n NAME, --name=NAME       sets NAME as password's name for operations (-g, -r, -m, -c).\n\
           -l LOGIN, --login=LOGIN    sets LOGIN as login for open a session.\n\
           -s SIZE, --size=SIZE       sets SIZE as password's size for --create.\n\
           -y, --yes-to-all           enable auto confirmation.\n");
}

