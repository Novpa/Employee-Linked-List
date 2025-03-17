# Employee Data Management in Linked List

## Overview

This project is a simple command-line Employee Data Management System written in C. It provides basic functionalities to manage employee information such as adding, viewing, and deleting employee data. The application uses a singly linked list data structure for dynamic storage and management of employee records.

## Features

- **Add Employee Data**: Input employee details including ID, name, date of birth, place of birth, and position.
- **View Employee Data**: Display all stored employee records in a formatted table.
- **Delete Individual Employee Data**: Remove specific employee records using Employee ID.
- **Delete Entire Employee Data**: Clear all employee records from the database.
- **Data Validation**: Ensures input accuracy by validating employee ID, name, place of birth, and position length.
- **Cross-platform Support**: Console clearing compatible with Windows, Linux, and macOS.

## Data Structure

### Employee Data Structure Attributes

- `employee_id`: Integer representing employee's unique ID (up to 5 digits).
- `name`: String holding employee's name (max 100 characters).
- `date_of_birth`: Struct containing day, month, and year of employee's birth.
  - `day`: Integer representing birth day.
  - `month`: Integer representing birth month.
  - `year`: Integer representing birth year.
- `place_of_birth`: String indicating the employee's birthplace (max 100 characters).
- `position`: String specifying employee's job position (max 100 characters).
- `link`: Pointer to the next employee record, forming a linked list.

### Struct Definitions

```c
struct date_of_birth {
    int day;
    int month;
    int year;
};

struct employee_data {
    int employee_id;
    char name[100];
    struct date_of_birth employee;
    char place_of_birth[100];
    char position[100];
    struct employee_data *link;
};
```

## Functions

- `add_data()`: Adds new employee data to the database.
- `print_data()`: Displays all employee data.
- `delete_employee()`: Removes data of a specific employee based on ID.
- `delete_entire()`: Deletes all stored employee data.
- `validate_employee_id()`, `validate_employee_name_pob()`, `validate_employee_position()`: Validates inputs for data accuracy.
- `input_data()`: Collects and validates employee information before insertion.
- `clearInputBuffer()`, `removeNewline()`, `clearConsole()`: Utility functions for managing user inputs and console outputs.

## Usage

To run this program:

1. Compile the C code:

```bash
gcc employee_data.c -o employee_data
```

2. Execute the compiled program:

```bash
./employee_data
```

## Example Output

```
|**********************************************|
|                                              |
|            WELCOME TO THE MAIN MENU          |
|                                              |
|**********************************************|

Please choose an option from the menu below:

|  --------------------------------------------  |
|  1. Input Employee Data                        |
|  2. View Employee Data                         |
|  3. Delete an Employee Data                    |
|  4. Delete All Employee Data                   |
|  5. Exit                                       |
|  --------------------------------------------  |

Choose menu --> 
```

## License

Feel free to use and modify this project according to your needs.
