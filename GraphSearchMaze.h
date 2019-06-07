#ifndef TREE_SERACH_H
#define TREE_SERACH_H


#include "DataTypesMaze.h"


// ==================== WRITE YOUR OPTIONAL COMMANDS ===========================
#define CITY_NUMBER  20

// ========  YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) COMMANDS ============ 
#define PREDETERMINED_GOAL_STATE  1
#define ACTIONS_NUMBER  4
#define MAX_SEARCHED_NODE 100000000

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================
#define NO_ACTION  0
#define TRUE       1
#define FALSE      0
#define FAILURE    NULL
#define SIZE 20

// =========  YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DECLARATIONS =======
State* Create_State();
void Print_State(const State *const state);
void Print_Action(const enum ACTIONS action);
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model);
int Compute_Heuristic_Function(const State *const state, const State *const goal); 

// ======= YOU DO NOT NEED TO CHANGE THIS COMPULSORY DECLARATIONS ==============
Node* First_GoalTest_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state);
Node* First_InsertFrontier_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state);
Node* DepthType_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state, const int Max_Level);
Node* Child_Node(Node *const parent, const enum ACTIONS action); 
Queue* Start_Frontier(Node *const root);
int Empty(const Queue *const frontier);
Node* Pop(Queue **frontier);
void Insert_FIFO(Node *const child, Queue **frontier);
void Insert_LIFO(Node *const child, Queue **frontier);
void Insert_Priority_Queue_UniformSearch(Node *const child, Queue **frontier); 
void Insert_Priority_Queue_GreedySearch(Node *const child, Queue **frontier);
void Insert_Priority_Queue_A_Star(Node *const child, Queue **frontier); 
void Print_Frontier(Queue *const frontier);
void Show_Solution_Path(Node *const goal, char maze[SIZE][SIZE]);	
void Print_Node(const Node *const node);
int Level_of_Node(Node *const node);
void Clear_All_Branch(Node *node, int *Number_Allocated_Nodes);
void Clear_Single_Branch(Node *node, int *Number_Allocated_Nodes);
void Warning_Memory_Allocation();
int Goal_Test(const State *const state, const State *const goal_state);
int Compare_States(const State *const state1, const State *const state2);
Node* Frontier_search(Queue *const frontier, const State *const state);
void Remove_Node_From_Frontier(Node *const old_child, Queue **const frontier) ; 

// ==================== WRITE YOUR OPTIONAL DECLARATIONS =======================

#endif

