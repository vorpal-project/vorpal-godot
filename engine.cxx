
#include "engine.h"

#include <oda/oda.h>

namespace {
using std::string;
using std::vector;
} // unnamed namespace

namespace oda {
namespace godot {

Engine::~Engine () {
  oda::Engine engine;
  if (engine.started())
    engine.finish();
}

bool Engine::start (const vector<string> &patch_paths) {
  return oda::Engine().start(patch_paths).ok();
}

bool Engine::ok () const {
  return oda::Engine().started();
}

size_t Engine::eventInstance (const string &name) {
  oda::Event *event = new oda::Event;
  oda::Engine().eventInstance(name, event);
  events_.push_back(event);
  return events_.size()-1;
}

void Engine::pushCommand (size_t id, const string &cmd) {
  events_[id]->pushCommand(cmd);
}

void Engine::tick (double dt) {
  oda::Engine().tick(dt);
}

} // namespace godot
} // namespace oda

