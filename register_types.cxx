
#include "register_types.h"

// Godot headers
#include "object_type_db.h"
#include "reference.h"
#include "ustring.h"

// Wrap for oda
#include "engine.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

const static string paths[1] = {"patches"};

class ODAModule : public Reference {
  OBJ_TYPE(ODAModule, Reference);
  public:
    ODAModule ()
      : engine_(vector<string>(paths, paths + sizeof(paths)/sizeof(string))) {}
    bool ok () const { return engine_.ok(); }
    size_t eventInstance (const String &name) {
      return engine_.eventInstance(name.c_str());
    }
  protected:
    static void _bind_methods () {
      ObjectTypeDB::bind_method("ok", &ODAModule::ok);
      ObjectTypeDB::bind_method("eventInstance", &ODAModule::eventInstance);
    }
  private:
    oda::godot::Engine engine_;
};

void register_openda_types () {
  ObjectTypeDB::register_type<ODAModule>();
}

void unregister_openda_types () {
  // nothing at all?
}

