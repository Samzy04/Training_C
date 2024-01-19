void print_sky_team(void)
{
   char skyName[10];//this variable is declared in the stack and it can hold up to 10 characters
   char* pTeamName = (char*) malloc(10);//pTeamName variable declared and allocating 10 bytes of memeory in the heap
   
   strcpy(skyName, "Sky UK");
   strcpy(pTeamName , "Home Comms SW Team"); //this is the main error as stcpy does not account the length as it is more then 10 characters and will copy characters until it reaches NULL terminater this could lead to a buffer overflow
   //the function does not free the dynamically allocated memory so it results in memeory leak
   
   printf("%s: %s\n", skyName, pTeamName); 
}