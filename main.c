#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Clear input buffer after scanf
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Remove new line after fgets
void removeNewline(char *str) {
    size_t len = strlen(str);
    // if (len > 0 && str[len - 1] == '\\n') {
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
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

//Date of birth struct
struct date_of_birth{
    int day;
    int month;
    int year;
};

//employee_data_structure
struct employee_data{
    int employee_id;
    char name[100];
    //Date of Birth
    struct date_of_birth employee;
    char place_of_birth[100];
    char position[100];
    struct employee_data *link;
};

//Function to print data
void print_data(struct employee_data *head){
    struct employee_data *ptr = head;
    printf("\n\n");
    if(ptr == NULL){
        printf("No data recorded!\n");
    }

    printf("============================================================================================\n");
    printf("| %-5s | %-20s | %-11s | %-20s | %-20s |\n", "ID", "Name", "Date of Birth", "Place of Birth", "Position");
    printf("============================================================================================\n\n");
    while(ptr != NULL){

        printf("| %-5d | %-20s | %02d/%02d/%-7d | %-20s | %-20s |\n", ptr->employee_id, ptr->name, ptr->employee.day, ptr->employee.month, ptr->employee.year,ptr->place_of_birth, ptr->position);
        printf("\n____________________________________________________________________________________________\n\n");
        ptr = ptr->link;
    }

    printf("\n\nPress Enter to continue...");
    getchar();
}

//Function for adding data to the list
void add_data(struct employee_data **head, int employee_id, char name[], int day, int month, int year, char place_of_birth[], char position[]){
    struct employee_data *new_data = malloc(sizeof(struct employee_data));

    new_data->employee_id = employee_id;
    strcpy(new_data->name, name);

    new_data->employee.day = day;
    new_data->employee.month = month;
    new_data->employee.year = year;

    strcpy(new_data->place_of_birth, place_of_birth);
    strcpy(new_data->position, position);

    if(*head == NULL ||  new_data->employee_id <= (*head)->employee_id){
        new_data->link = *head;
        *head = new_data;
        printf("\nData has been inserted!\n");
        printf("Press Enter to continue...");
        getchar();
    }else{
        struct employee_data *ptr = *head;

        //Traverse the list 
        while(ptr->link != NULL && ptr->link->employee_id < new_data->employee_id ){
            ptr = ptr->link;
        }
        new_data->link = ptr->link;
        ptr->link = new_data;
        printf("\nData has been inserted!\n");
        printf("Press Enter to continue...");
        getchar();
    }
}


//Function to validate the emplpoyee_id
int validate_employee_id(int employee_id){
    int counter = 0;
    while(employee_id > 0){
        employee_id = employee_id / 10;
        counter++;
    }
    if(counter > 5){
        printf("You enter %d digits, ID only contains 5 digits or less!\n", counter);
        return 0;
    }else{
        return 1;
    }
}

//Function validate employee_name & date of birth (MAX CHAR)
int validate_employee_name_pob(char data[]){
    int length = strlen(data);
    if(length >  30){
        printf("You enter %d character, name or place of birth only contains 30 characters or less!\n\n", length);
        return 0;
    }else{
        return 1;
    }
} 

//Function validate employee position (MAX CHAR)
int validate_employee_position(char position[]){
    int length = strlen(position);
    if(length >  50){
        printf("You enter %d character, position only contains 50 characters or less!\n\n", length);
        return 0;
    }else{
        return 1;
    }
} 

//Function delete list based on employee id
void delete_employee(struct employee_data **head){
    int employee_id;
    struct employee_data *ptr = *head;
    struct employee_data *ptr2 = NULL;
    printf("Enter employee ID to delete!: ");
    scanf("%d", &employee_id);
    getchar();

    if(ptr->employee_id == employee_id){
        ptr2 = ptr;
        *head = ptr->link;
        ptr->link = NULL;
        free(ptr);
    }
    while(ptr->employee_id !=  employee_id && ptr->link != NULL){
        ptr2 = ptr;
        ptr = ptr->link;
    }

    if(ptr->link == NULL){
        ptr2->link = NULL;
    }else{
        ptr2->link = ptr->link;
        ptr->link = NULL;
    }

    printf("\nUpdated database: \n");
    print_data(*head);
    printf("\nData has been deleted!\n");
    printf("Press Enter to continue...");
    getchar();

}

//Function to delete entire data
int delete_entire(struct employee_data **head){


    struct employee_data *ptr = *head;
    struct employee_data *ptr2 = NULL;

    int choice;
    printf("Press 1 to continue or other number to Main Menu!");
    scanf("%d", &choice);
    getchar();

    if(choice != 1){
        return 0;
    }

    while(ptr2 != NULL){
        ptr = ptr->link;
        free(ptr2);
        ptr2 = ptr;
    }

    
    *head = NULL;
    printf("\nEntire data have been deleted!\n");
    printf("\nUpdated database: \n");
    print_data(*head);
    printf("Press Enter to continue...");
    getchar();

}

//Function to validate 5 inputs data
int validate_input_list(struct employee_data *head, int rest){
    int counter = 0;
    
    struct employee_data *ptr = head;

    while(ptr != NULL){
        counter++;
        ptr = ptr->link;
    }
    
    rest = 5 - counter;
    printf("\nTotal Employee recorded: %d\n", counter);

    if(counter >= 5){
        // printf("Database has been filled by 5 list!\n");
        return 0;
    }else{
        // printf("%d slots remaining!\n", rest);
        return rest;
    }
}

// Function input data employee
int input_data(struct employee_data **head){
    int rest = 0;
    int validate_rest = validate_input_list(*head, rest);
    if(validate_rest == 0){
        printf("\nThe list has been full!");
        printf("Press Enter to continue...");
        getchar();
        return 0;
    }else{
        printf("%d Slots empty. Enter your data!\n", validate_rest);
    }

    int employee_id, day, month, year;
    int validate_id, validate_name, validate_place_of_birth, validate_position;
    char name[100];
    char place_of_birth[100];
    char position[100];

    //Inputting data
    do{
        printf("\nEnter Employee ID: ");
        scanf("%d", &employee_id);  
        getchar();
        validate_id = validate_employee_id(employee_id);
    }while (validate_id == 0);
    
    do{
        // removeNewline(name);
        printf("Enter Employee Name: ");
        fgets(name, sizeof(name), stdin);
        validate_name = validate_employee_name_pob(name);
    }while (validate_name == 0);
    removeNewline(name);

    printf("Enter Employee Date of Birth [DAY]: ");
    scanf("%d", &day);
    getchar();

    printf("Enter Employee Date of Birth [MONTH]: ");
    scanf("%d", &month);
    getchar();

    printf("Enter Employee Date of Birth [YEAR]: ");
    scanf("%d", &year);
    getchar();

    do{
        // removeNewline(place_of_birth);
        printf("Enter Employee Place of Birth: ");
        fgets(place_of_birth, sizeof(place_of_birth), stdin);
        validate_place_of_birth = validate_employee_name_pob(place_of_birth);
    }while (validate_place_of_birth == 0);
    removeNewline(place_of_birth);

    do{
        // removeNewline(position);
        printf("Enter Employee Position: ");
        fgets(position, sizeof(position), stdin);
        validate_position = validate_employee_position(position);
    }while(validate_position == 0);
    removeNewline(position);

    //Adding data
    add_data(&(*head), employee_id, name, day, month, year, place_of_birth, position);
}

//Welcome UI
void welcome() {
    printf("\n\n|**********************************************|\n");
    printf("|                                              |\n");
    printf("|            WELCOME TO THE MAIN MENU          |\n");
    printf("|                                              |\n");
    printf("|**********************************************|\n");

    printf("\n");

    printf("   Please choose an option from the menu below:   \n");
    printf("\n");
    printf("|  --------------------------------------------  |\n");
    printf("|  1. Input Employee Data                        |\n");
    printf("|  2. View Employee Data                         |\n");
    printf("|  3. Delete an Employee Data                    |\n");
    printf("|  4. Delete All Employee Data                   |\n");
    printf("|  5. Exit                                       |\n");
    printf("|  --------------------------------------------  |\n");

    printf("\n");

    printf("************************************************\n");
}

int main(){

    int choice;  
    struct employee_data *head = NULL;


do {
    clearConsole();
    welcome();
    printf("\nChoose menu --> ");
    scanf("%d", &choice);
    clearInputBuffer();
    if(choice == 5){
        return 0;
    }
    switch (choice) {
        case 1:
            input_data(&head);
            break;
        case 2:
            print_data(head);
            break;
        case 3:
            delete_employee(&head);
            break;
        case 4:
            delete_entire(&head);
            break;
        case 5:
            printf("\nExiting... Thank you!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            getchar();
            break;
    }
} while (choice != 5);
getchar();
  

    return 0;
}





