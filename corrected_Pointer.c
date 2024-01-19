#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void  get_sky_team_name(char* name)
{
   char* ptr = (char*) malloc(20);//allocating 20 bytes of memory in the heap to the pointer
   
   //copy team name to pointer

   strcpy(ptr, "Home Comms SW Team");
   
   //return team name
   strlcpy(name, ptr,20);//copying characters from ptr to name with a meximum of 20 characters


   free(ptr);
}
  
int main(void)
{
   char name[20];//20 bytes instead of 10
   char* pTeamName = NULL;    
   pTeamName = (char*)malloc(20); //allocating 20 bytes of memory in the heap to the pointer
 
   strcpy(name, "Sky UK");     
   printf("%s\n",name);
   while(1)
   {
       get_sky_team_name(pTeamName);        
       
       //print team name
       printf("Team name: %s\n", pTeamName); 
       
       sleep(1);
   }
   free(pTeamName);
   pTeamName = NULL;
   
  return 0;
}