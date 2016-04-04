
#ifndef ODA_GODOT_ENGINE_H_
#define ODA_GODOT_ENGINE_H_

#include <string>
#include <vector>

namespace oda {
namespace godot {

class Engine {
  public:
    Engine (const std::vector<std::string> &patch_paths);
    bool ok () const;
    ~Engine ();
};

} // namespace godot
} // namespace oda

#endif // ODA_GODOT_ENGINE_H_

