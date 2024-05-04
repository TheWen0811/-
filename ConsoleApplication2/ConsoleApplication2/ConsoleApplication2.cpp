#include <iostream>  
#include <fstream>

using namespace std;

int main() {
    string file_path;
    cout << "请输入文件路径：";
    cin >> file_path;

    ifstream input_file(file_path);
    if (!input_file) {
        cout << "无法打开文件!" << endl;
        return 1;
    }

    input_file.close();
    cout << "文件已成功打开!" << endl;

    return 0;
}
