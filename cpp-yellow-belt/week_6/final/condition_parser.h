#pragma once

#include "helpers.h"

#include "node.h"
#include "date.h"

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();
