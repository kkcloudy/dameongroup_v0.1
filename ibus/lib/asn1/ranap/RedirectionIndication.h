/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-PDU-Contents"
 * 	found in "RANAP-PDU-Contents.asn"
 */

#ifndef	_RedirectionIndication_H_
#define	_RedirectionIndication_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP-ProtocolIE-Container.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RedirectionIndication */
typedef ProtocolIE_Container_139P0_t	 RedirectionIndication_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RedirectionIndication;
asn_struct_free_f RedirectionIndication_free;
asn_struct_print_f RedirectionIndication_print;
asn_constr_check_f RedirectionIndication_constraint;
ber_type_decoder_f RedirectionIndication_decode_ber;
der_type_encoder_f RedirectionIndication_encode_der;
xer_type_decoder_f RedirectionIndication_decode_xer;
xer_type_encoder_f RedirectionIndication_encode_xer;
per_type_decoder_f RedirectionIndication_decode_uper;
per_type_encoder_f RedirectionIndication_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RedirectionIndication_H_ */
#include <asn_internal.h>
