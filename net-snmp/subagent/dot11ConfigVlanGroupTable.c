/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf,v 5.14.2.2 2005/05/09 08:13:01 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "dot11ConfigVlanGroupTable.h"
#include "autelanWtpGroup.h"
#include "mibif.h"
#include "ws_init_dbus.h"

#define  CONFIGVLANGROUP "2.22.1"

#if 1/*for ws_dcli_vlan.c has these funcs!!!*/
void ShowAlert( char *aaa)
{
	return;
}
void release(struct list *l)
{
	return;
}

struct list * get_chain_head(char *file_name)
{
	return NULL;
}

char *search(struct list *l,char *v)
{
	return NULL;
}
#endif
struct dot11ConfigVlanGroupTable_entry {
    /* Index values */
    long VlanID;
	long gindex;
    /* Column values */
    char *Port;
    char *VlanDescr;
    long InterfIndex;
    long ConfigVlanRowStatus;

    /* Illustrate using a simple linked list */
    int   valid;
    struct dot11ConfigVlanGroupTable_entry *next;
};

static int if_vlan_entry_params_set( struct dot11ConfigVlanGroupTable_entry *entry )
{
	if( NULL != entry &&
		entry->VlanID > 0 &&
		entry->gindex > 0 &&
		strlen( entry->Port ) > 0 &&
		strlen( entry->VlanDescr )  > 0 )
	{
		return 1;
	}

	return 0;
}

void dot11ConfigVlanGroupTable_load();

void
dot11ConfigVlanGroupTable_removeEntry( struct dot11ConfigVlanGroupTable_entry *entry);

/** Initializes the dot11ConfigVlanGroupTable module */
void
init_dot11ConfigVlanGroupTable(void)
{
  /* here we initialize all the tables we're planning on supporting */
    initialize_table_dot11ConfigVlanGroupTable();
}

/** Initialize the dot11ConfigVlanGroupTable table by defining its contents and how it's structured */
void
initialize_table_dot11ConfigVlanGroupTable(void)
{
    static oid dot11ConfigVlanGroupTable_oid[128] = {0};
    size_t dot11ConfigVlanGroupTable_oid_len   = 0;
	mad_dev_oid(dot11ConfigVlanGroupTable_oid,CONFIGVLANGROUP,&dot11ConfigVlanGroupTable_oid_len,enterprise_pvivate_oid);
    netsnmp_handler_registration    *reg;
    netsnmp_iterator_info           *iinfo;
    netsnmp_table_registration_info *table_info;

    reg = netsnmp_create_handler_registration(
              "dot11ConfigVlanGroupTable",     dot11ConfigVlanGroupTable_handler,
              dot11ConfigVlanGroupTable_oid, dot11ConfigVlanGroupTable_oid_len,
              HANDLER_CAN_RWRITE
              );

    table_info = SNMP_MALLOC_TYPEDEF( netsnmp_table_registration_info );
    netsnmp_table_helper_add_indexes(table_info,
                           ASN_INTEGER,  /* index: VlanID */
                           0);
    table_info->min_column = CONFIGVLANMIN;
    table_info->max_column = CONFIGVLANMAX;
    
    iinfo = SNMP_MALLOC_TYPEDEF( netsnmp_iterator_info );
    iinfo->get_first_data_point = dot11ConfigVlanGroupTable_get_first_data_point;
    iinfo->get_next_data_point  = dot11ConfigVlanGroupTable_get_next_data_point;
    iinfo->table_reginfo        = table_info;
    
    netsnmp_register_table_iterator( reg, iinfo );

	netsnmp_inject_handler(reg,netsnmp_get_cache_handler(DOT1DTPFDBTABLE_CACHE_TIMEOUT,dot11ConfigVlanGroupTable_load, dot11ConfigVlanGroupTable_removeEntry,
							dot11ConfigVlanGroupTable_oid, dot11ConfigVlanGroupTable_oid_len));
    /* Initialise the contents of the table here */
}

    /* Typical data structure for a row entry */

struct dot11ConfigVlanGroupTable_entry  *dot11ConfigVlanGroupTable_head;

