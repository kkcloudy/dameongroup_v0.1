/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#ifndef	_IMSIESN_H_
#define	_IMSIESN_H_


#include <asn_application.h>

/* Including external dependencies */
#include "IMSIDS41.h"
#include "ESN.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IMSIESN */
typedef struct IMSIESN {
	IMSIDS41_t	 iMSIDS41;
	ESN_t	 eSN;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IMSIESN_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IMSIESN;

#ifdef __cplusplus
}
#endif

#endif	/* _IMSIESN_H_ */
#include <asn_internal.h>
