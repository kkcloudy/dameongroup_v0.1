/* cgicTempDir is the only setting you are likely to need
	to change in this file. */

/*******************************************************************************
Copyright (C) Autelan Technology


This software file is owned and distributed by Autelan Technology 
********************************************************************************


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************
* wp_wtpnew.c
*
*
* CREATOR:
* autelan.software.Network Dep. team
* hupx@autelan.com
*
* DESCRIPTION:
*
*
*
*******************************************************************************/


#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>
#include "ws_usrinfo.h"
#include "ws_err.h"
#include "ws_ec.h"
#include "wcpss/asd/asd.h"
#include "wcpss/wid/WID.h"
#include "dbus/wcpss/dcli_wid_wtp.h"
#include "dbus/wcpss/dcli_wid_wlan.h"
#include "ws_dcli_wlans.h"
#include "ws_dcli_vrrp.h"
#include "ws_init_dbus.h"
#include "ws_dbus_list_interface.h"

int ShowWtpgroupnewPage(char *m,struct list *lpublic,struct list *lwlan);    
void NewWtpgroup(instance_parameter *ins_para,struct list *lpublic,struct list *lwlan);          /*返回0表示失败，返回1表示成功*/


int cgiMain()
{  
	char encry[BUF_LEN] = { 0 };
	char *str = NULL; 			   
	struct list *lpublic = NULL;   /*解析public.txt文件的链表头*/
	struct list *lwlan = NULL;     /*解析wlan.txt文件的链表头*/  
	memset(encry,0,sizeof(encry));
	lpublic=get_chain_head("../htdocs/text/public.txt");
	lwlan=get_chain_head("../htdocs/text/wlan.txt");

	ccgi_dbus_init();
	cgiFormStringNoNewlines("UN", encry, BUF_LEN);  /*首次进入该页*/
	str=dcryption(encry);
	if(str==NULL)
		ShowErrorPage(search(lpublic,"ill_user"));			/*用户非法*/
	else
		ShowWtpgroupnewPage(encry,lpublic,lwlan);

	release(lpublic);  
	release(lwlan);
	destroy_ccgi_dbus();
	return 0;
}

