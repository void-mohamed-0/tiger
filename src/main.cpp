#include <cstdio>
#include <fcntl.h>
#include <print>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>


int main(int words_num,char** words){
  if (words_num < 1){std::println("missing file path");return -1;}
  int fd =open(words[1],O_RDONLY);
  if (fd==-1){std::println("failed to open the fille");perror("open");return -1;};
  struct stat fd_st{};
  fstat(fd,&fd_st);
  std::vector<char>buf{};
  buf.resize(fd_st.st_size);
  if (read(fd,buf.data(),fd_st.st_size)==-1){std::println("failed to read the file");perror("read");return -1;};
  std::println("{}",buf.data());
  close(fd);
    
}
