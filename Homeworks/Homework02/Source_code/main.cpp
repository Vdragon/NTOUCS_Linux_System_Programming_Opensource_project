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
			#include <assert.h> */
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
			/* Strings
				#include <string> */
			/* Standard Template Library: Algorithms
				#include <algorithm> */
			/*
				#include <> */
		using namespace std;

	/* GNU gettext library */
		#include <libintl.h>

	/* POSIX API */
		/* for socket(2) (4.4BSD, POSIX.1-2001) */
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>

		/* for IPPROTO_* */
			#include <netinet/in.h>

		/* for inet_*()POSIX.1-2001 */
			#include <arpa/inet.h>

		/* for *host*() POSIX.1-2001 */
			/* struct hostent *gethostbyname(const char *name); */
				#include <netdb.h>
				/* extern int h_errno; obseluted*/
			/* gethostbyaddr() */
				#include <sys/socket.h>

			/* for getaddrinfo(3) */
				#include <sys/types.h>
				#include <sys/socket.h>
				#include <netdb.h>

		/* for getopt(3)
			#include <unistd.h>
			extern char *optarg;
			extern int optind, opterr, optopt; */

		/* for select(2) */
			/* According to POSIX.1-2001 */
			#include <sys/select.h>

			/* According to earlier standards */
			#include <sys/time.h>
			#include <sys/types.h>
			#include <unistd.h>

	/* Ｖ字龍的 C/C++ 函式庫蒐集
	 * Vdragons C CPP Libraries Collection
	 *   https://github.com/Vdragon/Vdragons_C_CPP_Libraries_Collection */
		#include "pauseProgram/pauseProgram.h"
		#include "showSoftwareInfo/showSoftwareInfo.h"
		#include "Project_specific_configurations/GNU_gettext_library.h"
		#include "Error/C/Error.h"
		#include "Time/C/Time.h"
		#include "printSomething/printSomething.h"

/* 常數與巨集的定義
 * Definition of constants & macros */
	/* GNU gettext library */
		#define _(Untranslated_C_string) gettext(Untranslated_C_string)
	/* 預設值 */
		#define DEFAULT_HOST "localhost"
		#define DEFAULT_IP_ADDR "127.0.0.1"
		#define DEFAULT_PORT 12345

	#define MAX_MESSAGE_LENGTH 100
/* 資料類型、enumeration、資料結構與物件類別的定義
 * Definition of data type, enumeration, data structure and class */

/* 函式的宣告（函式雛型）
 * Function declarations (function prototypes)
     用途
     Usage 
       預先告訴編譯器(compiler)子程式的存在 */
	void printTimestamp(FILE *output_stream, sockaddr_in address);
/* 全域變數
 * Global Variables */
	int generic_return_value = 0;

