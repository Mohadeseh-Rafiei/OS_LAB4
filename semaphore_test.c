//
// Created by mohadeseh on 02/01/2022.
//

#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    for(int i = 0; i < 5; i++)
        sem_init(i, 1);
    for (int i = 0; i < 5; ++i) {
        int pid = fork();
        if(pid == 0)
        {
            char id[] = {(char)(i + '0')};
            char* args[] = {"philosopher", id};
            exec("philosopher", args);
        }
    }
    for(int i = 0; i < 5; i++)
    {
        wait();
    }
    exit();
}