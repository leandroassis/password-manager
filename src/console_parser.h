/**
 * @file console_parser.h
 * @author Leandro A. dos Santos (assissantosleandro@gmail.com)
 * @brief Functions and types definitions for short and long option parser
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "types.h"

// functions
rTypes ParseConsoleCall(int argc,                     \
                        char **argv,                  \
                        bool *en_console,             \
                        bool *confirm,                \
                        char *passwordname,          \
                        char *username,              \    
                        unsigned short *passwordsize, \
                        op *operation);

void UsageCommand(void);
void HelpCommand(void);