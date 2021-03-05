#include "node.h"

bool EmptyNode::Evaluate(
    const Date& date, 
    const std::string& event) const {

    return true;
}

LogicalOperationNode::LogicalOperationNode(
        const LogicalOperation& logical_operation,
        const std::shared_ptr<Node>& left,
        const std::shared_ptr<Node>& right):
    logical_operation_(logical_operation),
    left_node(left),
    right_node(right) {}

bool LogicalOperationNode::Evaluate(
    const Date& date,
    const std::string& event) const {

    switch(logical_operation_) {
        case LogicalOperation::Or:
            return left_node->Evaluate(date, event) || right_node->Evaluate(date, event);
        case LogicalOperation::And:
            return left_node->Evaluate(date, event) && right_node->Evaluate(date, event);
    }
}

DateComparisonNode::DateComparisonNode(
    const Comparison& comp,
    const Date& date):
    comp_(comp),
    date_(date) {}

bool DateComparisonNode::Evaluate(
    const Date& date,
    const std::string& event) const {

    switch (comp_) {
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
    }


}

EventComparisonNode::EventComparisonNode(
    const Comparison& comp,
    const std::string& event): 
    comp_(comp),
    event_(event) {}

bool EventComparisonNode::Evaluate(
    const Date& date,
    const std::string& event) const {

    switch (comp_) {
        case Comparison::Equal:
            return event == event_;
        case Comparison::NotEqual:
            return event != event_;
        case Comparison::Greater:
            return event > event_;
        case Comparison::GreaterOrEqual:
            return event >= event_;
        case Comparison::Less:
            return event < event_;
        case Comparison::LessOrEqual:
            return event <= event_;
    }
}
