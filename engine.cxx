
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

bool Engine::ok () const {
  return oda::Engine().started();
}

size_t Engine::eventInstance (const string &name) {
  oda::Event *event = new oda::Event;
  oda::Engine().eventInstance(name, event);
  events_.push_back(event);
  return events_.size();
}

} // namespace godot
} // namespace oda

