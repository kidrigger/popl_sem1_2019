/* Inheritance.c
 * Author : Anish Bhobe
 * For Principles of Programming Languages, Sem I, 2019 - 20
 * BITS Pilani, K.K.Birla Goa Campus
 * Date : 09 Sept 2019
 */

#include "hiding.h"
#include <stdbool.h>
#include <stdio.h>

/*
 * Class Person
 * Public Members
 * - Name
 * - Gender
 * - Age
 * Private Members
 * - DoB
 * - Account Number
 * - Reference Count
 * - Marital Status
 * - Credit Score
 * - Phone Number
 */

typedef struct PersonImpl_T {
  char name[37];
  Gender gender;
  int age;
  DateTime dob;
  int account_no;
  float credit_score;
  char phone_number[11];
  bool married;
} PersonImpl;

void make_person(Person *person, char name[], Gender gender, int age,
                 DateTime dob, int account_no, float credit_score,
                 char phone_num[], bool married) {
  PersonImpl pimpl = {.gender = gender,
                      .age = age,
                      .dob = dob,
                      .account_no = account_no,
                      .credit_score = credit_score,
                      .married = married};
  strcpy(pimpl.name, name);
  strcpy(pimpl.phone_number, phone_num);
  memcpy(person, &pimpl, sizeof(Person));
}

char *get_name(Person *person) {
  PersonImpl *pimpl = (PersonImpl *)person;
  return pimpl->name;
}

Gender get_gender(Person *person) {
  PersonImpl *pimpl = (PersonImpl *)person;
  return pimpl->gender;
}

int get_age(Person *person) {
  PersonImpl *pimpl = (PersonImpl *)person;
  return pimpl->age;
}
