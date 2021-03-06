/* golden */
/* 1/2/2018 */

#ifndef _RESOLVE_H
#define _RESOLVE_H

#include "jkpayload.h"

// this is really a dependency, called from crt

// data
void *M_TEMP;
const struct sbl_map_list_entry **sbl_driver_mapped_pages;
const uint8_t *mini_syscore_self_binary;
struct sbl_key_rbtree_entry **sbl_keymgr_key_rbtree;
void *fpu_kern_ctx;

/** functions **/
// freebsd/common
int (*printf)(const char *fmt, ...);
int (*vprintf)(const char *fmt, va_list arg);
void *(*malloc)(unsigned long size, void *type, int flags);
void (*free)(void *addr, void *type);
void (*memcpy)(void *dst, const void *src, size_t len);
void *(*memset)(void *ptr, int value, size_t num);
int (*memcmp)(const void *ptr1, const void *ptr2, size_t num);
size_t (*strlen)(const char *str);
void (*pause)(const char *wmesg, int timo);
int (*kthread_add)(void (*func)(void *), void *arg, struct proc *procp, struct thread **newtdpp, int flags, int pages, const char *fmt, ...);
void (*kthread_exit)(void);
int (*proc_rwmem)(struct proc *p, struct uio *uio);
void (*sx_init_flags)(struct sx *sx, const char *description, int opts);
void (*sx_xlock)(struct sx *sx);
void (*sx_xunlock)(struct sx *sx);
void (*mtx_init)(struct mtx *mutex, const char *name, const char *type, int opts);
void (*mtx_lock_spin_flags)(struct mtx *mutex, int flags);
void (*mtx_unlock_spin_flags)(struct mtx *mutex, int flags);
void (*mtx_lock_sleep)(struct mtx *mutex, int flags);
void (*mtx_unlock_sleep)(struct mtx *mutex, int flags);
int (*fpu_kern_enter)(struct thread *td, void *ctx, unsigned int flags);
int (*fpu_kern_leave)(struct thread *td, void *ctx);

// virtual memory
// TODO: define structures for these function's parameters
void (*vm_map_lock_read)(uint64_t map, const char *b, int i);
int (*vm_map_lookup_entry)(uint64_t map, uint64_t start, uint64_t *entries);
void (*vm_map_unlock_read)(uint64_t map, const char *b, int i);
void (*vmspace_free)(uint64_t vm);
uint64_t (*vmspace_acquire_ref)(struct proc *a);

// sce
int (*sceSblServiceMailbox)(unsigned long service_id, uint8_t request[SBL_MSG_SERVICE_MAILBOX_MAX_SIZE], void *response);
int (*sceSblAuthMgrGetSelfInfo)(struct self_context *ctx, struct self_ex_info **info);
void *(*sceSblAuthMgrSmStart)(void **);
int (*sceSblAuthMgrIsLoadable2)(struct self_context *ctx, struct self_auth_info *old_auth_info, int path_id, struct self_auth_info *new_auth_info);
int (*sceSblAuthMgrVerifyHeader)(struct self_context *ctx);
int (*sceSblKeymgrSmCallfunc)(union keymgr_payload *payload);
int (*sceSblPfsKeymgrGenEKpfsForGDGPAC)(struct pfs_key_blob *key_blob);
int (*sceSblPfsSetKey)(uint32_t *ekh, uint32_t *skh, uint8_t *key, uint8_t *iv, int type, int unused, uint8_t is_disc);
int (*sceSblPfsClearKey)(uint32_t ekh, uint32_t skh);
int (*sceSblServiceCrypt)(struct ccp_req *request);
int (*sceSblServiceCryptAsync)(struct ccp_req *request);

// crypto
int (*AesCbcCfb128Encrypt)(uint8_t *out, const uint8_t *in, size_t data_size, const uint8_t *key, int key_size, uint8_t *iv);
int (*AesCbcCfb128Decrypt)(uint8_t *out, const uint8_t *in, size_t data_size, const uint8_t *key, int key_size, uint8_t *iv);
void (*Sha256Hash)(uint8_t hash[0x20], const uint8_t *data, size_t data_size);
void (*Sha256Hmac)(uint8_t hash[0x20], const uint8_t *data, size_t data_size, const uint8_t *key, int key_size);
int (*RsaesPkcs1v15Enc2048)(struct rsa_buffer *out, struct rsa_buffer *in, struct rsa_key *key);
int (*RsaesPkcs1v15Dec2048CRT)(struct rsa_buffer *out, struct rsa_buffer *in, struct rsa_key *key);

void resolve(uint64_t kernbase);

#endif
