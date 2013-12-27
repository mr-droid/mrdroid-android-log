#include <android/log.h>
#include "mruby.h"
#include "mruby/string.h"

void mrdroid_android_log_verbose(mrb_state *mrb, mrb_value self) {
  mrb_value tag, msg, trace;

  mrb_get_args(mrb, "ss|o", &tag, &msg, &trace);

  __android_log_write(ANDROID_LOG_VERBOSE, mrb_str_ptr(tag)->ptr, mrb_str_ptr(msg)->ptr);
}

void
mrb_mrdroid_android_log_gem_init(mrb_state* mrb) {
  struct RModule *module_android = mrb_define_module(mrb, "Android");
  struct RClass *class_android_log = mrb_define_class_under(mrb, module_android, "Log");
  mrb_define_method(mrb, class_android_log, "self.verbose", mrdroid_android_log_verbose, MRB_ARGS_ARG(2, 1));
}

void
mrb_mrdroid_android_log_gem_final(mrb_state* mrb) {
}
