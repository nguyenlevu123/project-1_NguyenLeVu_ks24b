#include <stdio.h>   // Thu vien nhap xuat co ban (printf, scanf, fgets,...)
#include <stdlib.h>  // Thu vien chua cac ham quan ly bo nho, chuyen doi kieu,...
#include <stdbool.h> // Thu vien ho tro kieu du lieu boolean (true/false)
#include <string.h>  // Thu vien ho tro xu ly chuoi (fgets, strcspn,...)
#define MAX_STUDENTS 100 // Dinh nghia so luong sinh vien toi da trong danh sach
#include "datatype.h"  // Gom dinh nghia struct `Student` (gia su la nhu vay)
#include "funtion.h"   // Gom khai bao cac ham nhu `displayMenu`, `displayStudents`, `addStudent`,...

Student students[MAX_STUDENTS];  // Mang luu danh sach sinh vien
int studentCount = 0;            // Bien dem so luong sinh vien hien co trong danh sach
        
void displayMenu() {
    printf("===============================\n");
    printf("%7sQUAN LY SINH VIEN\n","");  // Can giua tieu de bang cach in 7 dau cach
    printf("===============================\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Sap xep danh sach sinh vien\n");
    printf("6. Thoat\n");
    printf("Nhap lua chon: ");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }

    printf("-----------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-5s | %-20s |\n", "ID", "Ten", "Tuoi", "Nganh hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-5d | %-20s | %-5d | %-20s |\n", 
               students[i].id, students[i].name, students[i].age, students[i].major);
    }

    printf("-----------------------------------------------------------\n");
}


void addStudent() {
    if (studentCount >= MAX_STUDENTS) {  // Kiem tra neu danh sach da day
        printf("Khong the them sinh vien, danh sach da day.\n");
        return;
    }

    Student newStudent;  // Tao mot sinh vien moi de nhap thong tin
    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);  // Nhap ID cua sinh vien

    printf("Nhap ten: ");
    getchar();  // Loai bo ky tu '\n' con sot lai trong bo dem nhap
    fgets(newStudent.name, sizeof(newStudent.name), stdin);  // Nhap ten
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Xoa ky tu xuong dong '\n'

    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);  // Nhap tuoi sinh vien

    printf("Nhap nganh hoc: ");
    getchar();  // Loai bo ky tu '\n' con sot lai trong bo dem nhap
    fgets(newStudent.major, sizeof(newStudent.major), stdin); // Nhap nganh hoc
    newStudent.major[strcspn(newStudent.major, "\n")] = 0; // Xoa ky tu xuong dong '\n'

    students[studentCount++] = newStudent;  // Luu vao danh sach va tang bien dem
    printf("Them sinh vien thanh cong!\n");
}

