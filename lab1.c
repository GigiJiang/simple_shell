//
// Created by Ziyi Jiang on 2021/10/6.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void hello(){
    char *pgreeting = "Hi, welcome to Ginger's shell.\nHere you can find interact with the computer through text lines. Enjoy you journey!";
    printf("%s\n",pgreeting);
}

void goodbye(){
    exit(0);
}

void lab_name(){
    printf("202 lab #1\n");
}

void author(){
    printf("Ziyi Jiang, zj644\n");
}


int main(){
    char command[50];
    int a;
    int pid;
    int status;

    while(1) {
        printf("$ ");
        fgets(command, 50, stdin);
        a = strlen(command);
        command[a - 1] = '\0';


        if (strcmp(command, "hello") == 0) {
            hello();
        } else if (strcmp(command, "goodbye") == 0) {
            goodbye();
        } else if (strcmp(command, "lab-name") == 0) {
            lab_name();
        } else if (strcmp(command, "author") == 0) {
            author();
        } else {
            pid = fork();
            if(pid == 0){
                char path[60];
                char *argv[] = {command, NULL};
                sprintf(path, "/bin/%s", command);
                execve(path, argv,NULL);
                perror("No Command");
                exit(EXIT_FAILURE);
            }

            else if(pid > 0){
                wait(&status);
            }
            else{
                printf("Fork Falied");
                exit(1);
            }
        }
    }
        return 0;
}