/* create a new row in the (unsorted) table */
struct dot11ConfigVlanGroupTable_entry *
dot11ConfigVlanGroupTable_createEntry(
                 long  VlanID,
                 char *Port,
				 char *VlanDescr,
				 long InterfIndex,
				 long gindex,
				 long ConfigVlanRowStatus
                ) {
    struct dot11ConfigVlanGroupTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct dot11ConfigVlanGroupTable_entry);
    if (!entry)
        return NULL;

    entry->VlanID = VlanID;
	entry->Port = strdup(Port);
	entry->VlanDescr = strdup(VlanDescr);
	entry->InterfIndex = InterfIndex;
	entry->gindex = gindex;
	entry->ConfigVlanRowStatus = ConfigVlanRowStatus;
    entry->next = dot11ConfigVlanGroupTable_head;
    dot11ConfigVlanGroupTable_head = entry;
    return entry;
}

/* remove a row from the table */
void
dot11ConfigVlanGroupTable_removeEntry( struct dot11ConfigVlanGroupTable_entry *entry ) {
    struct dot11ConfigVlanGroupTable_entry *ptr, *prev;

    if (!entry)
        return;    /* Nothing to remove */

    for ( ptr  = dot11ConfigVlanGroupTable_head, prev = NULL;
          ptr != NULL;
          prev = ptr, ptr = ptr->next ) {
        if ( ptr == entry )
            break;
    }
    if ( !ptr )
        return;    /* Can't find it */

    if ( prev == NULL )
        dot11ConfigVlanGroupTable_head = ptr->next;
    else
        prev->next = ptr->next;
    FREE_OBJECT(entry->Port);
	FREE_OBJECT(entry->VlanDescr);
    SNMP_FREE( entry );   /* XXX - release any other internal resources */
}


 struct dot11ConfigVlanGroupTable_entry * get_vlan_in_lst( int vlan  )
 {
	 struct dot11ConfigVlanGroupTable_entry *ret=NULL;

	 for( ret = dot11ConfigVlanGroupTable_head; ret !=NULL; ret = ret->next )
	 {
	 	//printf("ret->VlanID = %d  vlan = %d\n", ret->VlanID, vlan);
		if( ret->VlanID == vlan )
		{
			return ret;
		}
	 }

	 return NULL;
 }
void dot11ConfigVlanGroupTable_load()
{	 
	
	snmp_log(LOG_DEBUG, "enter dot11ConfigVlanGroupTable_load\n");
	
	 int i;

#if 0	 
	 char *VlanDescr  = (char*)malloc(256);
	 memset(VlanDescr,0,256);
     struct vlan_info_simple receive_vlan[MAX_VLAN_NUM];
     ret = show_vlan_list(receive_vlan,port_num,&vlanNum); 
	 if ( ret == 0 )
	 {
	 	for(i=0;i<vlanNum;i++)
	 	{
	 		sprintf(VlanDescr,"%d",receive_vlan[i].vlanStat);
		    dot11ConfigVlanGroupTable_createEntry( receive_vlan[i].vlanId,
												VlanDescr,
												receive_vlan[i].vlanName,
												receive_vlan[i].ifindex,
												0);
	 	}
	 }
#endif
	mibsubiflst subiflst;

	memset( &subiflst, 0, sizeof(subiflst) );
	
	snmp_log(LOG_DEBUG, "enter get_all_submibif\n");
	get_all_submibif( &subiflst );
	snmp_log(LOG_DEBUG, "exit get_all_submibif\n");
	
	if( subiflst.mibif_num > 0 )
	{
	 	for(i=0;i<subiflst.mibif_num;i++)
	 	{
	 		struct dot11ConfigVlanGroupTable_entry *get = NULL;
			get = get_vlan_in_lst( subiflst.lst[i].subif_vlanid );
	 		if( NULL != get )
	 		{
				dot11ConfigVlanGroupTable_removeEntry( get );
			}
			//printf("before subiflst.lst[i].subif_vlanid = %d\n", subiflst.lst[i].subif_vlanid );
		    dot11ConfigVlanGroupTable_createEntry( subiflst.lst[i].subif_vlanid,
												   subiflst.lst[i].main_ifname,
												   subiflst.lst[i].info,
												   subiflst.lst[i].index,
												   subiflst.lst[i].gindex,
													1);
	 	}		
	}
	
	FREE_OBJECT( subiflst.lst );
	snmp_log(LOG_DEBUG, "exit dot11ConfigVlanGroupTable_load\n");
}

