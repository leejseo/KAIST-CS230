#include <stdio.h>
#include "ipc_test.h"

// Do not modify this file

int main() {  
    msg_queue_send("asdf", 0);
    printf("%s\n", msg_queue_rcv(0));
    
    shm_mem_send("asdf", 0);
    printf("%s\n", shm_mem_rcv(0));
}
