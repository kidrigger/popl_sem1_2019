/* Inheritance.c
 * Author : Anish Bhobe
 * For Principles of Programming Languages, Sem I, 2019 - 20
 * BITS Pilani, K.K.Birla Goa Campus
 * Date : 09 Sept 2019
 */

#ifndef _HIDING_H
#define _HIDING_H

#include <memory.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Class Person
 * Public Members
 * - Name   : char[37]  (40)
 * - Gender : enum      (4)
 * - Age    : int       (4)
 * Private Members
 * - DoB            : DateTime  (12)
 * - Account Number : int       (4)
 * - Credit Score   : float     (4)
 * - Phone Number   : char[11]  (11)
 * - Married        : bool      (1)
 */

typedef struct DateTime_T {
  int day;
  int mon;
  int year;
} DateTime;

typedef enum Gender_T { MALE, FEMALE, NOTA } Gender;

typedef struct Person_T {
  char __opaque[80];
} Person;

void make_person(Person *person, char name[], Gender gender, int age,
                 DateTime dob, int account_no, float credit_score,
                 char phone_num[], bool married);

char *get_name(Person *person);

Gender get_gender(Person *person);

int get_age(Person *person);

#endif /* _HIDING_H */