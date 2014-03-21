#include <mruby.h>
#include <mruby/compile.h>
#include "mrubybind.h"

#include <string>
using namespace std;

string emphasize(const char* str) {
  return "* " + string(str) + " *";
}

int main() {
  mrb_state* mrb = mrb_open();

  {
    mrubybind::MrubyBind b(mrb);
    b.bind("emphasize", emphasize);
  }

  int result_code = EXIT_SUCCESS;
  mrb_load_string(mrb, "puts emphasize('Hello, mruby!')");
  if (mrb->exc) {
    mrb_p(mrb, mrb_obj_value(mrb->exc));
    result_code = EXIT_FAILURE;
  }

  mrb_close(mrb);
  return 0;
}
