// Simple usage for binding function under some module.

#include <mruby.h>
#include <mruby/compile.h>
#include "mrubybind.h"
#include <stdlib.h>

void modfunc(int v) {
  printf("modfunc called: %d\n", v);
}

int main() {
  mrb_state* mrb = mrb_open();

  RClass* mod = mrb_define_module(mrb, "Mod");
  int arena = mrb_gc_arena_save(mrb);
  {
    mrubybind::MrubyBind b(mrb, mod);
    b.bind("modfunc", modfunc);
    b.bind_const("FOO_VALUE", 1234);
  }
  if (mrb->gc.arena_idx != arena) {
    fprintf(stderr, "Arena increased!\n");
    return EXIT_FAILURE;
  }

  mrb_load_string(mrb, "Mod.modfunc(Mod::FOO_VALUE)");
  if (mrb->exc) {
    mrb_p(mrb, mrb_obj_value(mrb->exc));
    return EXIT_FAILURE;
  }

  mrb_close(mrb);
  return EXIT_SUCCESS;
}
