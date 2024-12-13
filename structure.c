#include<stdio.h>

struct Student {
    char name[50];
    int id;
    int age;
};

void main() {
    
    struct Student student1 = {"Steeve", 135, 21};
    printf("Student Name: %s\n", student1.name);
    printf("Student ID: %d\n", student1.id);
    printf("Student Age: %d\n", student1.age);
}

