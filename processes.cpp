#include "tinbes.h"

#define TABLE_SIZE 25
#define RUNNING 'r'
#define PAUSED 'p'

string processName[TABLE_SIZE];
int id[TABLE_SIZE];
char state[TABLE_SIZE];
long addr[TABLE_SIZE];
int noOfProcesses = 0;
int idCounter = 0;

void fixLists(int x){

  for(int i = x; i < noOfProcesses; i++){
    id[i] = id[i+1];
    state[i] = state[i+1];
    addr[i] = addr[i+1];
    processName[i] = processName[i+1];
  }  
}

int newProcess(string name, long address) {
  processName[noOfProcesses] = name;
  id[noOfProcesses] = idCounter;
  addr[noOfProcesses] = address; 
  state[noOfProcesses] = 'p';

  noOfProcesses++;
  return idCounter++;
}

void removeProcess(int i) {
  
  for (int j = i; j < noOfProcesses; j++) {
    processName[j] = NULL;
    id[j] = NULL;
    addr[j] = NULL; 
    state[j] = NULL;
  }
  fixLists(i);
  noOfProcesses--;
}

void executeProcesses() {
  long newAddr;
  for (int i = 0; i < noOfProcesses; i++) {
    if (state[i] == RUNNING) {

      // TO DO

      if (newAddr == 0) {
        cout << "Process \"" << processName[i] << "\" has terminated." << endl;
        removeProcess(i--);
      } else {
        addr[i] = newAddr;
      }
    }
  }
}

void listProcesses() {
  for (int i = 0; i < noOfProcesses; i++) {
    cout << id[i] << ' ' << processName[i] << ' ' << state[i] << endl;
  }
}

int findProcess(int i) {
  for (int j = 0; j < noOfProcesses; j++) {

    // TO DO

  }
  return -1;
}

void suspendProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == PAUSED) {
    cout << "Process already paused." << endl;
  }
  else {

    // TO DO

  }
}

void resumeProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == RUNNING) {
    cout << "Process already running." << endl;
  }
  else {

    // TO DO

  }
}

void killProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
  } else {

    // TO DO

  }
}

int main() {
  unblockCin();
  string command;
  while (true) {
    if (charactersAvailable()) {
      command = readLine();
      if (command == "RUN") {
        string name = readLine();
        long address = stoi(readLine());
        cout << newProcess(name, address) << endl;
      }
      if (command == "LIST") {
        listProcesses();
      }
      if (command == "SUSPEND") {
        int i = stoi(readLine());
        suspendProcess(i);
      }
      if (command == "RESUME") {
        //To DO
      }
      if (command == "KILL") {
        //To DO
      }
    }
    else {
      executeProcesses();
    }
  }
}
