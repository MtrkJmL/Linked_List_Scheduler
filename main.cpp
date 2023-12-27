#include <iostream>
#include <fstream>
#include <string>
#include "ll_scheduler.h"

int main() {
    Node* ll_head = NULL; //linked list head is initialized
    int processID, arrivalTime, runTime, priority;
    int numProcesses;
    int ll_search=0,ll_count=0;
    Node* process_arr = nullptr;
    std::ifstream processesFile; //read input text file
    processesFile.open("processes500.txt");
    processesFile >> numProcesses;
    process_arr = (Node *) malloc(numProcesses*sizeof (Node));
    for (int i = 0; i < numProcesses; ++i) {/* read 4 integers from file */
        processesFile >> processID >> arrivalTime >> runTime >> priority;
        /* construct i'th element of the array */
        process_arr[i] = Node(processID, arrivalTime, runTime, priority);
    }
    processesFile.close();

    int time = 0; // CPU time
    bool CPUBusy = false; // is the CPU currently running a process
    Node *currentProcessLL = NULL; // pointer to the process CPU is currently running
    int processIndex = 0; // index of the process awaiting insertion in RQ

    while (processIndex < numProcesses || ll_head != NULL || CPUBusy == true){
        if (processIndex < numProcesses) // there are processes not inserted into RQ
            if (process_arr[processIndex].arrivalTime == time ){// if the process arrived now insert it into RQ
                Node arrived =process_arr[processIndex];
                Node* new_node_ll = new Node(arrived.processID,arrived.arrivalTime,arrived.runTime,arrived.priority); //call ll_insert to insert in RQ
                ll_insert(&ll_head,new_node_ll,&ll_count);

                processIndex = processIndex + 1;
            }

        if (CPUBusy == true) { // CPU is running a process
            currentProcessLL->runTime = currentProcessLL->runTime - 1;
            // 1 clock cycle elapsed
            if (currentProcessLL->runTime == 0) {// if it was last cycle of the process
                std::cout << currentProcessLL->processID << std::endl; // process finished execution
                CPUBusy = false; // CPU is no longer running a process
            }
        }
        if (CPUBusy == false && ll_head != NULL){  // CPU is not running a process but there are processes awaiting execution

            currentProcessLL = ll_getPrev(&ll_head,&ll_search);
            CPUBusy = true; // CPU is now running a process
        }
        time = time + 1; // 1 clock cycle elapsed
    }
    std::cout <<"Linked List RQ\n"<<ll_search<<" nodes visited for search\n"<<ll_count<<" nodes visited for insertion"<< std::endl;
    return 0;
}
