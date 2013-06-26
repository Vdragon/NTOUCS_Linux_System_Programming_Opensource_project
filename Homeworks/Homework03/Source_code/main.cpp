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
		/* C error number */
			#include <errno.h>
			#include <cerrno>
		/* C Diagnostics Library */
			#include <assert.h>
			#include <cassert>
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

	/* POSIX API */
		/* for socket(2) (4.4BSD, POSIX.1-2001) */
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>

		/* for IPPROTO_* */
			#include <netinet/in.h>

		/* for inet_*()POSIX.1-2001 */
			#include <arpa/inet.h>

	/* for basename conversion */
		#include <libgen.h>

	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		#include "pauseProgram/pauseProgram.h"
		#include "showSoftwareInfo/showSoftwareInfo.h"
		#include "Project_specific_configurations/GNU_gettext_library.h"
		#include "Error/C/Error.h"
		#include "Time/C/Time.h"

/* 常數與巨集的定義
 * Definition of constants & macros */
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)

/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */
	typedef int Socket_descriptor_t;

	/* 軟體設定值 */
		typedef struct configuration{
			string bind_address; /*  = "127.0.0.1" */
			unsigned bind_port;  /* 12345 */
			unsigned max_user;
		}Configuration;

	typedef struct online_user{
		/* 使用者識別編號 */
			unsigned uid;
			sockaddr_in addr;
		/* 使用者連線的 socket descripter */
			Socket_descriptor_t sock_des;
		/* 下一個使用者的指標 */
			struct online_user *next;
	}Online_user;

	typedef struct online_user_list{
		Online_user *head;
		unsigned user_quantity;
		unsigned last_assigned_uid;
	}Online_user_list;

#ifdef DISABLED
	class Online_user{
	private:
		/* 使用者識別編號 */
			unsigned uid;
		/* 使用者連線的 socket descripter */
			Socket_descriptor_t sock_des;
		/* 下一個使用者的指標 */
			Online_user *next;
	public:
		/* 使用者的稱呼 */
			string name;
		Online_user();
		virtual ~Online_user();
	};

	class Online_user_list{
	private:
		Online_user *head = NULL;
		unsigned length = 0;
	public:
		Online_user_list();
		virtual ~Online_user_list();
		void addUser(Socket_descriptor_t des);
		void removeUser(unsigned uid);
		void printList(void);
		/* 使用者的稱呼 */
			string name;
	};

	void Online_user_list::addUser(Socket_descriptor_t des){
		Online_user *new_user = new Online_user
		if(/* no user */head == NULL){
			head = new_user;
		}else{/* have user */
			Online_user *tmp = head;
			head = new_user;
			new_user->next = tmp;
		}
		return;
	}
#endif

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage 
       預先告訴編譯器(compiler)子程式的存在 */
	void printTimestamp(FILE *output_stream, sockaddr_in address);
	void addUser(Socket_descriptor_t des, sockaddr_in addr);
	void * acceptConnection(void *arguments);

/* 全域變數
 * Global Variables */
	Online_user_list list = {NULL, 0, 0};
	Socket_descriptor_t socket_des_listen = -1;

