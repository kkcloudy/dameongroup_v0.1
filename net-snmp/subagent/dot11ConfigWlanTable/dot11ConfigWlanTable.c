/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $ 
 *
 * $Id:$
 */
/** \mainpage MFD helper for dot11ConfigWlanTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11ConfigWlanTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "dot11ConfigWlanTable_interface.h"
#include "autelanWtpGroup.h"

#define  DOT11CONFWLANTABLE "2.13.2"

oid dot11ConfigWlanTable_oid[128] = { 0 };
int dot11ConfigWlanTable_oid_size = 0;

void initialize_table_dot11ConfigWlanTable(void);


/**
 * Initializes the dot11ConfigWlanTable module
 */
void
init_dot11ConfigWlanTable(void)
{
    DEBUGMSGTL(("verbose:dot11ConfigWlanTable:init_dot11ConfigWlanTable","called\n"));

    /*
     * TODO:300:o: Perform dot11ConfigWlanTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("dot11ConfigWlanTable"))
        initialize_table_dot11ConfigWlanTable();

} /* init_dot11ConfigWlanTable */

/**
 * Initialize the table dot11ConfigWlanTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_dot11ConfigWlanTable(void)
{
    dot11ConfigWlanTable_registration_ptr user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:dot11ConfigWlanTable:initialize_table_dot11ConfigWlanTable","called\n"));

    /*
     * TODO:301:o: Perform dot11ConfigWlanTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize dot11ConfigWlanTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("dot11ConfigWlanTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    mad_dev_oid(dot11ConfigWlanTable_oid,DOT11CONFWLANTABLE,&dot11ConfigWlanTable_oid_size,enterprise_pvivate_oid);
    _dot11ConfigWlanTable_initialize_interface(user_context, flags);
} /* initialize_table_dot11ConfigWlanTable */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
dot11ConfigWlanTable_pre_request(dot11ConfigWlanTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11ConfigWlanTable:dot11ConfigWlanTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform dot11ConfigWlanTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* dot11ConfigWlanTable_pre_request */

/**
 * post-request callback
 *
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
dot11ConfigWlanTable_post_request(dot11ConfigWlanTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11ConfigWlanTable:dot11ConfigWlanTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform dot11ConfigWlanTable pos-request actions.
     */

    return MFD_SUCCESS;
} /* dot11ConfigWlanTable_post_request */


/** @{ */
