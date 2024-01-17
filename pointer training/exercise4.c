//Exercise 4, create a program that crashes by trying to modify read only memory
int main(void){
    char *pStr ="HELLOOO";
    char *pStr2 = "WOOOORLD";
    *pStr = *pStr;
}