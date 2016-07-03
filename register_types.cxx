
#include "register_types.h"

// Godot headers
#include "dvector.h"
#include "object_type_db.h"
#include "reference.h"
#include "ustring.h"

// Wrap for oda
#include <oda/oda.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>

namespace oda {
namespace godot {

using std::shared_ptr;
using std::string;
using std::vector;

class ODAModule : public Reference {
  OBJ_TYPE(ODAModule, Reference);
 public:
  bool start(const String &path) {
    return engine_.start(vector<string>(1, path.ascii().get_data())).ok();
  }
  bool ok() const { return engine_.started(); }
  int eventInstance(const String &name) {
    shared_ptr<oda::SoundtrackEvent> event;
    oda::Status status = engine_.eventInstance(name.ascii().get_data(), &event);
    if (status.ok()) {
      events_.push_back(event);
      return events_.size()-1;
    }
    std::cout << "[ODA-wrap] Failed to instanciate event '"
              << name.ascii().get_data() << "'" << std::endl;
    std::cout << "[ODA-wrap] " << status.description() << std::endl;
    return -1;
  }
  void freeEvent(int id) {
    events_[id].reset();
  }
  void clear() {
    events_.clear();
  }
  void pushCommand (int id, const String &cmd) {
    events_[id]->pushCommand(cmd.ascii().get_data());
  }
  void pushCommand1f (int id, const String &cmd, float arg) {
    events_[id]->pushCommand(cmd.ascii().get_data(), arg);
  }
  void setEventPosition (int id, float x, float y, float z) {
    events_[id]->setAudioSource(x, y, z);
  }
  void tick (double dt) {
    engine_.tick(dt);
  }
 protected:
  static void _bind_methods () {
    ObjectTypeDB::bind_method("ok", &ODAModule::ok);
    ObjectTypeDB::bind_method("start", &ODAModule::start);
    ObjectTypeDB::bind_method("event_instance", &ODAModule::eventInstance);
    ObjectTypeDB::bind_method("free_event", &ODAModule::freeEvent);
    ObjectTypeDB::bind_method("clear", &ODAModule::clear);
    ObjectTypeDB::bind_method("set_event_position",
                              &ODAModule::setEventPosition);
    ObjectTypeDB::bind_method("push_command", &ODAModule::pushCommand);
    ObjectTypeDB::bind_method("push_command_1f", &ODAModule::pushCommand1f);
    ObjectTypeDB::bind_method("tick", &ODAModule::tick);
  }
 private:
  oda::Engine                               engine_;
  vector<shared_ptr<oda::SoundtrackEvent>>  events_;
};

} // namespace godot
} // namespace oda

void register_openda_types () {
  ObjectTypeDB::register_type<oda::godot::ODAModule>();
}

void unregister_openda_types () {
  // nothing at all?
}
