module;
#include <concepts>
#include <expected>
#include <vector>

export module collect;

namespace collect {
export template <std::movable T, std::movable E>
std::expected<std::vector<T>, E>
collect_expected(const std::vector<std::expected<T, E>> &inputs) {
  std::vector<T> res;
  res.reserve(inputs.size());

  for (const std::expected<T, E> &item: inputs) {
    if(!item.has_value()) {
      return std::unexpected(item.error());
    }
    res.push_back(item.value());
  }
  return res;
} 

export template <std::movable T, std::movable E>
std::expected<std::vector<T>, E>
move_collect_expected(std::vector<std::expected<T, E>> &&inputs) {
  std::vector<T> res;
  res.reserve(inputs.size());

  for (std::expected<T, E> &item: inputs) {
    if(!item.has_value()) {
      return std::unexpected(std::move(item).error());
    }
    res.push_back(std::move(item).value());
  }
  return res;
}
} // namespace collect
