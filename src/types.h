/**
 * @file types.h
 * @author Leandro Assis dos Santos (assissantosleandro@gmail.com)
 * @brief Global types definitions 
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TYPES_H
    #define TYPES_H
    #define DEVELOPMENT

    #define MAX_KEYNAME_SIZE     15
    #define MAX_USERNAME_SIZE    15


    #define NO_ERROR_EXEC    0
    #define INVALID_OPTION  -1


    typedef enum{
        OK = 0,
        CLI_INPUT_ERROR = -1
    } rTypes;

    typedef enum{
        true,
        false
    } bool;

    /**
     * @enum
     * 
     * 
     */
    typedef enum{
        GET,
        #ifdef DEVELOPMENT
        LIST,
        #endif
        REMOVE,
        ADD,
        MODIFY,
        CHANGE_PIN,
        INIT_TOKEN
    } op;

#endif