/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "callback.h"

bool_t
xdr_params (XDR *xdrs, params *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->data, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->seq))
		 return FALSE;
	return TRUE;
}
