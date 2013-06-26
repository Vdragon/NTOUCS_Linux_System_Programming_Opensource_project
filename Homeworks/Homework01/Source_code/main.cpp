/*
main.c
	主程式
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard C/C++ library definitions */
		#include <stdlib.h>
			/* for EXIT_* return code */

		/* for io manipulation */
			#include <iostream>
		/* error message? */
			#include <cerrno>
			#include <cstring>

	/* libc6-dev(POSIX) */
		/* for directory related definitions */
			#include <dirent.h>

	/* libc6-dev(The Single UNIX ® Specification, Version 2) */
		/* for filepath parsing procedures */
			#include <libgen.h>

	/* POSIX API */
		/* for stat() */
			 #include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>

	/* Vdragons_C_CPP_Libraries_Collection */
		/* for message tag definitions */
			#include "Messages_templates/zh_TW.h"
		#include "pauseProgram/pauseProgram.h"
			/* for pausing program execution */
		#include "showSoftwareInfo/showSoftwareInfo.h"
			/* for showing software info */
		/* Error */
			#include "Error/C/Error.h"
		#include "File_system/CPP/File_system.hpp"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 遞迴地印出所有目錄中項目資訊的子程式 */
		void listEntryRecursive(std::string entry_path);

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	using namespace std;

  int main(int argc, char *argv[]){
  	/* 印出使用說明子程式 */
  		void showHelp(const char *executable_name);

		std::string query_path;

#ifdef PAUSE_WHEN_FINISH
  restart_program_from_here:
#endif
		showSoftwareInfo("作業01演示程式");

		/* 處理命令列參數 */{
			if(argc == 1){
				query_path = ".";
			}else if(argc == 2){
				query_path = argv[1];
			}else{
				std::cerr << ERROR_TAG << "命令列參數格式錯誤！" << std::endl;
				showHelp(basename(argv[0]));
				goto finish_program;
			}
			cout << "欲查詢的檔案或目錄名稱為：" << query_path << endl;
		}

		listEntryRecursive(query_path);

	finish_program:
#ifdef PAUSE_WHEN_FINISH
		/*暫停程式運行（於main函式中）*/{
			if(pauseProgram() == 1){
					goto restart_program_from_here;
			}
		}
#endif
		return EXIT_SUCCESS;
  }

	void showHelp(const char *executable_name){
		std::cout << "用法：" << executable_name << " 「檔案或目錄路徑」" << std::endl;
		return;
	}

	void listEntryRecursive(std::string entry_path){

		/* 走訪的深度 */
			static string current_listing_directory = "";
			string previous_listing_directory = "";

		/* 不管是不是目錄先印出 entry_path 的資訊 */{
			showPathInfo(entry_path);
		}

		/* 如果是目錄 */{
			if(isDirectory(entry_path)){
				if(current_listing_directory == "" &&
						entry_path != "."){
					current_listing_directory = entry_path;
				}

				/* access directory stream */{
					/* This is the data type of directory stream objects.
						 The actual structure is opaque to users.  */
						DIR *dir_stream;
					struct dirent *dir_entry;

					if((dir_stream = opendir(entry_path.c_str())) == NULL){
						std::cerr << ERROR_TAG << "無法開啟目錄「" << entry_path << "」！" << std::endl
											 << ERROR_TAG << "您的系統告訴我們的原因為：" << strerror(errno) << "。" << std::endl;
					}else{
						/* access directory entries */{
							while((dir_entry = readdir(dir_stream)) != NULL){
								string entry_name = dir_entry->d_name;

								if(entry_name == "." || entry_name == ".."){
									/* 略過當前目錄、上一層目錄 */
									continue;
								}else if(isDirectory(((current_listing_directory == "") ? "" : current_listing_directory + '/') + entry_name)){
									previous_listing_directory = current_listing_directory;
									current_listing_directory = ((current_listing_directory == "") ? "" : current_listing_directory + '/') + entry_name;
									listEntryRecursive(current_listing_directory);
									current_listing_directory = previous_listing_directory;
								}else{
									listEntryRecursive(((current_listing_directory == "") ? "" : current_listing_directory + '/') + entry_name);
								}
							}
						}
					}
					closedir(dir_stream);
				}
			}
		}

		return;
	}
