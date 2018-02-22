#ifndef _TALMECH_NODES_REPORT_NODE_H_
#define _TALMECH_NODES_REPORT_NODE_H_

#include "../agent.h"
#include "ros_node.h"
#include <talmech_msgs/Task.h>

namespace talmech
{
namespace nodes
{
class ReportNode : public ROSNode
{
public:
  typedef boost::shared_ptr<ReportNode> Ptr;
  typedef boost::shared_ptr<const ReportNode> ConstPtr;
  ReportNode(const ros::NodeHandlePtr& nh,
            const ros::Rate& rate = ros::Rate(20));
  virtual ~ReportNode() {}
protected:
  talmech::AgentPtr agent_;
  virtual void readParameters();
private:
  ros::Subscriber task_sub_;
  virtual bool isSettedUp() { return agent_.get(); }
  virtual void controlLoop() { agent_->process(); }
};
typedef ReportNode::Ptr ReportNodePtr;
typedef ReportNode::ConstPtr ReportNodeConstPtr;
}
}

#endif // _TALMECH_NODES_REPORT_NODE_H_
