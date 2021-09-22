#include <stdio.h>
#include <string.h>
#include <unistd.h>


void print_args(int arg_count, char ** args);
void swap_char_ptr(char* &one, char* &two);
void selection_sort(char** args_list, const int count);
bool first_is_bigger(char* first, char* second);

int main(int argc, char *argv[]) {
  printf("Number of arguments: %d\n", argc-1);
  printf("Max length of argument: %ld\n", sysconf(_SC_ARG_MAX));
  print_args(argc, argv);
  printf("-----sorting args----------------\n");
  selection_sort(argv, argc);
  printf("---sorted------------------------\n");
  print_args(argc,argv);

  return  0;
}

void selection_sort(char** args_list, const int count){
  int min;
  for (int i = 1;i < count-1; i++){
    min = i;
    for(int j = i+1; j < count; j++){ 
      printf("Sorting slot #%d: ", i);
      printf("%s vs. %s",args_list[i],args_list[j]);
      if(first_is_bigger(args_list[i],args_list[j])){
        printf(" ->swap\n");
        swap_char_ptr(args_list[i], args_list[j]);  
      }
      else{
        printf(" ->no swap\n");
      }
    }
  }
}

bool first_is_bigger(char* first, char* second){
  if(strncmp(first, second,sysconf(_SC_ARG_MAX)) > 0){
    return true;
  }
  return false;
}

void print_args(int arg_count, char **args){

  for(int i =1; i< arg_count; i++){
    printf("%s",args[i]);
    printf("\n");
  }
}

void swap_char_ptr(char* &one, char* &two){
  char* temp = one;
  //printf("Value one:%p, Value 2:%p, Value temp:%p\n", one, two, temp);
  //printf("Value one:%s, Value 2:%s, Value temp:%s\n", (char *)one,  (char *)two, (char *)temp);
  one = two;
  //printf("Value one:%p, Value 2:%p, Value temp:%p\n", one, two, temp);
  //printf("Value one:%s, Value 2:%s, Value temp:%s\n", (char *)one,  (char *)two, (char *)
  two = temp;
  //printf("Value one:%p, Value 2:%p, Value temp:%p\n", one, two, temp);
  //printf("Value one:%s, Value 2:%s, Value temp:%s\n", (char *)one,  (char *)two, (char *)temp);
}