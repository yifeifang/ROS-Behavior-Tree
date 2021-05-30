#include <behavior_tree.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BehaviorTree");
    try
    {
        int TickPeriod_milliseconds = 1000;


        BT::ROSAction* fake_action2 = new BT::ROSAction("fake_action2");
        BT::ROSAction* fake_action1 = new BT::ROSAction("fake_action1");
        BT::ROSCondition* fake_condition = new BT::ROSCondition("fake_condition");
        BT::FallbackNode* fallback = new BT::FallbackNode("fb1");
        BT::SequenceNode* sequence1 = new BT::SequenceNode("sqm1");

        sequence1->AddChild(fallback);
        fallback->AddChild(fake_condition);
        fallback->AddChild(fake_action1);

        sequence1->AddChild(fake_action2);

        Execute(sequence1, TickPeriod_milliseconds);
        // if(Execute(sequence1, TickPeriod_milliseconds))  // from BehaviorTree.cpp
        // {
            
        //     ros::shutdown();
        // }
    }
    catch (BT::BehaviorTreeException& Exception)
    {
        std::cout << Exception.what() << std::endl;
    }

    return 0;
}
