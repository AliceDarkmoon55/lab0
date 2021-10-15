#pragma once
#include<string>
#include<fstream>
#include<vector>

class CsvWriter {
public:
    explicit CsvWriter(const std::string& path) : path_(path), is_open_(false)
    {
        file_.open(path_);
        is_open_ = file_.is_open();
    }

    ~CsvWriter() {
        file_.close();
    }

    void writeln(const std::string& s) {
        file_ << s << std::endl;
    }

    void write(const std::string& s) {
        file_ << s << ",";
    }

    bool is_open() const {
        return is_open_;
    }

    std::string getPath() const {
        return path_;
    }
private:
    std::string path_;
    bool is_open_;
    std::ofstream file_;

    CsvWriter(const CsvWriter& w);
    CsvWriter& operator=(const CsvWriter& w);
};