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

struct msgbuf{
    long mtype;
    char mtext[1024];
}msgp;

int main(){
    key_t key = ftok("file1.txt",60);
    id = msgget(key, IPC_CREAT|0666);
    printf("======SERVER======\n");
    while(1){
        msgrcv(id, &msgp, 1024, 0, 0);
        printf("message from process id: %ld\n", msgp.mtype);
        for(int i = 0; i < strlen(msgp.mtext); i++){
            if(msgp.mtext[i] <= 'z' && msgp.mtext[i] >= 'a')msgp.mtext[i] -= 32;
        }
        msgsnd(id, &msgp, 1024, 0);
    }
}