#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<pthread.h>

int id;
char tempb[1024];

struct msgbuf{
    long mtype;
    char mtext[1024];
}msgp, msgpx;

void *reader(void *arg){
    msgp.mtype = getpid();
    while(1){
        memset(msgp.mtext, 0, sizeof(msgp.mtext));
        msgrcv(id, &msgp, 1024, getpid(), 0);
        printf("Server sent: \t\t%s\n", msgp.mtext);
    }
}

void *writer(void *arg){
    while(1){
        msgpx.mtype = getpid();
        printf("Send msg: \t\t");
        memset(msgpx.mtext, 0, sizeof(msgpx.mtext));
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        scanf("%s", buffer);
        strcpy(msgpx.mtext, buffer);
        msgsnd(id, &msgpx, 1024, 0);
    }
}

int main(){
    key_t key = ftok("file1.txt", 60);
    id = msgget(key, IPC_CREAT|0666);
    printf("======CLIENT1======\n");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, reader, NULL);
    pthread_create(&t2, NULL, writer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2,NULL);
}