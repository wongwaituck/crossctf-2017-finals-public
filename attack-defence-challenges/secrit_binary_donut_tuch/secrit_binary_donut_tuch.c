#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define PARENT(i)   ((i)/2)
#define LEFTC(i)    (2*(i))
#define RIGHTC(i)   (2*(i)+1)

#define MAX_CAPACITY 64

/* bubble_down */
void f0(uint64_t *heap, int ind)
{
    // Bubbles down zero and negative
    if (LEFTC(ind) >= MAX_CAPACITY) return;
    uint64_t cur = heap[ind];
    uint64_t lc = heap[LEFTC(ind)], rc = heap[RIGHTC(ind)];
    if (cur < lc && lc > rc) {
        heap[ind] = lc;
        heap[LEFTC(ind)] = cur;
        f0(heap, LEFTC(ind));
    } else if (cur < rc) {
        heap[ind] = rc;
        heap[RIGHTC(ind)] = cur;
        f0(heap, RIGHTC(ind));
    }
}

/* extract_max */
int f1(uint64_t *heap)
{
    // BUG: Does not check for heap[0] <= 0 but checks if heap[1] <= 0.
    if (heap[1] <= 0) return -1;
    uint64_t ret = heap[1];
    heap[1] = heap[heap[0]];
    heap[heap[0]] = 0;
    heap[0]--;

    // BUG: "Optimization" that prevents bubbling down negative values
    if (heap[1] > 0)
        f0(heap, 1);
    return ret;
}

/* insert_heap */
void f2(uint64_t *heap, uint64_t val)
{
    // BUG: can insert zero
    if (heap[0] >= MAX_CAPACITY - 1) return;
    heap[0]++;
    uint64_t ind = heap[0];
    heap[ind] = val;
    while(PARENT(ind) > 0) {
        uint64_t p = heap[PARENT(ind)];
        if (val > p) {
            heap[PARENT(ind)] = val;
            heap[ind] = p;
            ind = PARENT(ind);
        } else return;
    }
}

/* set_count */
void f3(uint64_t *heap)
{
    uint64_t c;
    for (c = 1; c < MAX_CAPACITY; c++)
        if (heap[c] <= 0) break;
    heap[0] = --c;
}

/* heapify */
void f4(uint64_t *heap)
{
    uint64_t ind;
    for (ind = MAX_CAPACITY - 1; ind > 0; ind--)
        f0(heap, ind);
}

/* For debugging */
/* verify_heap */
/*
int verify(uint64_t *heap, uint64_t ind)
{
    if (ind >= MAX_CAPACITY || heap[ind] <= 0) return 1;
    if (LEFTC(ind) >= MAX_CAPACITY) return 1;
    if (heap[ind] >= heap[LEFTC(ind)]
        && heap[ind] >= heap[RIGHTC(ind)]
        && verify(heap, LEFTC(ind))
        && verify(heap, RIGHTC(ind)))
        return 1;
    return 0;
}
*/
/*
void dump_heap(uint64_t *heap)
{
    uint64_t i;
    for (i = 0; i < MAX_CAPACITY; i++)
        printf("%lld ", heap[i]);
    printf("\n");
    fflush(stdout);
}
*/

void seed()
{
    time_t t;
    srand((unsigned)time(&t));
}

typedef struct ss {
    uint64_t pad0;
    char *addr;
    uint64_t pad1[4];
    uint64_t heap[MAX_CAPACITY];
} __attribute__((packed)) ss;

ss data;

int main()
{
    char *addr_backup;

    seed();

    data.addr = (char *)malloc(8);
    strcpy(data.addr, "findme!");
    addr_backup = data.addr;

    puts("WIP TESTNIG ORIGINAL EXPLOTI DO NOT STEAL!!");
    puts("===========================================");
    fflush(stdout);
 
    int i;
    for (i = 1; i < MAX_CAPACITY; i++)
        data.heap[i] = rand() % 1000 + 1;
    f4(data.heap);
    f3(data.heap);

    puts("Please enter your test string:");
    fflush(stdout);

    char buf[2 * MAX_CAPACITY];
    fgets(buf, 2 * MAX_CAPACITY, stdin);
    int l = strlen(buf) - 1;

    for (i = 0; i < l; i++) {
        switch(buf[i]) {
            case 'p':
                f4(data.heap);
                break;
            case 'q':
                f1(data.heap);
                break;
            case 'r':
                f3(data.heap);
                break;
            case 's':
                puts("Please enter an integer (base 10):");
                fflush(stdout);
                uint64_t inp;
                char ibuf[32];
                fgets(ibuf, 32, stdin);
                if (sscanf(ibuf, "%llud", &inp) != 1) goto FAIL;
                f2(data.heap, inp);
                break;
            default:
                fflush(stdout);
                goto FAIL;
        }
    }

    if (f1(data.heap) == (uint64_t)addr_backup) {
        puts("Omega good job!");

        FILE *f = fopen("flag.txt", "r");
        char flag[24];
        if (f && fgets(flag, 24, f))
            printf("The flag is: %s\n", flag);
        goto END;
    }

FAIL:
    puts("Nope.");
END:
    printf("Press any key to continue...");
    fflush(stdout);
    getchar();
    return 0;
}
