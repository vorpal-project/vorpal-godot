
#include "register_types.h"
#include "object_type_db.h"
#include "reference.h"

// Wrap for oda
#include "engine.h"

namespace {

class ODAModule : public Reference {
  OBJ_TYPE(ODAModule, Reference);
  protected:
    static void _bind_methods () {
      // nothing;
    }
  private:
    oda::godot::Engine engine;
};

} // unnamed namespace

void register_openda_types () {
  ObjectTypeDB::register_type<ODAModule>();
}

void unregister_openda_types () {
  // nothing at all?
}