int ShowWtpgroupnewPage(char *m,struct list *lpublic,struct list *lwlan)
{  
  int i = 0,result = 0,wnum = 0;
  char wid_scope[20] = { 0 };
  int wid_len = 0;
  DCLI_WTP_API_GROUP_ONE *WTPINFO = NULL;
  char select_insid[10] = { 0 };
  instance_parameter *paraHead1 = NULL,*paraHead2 = NULL;
  instance_parameter *pq = NULL;
  char temp[10] = { 0 };
  dbus_parameter ins_para;
  
  
  cgiHeaderContentType("text/html");
  fprintf(cgiOut,"<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>");
  fprintf(cgiOut,"<meta http-equiv=Content-Type content=text/html; charset=gb2312>");
  fprintf(cgiOut,"<title>Wtp</title>");
  fprintf(cgiOut,"<link rel=stylesheet href=/style.css type=text/css>"\
  	"<style type=text/css>"\
  	".a3{width:30;border:0; text-align:center}"\
  	"</style>"
  "</head>"\
  "<script src=/instanceid_onchange.js>"\
  "</script>"\
  "<body>");  
  memset(select_insid,0,sizeof(select_insid));
  cgiFormStringNoNewlines( "INSTANCE_ID", select_insid, 10 );
  if(strcmp(select_insid,"")==0)
  {	
	list_instance_parameter(&paraHead1, INSTANCE_STATE_WEB);	
	if(paraHead1)
	{
		snprintf(select_insid,sizeof(select_insid)-1,"%d-%d-%d",paraHead1->parameter.slot_id,paraHead1->parameter.local_id,paraHead1->parameter.instance_id);
	} 
  }  
  else
  {
	get_slotID_localID_instanceID(select_insid,&ins_para);	
	get_instance_dbus_connection(ins_para, &paraHead1, INSTANCE_STATE_WEB);
  }
  if(cgiFormSubmitClicked("wtpnew_group") == cgiFormSuccess)
  { 
  	if(paraHead1)
	{
		NewWtpgroup(paraHead1,lpublic,lwlan);
	} 
  }
  fprintf(cgiOut,"<form>"\
  "<div align=center>"\
  "<table width=976 border=0 cellpadding=0 cellspacing=0>"\
  "<tr>"\
    "<td width=8 align=left valign=top background=/images/di22.jpg><img src=/images/youce4.jpg width=8 height=30/></td>"\
    "<td width=51 align=left valign=bottom background=/images/di22.jpg><img src=/images/youce33.jpg width=37 height=24/></td>"\
    "<td width=153 align=left valign=bottom id=%s background=/images/di22.jpg>%s</td>",search(lpublic,"title_style"),search(lwlan,"ap"));
    fprintf(cgiOut,"<td width=690 align=right valign=bottom background=/images/di22.jpg>");
	 
    	  fprintf(cgiOut,"<table width=155 border=0 cellspacing=0 cellpadding=0>"\
          "<tr>"\
          "<td width=62 align=center><input id=but type=submit name=wtpnew_group style=background-image:url(/images/%s) value=""></td>",search(lpublic,"img_ok"));
     fprintf(cgiOut,"<td width=62 align=center><a href=wp_wlan.cgi?UN=%s target=mainFrame><img src=/images/%s border=0 width=62 height=20/></a></td>",m,search(lpublic,"img_cancel"));
		  fprintf(cgiOut,"</tr>"\
          "</table>");
				
      fprintf(cgiOut,"</td>"\
    "<td width=74 align=right valign=top background=/images/di22.jpg><img src=/images/youce3.jpg width=31 height=30/></td>"\
  "</tr>"\
  "<tr>"\
    "<td colspan=5 align=center valign=middle><table width=976 border=0 cellpadding=0 cellspacing=0 bgcolor=#f0eff0>"\
      "<tr>"\
        "<td width=12 align=left valign=top background=/images/di888.jpg>&nbsp;</td>"\
        "<td width=948><table width=947 border=0 cellspacing=0 cellpadding=0>"\
            "<tr height=4 valign=bottom>"\
              "<td width=120>&nbsp;</td>"\
              "<td width=827 valign=bottom><img src=/images/bottom_05.gif width=827 height=4/></td>"\
            "</tr>"\
            "<tr>"\
              "<td><table width=120 border=0 cellspacing=0 cellpadding=0>"\
                   "<tr height=25>"\
                    "<td id=tdleft>&nbsp;</td>"\
                  "</tr>");	   	  
  				  fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtplis.cgi?UN=%s target=mainFrame class=top><font id=yingwen_san>AP</font><font id=%s> %s</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"list"));                       
                  fprintf(cgiOut,"</tr>"\
				  "<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtpsearch.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font><font id=yingwen_san> AP</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"Search"));                       
                  fprintf(cgiOut,"</tr>");
		  
		  fprintf(cgiOut,"<tr height=25>"\
					"<td align=left id=tdleft><a href=wp_wtpnew.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font><font id=yingwen_san> AP</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"create")); 		      
		  fprintf(cgiOut,"</tr>");
		  				  		    
		    fprintf(cgiOut,"<tr height=25>"\
  					  "<td align=left id=tdleft><a href=wp_wtpgrouplist.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lwlan,"ap_group_list"));                       
                    fprintf(cgiOut,"</tr>");
		    
		    fprintf(cgiOut, "<tr height=26>"\
		       "<td align=left id=tdleft background=/images/bottom_bg.gif style=\"border-right:0\"><font id=%s>%s</font></td>",search(lpublic,"menu_san"),search(lwlan,"create_apgroup"));   /*突出显示*/
				     fprintf(cgiOut,"</tr>");
		    
				   fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtpver.cgi?UN=%s target=mainFrame class=top><font id=yingwen_san>AP</font><font id=%s> %s</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"mode"));                       
                  fprintf(cgiOut,"</tr>");
				  fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtpdown.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"version_upload"));                       
                  fprintf(cgiOut,"</tr>");	
				  fprintf(cgiOut,"<tr height=25>"\
				  	"<td align=left id=tdleft><a href=wp_verbind.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lwlan,"version_bind"));                       
                  fprintf(cgiOut,"</tr>"\
				  "<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtpupgrade.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lwlan,"batch_update"));                       
                  fprintf(cgiOut,"</tr>");
				  fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_wtpbw.cgi?UN=%s target=mainFrame class=top><font id=yingwen_san>MAC </font><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lwlan,"mac_filter"));                       
                  fprintf(cgiOut,"</tr>");
				  fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_showAutoAp.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font><font id=yingwen_san>AP</font><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"show_auto"),search(lpublic,"menu_san"),search(lpublic,"policy"));                       
                  fprintf(cgiOut,"</tr>");
				  fprintf(cgiOut,"<tr height=25>"\
  					"<td align=left id=tdleft><a href=wp_conAutoAp.cgi?UN=%s target=mainFrame class=top><font id=%s>%s</font><font id=yingwen_san>AP</font><font id=%s>%s</font></a></td>",m,search(lpublic,"menu_san"),search(lpublic,"config_auto"),search(lpublic,"menu_san"),search(lpublic,"policy"));                       
                  fprintf(cgiOut,"</tr>");
                  for(i=0;i<0;i++)
	              {
  				    fprintf(cgiOut,"<tr height=25>"\
                      "<td id=tdleft>&nbsp;</td>"\
                    "</tr>");
	              }
                fprintf(cgiOut,"</table>"\
              "</td>"\
              "<td align=left style=\"background-color:#ffffff; border-right:1px solid #707070; padding-left:30px\">"\
			  "<table width=520 border=0 cellspacing=0 cellpadding=0>"\
  "<tr height=30>"\
	  "<td  width=80  align=right >%s ID:</td>",search(lpublic,"instance"));
	  fprintf(cgiOut,"<td align=left colspan=2>"\
		  "<select name=instance_id id=instance_id style=width:72px onchange=instanceid_change(this,\"wp_wtpgroupnew.cgi\",\"%s\")>",m);  
		  list_instance_parameter(&paraHead2, INSTANCE_STATE_WEB);	 
		  for(pq=paraHead2;(NULL != pq);pq=pq->next)
		  {
			 memset(temp,0,sizeof(temp));
			 snprintf(temp,sizeof(temp)-1,"%d-%d-%d",pq->parameter.slot_id,pq->parameter.local_id,pq->parameter.instance_id);
		  
			 if(strcmp(select_insid,temp) == 0)
			   fprintf(cgiOut,"<option value='%s' selected=selected>%s",temp,temp);
			 else
			   fprintf(cgiOut,"<option value='%s'>%s",temp,temp);
		  } 		  
		  free_instance_parameter_list(&paraHead2);
		  fprintf(cgiOut,"</select>"\
	  "</td>"\
  "</tr>"\
  "<tr height=30>"\
    "<td width=80 align=right >%s ID:</td>",search(lwlan,"ap_group"));

    fprintf(cgiOut,"<td width=180 align=left><input type=text name=wtpgroup_id size=25 maxLength=2 onkeypress=\"return event.keyCode>=48&&event.keyCode<=57\"></td>");
    fprintf(cgiOut,"<td width=270><font color=red>(1--%d)</font></td>",WTP_GROUP_NUM-1);
  fprintf(cgiOut,"</tr>"\
  "<tr height=30>"\
    "<td  width=80  align=right >%s %s:</td>",search(lwlan,"ap_group"),search(lpublic,"name"));
    fprintf(cgiOut,"<td align=left><input type=text name=wtpgroup_name size=25 maxLength=%d onkeypress=\"return event.keyCode!=32\"></td>",WTP_AP_GROUP_NAME_MAX_LEN);
	  fprintf(cgiOut,"<td align=left><font color=red>(%s%d%s)</font></td>",search(lwlan,"most1"),WTP_AP_GROUP_NAME_MAX_LEN,search(lwlan,"most2"));
  fprintf(cgiOut,"</tr>");
  fprintf(cgiOut,"<tr>"\
    "<td><input type=hidden name=UN value=%s></td>",m);
    fprintf(cgiOut,"<td colspan=2><input type=hidden name=INSTANCE_ID value=%s></td>",select_insid);
  fprintf(cgiOut,"</tr>"\
"</table>"\
              "</td>"\
            "</tr>"\
            "<tr height=4 valign=top>"\
              "<td width=120 height=4 align=right valign=top><img src=/images/bottom_07.gif width=1 height=10/></td>"\
              "<td width=827 height=4 valign=top bgcolor=#FFFFFF><img src=/images/bottom_06.gif width=827 height=15/></td>"\
            "</tr>"\
          "</table>"\
        "</td>"\
        "<td width=15 background=/images/di999.jpg>&nbsp;</td>"\
      "</tr>"\
    "</table></td>"\
  "</tr>"\
  "<tr>"\
    "<td colspan=3 align=left valign=top background=/images/di777.jpg><img src=/images/di555.jpg width=61 height=62/></td>"\
    "<td align=left valign=top background=/images/di777.jpg>&nbsp;</td>"\
    "<td align=left valign=top background=/images/di777.jpg><img src=/images/di666.jpg width=74 height=62/></td>"\
  "</tr>"\
"</table>"\
"</div>"\
"</form>"\
"</body>"\
"</html>");	
free_instance_parameter_list(&paraHead1);
return 0;
}

