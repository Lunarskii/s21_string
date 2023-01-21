#include "smain.h"

int main(void) {
  Suite *list[] = {st_sscanf(), st_sprintf(), st_20funcs(), NULL};
  for (Suite **current_testcase = list; *current_testcase != NULL;
       current_testcase++) {
    SRunner *sr = srunner_create(*current_testcase);

    srunner_run_all(sr, CK_ENV);  // CK_VERBOSE - ALL
    srunner_free(sr);
  }

  return 0;
}
