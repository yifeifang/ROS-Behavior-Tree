#include <behavior_tree.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BehaviorTree");
    try
    {
        int TickPeriod_milliseconds = 1000;


        BT::ROSAction* navi_to_door = new BT::ROSAction("navigate_to_door");
        BT::ROSAction* grasping = new BT::ROSAction("grasping");
        BT::ROSCondition* condition = new BT::ROSCondition("door_in_view");
        BT::FallbackNode* fallback = new BT::FallbackNode("fb1");
        BT::SequenceNodeWithMemory* sequence1 = new BT::SequenceNodeWithMemory("sqm1");

        sequence1->AddChild(fallback);
        fallback->AddChild(condition);
        fallback->AddChild(navi_to_door);

        sequence1->AddChild(grasping);

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
