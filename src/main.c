#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sendfile.h>

// compile command : gcc src/main.c -o -std=c17 test

// execute command : ./test

int main(int words_num,char** words){
  if (words_num < 2){return -1;}

  int fd =open(words[1],O_RDONLY);
  
  if (fd==-1){return -1;};
  
  struct stat fd_st;
  
  fstat(fd,&fd_st);
  
  sendfile(1,fd,0,fd_st.st_size);
  
  close(fd);
    
}
