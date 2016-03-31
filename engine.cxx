
#include "engine.h"

#include <oda/oda.h>

namespace {
using std::string;
using std::vector;
} // unnamed namespace

namespace oda {
namespace godot {

Engine::Engine (const vector<string> &patch_paths) {
  oda::Engine().start(patch_paths);
}

Engine::~Engine () {
  oda::Engine engine;
  if (engine.started())
    engine.finish();
}

} // namespace godot
} // namespace oda

