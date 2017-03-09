#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#define MAX_CHARACTERS_LINE  80 //Max characters in a line
#define HISTORY_SIZE  5 //Max number of history items

char g_history[HISTORY_SIZE][MAX_CHARACTERS_LINE]; //stores the commands here(history)
int g_command_count = 0; //helper used inside displayHistory()

/**
 * Adds a command to the history.
 * @post The command has been added to the g_history[] data structure.
 */
void addCommandToHistory(char *command) {
  //add the command in to the history here.
//  command[sizeof(command-1)]='\0';
  strcpy(g_history[g_command_count], command);
  g_command_count++;
}
/**
 * This is a helper function that displays the history items.
 * Use this to get an idea of how the history is handled.
 * This should give you some hints on how to implement addCommandToHistory()
 */
void displayHistory() { //DO NOT MODIFY
  int maxItems;
  if (g_command_count < HISTORY_SIZE)
    maxItems = g_command_count;
  else
    maxItems = HISTORY_SIZE;

  for (int i = 1; i <= maxItems; i++) {
    printf("%d \t %s\n", i, g_history[g_command_count-i]);
  }
}

/**
 * The setup function is used to parse the input and prepare the arguments array args[].
 * @returns boolean: valid command parsed.
 */
int setup(char inputBuffer[], char *args[]) {
  int m_inputLength,                //Number of characters that read() reads from the command line
      i,                            //Arbitrary counter
      start,                        //temporary index ( helper) used to indicate the start of the next parameter
      argumentCharacterCounter;     //counter index for where to place the next parameter into args[]
    
  /**
   * Printing shell> and reading in from the standard input
   */
  do {
    printf("shell>");
    fflush(stdout);  //Flush 'shell>' out into the command line
    m_inputLength = read(STDIN_FILENO, inputBuffer, MAX_CHARACTERS_LINE);  //Read from command line into our inputBuffer
  }
  while (inputBuffer[0] == '\n');  //ignore newline characters

  /**
   * Add the command to the history
   */
  addCommandToHistory(inputBuffer);

  argumentCharacterCounter = 0;  //helper variable
  start = -1;  //helper variable.

  if (m_inputLength == 0) {
    exit(0);
  }

  /**
   * Parse the contents of inputBuffer
   */
  for (i = 0; i < m_inputLength; i++) {  //Parse every character in the inputBuffer

    // parse every character
    // use ' ' as the separator between arguments
    // store the arguments into args[] which will eventually be passed back into the shell function.

    // For referencing switch statements and use of copying inputBuffer to args
    // http://stackoverflow.com/questions/19244314/adding-a-history-feature-to-my-simple-shell

      switch (inputBuffer[i]) {

        case ' ' :
          if(start != -1){
            args[argumentCharacterCounter] = &inputBuffer[start];
            argumentCharacterCounter++;
          }

          inputBuffer[i] = '\0';
          start = -1;

          break;

        case '\n' :
          if (start != -1) {
            args[argumentCharacterCounter] = &inputBuffer[start];
            argumentCharacterCounter++;
          }

          inputBuffer[i] = '\0';
          args[argumentCharacterCounter] = NULL;

          break;

        default :
          if (start == -1)
            start = i;
      }
  }
    args[argumentCharacterCounter] = NULL; //just in case the input line was > 80

  return 1;

}  //End of setup()

int shell(int argc, char *argv[]) {

  char m_inputBuffer[MAX_CHARACTERS_LINE];      //buffer to hold the command entered
  char *args[MAX_CHARACTERS_LINE / 2 + 1];      //command line (of 80) has max of 40 arguments
  pid_t m_child;                                //process id of the m_child process
  int m_status;                                 //result from execvp system call*/
  int m_isValidCommand = 1;

  while (42) {  //Program terminates when you enter the 'exit' command


    m_isValidCommand = setup(m_inputBuffer, args);       //get next command

    if (strncmp(m_inputBuffer, "exit", 4) == 0)
      return 0;
    else if (strncmp(m_inputBuffer, "g_history", 7) == 0) {
      displayHistory();
      continue;
    }
      // Start the external command execution here
    if (m_isValidCommand) {
      //TODO: use fork to create a child
      m_child = fork();
      //TODO: use perror() to indicate errors
      if (m_child < 0) {
        perror("An error occurred");
      }
      //TODO: use execvp inside the child to start the program passed in as argument
      else if (m_child == 0) {
        execvp(args[0], args);
      }
      //TODO: make the parent wait for the child
      else {
        wait(&m_status);
      }

    } else {
      printf("Invalid command!\n");
    }
  }


  return 42;
}
