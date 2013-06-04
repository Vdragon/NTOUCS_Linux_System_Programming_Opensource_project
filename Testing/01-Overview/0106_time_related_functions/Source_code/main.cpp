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
      #include <stdio.h>
      #include <cstdio> */
    /* C Standard General Utilities Library
      #include <stdlib.h> */
      #include <cstdlib>
    /* C error number
      #include <errno.h>
      #include <cerrno> */
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
      #include <string.h>
      #include <cstring> */
    /* C Time Library
      #include <time.h> */
      #include <ctime>
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
      /* Standard Input / Output Streams Library */
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

  /* Ｖ字龍的 C/C++ 函式庫蒐集
   * Vdragons C CPP Libraries Collection
   *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		  #include "pauseProgram/pauseProgram.h"
		  #include "showSoftwareInfo/showSoftwareInfo.h"

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

/* 函式的實作
 * Function implementations */
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
      time_t current_time;
      tm *current_time_broken_down;
      std::string current_time_literarily;

    /*用來重新運行程式的label*/
    restart_program:
      showSoftwareInfo(PROGRAM_NAME);

      current_time = time(NULL);
      std::cout << "time() 回傳了 " << current_time << std::endl;
      current_time_broken_down = localtime(&current_time);
      current_time_literarily = asctime(current_time_broken_down);
      std::cout << "此值代表了現在時間為：" << current_time_literarily;

      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }

      return EXIT_SUCCESS;
    }
