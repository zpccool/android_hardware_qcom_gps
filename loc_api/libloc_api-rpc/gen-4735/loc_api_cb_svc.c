/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "loc_api_cb.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

void
loc_apicbprog_0x00020001(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		rpc_loc_event_cb_f_type_args rpc_loc_event_cb_f_type_0x00020001_arg;
	} argument;
	union {
		rpc_loc_event_cb_f_type_rets rpc_loc_event_cb_f_type_0x00020001_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case rpc_loc_event_cb_f_type:
		_xdr_argument = (xdrproc_t) xdr_rpc_loc_event_cb_f_type_args;
		_xdr_result = (xdrproc_t) xdr_rpc_loc_event_cb_f_type_rets;
		local = (bool_t (*) (char *, void *,  struct svc_req *))rpc_loc_event_cb_f_type_0x00020001_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!loc_apicbprog_0x00020001_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}
