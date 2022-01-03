//
// Created by mohadeseh on 02/01/2022.
//

#include "types.h"
#include "stat.h"
#include "user.h"

#define THINKING 0
#define HUNGRY 1
#define EATING 2
int { THINKING, HUNGRY, EATING } state[5];

void test(int i) {
    if ((state[(i + 4) % 5] != EATING) &&
        (state[i] == HUNGRY) &&
        (state[(i + 1) % 5] != EATING)) {
        state[i] = EATING;
        sem_release(i);
    }
}

void pickup(int i) {
    state[i] = HUNGRY;
    test(i);
    if (state[i] != EATING)
        sem_acquire(i);
}

void put_down(int i) {
    state[i] = THINKING;
    test((i + 4) % 5);
    test((i + 1) % 5);
}

void init() {
    for (int i = 0; i < 5; i++) {
        state[i] = THINKING;
        sem_init(i, 1);
    }
}

int main(){
    int p[100][2];
    char* readPipes[];
    for (int i = 0; i < 5; ++i) {
        int pid = fork();
        if(pid == 0){
            readPipes[i] = (char*)malloc(2000 * sizeof(char));
            sprintf(readPipes[i], "%d", p[i][0]);
            char* args[] = {(char*)"./philosopher.out", readPipes[i]};
        }
    }
}