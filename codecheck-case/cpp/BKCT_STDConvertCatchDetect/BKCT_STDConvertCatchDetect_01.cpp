// defect:bkcheck(STDConvertCatchDetect)

void bad() {
    std::string tmp_value = "";
    // bad
    a.b = std::stoi(tmp_value);
    // bad
    a.b = std::stof(tmp_value);
    // bad
    a.b = std::stod(tmp_value);
    // bad
    a.b = std::stold(tmp_value);
    // bad
    a.b = std::stol(tmp_value);
    // bad
    a.b = std::stoll(tmp_value);
    // bad
    a.b = std::stoul(tmp_value);
    // bad
    a.b = std::stoull(tmp_value);
}

void good() {
    std::string str = "12345";
    try {
        // good
        int num = std::stoi(str);
        std::cout << "The number is: " << num << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}