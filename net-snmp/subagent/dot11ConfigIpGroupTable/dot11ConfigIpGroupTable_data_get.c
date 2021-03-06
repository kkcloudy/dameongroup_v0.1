/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11ConfigIpGroupTable.h"


/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement dot11ConfigIpGroupTable get routines.
 * TODO:240:M: Implement dot11ConfigIpGroupTable mapping routines (if any).
 *
 * These routine are used to get the value for individual objects. The
 * row context is passed, along with a pointer to the memory where the
 * value should be copied.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11ConfigIpGroupTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11ConfigIpGroupTable is subid 1 of dot11ConfigIpGroup.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.26.1, length: 12
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement dot11ConfigIpGroupTable data context functions.
 */


/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
 * @param Ifconfigindex_val
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This convenience function is useful for setting all the MIB index
 *  components with a single function call. It is assume that the C values
 *  have already been mapped from their native/rawformat to the MIB format.
 */
int
dot11ConfigIpGroupTable_indexes_set_tbl_idx(dot11ConfigIpGroupTable_mib_index *tbl_idx, long Ifconfigindex_val)
{
    DEBUGMSGTL(("verbose:dot11ConfigIpGroupTable:dot11ConfigIpGroupTable_indexes_set_tbl_idx","called\n"));

    /* Ifconfigindex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/r/d/h */
    tbl_idx->Ifconfigindex = Ifconfigindex_val;
    

    return MFD_SUCCESS;
} /* dot11ConfigIpGroupTable_indexes_set_tbl_idx */

/**
 * @internal
 * set row context indexes
 *
 * @param reqreq_ctx the row context that needs updated indexes
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This function sets the mib indexs, then updates the oid indexs
 *  from the mib index.
 */
int
dot11ConfigIpGroupTable_indexes_set(dot11ConfigIpGroupTable_rowreq_ctx *rowreq_ctx, long Ifconfigindex_val)
{
    DEBUGMSGTL(("verbose:dot11ConfigIpGroupTable:dot11ConfigIpGroupTable_indexes_set","called\n"));

    if(MFD_SUCCESS != dot11ConfigIpGroupTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , Ifconfigindex_val
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != dot11ConfigIpGroupTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* dot11ConfigIpGroupTable_indexes_set */


/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11ConfigIpGroupEntry.IfconfigIpAddr
 * IfconfigIpAddr is subid 2 of dot11ConfigIpGroupEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.26.1.1.2
 * Description:
Create configIpAddr.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is IPADDR (based on perltype IPADDR)
 * The net-snmp type is ASN_IPADDRESS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the IfconfigIpAddr data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param IfconfigIpAddr_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
IfconfigIpAddr_get( dot11ConfigIpGroupTable_rowreq_ctx *rowreq_ctx, u_long * IfconfigIpAddr_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != IfconfigIpAddr_val_ptr );


    DEBUGMSGTL(("verbose:dot11ConfigIpGroupTable:IfconfigIpAddr_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the IfconfigIpAddr data.
 * copy (* IfconfigIpAddr_val_ptr ) from rowreq_ctx->data
 */
    (* IfconfigIpAddr_val_ptr ) = rowreq_ctx->data.IfconfigIpAddr;

    return MFD_SUCCESS;
} /* IfconfigIpAddr_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11ConfigIpGroupEntry.IfconfigNetmask
 * IfconfigNetmask is subid 3 of dot11ConfigIpGroupEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.26.1.1.3
 * Description:
Create Netmask.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is IPADDR (based on perltype IPADDR)
 * The net-snmp type is ASN_IPADDRESS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the IfconfigNetmask data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param IfconfigNetmask_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
IfconfigNetmask_get( dot11ConfigIpGroupTable_rowreq_ctx *rowreq_ctx, u_long * IfconfigNetmask_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != IfconfigNetmask_val_ptr );


    DEBUGMSGTL(("verbose:dot11ConfigIpGroupTable:IfconfigNetmask_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the IfconfigNetmask data.
 * copy (* IfconfigNetmask_val_ptr ) from rowreq_ctx->data
 */
    (* IfconfigNetmask_val_ptr ) = rowreq_ctx->data.IfconfigNetmask;

    return MFD_SUCCESS;
} /* IfconfigNetmask_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11ConfigIpGroupEntry.ConfigIpRowStatus
 * ConfigIpRowStatus is subid 4 of dot11ConfigIpGroupEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.26.1.1.4
 * Description:
This variable is used to create, modify, and/or delete a row
			        	 in this table.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 3/8. Values:  active(1), notInService(2), notReady(3), createAndGo(4), createAndWait(5), destroy(6)
 *
 * Its syntax is RowStatus (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the ConfigIpRowStatus data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param ConfigIpRowStatus_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
ConfigIpRowStatus_get( dot11ConfigIpGroupTable_rowreq_ctx *rowreq_ctx, u_long * ConfigIpRowStatus_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != ConfigIpRowStatus_val_ptr );

    (* ConfigIpRowStatus_val_ptr ) = rowreq_ctx->data.ConfigIpRowStatus;

    return MFD_SUCCESS;
} /* ConfigIpRowStatus_get */



/** @} */
