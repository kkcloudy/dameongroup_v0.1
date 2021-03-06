/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_HorizontalVelocity_H_
#define	_HorizontalVelocity_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HorizontalSpeedAndBearing.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
/* auto changed by perl script */
/*struct ;*/

/* HorizontalVelocity */
typedef struct HorizontalVelocity {
	HorizontalSpeedAndBearing_t	 horizontalSpeedAndBearing;
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_209P0 *iE_Extensions ;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HorizontalVelocity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HorizontalVelocity;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _HorizontalVelocity_H_ */
#include <asn_internal.h>