/* 函式的實作
 * Function implementations */
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
    	void printUsage(char *argv[]);
    	/* 在 message_available 條件變數達成時將訊息廣播出去 */
    		void broadcastMessage(void);
    	void cleanupUserList(void);

    	Configuration config = {"127.0.0.1", 12345, 10};

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
				cout << _("\t通訊埠編號：");
				if(config.bind_port != 0){
					cout << config.bind_port << endl;
				}else{
					cout << _("自動偵測") << endl;
				}
			}

			/* 準備外部連線 */{
      	struct sockaddr_in socket_addr_listen;

				/* create a socket */{
	      	if((socket_des_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
	      		printErrorErrno("socket", errno);
	      		exit(EXIT_FAILURE);
	      	}
				}

				/* setup socket to allow same port rebinding */{
					int setting = 1;

					if(setsockopt(socket_des_listen, SOL_SOCKET, SO_REUSEADDR, &setting, sizeof(setting)) != 0){
						printErrorErrno("setsockopt", errno);
					}
				}

				/* 初始化 address */
					memset(&socket_addr_listen, 0, sizeof(struct sockaddr_in));
					socket_addr_listen.sin_family = AF_INET;
					socket_addr_listen.sin_port = htons(config.bind_port);
	      	if(inet_aton(config.bind_address.c_str(), &socket_addr_listen.sin_addr) == 0){
	      		printError("inet_aton", ERROR_SELF_DEFINED, _("IP 地址格式錯誤！"));
	      		exit(EXIT_FAILURE);
	      	}

				/* 將地址與 socket 結合 */{
					if(bind(socket_des_listen, (struct sockaddr *)&socket_addr_listen, sizeof(struct sockaddr)) != 0){
						printErrorErrno("bind", errno);
						exit(EXIT_FAILURE);
					}
				}

				/* 開始接聽 */{
					if(listen(socket_des_listen, 1) != 0){
						printErrorErrno("listen", errno);
						exit(EXIT_FAILURE);
					}else{
						cout << "開始接聽外部連線。" << endl
								 << _("\t請於終端機內執行 telnet ")
								 << config.bind_address << ' ' << config.bind_port
								 << _(" 以連接到此伺服器。") << endl;
					}
				}
			}

			/* prepare user list */{
				atexit(cleanupUserList);
			}

			/* 持續接受服務請求 */{
				pthread_t tid_accept;
				if(pthread_create(&tid_accept, NULL, acceptConnection, NULL) != 0){
					printError("pthread_create", ERROR_SELF_DEFINED, _("無法建立執行緒！"));
					exit(EXIT_FAILURE);
				}
				pthread_detach(tid_accept);
			}
			/* 結束 */{
				/* 中斷連線 */{
					cout << _("結束連線。") << endl;
					if(shutdown(socket_des_listen, SHUT_RDWR) != 0){
						/* 不存在準確確定連線是否已經中斷的方法，所以忽略連線已經中斷的錯誤 */
							if(errno != ENOTCONN){
								printErrorErrno("shutdown", errno);
								exit(EXIT_FAILURE);
							}
					}

				/* 摧毀 socket */
					if(close(socket_des_listen) != 0){
						printErrorErrno("close", errno);
						exit(EXIT_FAILURE);
					}
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

    void cleanupUserList(void){
    	Online_user *i, *tmp_next;

    	if(list.user_quantity > 0){
    		i = list.head;
    		while(i != NULL){
    			close(i->sock_des);
    			tmp_next = i->next;
    			free(i);
    			i = tmp_next;
    		}
    	}
    	return;
    }

    void printTimestamp(FILE *output_stream, sockaddr_in address){
    	fputc('[', output_stream);
    	fprintTime(output_stream, DEFAULT);
    	fprintf(output_stream, " ＠ %s:%d",
    			inet_ntoa(address.sin_addr),
    			ntohs(address.sin_port));
    	fputc(']', output_stream);
    	return;
    }

    void addUser(Socket_descriptor_t des, sockaddr_in addr){
    	Online_user *tmp_user, *tmp_user_tmp;

			if((tmp_user = (Online_user *)malloc(sizeof(Online_user))) == NULL){
				exitError(ERROR_MEMORY_ALLOCATION_FAILED, EXIT_FAILURE);
			}else{
				tmp_user->uid = list.last_assigned_uid++;
				tmp_user->sock_des = des;
				tmp_user->addr = addr;

				list.user_quantity += 1;
	    	if(list.user_quantity == 0){
	    		tmp_user->next = NULL;
	    		list.head = tmp_user;
	    	}else{
	    		tmp_user_tmp = list.head;
	    		list.head = tmp_user;
	    		tmp_user->next = tmp_user_tmp;
	    	}
			}
    	return;
    }

    void * acceptConnection(void *arguments){

			while(true){
				Socket_descriptor_t socket_descriptor_new = -1;
				struct sockaddr_in client_addr;
				unsigned int generic_integer;

				memset(&client_addr, 0, sizeof(client_addr));
				generic_integer = sizeof(client_addr);

				if((socket_descriptor_new =
							accept(
									socket_des_listen,
									(sockaddr *)&client_addr, &generic_integer)) < 0){
					printErrorErrno("accept", errno);
					exit(EXIT_FAILURE);
				}else{
					printTimestamp(stdout, (sockaddr_in) client_addr);
					printf(_("已和客戶端 %s:%d 建立連線！\n"),
							inet_ntoa(client_addr.sin_addr),
							ntohs(client_addr.sin_port));
					addUser(socket_descriptor_new, client_addr);
					break;
				}
			}
			return NULL;
    }
