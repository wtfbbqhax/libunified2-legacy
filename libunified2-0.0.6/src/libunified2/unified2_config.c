#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "unified2.h"

char * unified2_lib_version( ) {
    char *string = PACKAGE_VERSION;
    return string;
}

char * unified2_lib_string( ) {
    char *string = PACKAGE_STRING;
    return string;
}

char * unified2_lib_bugreport( ) {
    char *string = PACKAGE_BUGREPORT;
    return string;
}
