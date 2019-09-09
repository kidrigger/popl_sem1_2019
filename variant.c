/* variant.c
 * Author : Anish Bhobe
 * For Principles of Programming Languages, Sem I, 2019 - 20
 * BITS Pilani, K.K.Birla Goa Campus
 * Date : 09 Sept 2019
 */

#include <stdbool.h>
#include <stdio.h>

typedef struct variant_t {
  enum type { TYPE_INT, TYPE_FLOAT } dType;
  union data {
    int iData;
    float fData;
  } data;
} variant;

variant add(variant a, variant b) {
  variant res;
  if (a.dType == b.dType) {
    if (a.dType == TYPE_INT) {
      res.dType = TYPE_INT;
      res.data.iData = a.data.iData + b.data.iData;
    } else {
      res.dType = TYPE_FLOAT;
      res.data.fData = a.data.fData + b.data.fData;
    }
  } else {
    res.dType = TYPE_FLOAT;
    float fa = (a.dType == TYPE_FLOAT ? a.data.fData : (float)a.data.iData);
    float fb = (b.dType == TYPE_FLOAT ? b.data.fData : (float)b.data.iData);
    res.data.fData = fa + fb;
  }
  return res;
}

int main() {
  variant var_i;
  var_i.dType = TYPE_INT;
  var_i.data.iData = 42;

  variant var_f;
  var_f.dType = TYPE_FLOAT;
  var_f.data.fData = 42.0f;

  variant result = add(var_i, var_f);
  if (result.dType == TYPE_INT) {
    printf("%d\n", result.data.iData);
  } else {
    printf("%f\n", result.data.fData);
  }

  return 0;
}
