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
			#include <locale.h> */
			#include <clocale>
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
		using namespace std;

	/* GNU gettext library */
		#include <libintl.h>

	/* POSIX pthread */
		#include <pthread.h>

	/* for basename conversion */
		#include <libgen.h>

	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		#include "pauseProgram/pauseProgram.h"
		#include "showSoftwareInfo/showSoftwareInfo.h"
		#include "Project_specific_configurations/GNU_gettext_library.h"
		#include "Error/C/Error.h"

/* 常數與巨集的定義
 * Definition of constants & macros */
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)

/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */
	/* 軟體設定值 */
		typedef struct configuration{
			string bind_address; /*  = "127.0.0.1" */
			unsigned bind_port;  /* 12345 */
		}Configuration;

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
    	void printUsage(char *argv[]);

    	Configuration config = {"127.0.0.1", 12345};

    	/* 初始化 GNU gettext 函式庫 */
				/* Use system default locale instead of "C" locale */
					setlocale(LC_MESSAGES, "");
				bindtextdomain(MESSAGE_DOMAIN, LOCALEDIR);
				textdomain(MESSAGE_DOMAIN);
				bind_textdomain_codeset(MESSAGE_DOMAIN, MESSAGE_CHARSET);

			/* register exit callback */
				atexit(showSoftwareInfoBeforeExit);

    /*用來重新運行程式的label*/
    restart_program:
      showSoftwareInfo(_(PROGRAM_MAIN_NAME));

			/* 分析命令列參數 */{
				if(/* 沒有參數 */argc == 1){
					config.bind_port = 12345;
				}else if(/* port */argc == 2){
					char *last_valid_char;

					config.bind_port = strtol(argv[1], (char **) &last_valid_char, 10);
					if(/* 不是整個字串都是有效的數字 */!(
							argv[1][0] != '\0' &&
							*last_valid_char == '\0')){
						cerr << _("偵測到錯誤的連接埠格式！") << endl;
						printUsage(argv);
						exit(EXIT_FAILURE);
					}else if(
							config.bind_port != 0 &&
							config.bind_port <= 1024 &&
							getuid() != 0){
						cout << _("【警告】您指定的連接埠為通常只有 superuser 才能使用的連接埠範圍(1~1024)。") << endl
								 << _("【警告】如果稍後 bind() 發生錯誤表示您沒有權限使用該連接埠。") << endl;
					}else if(config.bind_port > 65535){
						cerr << _("偵測到錯誤的連接埠格式！") << endl;
						printUsage(argv);
						exit(EXIT_FAILURE);
					}
				}else{
					cerr << _("【錯誤】命令格式錯誤！") << endl;
					printUsage(argv);
					exit(EXIT_FAILURE);
				}
			}

			/* 顯示伺服器配置 */{
				cout << _("當前伺服器的配置：") << endl
						 << _("\tIP 地址：") << config.bind_address << endl;
				if(config.bind_port != 0){
					cout << _("\t通訊埠編號：") << config.bind_port << endl
					     << _("\t請於終端機內執行 telnet ")
					     << config.bind_address << ' ' << config.bind_port
					     << _(" 以連接到此伺服器。") << endl;
				}
			}

      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }

      return EXIT_SUCCESS;
    }

    void printUsage(char *argv[]){
    	cout << _("命令格式：") << basename(argv[0]) << _(" 「使用的連接埠編號（0~65535，0 為自動選取可用連接埠）」") << endl;
    	return;
    }
