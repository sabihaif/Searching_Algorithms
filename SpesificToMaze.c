/* 
    These functions are compulsory for tree search algorithms but they are specific
    to problems. More clearly, and you must must update their blocks but do not change
    their input and output parameters.
    
    Also, you can add new functions at the end of file by declaring them in TREE_SEARCH.h
*/
#include "GraphSearchMaze.h"
#include "DataTypesMaze.h"
#include <stdio.h>
#include <stdlib.h>

//______________________________________________________________________________
State* Create_State()
{
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 
   
        do{ 
	    	printf("x point:");
	    	scanf("%d", &state->x);
	    }while(state->x<0 || state->x>SIZE);	
	    do{
	    	printf("y point:");
	        scanf("%d", &state->y);
	    }while(state->y<0 || state->y>SIZE);	
    return state;    
}

//______________________________________________________________________________

void Print_State(const State *const state)
{
printf("(x,y) = (%d,%d)",state->x, state->y); 
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
   switch(action){
         case  Go_Left:      printf("Go_Left"); break;
         case  Go_Right:     printf("Go_Right"); break;
         case  Go_Up:        printf("Go_Up"); break;
         case  Go_Down:      printf("Go_Down"); break;

    }        
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{    
    
   char W='W',O='O';
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
	 
	State new_state; 
    if(action == 0){
		 	new_state.x = parent_state->x-1;
		 	new_state.y = parent_state->y;
		 	if(maze[new_state.x][new_state.y]=='W' || (new_state.x<0 || new_state.y<0) || (new_state.x>SIZE || new_state.y>SIZE)) 
	              return FALSE;
        else{     
              trans_model->new_state = new_state;
              trans_model->step_cost = 1; 
         }     
         return TRUE;
    }
	 
	if(action == 1){
	 	new_state.x = parent_state->x+1;
	 	new_state.y = parent_state->y;
	 	if(maze[new_state.x][new_state.y]=='W' || (new_state.x<0 || new_state.y<0) || (new_state.x>SIZE || new_state.y>SIZE)) 
              return FALSE;
         else{     
              trans_model->new_state = new_state;
              trans_model->step_cost = 1; 
         }     
         return TRUE;
	 }
	 	
    if(action == 2){
	 	new_state.x = parent_state->x;
	 	new_state.y = parent_state->y-1;
	 	if(maze[new_state.x][new_state.y]=='W' || (new_state.x<0 || new_state.y<0) || (new_state.x>SIZE || new_state.y>SIZE)) 
              return FALSE;
         else{     
              trans_model->new_state = new_state;
              trans_model->step_cost = 1; 
         }     
         return TRUE;
	 }
	 		
	 if(action == 3){
	 	new_state.x = parent_state->x;
	 	new_state.y = parent_state->y+1;
	 	if(maze[new_state.x][new_state.y]=='W' || (new_state.x<0 || new_state.y<0) || (new_state.x>SIZE || new_state.y>SIZE)) 
              return FALSE;
         else{     
              trans_model->new_state = new_state;
              trans_model->step_cost = 1; 
         }     
         return TRUE;
	 }
	 		
}

int Compute_Heuristic_Function(const State *const state, const State *const goal)
{
  
  return(abs(goal->x-state->x) + abs(goal->y-state->y));
          
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS ==========================

