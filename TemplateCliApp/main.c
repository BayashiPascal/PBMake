#include "gset.h"

int main() {
  GSet* set = GSetCreate();
  GSet s = GSetCreateStatic();
  GSetFlush(&s);
  GSetFree(&set);
  return 0;
}
