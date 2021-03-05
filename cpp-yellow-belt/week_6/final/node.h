#pragma once

#include "helpers.h"
#include "date.h"

enum class LogicalOperation {
    And,
    Or,
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

class Node {
public:
    virtual bool Evaluate(
        const Date& date, 
        const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(
        const Date& date, 
        const std::string& event) const override;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(
        const LogicalOperation& logical_operation,
        const std::shared_ptr<Node>& left, 
        const std::shared_ptr<Node>& right);

    bool Evaluate(
        const Date& date, 
        const std::string& event) const override;

private:
    LogicalOperation logical_operation_;
    std::shared_ptr<Node> left_node, right_node;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& comp, const Date& date);

    bool Evaluate(
        const Date& date, 
        const std::string& event) const override;

private:
    const Comparison comp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& comp, const std::string& event);

    bool Evaluate(
        const Date& date, 
        const std::string& event) const override;

private:
    const Comparison comp_;
    const std::string event_;
};
