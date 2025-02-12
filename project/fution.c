#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STUDENTS 100
#include "datatype.h"
#include "funtion.h"

Student students[MAX_STUDENTS];  
int studentCount = 0;            

void pressAnyKeyToExit() { 
    printf("\nPress any key to return...");
    getchar(); // Read Enter key if exists
    getchar(); // Wait for user input
}

void saveStudents() {
    FILE *file = fopen("user.bin", "wb");
    if (file) {
        fwrite(&studentCount, sizeof(int), 1, file);
        fwrite(students, sizeof(Student), studentCount, file);
        fclose(file);
    }
}

void loadStudents(){
    FILE *file = fopen("user.bin", "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        if (studentCount > 0 && studentCount <= MAX_STUDENTS) {
            fread(students, sizeof(Student), studentCount, file);
        } else {
            studentCount = 0; // Reset if data is invalid
        }
    }
}

void displayMenu() {
    printf("===============================\n");
    printf("%7sSTUDENT MANAGEMENT\n", "");
    printf("===============================\n");
    printf("1. Show student list\n");
    printf("2. Add students\n");
    printf("3. Edit student information\n");
    printf("4. Delete student\n"); 
    printf("5. Sort student list\n");
    printf("6. Exit\n");
    printf("Enter selection: ");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("Student list is empty!\n");
        return;
    }

    printf("-----------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-5s | %-16s |\n", "ID", "Name", "Age", "Major");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-5d | %-20s | %-5d | %-16s |\n", 
               students[i].id, students[i].name, students[i].age, students[i].major);
    }

    printf("-----------------------------------------------------------\n");
    saveStudents();
    pressAnyKeyToExit(); // Wait for user input
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {  
        printf("Cannot add student, the list is full.\n");
        return;
    }

    Student newStudent;
    printf("Enter ID: ");
    scanf("%d", &newStudent.id);
    
    getchar();
    
    printf("Enter name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    getchar();

    printf("Enter major: ");
    fgets(newStudent.major, sizeof(newStudent.major), stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = 0;

    students[studentCount++] = newStudent;
    printf("Successfully added student!\n");

    saveStudents();
    pressAnyKeyToExit();
}

void editStudent() {  
    int id, choice, found = 0;

    printf("Enter student ID to edit: "); 
    if (scanf("%d", &id) != 1) { 
        printf("Error: ID must be an integer!\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    for (int i = 0; i < studentCount; i++) { 
        if (students[i].id == id) { 
            found = 1;
            while (1) { 
                printf("\n===== Edit student information ID %d =====\n", id);
                printf("1. Edit name\n");
                printf("2. Edit age\n");
                printf("3. Edit major\n");
                printf("4. Return\n");
                printf("Choice: ");
                if (scanf("%d", &choice) != 1) {
                    printf("Error: Please enter a number!\n");
                    while (getchar() != '\n');
                    continue;
                }
                getchar();

                switch (choice) {
                    case 1:
                        printf("Enter new name: ");
                        fgets(students[i].name, sizeof(students[i].name), stdin);
                        students[i].name[strcspn(students[i].name, "\n")] = '\0';
                        printf("Name updated successfully!\n");
                        break;
                    case 2:
                        printf("Enter new age: ");
                        int newAge;
                        if (scanf("%d", &newAge) != 1 || newAge <= 0) {
                            printf("Error: Age must be a positive integer!\n");
                            while (getchar() != '\n');
                            continue;
                        }
                        students[i].age = newAge;
                        getchar();
                        printf("Age updated successfully!\n");
                        break;
                    case 3:
                        printf("Enter new major: ");
                        fgets(students[i].major, sizeof(students[i].major), stdin);
                        students[i].major[strcspn(students[i].major, "\n")] = '\0';
                        printf("Major updated successfully!\n");
                        break;
                    case 4:
                        return;
                    default:
                        printf("Invalid choice!\n");
                }
            }
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
    
    saveStudents();
    pressAnyKeyToExit();
}

