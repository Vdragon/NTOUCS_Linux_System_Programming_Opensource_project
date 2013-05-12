#include <iostream>
#include <dirent.h>
#include <string>

int main(int argc, char *argv[])
{
    std::string query;

		/* parse arguements */{
			if(argc == 1){
				query = ".";
			}else if(argc == 2){
				query = argv[1];
			}else{
				std::cerr << "命令格式輸入錯誤！" << std::endl;
			}
    }

		/* open directory, then read all name of items under the directory */{
			DIR *dir_stream;
			struct dirent *dir_entry;

			dir_stream = opendir(query.c_str());
			if(dir_stream == NULL){
				std::cerr << "目錄開啟失敗！" << std::endl;
			}else{
				while((dir_entry = readdir(dir_stream)) != NULL){
					std::cout << dir_entry->d_name << std::endl;
				}
				closedir(dir_stream);
			}
		}
    return 0;
}
