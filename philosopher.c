//
// Created by mohadeseh on 02/01/2022.
//

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{ 
    int id = (int)(argv[1][0] - '0');
    while(1)
    {
        if(id == 0)
        {
            sem_acquire((id + 1) % 5);
            sem_acquire(id);
        }
        else 
        {
            sem_acquire(id);
            sem_acquire((id + 1) % 5);
        }
        sleep(700);
        sem_release(id);
        sem_release((id + 1) % 5);
    }
    exit();
}