#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "err.h"

using namespace std;
int main () {
    pid_t pid;
    int counter = 0;
    int i;

    cout << "My process id = " << getpid() << endl;

    for (i = 1; i <= 100; i++) {
        switch ( pid = fork() ) {
            case -1:
                cout << "Error in fork";
                return -1;

            case 0:
                sleep(1);
                counter ++;
                cout << "Child process id = " << getpid() << " " << counter <<  endl;
                return 0;

            default:
                cout << "Parent process. My process id = " << getpid() << endl;
                cout << "Parent process. Value returned by fork() = " << pid << endl;

                if (wait(NULL) == -1) {
                    cout << "Error in wait";
                }
        }
    }  
    return 0;
}
