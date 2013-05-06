/*
	主程式

	本程式的框架基於「C/C++ program templates」專案
	This program's frame is based on "C/C++ program templates" project
		https://github.com/Vdragon/C_CPP_program_templates
*/
/* 程式所 include 之函式庫的標頭檔
 * Included Library Headers */
	/* feature test macros(7) */
		/* for crypt() */
			#define _XOPEN_SOURCE

	/* POSIX API */
		/* for crypt() */
			#include <unistd.h>

	/* Standard C/C+#include <unistd.h>+ library */
    /* for EXIT_* return code definition */
		  #include <stdlib.h>
		/* for cout */
			#include <iostream>

  /* Vdragons_C_CPP_Libraries_Collection
   * https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
    /* for pausing program definition */
		  #include "pauseProgram/Pause_program.h"
    /* for showing software info */
		  #include "Show_software_info/Show_software_info.h"

/* 常數與巨集
 * Constants & Macros */

/* Definition of data type, enumeration, data structure and class */

/* 函式雛型
 * Function Prototypes */

/* 全域變數
 * Global Variables */

/* 主要程式碼
 * Main Code */
  int main(int argc, char *argv[]){
  /*用來重新運行程式的label*/
  restart_program:
    show_software_info("主程式");

		std::cout << "[DES]crypt(\"abc\", \"aa\") = " << crypt("abc", "aa") << std::endl;
			/* [DES]crypt("abc", "aa") = aaMjTET7rKV4Y */
		std::cout << "[DES]crypt(\"abc\", \"de\") = " << crypt("abc", "de") << std::endl;
			/* [DES]crypt("abc", "de") = de86L5W89BsXE */

		std::cout << "[MD5]crypt(\"abc\", \"$1$$\") = " << crypt("abc", "$1$$") << std::endl;
			/* [MD5]crypt("abc", "$1$$") = $1$$j0yT3c/2mYPQF09fpvPLb0 */
		std::cout << "[MD5]crypt(\"abc\", \"$1$def$\") = " << crypt("abc", "$1$def$") << std::endl;
			/* [MD5]crypt("abc", "$1$def$") = $1$def$o5eQR666h6lVZ3AIuBlas0 */
		std::cout << "[MD5]crypt(\"abc\", \"$1$defsdaffsfasdfdsfdsafdssafdsfdsfasdfsdfsdafsff$\") = " << crypt("abc", "$1$defsdaffsfasdfdsfdsafdssafdsfdsfasdfsdfsdafsff$") << std::endl;
			/* [MD5]crypt("abc", "$1$def$") = $1$defsdaff$ld5w5DfnArGaVt0rz4MCI0 */
		std::cout << "[MD5]crypt(\"abc\", \"$1$defsdaffsfa$\") = " << crypt("abc", "$1$defsdaffsfa$") << std::endl;
			/* [MD5]crypt("abc", "$1$def$") = $1$defsdaff$ld5w5DfnArGaVt0rz4MCI0 */

		std::cout << "[Blowfish]crypt(\"abc\", \"$2a$defsdaffsfa$\") = " << crypt("abc", "$2a$defsdaffsfa$") << std::endl;
			/* [Blowfish]crypt("abc", "$2a$defsdaffsfa$") = $2pGYr0GpQ9uw */

		std::cout << "[SHA-256]crypt(\"abc\", \"$5$defsdaffsfa$\") = " << crypt("abc", "$5$defsdaffsfa$") << std::endl;
			/* [SHA-256]crypt("abc", "$5$defsdaffsfa$") = $5$defsdaffsfa$YrKtviyXHmLx7oU2/Ty6H04vynjM8flKeOLH8ivYxV5 */

		std::cout << "[SHA-512]crypt(\"abc\", \"$6$defsdaffsfa$\") = " << crypt("abc", "$6$defsdaffsfa$") << std::endl;
			/* [SHA-512]crypt("abc", "$6$defsdaffsfa$") = $6$defsdaffsfa$K0cAW/K7/hZFBoORCbDkOATZHATKbOBgUnjJg7FIumrcVFv1rQU9WAcbZoCpPt5sG96Gp7fAZBxWlScNE7aKH. */

    /*暫停程式運行（於main函式中）*/
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return EXIT_SUCCESS;
  }
