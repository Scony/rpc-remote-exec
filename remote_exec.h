/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _REMOTE_EXEC_H_RPCGEN
#define _REMOTE_EXEC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct arg {
	char *val;
	struct arg *next;
};
typedef struct arg arg;

struct rexec_params {
	char *name;
	arg *first;
};
typedef struct rexec_params rexec_params;

struct cin_params {
	char *data;
	int seq;
};
typedef struct cin_params cin_params;

#define REMOTE_EXEC 0x20199280
#define V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define rexec 1
extern  int * rexec_1(rexec_params *, CLIENT *);
extern  int * rexec_1_svc(rexec_params *, struct svc_req *);
#define cin 2
extern  int * cin_1(cin_params *, CLIENT *);
extern  int * cin_1_svc(cin_params *, struct svc_req *);
extern int remote_exec_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define rexec 1
extern  int * rexec_1();
extern  int * rexec_1_svc();
#define cin 2
extern  int * cin_1();
extern  int * cin_1_svc();
extern int remote_exec_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_arg (XDR *, arg*);
extern  bool_t xdr_rexec_params (XDR *, rexec_params*);
extern  bool_t xdr_cin_params (XDR *, cin_params*);

#else /* K&R C */
extern bool_t xdr_arg ();
extern bool_t xdr_rexec_params ();
extern bool_t xdr_cin_params ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_REMOTE_EXEC_H_RPCGEN */
