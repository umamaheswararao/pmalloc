/****************************************************************************************
 Persist Memory allocator
 *****************************************************************************************/

#ifndef PMALLOC_H
#define PMALLOC_H 1

#include <config.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

#define PMALLOC_KEYS		255

extern void *pmopen(const char *fn, void *baseaddr, size_t initial_size);

extern void pmclose(void* md);

extern void * pmalloc(void *, size_t);

extern void * pmalloc_check(void *, size_t, void *);

extern void * pmrealloc(void *, void *, size_t);

extern void * pmrealloc_check(void *, void *, size_t, void *);

extern void * pmcalloc(void *, size_t, size_t);

extern void * pmcalloc_check(void *, size_t, size_t, void *);

extern void pmfree(void *, void *);

extern void pmfree_check(void *, void *, void *);

extern void * pmalign(void *, size_t, size_t);

extern void * pmvalloc(void *, size_t);

extern void pmcheck(void *, void (*)(void *, void *, int));

extern struct mempoolstats pmstats(void *);

extern void * pmalloc_attach(int, void *, size_t);

extern void * pmalloc_detach(void *);

extern int pmalloc_setkey(void *, int, void *);

extern void * pmalloc_getkey(void *, int);

extern int pmalloc_errno(void *);

extern int pmtrace(void);

extern void * p_addr(void *, void *);

extern void * e_addr(void *, void *);

extern void * b_addr(void *);

#endif  /* PMALLOC_H */
