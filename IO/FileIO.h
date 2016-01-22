#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


namespace roy_c {
    /*
     *  Pure C File Read Utility, Legacy
     */
    char* _fread(FILE *fp)
    {
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char* str = (char*) malloc(file_size*sizeof(char) + 1);
        fread(str, sizeof(char), file_size, fp);
        *(str + file_size) = '\0';
        fclose(fp);
        return str;
    }

    char* read(char* pth)
    {
        char mode[] = "r";
        FILE* fp = fopen(pth, mode);
        return _fread(fp);
    }

    void read_clean(char* str)
    {
        free(str);
    }


    /*
     *   C++ File IO Utility
     */

    int f_exist(std::string file_path){
        int return_code;
        if( access( file_path.c_str(), F_OK ) != -1 ) {
            return_code = 0;
        } else {
            return_code = -1;
        }

        /*
         * return_code spec:
         *    0 ==> File Exist
         *    1 ==> File Don't Exist
         */

        return return_code;
    }


    std::string f_read(std::string file_path){
        std::string file_content = "";
        std::string buffer;
        std::ifstream myfile (file_path, std::ios::in);

      if (myfile.is_open()) {
              /*
               * when is_open() == false, file open failed
               */
            while ( getline (myfile,buffer) ) {
              file_content += buffer + "\n";
                /*
                 * The end of file newline char trailing might not be desired;
                 */
            }
            myfile.close();
            return file_content;
      }
        else {
          return "fail";
      }
    }


    std::ios_base::open_mode _f_mode_flags(std::string mode) {

         std::ios_base::open_mode flag = std::ios_base::in;
        // default to std::ios::in
         if (mode=="r"||"in"||"IN"){
             flag = std::ios_base::in;
         }
        else if (mode=="o"||"w"||"OUT"){
             flag = std::ios_base::out;
         }
        else if (mode=="a"||"APP"||"app") {
             flag = std::ios_base::app;
         }
        else if (mode=="b"||"bin"||"binary") {
             flag = std::ios_base::binary;
         }
        else {
             std::cout << "Wrong Mode Parameter Given" << std::endl;
         }

        return flag;
        /*
         * TODO: Handle exceptions when invalid mode parameter is given
         */
        /*
         * TODO: Fixed Type Conversion Bug
         */
    };


    int f_write(std::string file_path, std::string content, std::string mode){
        // std::ios_base::open_mode flag = _f_mode_flags(mode);

        if ((mode=="o")||(mode=="w")||(mode=="OUT")) {
            std::ofstream myfile(file_path, std::ios::out);

            if (myfile.is_open()) {
                myfile << content;
                myfile.close();
                return 0;
            }
            else {
                return -1;
            }
        }

        else if ((mode=="a")||(mode=="app")||(mode=="APP")) {
            std::ofstream myfile(file_path, std::ios::app);

            if (myfile.is_open()) {
                myfile << content;
                 myfile.close();
                return 0;
            }
            else {
                return -1;
            }

        }
      }

    /*  rapidjson , reader template
    rapidjson::Document json_read(std::string file_path){
        using namespace rapidjson;
        const char* json = roy_c::f_read(file_path).c_str();
        Document d;
        d.Parse(json);
        return d;
    }
     */
}
