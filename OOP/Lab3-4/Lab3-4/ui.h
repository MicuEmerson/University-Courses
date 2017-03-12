#pragma once
#include "controller.h"

typedef struct {

	Controller *ctrl;

}UI;

UI *create_ui(Controller *ctrl);
void delete_ui(UI* u);
void start_ui(UI* u);
