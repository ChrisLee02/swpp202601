// Implement module maybe_something here
module;
#include <string>
#include <string_view>

module maybe_something;

namespace maybe_something {

// Static member initialization
size_t Something::global_num_objects = 0;
size_t Nothing::global_num_objects = 0;

// Something constructors
Something::Something(const std::string &s) : state(State::VALID) {
  global_num_objects++;
  content = s;
}

Something::Something(std::string &&s)
    : content(std::move(s)), state(State::VALID) {
  global_num_objects++;
}

Something::Something(const Something &other) {
  global_num_objects++;
  content = other.content;
  state = other.state;
}

Something &Something::operator=(const Something &other) {
  content = other.content;
  return *this;
}

Something::Something(Something &&other) noexcept {}

Something &Something::operator=(Something &&other) noexcept {}

Something::~Something() {}

std::string_view Something::view_content() const {}

size_t Something::count() const noexcept {}

// Nothing constructors
Nothing::Nothing() {}

Nothing::Nothing(const Nothing &other) {}

Nothing &Nothing::operator=(const Nothing &other) {}

Nothing::Nothing(Nothing &&other) noexcept {}

Nothing &Nothing::operator=(Nothing &&other) noexcept {}

Nothing::~Nothing() {}

size_t Nothing::count() const noexcept {}

// Export functions
MaybeSomething create_something_by_copying(const std::string &s) {}

MaybeSomething create_something_by_moving(std::string &&s) {}

MaybeSomething create_nothing() {}

std::string_view view(const MaybeSomething &thing) {}

size_t count_siblings(const MaybeSomething &thing) {}

} // namespace maybe_something