/* 函式的實作
 * Function implementations */
  /* main 函式 - C/C++ 程式的進入點(entry point) */
    int main(int argc, char *argv[]){
    	void service(FILE *client_read, FILE *client_write);
    	string host = DEFAULT_HOST;;
    	string ip_addr = DEFAULT_IP_ADDR;;
    	int port = -1;

    	/* 初始化 GNU gettext 函式庫 */
				/* Use system default locale instead of "C" locale
					setlocale(LC_MESSAGES, ""); */
				bindtextdomain(MESSAGE_DOMAIN, LOCALEDIR);
				textdomain(MESSAGE_DOMAIN);
				bind_textdomain_codeset(MESSAGE_DOMAIN, MESSAGE_CHARSET);

#define HEADING
#ifdef PAUSE
    /*用來重新運行程式的label*/
    restart_program:
#endif
#ifdef HEADING
      showSoftwareInfo(_(PROGRAM_MAIN_NAME));
#endif

      /* 分析命令列參數 */{
				if(/* 沒有參數 */argc == 1){
		    	port = DEFAULT_PORT;
				}else if(/* port */argc == 2){
					port = atoi(argv[argc - 1]);
				}else{
					cerr << _("命令格式錯誤！") << endl;
					cerr << _("命令格式：") << argv[0] << _(" 「使用的連接埠編號」") << endl;
					exit(EXIT_FAILURE);
				}
      }

      /* 顯示伺服器配置 */{
      	cout << _("當前伺服器的配置：") << endl
      			 << _("\tIP 地址：") << ip_addr << endl
      			 << _("\t通訊埠編號：") << port << endl
      			 << _("\t請於終端機內執行 telnet ")
      			 << ip_addr << ' ' << port << _(" 以連接到此伺服器。") << endl;
      }

      /* create a socket */{
      	int socket_descriptor = -1;
      	struct sockaddr_in socket_address;

      	if((socket_descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
      		printErrorErrno("socket", errno);
      		exit(EXIT_FAILURE);
      	}

  			/* setup socket to allow same port rebinding */{
  				int setting = 1;

  				if(setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &setting, sizeof(setting)) != 0){
  					printErrorErrno("setsockopt", errno);
  				}
  			}

      	/* clear all structure to 0(?) */
      		memset(&socket_address, 0, sizeof(struct sockaddr_in));

				socket_address.sin_family = AF_INET;
				socket_address.sin_port = htons(DEFAULT_PORT);
      	if(inet_aton(DEFAULT_IP_ADDR, &socket_address.sin_addr) == 0){
      		printError("inet_aton", ERROR_SELF_DEFINED, _("IP 地址格式錯誤！"));
      		exit(EXIT_FAILURE);
      	}

				/* bind a address to socket */{
					if(bind(socket_descriptor, (struct sockaddr *)&socket_address, sizeof(struct sockaddr)) != 0){
						printErrorErrno("bind", errno);
						exit(EXIT_FAILURE);
					}
				}

				/* create connection */{
					if(listen(socket_descriptor, 5) != 0){
						printErrorErrno("listen", errno);
						exit(EXIT_FAILURE);
					}
				}

				/* main server loop */{
					sockaddr_in client_addr;
					int socket_descriptor_client;
					unsigned int i = sizeof(client_addr);
					FILE *socket_stream_client_r, *socket_stream_client_w;
					int socket_descriptor_client_w = -1;
//					pid_t child_pid;
					fd_set readfds, backup;
//					struct timeval timeout;
					string message;
					char message_C[MAX_MESSAGE_LENGTH];

					memset(&client_addr, 0, sizeof(client_addr));

					while(true){
						if((socket_descriptor_client = accept(socket_descriptor, (sockaddr *)&client_addr, &i)) < 0){
							printErrorErrno("accept", errno);
							exit(EXIT_FAILURE);
						}else{
							printTimestamp(stdout, (sockaddr_in) client_addr);
							printf(_("已和客戶端 %s:%d 建立連線！\n"), inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
						}

						FD_ZERO(&readfds);

						FD_SET(STDIN_FILENO, &readfds);
						FD_SET(socket_descriptor_client, &readfds);
						backup = readfds;

						if((socket_descriptor_client_w = dup(socket_descriptor_client)) < 0){
							printErrorErrno("dup", errno);
							exit(EXIT_FAILURE);
						}

						if(((socket_stream_client_r = fdopen(socket_descriptor_client, "r")) == NULL) ||
							 ((socket_stream_client_w = fdopen(socket_descriptor_client_w, "w")) == NULL)){
							printErrorErrno("fdopen", errno);
							exit(EXIT_FAILURE);
						}

						setlinebuf(socket_stream_client_r);
						setlinebuf(socket_stream_client_w);
						fprintf(socket_stream_client_w, _(
				    		"歡迎使用聊天服務！\n"
				    		"打完要輸入的內容後按下 Enter 就會送出內容。\n"));
						cout << _(
				    		"歡迎使用聊天服務！\n"
				    		"打完要輸入的內容後按下 Enter 就會送出內容。\n");

						while(true){
							readfds = backup;
							generic_return_value = select(socket_descriptor_client + 1, &readfds, NULL, NULL, NULL);
							if(generic_return_value < 0){
								printErrorErrno("select", errno);
								exit(EXIT_FAILURE);
							}else if(generic_return_value){
								fprintMessageDebug(stderr, _("select() 偵測到 nonblocking stream 了"));
								if(FD_ISSET(STDIN_FILENO, &readfds)){
									cin >> message;
									if(message == "quit"){
										exit(EXIT_SUCCESS);
									}
									printTimestamp(socket_stream_client_w, (sockaddr_in)socket_address);
									fputs(_("伺服端："), socket_stream_client_w);
									fputs(message.c_str(), socket_stream_client_w);
									fputc('\n', socket_stream_client_w);
									message.clear();
								}

								if(FD_ISSET(socket_descriptor_client, &readfds)){
									if(fgets(message_C, MAX_MESSAGE_LENGTH, socket_stream_client_r) == NULL){
										printErrorErrno("fgets", errno);
										if(feof(socket_stream_client_r)){
											cout << _("客戶端已斷線！") << endl;
											shutdown(socket_descriptor_client, SHUT_RDWR);
										}
										exitError(ERROR_UNEXPECTED_CONDITION, EXIT_FAILURE);

									}else{
										if(strcmp(message_C, "quit\r\n") == 0){
											cout << _("客戶端已斷線！") << endl;
											shutdown(socket_descriptor_client, SHUT_RDWR);
											break;
										}
									}
									putchar('[');printTime(DEFAULT);putchar(']');
									cout << _("客戶端：") << message_C;
								}
							}
						}
#ifdef DISABLED
						if((child_pid = fork()) < 0){
							printErrorErrno("fork", errno);
							exit(EXIT_FAILURE);
						}else if(child_pid == 0){/* 子進程 */
							FILE *socket_stream_client_r, *socket_stream_client_w;
							int socket_descriptor_client_w = -1;

							close(socket_descriptor);
							if((socket_descriptor_client_w = dup(socket_descriptor_client)) < 0){
								printErrorErrno("dup", errno);
								exit(EXIT_FAILURE);
							}
							if((socket_stream_client_r = fdopen(socket_descriptor_client, "r")) == NULL){
								printErrorErrno("fdopen", errno);
								exit(EXIT_FAILURE);
							}
							if((socket_stream_client_w = fdopen(socket_descriptor_client_w, "w")) == NULL){
								printErrorErrno("fdopen", errno);
								exit(EXIT_FAILURE);
							}
							service(socket_stream_client_r, socket_stream_client_w);
							if(fclose(socket_stream_client_r) == EOF){
								printErrorErrno("fclose", errno);
								exit(EXIT_FAILURE);
							}
							if(fclose(socket_stream_client_w) == EOF){
								printErrorErrno("fclose", errno);
								exit(EXIT_FAILURE);
							}

							exit(EXIT_SUCCESS);
						}else{/* 母進程 */
							close(socket_descriptor_client);
						}
#endif
					}
				}

				/* termination */{
					if(shutdown(socket_descriptor, SHUT_RDWR) != 0){
						printErrorErrno("shutdown", errno);
					}

					if(close(socket_descriptor) != 0){
						printErrorErrno("close", errno);
					}
				}

      }
#ifdef PAUSE
      /* 暫停程式運行（於main函式中） */
        if(pauseProgram() == 1){
          goto restart_program;
        }
#endif
      return EXIT_SUCCESS;
    }

    void service(FILE *client_read, FILE *client_write){
    	fprintf(client_write, _(
    		"歡迎使用聊天服務！\n"
    		"打完要輸入的內容後按下 Enter 就會送出內容。\n"));

    	return;
    }

    void printTimestamp(FILE *output_stream, sockaddr_in address){
    	fputc('[', output_stream);
    	fprintTime(output_stream, DEFAULT);
    	fprintf(output_stream, " @ %s:%d",
    			inet_ntoa(address.sin_addr),
    			ntohs(address.sin_port));
    	fputc(']', output_stream);
    	return;
    }
