#include "ipc_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/msg.h>

const int MAX_SIZE = 100;

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} _msgbuf;


/*
    Send a message via message queue
    msg: Message to be sent
    prj_id: ID to create unique ipc key
*/
void msg_queue_send(char *msg, int prj_id) {
    /* 
    Write your code here
    */
    // make file - copied from my code of HW3
    int _file = open("CS230", O_RDWR|O_CREAT, 0644);
    close(_file);
    
    key_t key = ftok("CS230", prj_id); // create key
    int msgid = msgget(key, IPC_CREAT|0644); //msgid
    
    _msgbuf mbuf;
    mbuf.mtype = 1;
    strcpy(mbuf.mtext, msg); // copy message into msgbuf
    
    msgsnd(msgid, &mbuf, MAX_SIZE, IPC_NOWAIT);
}

/*
    Receive a message via message queue
    The program may hang due to no data, consider to handle this case
    Be sure the IPC keys of two process are them same
    Expected output: Message obtained from queue
*/

char ret[100];

char* msg_queue_rcv(int prj_id) {
    /* 
    Write your code here
    */
    key_t key = ftok("CS230", prj_id); // create key
    int msgid = msgget(key, 0);
    
    _msgbuf mbuf;
    msgrcv(msgid, &mbuf, MAX_SIZE, 0, IPC_NOWAIT);
    
    strcpy(ret, mbuf.mtext);
    return ret;
}

/*
    Send a message via shared memory
*/
void shm_mem_send(char *msg, int prj_id) {
    /* 
    Write your code here
    */
    int _file = open("CS230", O_RDWR|O_CREAT, 0644);
    close(_file);
    
    key_t key = ftok("CS230", prj_id); // create key
    int shmid = shmget(key, MAX_SIZE, IPC_CREAT|0644);
    
    char *shmaddr = (char*)shmat(shmid, NULL, 0);
    strcpy(shmaddr, msg);
    shmdt(shmaddr); // release
}

/*
    Receive a message via shared memory
    The program may hang due to no data, consider to handle this case
    Expected output: Message obtained from shared memory
*/
char* shm_mem_rcv(int prj_id) {
    /* 
    Write your code here
    */
    key_t key = ftok("CS230", prj_id); // create key
    int shmid = shmget(key, MAX_SIZE, 0);
    
    char *shmaddr = (char*)shmat(shmid, NULL, 0);
    strcpy(ret, shmaddr);
    shmdt(shmaddr);
    return ret;
}

/*
    General function for IPC sending
    Recommended to not modify this function
*/
void ipc_send(int ipc_type, char *msg, int prj_id) {
    switch (ipc_type) {
    case MSG_QUEUE:
        msg_queue_send(msg, prj_id);
        break;
    case SHM_MEM:
        shm_mem_send(msg, prj_id);
        break;
    default:
        printf("Wrong IPC type! \n");
        break;
    }
}

/*
    General function for IPC receiving
    Recommended to not modify this function
*/
char* ipc_rcv(int ipc_type, int prj_id) {
    char* rcv = NULL;
    
    switch (ipc_type) {
    case MSG_QUEUE:
        rcv = msg_queue_rcv(prj_id);
        break;
    case SHM_MEM:
        rcv = shm_mem_rcv(prj_id);
        break;
    default:
        printf("Wrong IPC type! \n");
        break;
    }
    
    return rcv;
}


