#include <stdio.h>
#include <stdlib.h>
#include "GraphSearchMaze.h"
#include "DataTypesMaze.h"
 	

int main()
{	

    const char W='X',O=' ';
    /*char maze[SIZE][SIZE] =
	{{W,W,W,W,W,W,W,W,W,W,W,W},
	 {W,O,O,W,O,O,O,O,O,O,O,W},
	 {W,O,O,W,O,O,W,W,W,W,W,W},
	 {W,O,O,W,O,O,O,O,O,O,O,W},
	 {W,O,O,W,O,O,O,O,O,O,O,W},
	 {W,O,O,W,O,W,O,O,O,O,O,W},
	 {W,O,O,O,O,W,O,O,O,O,O,W},
	 {W,O,O,O,O,W,O,O,W,O,O,W},
	 {W,O,O,O,O,W,O,O,W,O,O,W},
	 {W,O,O,O,O,W,O,O,W,O,O,W},
	 {W,O,O,O,O,W,O,O,W,O,O,W},
	 {W,W,W,W,W,W,W,W,W,W,W,W}};*/
	 
	   char maze[SIZE][SIZE]=
	{{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
	 {W,O,W,W,W,O,O,O,W,O,O,O,O,W,O,O,O,O,O,W},
	 {W,O,O,O,O,O,O,O,W,O,O,O,O,W,O,W,W,W,O,W},
	 {W,W,O,O,O,O,O,O,W,O,O,O,O,W,O,W,O,W,O,W},
	 {W,W,O,O,O,O,O,O,O,O,O,O,O,W,O,O,O,W,O,W},
	 {W,W,O,W,W,W,W,W,W,W,O,O,O,W,O,O,O,W,O,W},
	 {W,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,W},
	 {W,O,O,O,O,O,O,O,O,W,O,O,O,O,O,O,O,O,O,W},
	 {W,O,W,W,W,W,W,O,O,W,O,O,O,W,W,W,W,W,O,W},
	 {W,O,O,O,O,O,O,O,O,W,O,O,O,O,O,O,O,O,O,W},
	 {W,O,O,O,O,O,O,O,O,W,O,O,O,O,O,O,O,O,O,W},
	 {W,O,O,W,W,W,O,O,O,W,O,O,O,O,O,O,O,O,O,W},
	 {W,O,O,W,O,O,O,O,O,O,O,O,O,O,W,O,O,O,O,W},
	 {W,O,O,W,O,O,O,O,O,O,O,O,O,O,W,O,O,O,O,W},
	 {W,O,O,W,O,W,O,O,O,O,O,O,O,O,W,O,O,O,O,W},
	 {W,O,O,W,O,W,O,O,O,O,O,O,O,O,W,O,O,W,W,W},
	 {W,O,O,W,O,W,W,W,W,W,W,O,O,O,W,O,O,O,O,W},
	 {W,O,O,W,O,W,O,O,O,O,O,O,O,O,W,O,O,O,O,W},
	 {W,O,O,O,O,W,O,O,O,O,O,O,O,O,W,O,O,O,O,W},
	 {W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W}};
	 

    Node root, *goal;
    State *goal_state = NULL;
    enum METHODS method;
    int Max_Level, level, i, j;
    	
	for(i=0;i<SIZE;i++){
		printf("\n");
	 	for(j=0;j<SIZE;j++){
	 		printf("%c ",maze[i][j]);
		}
		 	
    }
    
   
   
    // This part must be updated if a new algorithm is added. 
    printf("\n1 --> Breast-First Search\n");
    printf("2 --> Uniform-Cost Search\n");
    printf("3 --> Depth-First Search\n");
    printf("4 --> Depth-Limited Search\n");
    printf("5 --> Iterative Deepening Search\n");
    printf("6 --> Greedy Search\n");
    printf("7 --> A* Search\n");
    printf("Select a method to solve the problem: ");
    scanf("%d", &method);
    if(method==DepthLimitedSearch){
	    printf("Enter maximum level for depth-limited search : ");                         
	    scanf("%d", &Max_Level);                  
	}     
    
    // Creating the root node ... 
    root.parent    = NULL;
    root.path_cost = 0;
    root.action    = NO_ACTION;
    root.Number_of_Child = 0;
    do{	
	    printf("======== SELECTION OF INITIAL STATE =============== \n");
	    printf("Enter the coordinate of starting point\n ");
	    root.state     = *(Create_State());
	    
	    if(PREDETERMINED_GOAL_STATE)  // User will determine the goal state if it is true
	    {
		    printf("======== SELECTION OF GOAL STATE =============== \n"); 
		    printf("Enter the coordinate of goal state\n ");
		    goal_state = Create_State();
	    }
    }while(maze[root.state.x][root.state.y]=='X' || maze[goal_state->x][goal_state->y]=='X');
    
    if(method==GreedySearch || method==AStarSearch){
        root.state.h_n  = Compute_Heuristic_Function(&(root.state), goal_state);
        goal_state->h_n = 0;                 
	}  
    	
    switch(method) 
    {
        case BreastFirstSearch: 
        case GreedySearch:               
            goal = First_GoalTest_Search_TREE(method, &root, goal_state);
			  break; 
		case DepthFirstSearch: 	
		case DepthLimitedSearch: 
			goal = DepthType_Search_TREE(method, &root, goal_state, Max_Level);  break;  
        case IterativeDeepeningSearch:
            for(level=0; TRUE ;level++){
            	goal = DepthType_Search_TREE(method, &root, goal_state, level);
            	if(goal!=FAILURE){
            		printf("The goal is found in level %d.\n", level); 
            		break;
				}		
			}
            break;     
        case UniformCostSearch: 
        case AStarSearch:     
            goal = First_InsertFrontier_Search_TREE(method, &root, goal_state);  break;      
     
        default: 
            printf("ERROR: Unknown method.\n");  
            exit(-1);    
    }
	
	maze[root.state.x][root.state.y] = 'o';
    Show_Solution_Path(goal, maze);
    printf("\nSolution path is:\n");
    for(i=0;i<SIZE;i++){
		printf("\n");
	 	for(j=0;j<SIZE;j++){
	 		printf("%c ",maze[i][j]);
		}
		 	
    }
  	
    return 0;
}


