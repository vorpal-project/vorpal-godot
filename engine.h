
#ifndef ODA_GODOT_ENGINE_H_
#define ODA_GODOT_ENGINE_H_

#include <memory>
#include <queue>
#include <string>
#include <vector>

namespace oda {

class SoundtrackEvent;

namespace godot {

class Engine {
  public:
    ~Engine ();
    bool start (const std::vector<std::string> &patch_paths);
    bool ok () const;
    size_t eventInstance (const std::string &name);
    void pushCommand (size_t id, const std::string &cmd);
    void tick (double dt);
  private:
    std::vector<std::shared_ptr<SoundtrackEvent>> events_;
    //std::queue<size_t> free_ids_;
};

} // namespace godot
} // namespace oda

#endif // ODA_GODOT_ENGINE_H_

