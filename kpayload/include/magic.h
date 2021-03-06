/* golden */
/* 1/2/2018 */

// inspired by fail0verflow, of course
// 4.05

// ref FFFFFFFF8E7C0000

#define __Xfast_syscall							0x30EB30
#define __copyin								0x286DF0
#define __copyout								0x286D70
#define __printf								0x347580
#define __vprintf								0x3475F0
#define __malloc								0x1D1700
#define __free									0x1D18D0
#define __memcpy								0x286CF0
#define __memset								0x1ECB10
#define __memcmp								0x29CD10
#define __strlen								0x1D3640
#define __pause									0x08A7A0
#define __kthread_add							0x1C9890
#define __kthread_exit							0x1C9B60
#define __sx_init_flags							0x27AAF0
#define __sx_xlock								0x27AC20
#define __sx_xunlock							0x27ADB0
#define __mtx_init								0x36EC70
#define __mtx_lock_spin_flags					0x36E640
#define __mtx_unlock_spin_flags					0x36E800
#define __mtx_lock_sleep						0x36E260
#define __mtx_unlock_sleep						0x36E510
#define __fpu_kern_enter						0x39A120
#define __fpu_kern_leave						0x39A220
#define __vm_map_lock_read						0x43DF10
#define __vm_map_lookup_entry					0x43E470
#define __vm_map_unlock_read					0x43DF60
#define __vmspace_free							0x43DB70
#define __vmspace_acquire_ref					0x43DD40
#define __proc_rwmem							0x0ABBB0
#define __sceSblAuthMgrIsLoadable2				0x614A80
#define __sceSblAuthMgrVerifyHeader				0x614AE0
#define __sceSblAuthMgrGetSelfInfo				0x615360
#define __sceSblAuthMgrSmStart					0x6153F0
#define __sceSblKeymgrSmCallfunc				0x5FF500
#define __sceSblPfsKeymgrGenEKpfsForGDGPAC		0x5FFE80
#define __sceSblPfsSetKey						0x600640
#define __sceSblPfsClearKey						0x6007C0
#define __sceSblServiceMailbox					0x606F40
#define __sceSblServiceCrypt					0x5F7820
#define __sceSblServiceCryptAsync				0x5F79B0
#define __AesCbcCfb128Encrypt					0x19D650
#define __AesCbcCfb128Decrypt					0x19D880
#define __Sha256Hash							0x3368E0
#define __Sha256Hmac							0x3369B0
#define __RsaesPkcs1v15Enc2048					0x44C1C0
#define __RsaesPkcs1v15Dec2048CRT				0x1E82A0

#define __sysent						0xF17790
#define __allproc						0x1FE3498
#define __disable_console_output		0x186B0A0
#define __prison0						0xF26010
#define __rootvnode						0x206D250
#define __M_TEMP						0x134B730
#define __fpu_kern_ctx					0x235C6C0
#define __mini_syscore_self_binary 		0x136B3E8
#define __sbl_driver_mapped_pages  		0x234ED68
#define __sbl_keymgr_key_rbtree			0x2370058
