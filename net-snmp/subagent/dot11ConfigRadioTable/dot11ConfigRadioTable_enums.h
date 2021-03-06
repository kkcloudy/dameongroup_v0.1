/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c,v 1.3 2004/05/18 17:44:32 rstory Exp $
 *
 * $Id:$
 */
#ifndef DOT11CONFIGRADIOTABLE_ENUMS_H
#define DOT11CONFIGRADIOTABLE_ENUMS_H

#ifdef __cplusplus
extern "C" {
#endif

 /*
 * NOTES on enums
 * ==============
 *
 * Value Mapping
 * -------------
 * If the values for your data type don't exactly match the
 * possible values defined by the mib, you should map them
 * below. For example, a boolean flag (1/0) is usually represented
 * as a TruthValue in a MIB, which maps to the values (1/2).
 *
 */
/*************************************************************************
 *************************************************************************
 *
 * enum definitions for table dot11ConfigRadioTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * radioType (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOTYPE_ENUMS
#define RADIOTYPE_ENUMS

#define RADIOTYPE_A         1 
#define RADIOTYPE_B         2 
#define RADIOTYPE_G         4 
#define RADIOTYPE_BG        6 
#define RADIOTYPE_AN        8 
#define RADIOTYPE_AAN       9 
#define RADIOTYPE_GN        16 
#define RADIOTYPE_GGN       20 
#define RADIOTYPE_BGGN      22 

#endif /* RADIOTYPE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioType enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOTYPE_A        1 
#define INTERNAL_RADIOTYPE_B        2 
#define INTERNAL_RADIOTYPE_G        4 
#define INTERNAL_RADIOTYPE_BG       6 
#define INTERNAL_RADIOTYPE_AN       8 
#define INTERNAL_RADIOTYPE_AAN      9 
#define INTERNAL_RADIOTYPE_GN       16 
#define INTERNAL_RADIOTYPE_GGN      20 
#define INTERNAL_RADIOTYPE_BGGN     22 

/*************************************************************
 * constants for enums for the MIB node
 * radioLeadCode (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOLEADCODE_ENUMS
#define RADIOLEADCODE_ENUMS

#define RADIOLEADCODE_SHORT  1 
#define RADIOLEADCODE_LONG  2 


#endif /* RADIOLEADCODE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioLeadCode enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOLEADCODE_SHORT  1 
#define INTERNAL_RADIOLEADCODE_LONG  2 

/*************************************************************
 * constants for enums for the MIB node
 * radioService (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOSERVICE_ENUMS
#define RADIOSERVICE_ENUMS

#define RADIOSERVICE_DISABLE  1 
#define RADIOSERVICE_ENABLE  2 


#endif /* RADIOSERVICE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioService enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOSERVICE_DISABLE  1 
#define INTERNAL_RADIOSERVICE_ENABLE  2 

/*************************************************************
 * constants for enums for the MIB node
 * radioAmpduSwitch (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOAMPDUSWITCH_ENUMS
#define RADIOAMPDUSWITCH_ENUMS

#define RADIOAMPDUSWITCH_OFF  0 
#define RADIOAMPDUSWITCH_ON  1 


#endif /* RADIOAMPDUSWITCH_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioAmpduSwitch enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOAMPDUSWITCH_OFF  0 
#define INTERNAL_RADIOAMPDUSWITCH_ON  1 

/*************************************************************
 * constants for enums for the MIB node
 * radioCwmode (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOCWMODE_ENUMS
#define RADIOCWMODE_ENUMS

#define RADIOCWMODE_HT20  0 
#define RADIOCWMODE_HT20_HT40  1 
#define RADIOCWMODE_HT40  2 


#endif /* RADIOCWMODE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioCwmode enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOCWMODE_HT20  0 
#define INTERNAL_RADIOCWMODE_HT20_HT40  1 
#define INTERNAL_RADIOCWMODE_HT40  2 

/*************************************************************
 * constants for enums for the MIB node
 * radioShortGISwitch (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOSHORTGISWITCH_ENUMS
#define RADIOSHORTGISWITCH_ENUMS

#define RADIOSHORTGISWITCH_OFF  0 
#define RADIOSHORTGISWITCH_ON  1 


#endif /* RADIOSHORTGISWITCH_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioShortGISwitch enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOSHORTGISWITCH_OFF  0 
#define INTERNAL_RADIOSHORTGISWITCH_ON  1 

/*************************************************************
 * constants for enums for the MIB node
 * radioAmsduSwitch (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIOAMSDUSWITCH_ENUMS
#define RADIOAMSDUSWITCH_ENUMS

#define RADIOAMSDUSWITCH_OFF  0 
#define RADIOAMSDUSWITCH_ON  1 


#endif /* RADIOAMSDUSWITCH_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radioAmsduSwitch enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIOAMSDUSWITCH_OFF  0 
#define INTERNAL_RADIOAMSDUSWITCH_ON  1 

/*************************************************************
 * constants for enums for the MIB node
 * radio11nSwitch (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef RADIO11NSWITCH_ENUMS
#define RADIO11NSWITCH_ENUMS

#define RADIO11NSWITCH_OFF  0 
#define RADIO11NSWITCH_ON  1 


#endif /* RADIO11NSWITCH_ENUMS */

    /*
     * TODO:140:o: Define interal representation of radio11nSwitch enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_RADIO11NSWITCH_OFF  0 
#define INTERNAL_RADIO11NSWITCH_ON  1 

/*************************************************************
 * constants for enums for the MIB node
 * OnlyAllow11nStaAccess (TruthValue / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef TRUTHVALUE_ENUMS
#define TRUTHVALUE_ENUMS

#define TRUTHVALUE_TRUE  1 
#define TRUTHVALUE_FALSE  2 


#endif /* TRUTHVALUE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of OnlyAllow11nStaAccess enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_ONLYALLOW11NSTAACCESS_TRUE  1 
#define INTERNAL_ONLYALLOW11NSTAACCESS_FALSE  2 

#ifndef RADIOROLE_ENUMS
#define RADIOROLE_ENUMS

#define RADIOROLE_CLINT  1 
#define RADIOROLE_OTHER  2 
#define RADIOROLE_AP  6 
#define RADIOROLE_MESH  9 

#endif /* RADIOROLE_ENUMS */

#ifdef __cplusplus
}
#endif

#endif /* DOT11CONFIGRADIOTABLE_ENUMS_H */
