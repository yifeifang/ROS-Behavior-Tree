#include <behavior_tree.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BehaviorTree");
    try
    {
        int TickPeriod_milliseconds = 1000;


        BT::ROSAction* nav_phy = new BT::ROSAction("nav_phy");
        BT::ROSAction* moveit_final = new BT::ROSAction("moveit_final");
        BT::ROSAction* idle = new BT::ROSAction("idle");
        BT::ROSCondition* fake_condition = new BT::ROSCondition("fake_condition");
        BT::SequenceNode* seq1 = new BT::SequenceNode("sqm1");
        BT::SequenceNodeWithMemory* seqm1 = new BT::SequenceNodeWithMemory("seqm1");

        seq1->AddChild(fake_condition);
        seq1->AddChild(nav_phy);

        seqm1->AddChild(seq1);
        seqm1->AddChild(moveit_final);
        seqm1->AddChild(idle);
        Execute(seqm1, TickPeriod_milliseconds);
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
