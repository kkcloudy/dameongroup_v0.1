#!/bin/sh
#
###########################################################################
#
#              Copyright (C) Autelan Technology
#
#This software file is owned and distributed by Autelan Technology 
#
############################################################################
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
#ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
#WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
#DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
#ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
#(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
#LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
#ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
#(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
#SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##############################################################################
#
# 
#
# CREATOR:
# autelan.software.team
# 
# DESCRIPTION: 
# rip_timer_base.sh on timer1 timer2 timer3
#rip_timer_base.sh off#    
#############################################################################

source vtysh_start.sh

if [ $# -eq 4 ] ; then
	if [ $1 = "on" ] ; then
		cmdstr="
		configure terminal
		router rip
		timers basic $2 $3 $4
		"
	else
		exit -2
	fi
elif [ $# -eq 1 ] ; then
        if [ $1 = "off" ] ; then
	cmdstr="
	configure terminal
	router rip
	no timer basic
	"
	else
		exit -3
	fi
else
	exit -4
fi
#	echo $cmdstr
	vtysh -c "$cmdstr"
	if [ $? -eq 0 ] ; then
	exit 0
	else
	exit -1
	fi