/* Example iterator hook routines - using 'get_next' to do most of the work */
netsnmp_variable_list *
dot11ConfigVlanGroupTable_get_first_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{   
    if(dot11ConfigVlanGroupTable_head==NULL)
		return NULL;
	
	*my_data_context = dot11ConfigVlanGroupTable_head;
    *my_loop_context = dot11ConfigVlanGroupTable_head;
    return dot11ConfigVlanGroupTable_get_next_data_point(my_loop_context, my_data_context,
                                    put_index_data,  mydata );
}

netsnmp_variable_list *
dot11ConfigVlanGroupTable_get_next_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    struct dot11ConfigVlanGroupTable_entry *entry = (struct dot11ConfigVlanGroupTable_entry *)*my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if ( entry ) {
        snmp_set_var_value( idx, (u_char*)&entry->VlanID, sizeof(entry->VlanID) );
        idx = idx->next_variable;
        *my_data_context = (void *)entry;
        *my_loop_context = (void *)entry->next;
    } else {
        return NULL;
    }
	return put_index_data;
}

int check_if_gindex_success( struct dot11ConfigVlanGroupTable_entry *dot11ConfigVlanGroupTable_head,
							struct dot11ConfigVlanGroupTable_entry *cur_entry, int gindex )
{/*0  current entry is set to the same gindex, -1 failed ,1  success*/
	struct dot11ConfigVlanGroupTable_entry *temp = NULL;
	

