#include <behavior_tree.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BehaviorTree");
    try
    {
        int TickPeriod_milliseconds = 1000;


        BT::ROSAction* go_stright = new BT::ROSAction("go_stright");
        BT::ROSAction* rotate = new BT::ROSAction("rotate");
        BT::ROSCondition* obstacle_encounter = new BT::ROSCondition("obstacle_encounter");
        BT::FallbackNode* fallback = new BT::FallbackNode("fb1");
        BT::SequenceNodeWithMemory* sequence1 = new BT::SequenceNodeWithMemory("sqm1");

        sequence1->AddChild(fallback);
        fallback->AddChild(obstacle_encounter);
        fallback->AddChild(go_stright);

        sequence1->AddChild(rotate);

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
