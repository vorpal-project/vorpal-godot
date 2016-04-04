
#ifndef ODA_GODOT_ENGINE_H_
#define ODA_GODOT_ENGINE_H_

#include <queue>
#include <string>
#include <vector>

namespace oda {

class Event;

namespace godot {

class Engine {
  public:
    Engine (const std::vector<std::string> &patch_paths);
    bool ok () const;
    size_t eventInstance(const std::string &name);
    ~Engine ();
  private:
    std::vector<Event*> events_;
    //std::queue<size_t> free_ids_;
};

} // namespace godot
} // namespace oda

#endif // ODA_GODOT_ENGINE_H_

