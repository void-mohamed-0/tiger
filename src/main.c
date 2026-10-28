#define _GNU_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

// compile command : gcc src/main.c -std=c17 -o test

// execute command : ./test

int main(int words_num,char** words){
  if (words_num < 3){return -1;}

  int in_fd =open(words[1],O_RDONLY);
  int out_fd =  open(words[2],O_WRONLY);
  
  if (in_fd==-1 || out_fd ==-1 ){return -1;};
  
  struct stat fd_st;
  
  fstat(in_fd,&fd_st);
  
  copy_file_range(in_fd,0
                  ,out_fd,0
                  ,fd_st.st_size,0);
  
  
  close(in_fd);
  close(out_fd);
    
}
