#define DATATYPE_H
#define DATATYPE_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char major[50];
} Student;


extern Student students[MAX_STUDENTS]; // Khai bao mang toan cuc luu danh sach sinh vien, duoc dinh nghia o file khac
extern int studentCount;               // Khai bao bien dem so luong sinh vien, duoc dinh nghia o file khac