	for( temp = dot11ConfigVlanGroupTable_head;
			NULL != temp;
			temp = temp->next )
	{
		if( gindex == temp->gindex )
		{
			if( cur_entry == temp )
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
	return 1;
}
/** handles requests for the dot11ConfigVlanGroupTable table */
int
dot11ConfigVlanGroupTable_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests) {

    netsnmp_request_info       *request;
    netsnmp_table_request_info *table_info;
    struct dot11ConfigVlanGroupTable_entry          *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
      		if( NULL == table_entry )
    		{
				netsnmp_set_request_error(reqinfo,request,SNMP_NOSUCHINSTANCE);
				continue;
			}
			
            switch (table_info->colnum) {
            case COLUMN_VLANID:
                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->VlanID,
                                          sizeof(table_entry->VlanID));
                break;
            case COLUMN_PORT:
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          (u_char*)table_entry->Port,
                                          strlen(table_entry->Port));
                break;
            case COLUMN_VLANDESCR:
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          (u_char*)table_entry->VlanDescr,
                                          strlen(table_entry->VlanDescr));
                break;
            case COLUMN_INTERFINDEX:
                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->gindex,
                                          sizeof(table_entry->gindex));
                break;
            case COLUMN_CONFIGVLANROWSTATUS:
                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->ConfigVlanRowStatus,
                                          sizeof(table_entry->ConfigVlanRowStatus));
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
            switch (table_info->colnum) {
            case COLUMN_VLANID:
                if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            case COLUMN_PORT:
                if ( request->requestvb->type != ASN_OCTET_STR ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            case COLUMN_VLANDESCR:
                if ( request->requestvb->type != ASN_OCTET_STR ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            case COLUMN_INTERFINDEX:
                if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            case COLUMN_CONFIGVLANROWSTATUS:
                if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                switch (*request->requestvb->val.integer) {
                case RS_ACTIVE:
                case RS_NOTINSERVICE:
                    if (!table_entry) {
                        netsnmp_set_request_error( reqinfo, request,
                                                   SNMP_ERR_INCONSISTENTVALUE );
                        return SNMP_ERR_NOERROR;
                    }
                    break;
                case RS_CREATEANDGO:
                case RS_CREATEANDWAIT:
                    if (table_entry) {
                        netsnmp_set_request_error( reqinfo, request,
                                                   SNMP_ERR_INCONSISTENTVALUE );
                        return SNMP_ERR_NOERROR;
                    }
                    break;
                case RS_DESTROY:
                    /* Valid in all circumstances */
                    break;
                case RS_NOTREADY:
                default:
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGVALUE );
                    return SNMP_ERR_NOERROR;
                    break;
                }
                break;
            default:
                netsnmp_set_request_error( reqinfo, request,
                                           SNMP_ERR_NOTWRITABLE );
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
            switch (table_info->colnum) {
            case COLUMN_CONFIGVLANROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_CREATEANDGO:
                case RS_CREATEANDWAIT:
					//printf("*table_info->indexes->val.integer = %d\n", *table_info->indexes->val.integer );
					 dot11ConfigVlanGroupTable_createEntry(*table_info->indexes->val.integer,
                        "x", 
                        "x",
                        0,
                        0,
                        RS_NOTREADY);
                	break;   
                }
            }
        }
        break;

    case MODE_SET_FREE:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
      		if( NULL == table_entry )
    		{
				continue;
			}  
            switch (table_info->colnum) {
            case COLUMN_CONFIGVLANROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_CREATEANDGO:
                case RS_CREATEANDWAIT:
                    break;
                }
            }
        }
        break;

    case MODE_SET_ACTION:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    		if( NULL == table_entry )
    		{
				continue;
			}
            switch (table_info->colnum) {
            case COLUMN_VLANID:
			{
				if(table_entry)
				{
					table_entry->VlanID= *request->requestvb->val.integer;
				}
				else
				{
					netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
				}  	
			}
                break;
            case COLUMN_PORT:
				//printf("table_entry->VlanID = %d\n", table_entry->VlanID );
            	{
					char * input_string = (char *)malloc(request->requestvb->val_len+1);
					if(NULL == input_string) {
                        netsnmp_set_request_error( reqinfo, request, SNMP_ERR_WRONGTYPE );
                        break;
					}
					
					memset(input_string,0,request->requestvb->val_len+1);
					strncpy(input_string,request->requestvb->val.string,request->requestvb->val_len);

					if((input_string)&&( 1 == if_main_mibif(input_string) ))
					{
						if( 1 == table_entry->ConfigVlanRowStatus )
						{
							mod_sub_mibif_mainif( table_entry->VlanID, table_entry->Port, input_string );
						}					
						if(table_entry->Port!= NULL)
						{
							free(table_entry->Port);
						}
						table_entry->Port = strdup(input_string);

						
					}
					else
					{
						netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
					}
					FREE_OBJECT(input_string);
            	}

                break;
            case COLUMN_VLANDESCR:
            	{
					char * input_string = (char *)malloc(request->requestvb->val_len+1);
					if(NULL == input_string) {
                        netsnmp_set_request_error( reqinfo, request, SNMP_ERR_WRONGTYPE );
                        break;
					}
					
					memset(input_string,0,request->requestvb->val_len+1);
					strncpy(input_string,request->requestvb->val.string,request->requestvb->val_len);

					if((input_string)&&( strlen(input_string) > 0 ))
					{
						if( 1 == table_entry->ConfigVlanRowStatus )
						{
							mod_sub_mibif_info( table_entry->VlanID, input_string );
						}					
						if(table_entry->VlanDescr!= NULL)
						{
							free(table_entry->VlanDescr);
						}
						table_entry->VlanDescr = strdup(input_string);
					}
					else
					{
						netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
					}
					FREE_OBJECT(input_string);
            	}
#if 0
           {
			char * input_string = (char *)malloc(request->requestvb->val_len+1);
			memset(input_string,0,request->requestvb->val_len+1);
			strncpy(input_string,request->requestvb->val.string,request->requestvb->val_len);			 
			if(table_entry->VlanDescr!= NULL)
			{
				free(table_entry->VlanDescr);
			}
			table_entry->VlanDescr	  = strdup(input_string);
			 
			free(input_string);
            }
#endif
                break;
            case COLUMN_INTERFINDEX:
				if( 1 == table_entry->ConfigVlanRowStatus )
				{
					int ixret = check_if_gindex_success(dot11ConfigVlanGroupTable_head,
								table_entry, *request->requestvb->val.integer);
					if( -1 == ixret )
					{
						netsnmp_set_request_error( reqinfo, request,
										   SNMP_ERR_WRONGTYPE );
						break;
					}
#if 0					
					else if( 0 == ixret )/*current index is!*/
					{
						printf("curent is this gindex, no need set");
						break;
					}
#endif
					table_entry->gindex = *request->requestvb->val.integer;
					if( 0 != mod_sub_mibif_gindex(table_entry->VlanID,
								table_entry->Port, table_entry->gindex ) )
					{
						netsnmp_set_request_error( reqinfo, request,
										   SNMP_ERR_WRONGTYPE );
					}
					else
					{
						table_entry->gindex = *request->requestvb->val.integer;
					}
				}
				else
				{
					int ixret = check_if_gindex_success(dot11ConfigVlanGroupTable_head,
								table_entry, *request->requestvb->val.integer);
					if( -1 == ixret )
					{
						netsnmp_set_request_error( reqinfo, request,
										   SNMP_ERR_WRONGTYPE );
						break;
					}
				 	table_entry->gindex = *request->requestvb->val.integer;
				}
                break;
            }

			if( 1 == if_vlan_entry_params_set(table_entry) && 
					RS_NOTREADY == table_entry->ConfigVlanRowStatus )
			{
				table_entry->ConfigVlanRowStatus = RS_NOTINSERVICE;
			}
        }
        /* Check the internal consistency of an active row */
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_CONFIGVLANROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_ACTIVE:
                case RS_CREATEANDGO:
                    break;
                }
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_VLANID:
                /* Need to restore old 'table_entry->VlanID' value.
                   May need to use 'memcpy' */
                break;
            case COLUMN_PORT:
                /* Need to restore old 'table_entry->Port' value.
                   May need to use 'memcpy' */
                break;
            case COLUMN_VLANDESCR:
                /* Need to restore old 'table_entry->VlanDescr' value.
                   May need to use 'memcpy' */
                break;
            case COLUMN_INTERFINDEX:
                /* Need to restore old 'table_entry->InterfIndex' value.
                   May need to use 'memcpy' */
                break;
            case COLUMN_CONFIGVLANROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_CREATEANDGO:
                case RS_CREATEANDWAIT:
			    break;
                }
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11ConfigVlanGroupTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);

			//printf("MODE_SET_COMMIT!!!!\n");
			if( !table_entry ){
					continue;
				}     
            switch (table_info->colnum) {
            case COLUMN_CONFIGVLANROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_CREATEANDGO:
                    table_entry->valid = 1;
                    /* Fall-through */
                case RS_ACTIVE:
					{  
						//printf("get RS_ACTIVE!\n");
						if( 1 == if_main_mibif( table_entry->Port ) )
						{
							mibif mif;
							
							//printf("before create_sub_mibif\n");
							create_sub_mibif( table_entry->VlanID, table_entry->Port, table_entry->VlanDescr );

							mod_sub_mibif_gindex(table_entry->VlanID,
										table_entry->Port, table_entry->gindex );
							{
					    		table_entry->ConfigVlanRowStatus= RS_ACTIVE;								
								struct dot11ConfigVlanGroupTable_entry  *temp; 
								 while( dot11ConfigVlanGroupTable_head ){
									 temp=dot11ConfigVlanGroupTable_head->next;
									 dot11ConfigVlanGroupTable_removeEntry(dot11ConfigVlanGroupTable_head);
									 dot11ConfigVlanGroupTable_head=temp;
								 }
							}
	
						}
						else
						{
							table_entry->ConfigVlanRowStatus = RS_NOTREADY;
						}
						
                	}                   
                    break;

                case RS_CREATEANDWAIT:
                    //table_entry->valid = 1;
                    /* Fall-through */
					break;
                case RS_NOTINSERVICE:
                    table_entry->ConfigVlanRowStatus = RS_NOTINSERVICE;
                    break;

                case RS_DESTROY:
					{   
						//printf("table_entry->VlanID = %d\n", table_entry->VlanID);
						//printf("table_entry->Port = %s\n", table_entry->Port );
						//if( table_entry->VlanID > 0 && 1 == if_main_mibif( table_entry->Port ) )
						{
							delete_sub_mibif( table_entry->VlanID, table_entry->Port );
							
							struct dot11ConfigVlanGroupTable_entry	*temp; 
							while( dot11ConfigVlanGroupTable_head ){
								 temp=dot11ConfigVlanGroupTable_head->next;
								 dot11ConfigVlanGroupTable_removeEntry(dot11ConfigVlanGroupTable_head);
								 dot11ConfigVlanGroupTable_head=temp;
							 }							
						}

						
               		}
					break;
                }
				break;
            }			
        }
        break;
    }
    return SNMP_ERR_NOERROR;
}
