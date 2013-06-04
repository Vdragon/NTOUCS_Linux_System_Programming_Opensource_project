/*
	主程式

	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
*/
/* 程式所 include 之函式庫的標頭檔
 * Included Library Headers */
	/* Standard C/C++ library */
    /* for EXIT_* return code definition */
		  #include <cstdlib>
		/* for error number */
			#include <cerrno>
    /* for io */
      #include <iostream>

  /* Vdragons_C_CPP_Libraries_Collection
   * https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    /* for pausing program definition */
		  #include "pauseProgram/Pause_program.h"
    /* for showing software info */
		  #include "Show_software_info/Show_software_info.h"
		/* for process errno */
			#include "Error/C/Error.h"

	/* POSIX API */
		/* for chdir() definition */
			#include <unistd.h>

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */
	extern int errno;

/* 主要程式碼
 * Main Code */
  int main(int argc, char *argv[]){
  	char current_working_directory[255];

  /*用來重新運行程式的label*/
  restart_program:
    show_software_info("0105_chdir_function 主程式");

		if(getcwd(current_working_directory, sizeof(current_working_directory)) != NULL){
      std::cout
        << "當前工作目錄(current working directory)為：" << std::endl
        << '\t' << current_working_directory << std::endl;
		}else{
		  printError(errno);
		}

    std::cout << "chdir()ed" << std::endl;
		if(chdir("Source_code") != 0){
		  printError(errno);
		}


    if(getcwd(current_working_directory, sizeof(current_working_directory)) != NULL){
      std::cout
        << "當前工作目錄(current working directory)為：" << std::endl
        << '\t' << current_working_directory << std::endl;
    }else{
      printError(errno);
    }

    /*暫停程式運行（於main函式中）*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return EXIT_SUCCESS;
  }
