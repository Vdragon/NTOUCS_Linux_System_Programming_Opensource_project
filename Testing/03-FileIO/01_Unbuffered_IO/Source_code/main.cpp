/*
  請見本檔案的標頭(header)檔案以得到更多關於本檔案的說明

  本程式的框架基於「C/C++ 程式範本」專案
  This program's frame is based on "C/C++ program templates" project
    https://github.com/Vdragon/C_CPP_program_templates
  建議編輯器設定
  Recommended editor settings
    Indentation by tab character
    Tab character width = 2 space characters
*/
/* 程式所引入(include)之函式庫的標頭(header)檔案
 * Included library headers */
  /* 自己的 header 檔案 */
    #include "main.hpp"

  /* 標準 C 函式庫
   * Standard C libraries
   *   C library - C++ Reference
   *   http://www.cplusplus.com/reference/clibrary/ */
    /* C library to perform Input/Output operations
      #include <stdio.h> */
      #include <cstdio>
    /* C Standard General Utilities Library
      #include <stdlib.h> */
      #include <cstdlib>
    /* C error number
      #include <errno.h> */
      #include <cerrno>
    /* C Diagnostics Library
      #include <assert.h>
      #include <cassert> */
    /* C Character handling functions
      #include <ctype.h>
      #include <cctype> */
    /* Characteristics of floating-point types
      #include <float.h>
      #include <cfloat> */
    /* ISO 646 Alternative operator spellings
      #include <iso646.h>
      #include <ciso646> */
    /* Sizes of integral types
      #include <limits.h>
      #include <climits> */
    /* C localization library
      #include <locale.h>
      #include <clocale> */
    /* C numerics library
      #include <math.h>
      #include <cmath> */
    /* Non local jumps
      #include <setjmp.h>
      #include <csetjmp> */
    /* C library to handle signals
      #include <signal.h>
      #include <csignal> */
    /* Variable arguments handling
      #include <stdarg.h>
      #include <cstdarg> */
    /* Boolean type(C99 or later)
      #include <stdbool.h>
      #include <cstdbool> */
    /* C Standard definitions
      #include <stddef.h>
      #include <cstddef> */
    /* Integer types(C++11 later)
      #include <stdint.h>
      #include <cstdint> */
    /* C Strings
      #include <string.h> */
      #include <cstring>
    /* C Time Library
      #include <time.h>
      #include <ctime> */
    /* Unicode characters handling library(C++11 later)
      #include <uchar.h>
      #include <cuchar> */
    /* Wide characters handling library
      #include <wchar.h>
      #include <cwchar> */
    /* Wide character type
      #include <wctype.h>
      #include <cwctype> */
    /* Type-generic math(non C89)
      #include <tgmath.h>
      #include <ctgmath> */
    /*
      #include <.h>
      #include <c> */

  /* 標準 C++ 函式庫 */
    /* Input/Output related */
      /* Standard Input / Output Streams Library*/
        #include <iostream>
      /* Input/output file stream class
        #include <fstream> */
    /* Container */
      /* list
        #include <list> */
    /* Unclassified */
      /* Strings */
        #include <string>
      /* Standard Template Library: Algorithms
        #include <algorithm> */
      /*
        #include <> */
		using namespace std;

  /* Ｖ字龍的 C/C++ 函式庫蒐集
   * Vdragons C CPP Libraries Collection
   *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    #include "pauseProgram/pauseProgram.h"
    #include "showSoftwareInfo/showSoftwareInfo.h"
    #include "testSomething/C/testSomething.h"
    #include "Error/C/Error.h"
		#include "printSomething/printSomething.h"


  /* Linux system calls */
    /* for open(2) */
      #include <sys/types.h>
      #include <sys/stat.h>
      #include <fcntl.h>

    /* for close(2) */
      #include <unistd.h>

/* 常數與巨集的定義
 * Definition of constants & macros */

/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage 
       預先告訴編譯器(compiler)子程式的存在 */

/* 全域變數
 * Global Variables */
  // static int generic_return_value;

/* 函式的實作
 * Function implementations */
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
      void testOpenAndClose();

    /*用來重新運行程式的label*/
    restart_program:
      showSoftwareInfo(PROGRAM_NAME);

      testProcedure("testOpenAndClose", testOpenAndClose, "-", 20);

      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }

      return EXIT_SUCCESS;
    }

  void testOpenAndClose(){
    std::string file_name;
    int file_descriptor;


    cout << "目前的工作目錄為：";
    printCurrentWorkingDirectory();
    cout << endl;
    file_name = "Resources/Testing_open01.file";
    file_descriptor = open(file_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
      /* You MUST specify mode if O_CREATE, not specifying it will make a uninitialized garbage mode to the new file! */
    if(file_descriptor == -1){
      printf("%s failed to open!, system gives the following error: %s.\n", file_name.c_str(), strerror(errno));
    }else{
      printf("%s opened, system gives file descriptor %d to handle it.\n", file_name.c_str(), file_descriptor);
      if(close(file_descriptor) == -1){
        printError(errno);
      }else{
        printf("%s closed.\n", file_name.c_str());
      }

    }

    return;
  }
