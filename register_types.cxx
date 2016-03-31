
#include "register_types.h"
#include "object_type_db.h"
#include "reference.h"

// Wrap for oda
#include "engine.h"

#include <vector>
#include <string>

namespace {

using std::string;
using std::vector;

const vector<string> paths = {"patches"}

class ODAModule : public Reference {
  OBJ_TYPE(ODAModule, Reference);
  public:
    ODAModule () : engine_(paths) {}
  protected:
    static void _bind_methods () {
      ObjectTypeDB::bind_method(
    }
  private:
    oda::godot::Engine engine_;
};

} // unnamed namespace

void register_openda_types () {
  ObjectTypeDB::register_type<ODAModule>();
}

void unregister_openda_types () {
  // nothing at all?
}

