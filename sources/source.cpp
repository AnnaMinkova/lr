#include "header.hpp"

#include <google/protobuf/repeated_field.h>

#include <mutex>
#include <string>
#include <shared_mutex>
#include <thread>
#include <set>

void makeSuggestionsJson() {
  std::string json = R"([
  {
    "id": "hel",
    "name": "hello world",
    "cost": 70
  },
  {
    "id": "hel",
    "name": "hello",
    "cost": 10
  },
  {
    "id": "hel",
    "name": "helm",
    "cost": 200
  }
])";
  std::ofstream fout{"suggestions.json"};
  fout << json;
  fout.close();
}

bool operator< (const Suggestion& lhs, const Suggestion& rhs) {
  return (lhs.cost < rhs.cost) ||
         (lhs.cost == rhs.cost && lhs.id < rhs.id) ||
         (lhs.cost == rhs.cost && lhs.id == rhs.id && lhs.name < rhs.name);
}

void from_json(const nlohmann::json& j, Suggestion& s) {
  j.at("id").get_to(s.id);
  j.at("name").get_to(s.name);
  j.at("cost").get_to(s.cost);
}