void NewWtpgroup(instance_parameter *ins_para,struct list *lpublic,struct list *lwlan)          
{
	int id = 0,ret = 0; 
	char *endptr = NULL;    
	char ID[10] = { 0 };
	char wtpgroup_name[WTP_AP_GROUP_NAME_MAX_LEN+5] = { 0 };
	char alt[100] = { 0 };
	char max_wtp_name_len[10] = { 0 };
	char max_wtp_num[10] = { 0 };

	memset(ID,0,sizeof(ID));
	cgiFormStringNoNewlines("wtpgroup_id",ID,10); 
	memset(wtpgroup_name,0,sizeof(wtpgroup_name));
	cgiFormStringNoNewlines("wtpgroup_name",wtpgroup_name,WTP_AP_GROUP_NAME_MAX_LEN+5);  

	if(strcmp(ID,"")!=0)                            
	{
		id=strtoul(ID,&endptr,10);					   		
		if((id>0)&&(id<WTP_GROUP_NUM))              
		{
			if(strcmp(wtpgroup_name,"")!=0)           
			{
				if(strlen(wtpgroup_name) > WTP_AP_GROUP_NAME_MAX_LEN)
				{
					  memset(alt,0,sizeof(alt));
					  strncpy(alt,search(lwlan,"wtp_group_name_too_long1"),sizeof(alt)-1);
					  memset(max_wtp_name_len,0,sizeof(max_wtp_name_len));
					  snprintf(max_wtp_name_len,sizeof(max_wtp_name_len)-1,"%d",WTP_AP_GROUP_NAME_MAX_LEN);
					  strncat(alt,max_wtp_name_len,sizeof(alt)-strlen(alt)-1);
					  strncat(alt,search(lwlan,"wtp_name_too_long2"),sizeof(alt)-strlen(alt)-1);
					  ShowAlert(alt);
				}
				else
				{
					  ret = ccgi_create_ap_group_cmd(ins_para->parameter, ins_para->connection, ID, wtpgroup_name);
					  switch(ret)
					  {
					  	case 0:
							  ShowAlert(search(lpublic,"create_success"));
							  break;					  
					  	case 1:
							ShowAlert(search(lpublic,"create_fail"));
							break;
						case 5:
							ShowAlert(search(lpublic,"wtp_group_exist"));
							break;						
						default:
							ShowAlert(search(lpublic,"create_fail"));
							break;


					  }
			    	}
			}
			else
			{
				ShowAlert(search(lpublic,"para_incom"));
			}
		}
		else
		{
			  memset(alt,0,sizeof(alt));
			  strncpy(alt,search(lwlan,"wtp_group_id_illegal1"),sizeof(alt)-1);
			  memset(max_wtp_num,0,sizeof(max_wtp_num));
			  snprintf(max_wtp_num,sizeof(max_wtp_num)-1,"%d",WTP_GROUP_NUM-1);
			  strncat(alt,max_wtp_num,sizeof(alt)-strlen(alt)-1);
			  strncat(alt,search(lwlan,"wtp_id_illegal2"),sizeof(alt)-strlen(alt)-1);
			  ShowAlert(alt);
		}
	}
	else
	{
		ShowAlert(search(lpublic,"para_incom"));   
	}
}
