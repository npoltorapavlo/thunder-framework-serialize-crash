#include "Module.h"

#define MAX_LEN (32)
typedef struct _State_Param_t {
  char state[MAX_LEN];
} State_Param_t;

auto getState(JsonObject &response) -> void {
  State_Param_t param;
  param.state[MAX_LEN - 1] = 0;
  response["state"] = string(param.state);
  std::string json;
  response.ToString(json);
  printf("response=%s\n", json.c_str());
}

auto main() -> int {
  for (int i = 0; i < 10000; i++) {
    JsonObject response;
    getState(response);
  }
  return (0);
}
