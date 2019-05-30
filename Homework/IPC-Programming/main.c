#include <stdio.h>
#include "ipc_test.h"

// Do not modify this file

int main() {  
    msg_queue_send("asdf", 0);
    printf("%s\n", msg_queue_rcv(0));
    msg_queue_send("as", 0);
    printf("%s\n", msg_queue_rcv(0));
    printf("%d\n", msg_queue_rcv(1)==0);
    shm_mem_send("asdf", 0);
    printf("%s\n", shm_mem_rcv(0));
    shm_mem_send("as", 0);
    printf("%s\n", shm_mem_rcv(0));
    printf("%d\n", shm_mem_rcv(1)==0);
}
