/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#include "GlobalCN-ID.h"

static asn_TYPE_member_t asn_MBR_GlobalCN_ID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GlobalCN_ID, pLMNidentity),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PLMNidentity,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pLMNidentity"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GlobalCN_ID, cN_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CN_ID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cN-ID"
		},
};
static ber_tlv_tag_t asn_DEF_GlobalCN_ID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_GlobalCN_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pLMNidentity at 890 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cN-ID at 892 */
};
static asn_SEQUENCE_specifics_t asn_SPC_GlobalCN_ID_specs_1 = {
	sizeof(struct GlobalCN_ID),
	offsetof(struct GlobalCN_ID, _asn_ctx),
	asn_MAP_GlobalCN_ID_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_GlobalCN_ID = {
	"GlobalCN-ID",
	"GlobalCN-ID",
	SEQUENCE_free_for_RANAP,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper_for_RANAP,
	SEQUENCE_encode_uper_for_RANAP,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_GlobalCN_ID_tags_1,
	sizeof(asn_DEF_GlobalCN_ID_tags_1)
		/sizeof(asn_DEF_GlobalCN_ID_tags_1[0]), /* 1 */
	asn_DEF_GlobalCN_ID_tags_1,	/* Same as above */
	sizeof(asn_DEF_GlobalCN_ID_tags_1)
		/sizeof(asn_DEF_GlobalCN_ID_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_GlobalCN_ID_1,
	2,	/* Elements count */
	&asn_SPC_GlobalCN_ID_specs_1	/* Additional specs */
};

