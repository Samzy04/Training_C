#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void  get_sky_team_name(char* name)//pTeamName is the parameter here
{
   char* ptr = (char*) malloc(10);// Declaring pointer variable ptr and allocating 10 bytes of memory on the heap
   
   //copy team name to pointer
   strcpy(ptr, "Home Comms SW Team");//copying Home Comms SW Team into the pointer
   
   //return team name
   name = ptr;//this line is wrong as it is trying to make name point to the same memory location as ptr so this will not work I think

   free(ptr);//free up uneeded memeory
}
  
int main(void)
{
   char name[10];//declaring name variable which can hold 10 characters max
   char* pTeamName = NULL;  //pTeamName pointer variable declared and is set to NULL  
   
   strcpy(name, "Sky UK");//copying Sky UK to name    
   
   while(1)//infinite loop
   {
       get_sky_team_name(pTeamName); //this is the main problem as stcpy just copies till NULL terminator it does not take into account the number of characters and (Home Comms SW Team) is higher then 10 as  (char name[10]) max it can hold is 10   
       
       //print team name
       printf("%s: %s\n", skyName, pTeamName); //skyName undefinied
       
       sleep(1);
   }
   
  return 0;
}