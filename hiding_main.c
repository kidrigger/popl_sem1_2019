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

int main() {
  Person per;
  DateTime dob = {.day = 16, .mon = 3, .year = 1998};
  make_person(&per, "Anish Bhobe", MALE, 21, dob, 12345678, 42.0f, "9820601442",
              false);
  // printf("%s:%d\n", per.name, per.age);
  printf("%s:%d\n", get_name(&per), get_age(&per));
}
