#include <stdio.h>
#include <string.h>

#define NAME_LEN 30

/* Definition of a reusable name type */
struct PersonName {
  char first[NAME_LEN + 1];  // First name (null-terminated)
  char last[NAME_LEN + 1];   // Last name  (null-terminated)
//  int k;
};

/* A student contains a name and additional info */
struct Student {
  int id;
  int age;
  char sex;                  // 'M' / 'F' / etc.
  struct PersonName name;   // Nested struct
};

/* Display a full name */
void display_name(struct PersonName name) {
  printf("%s %s\n", name.first, name.last);
}

int main(void) {
  struct Student student;

  /* Accessing nested fields requires two '.' operators */
  strcpy(student.name.first, "Tieniu");
  strcpy(student.name.last,  "Tan");

  display_name(student.name);

  printf("sizeof student: %lu\n", sizeof(struct Student));
  printf("student: %p\n", &student);
  printf("name: %p\n", &student.name);

  return 0;
}
