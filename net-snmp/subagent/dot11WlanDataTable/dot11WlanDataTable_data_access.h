/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.12 $ of : mfd-data-access.m2c,v $
 *
 * $Id:$
 */
#ifndef DOT11WLANDATATABLE_DATA_ACCESS_H
#define DOT11WLANDATATABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "autelanWtpGroup.h"

/* *********************************************************************
 * function declarations
 */

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WlanDataTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11WlanDataTable is subid 5 of dot11wlanConfig.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.13.5, length: 12
*/


    int dot11WlanDataTable_init_data(dot11WlanDataTable_registration_ptr dot11WlanDataTable_reg);


/*
 * TODO:180:o: Review dot11WlanDataTable cache timeout.
 * The number of seconds before the cache times out
 */
#define DOT11WLANDATATABLE_CACHE_TIMEOUT   DOT1DTPFDBTABLE_CACHE_TIMEOUT

void dot11WlanDataTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache);
int dot11WlanDataTable_cache_load(netsnmp_container *container);
void dot11WlanDataTable_cache_free(netsnmp_container *container);

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
/* *********************************************************************
 * Since we have no idea how you really access your data, we'll go with
 * a worst case example: a flat text file.
 */
#define MAX_LINE_SIZE 256
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    int dot11WlanDataTable_row_prep( dot11WlanDataTable_rowreq_ctx *rowreq_ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11WLANDATATABLE_DATA_ACCESS_H */
