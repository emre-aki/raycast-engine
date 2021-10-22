/*
 *  m_emalloc.h
 *  raycast-engine
 *
 *
 *  Created by Emre Akı on 3/22/21.
 *
 *
 *  SYNOPSIS:
 *      My very own custom memory allocator. (The prefix 'E' stands for 'Emre'–
 *      I know, I know...)
 *
 *      Exposes a single memory zone available for allocation. There is never
 *      any space between memory blocks, and there will never be two contiguous
 *      free memory blocks.
 */

#ifndef m_emalloc_h

#define m_emalloc_h_E_Memblock E_Memblock
#define m_emalloc_h_E_Init E_Init
#define m_emalloc_h_E_Destroy E_Destroy
#define m_emalloc_h_E_Malloc E_Malloc
#define m_emalloc_h_E_Free E_Free
#define m_emalloc_h_E_Memcpy E_Memcpy
#define m_emalloc_h_E_Relloc E_Realloc
#define m_emalloc_h_E_Verify E_Verify
#define m_emalloc_h_E_Dump E_Dump

typedef struct memblock {
    int size;
    void* owner;
    int tag;
    struct memblock *p_prev, *p_next;
} E_Memblock;

void E_Init (int sizemib);
void E_Destroy (void);
void* E_Malloc (int size, void* requester);
void* E_Free (void* ptr);
void E_Memcpy (void* dest, void* src, int size);
void* E_Realloc (void* ptr, int size);
int E_Verify (void);
void E_Dump (void);

#endif
