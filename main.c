#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Clear input buffer after scanf
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\\n' && c != EOF);
}

//Remove new line after fgets
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\\n') {
        str[len - 1] = '\\0';
    }
}

//Clear the console
void clearConsole() {
    #ifdef _WIN32
        system("cls");  
    
    #elif defined(__unix__) || defined(__APPLE__)
        system("clear");
    
    #else
        // No-op or alternative handling
    
    #endif
    }

//employee_data_structure
struct employee_data{
    int employee_id;
    char name[30];
    char place_of_birth[30];
    char position[50];
    struct employee_data *link;
};

void add_data(struct employee_data **head, int employee_id, char name[], char place_of_birth[], char position[]){
    struct employee_data *new_data = malloc(sizeof(struct employee_data));
    struct employee_data *ptr = *head;

    new_data->employee_id = employee_id;
    strcpy(new_data->name, name);
    strcpy(new_data->place_of_birth, place_of_birth);
    strcpy(new_data->position, position);

    if((*head) == NULL){
        *head = new_data;
        (*head)->link = NULL;
    }else{
        while(*head != NULL && new_data->employee_id <= ptr->link->employee_id){
            
        }
    }
}


int main(){

    

    return 0;
}