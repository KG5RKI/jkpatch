/* golden */
/* 1/30/2018 */

#ifndef _PROC_H
#define _PROC_H

#include "jkpatch.h"

struct proc_vm_map_entry {
	vm_offset_t start;
	vm_offset_t end;
	vm_offset_t offset;
	vm_prot_t prot;
};

struct proc *proc_find_by_name(const char *name);
struct proc *proc_find_by_pid(int pid);
int proc_get_vm_map(struct proc *p, struct proc_vm_map_entry **entries, size_t *num_entries);

int proc_rw_mem(struct proc *p, void *ptr, size_t size, void *data, size_t *n, int write);
int proc_read_mem(struct proc *p, void *ptr, size_t size, void *data, size_t *n);
int proc_write_mem(struct proc *p, void *ptr, size_t size, void *data, size_t *n);

#endif
