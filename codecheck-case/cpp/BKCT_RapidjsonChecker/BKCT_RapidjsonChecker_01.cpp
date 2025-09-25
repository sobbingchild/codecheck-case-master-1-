#include <stdlib.h>
#include "rapidjson/document.h"

// define:bkcheck(RapidjsonChecker)
void bad_01(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    //bad: should judge parse correctly first
    cout << doc["a"].getString();
}

void bad_02(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError()) {
        return;
    }
    //bad: should judge if result is an array
    cout << doc[1].getString();
}


void bad_03(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError()) {
        return;
    }
    //bad: should judge if result is an object
    cout << doc["a"].getString();
}

void bad_04(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError() || !doc.IsObject()) {
        return;
    }
    //bad: should judge if result is an array
    cout << doc[1].getString();
}

void bad_05(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError() || !doc.IsArray()) {
        return;
    }
    //bad: should judge if result is an object
    cout << doc["a"].getString();
}


void good_01(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError() || !doc.IsArray()) {
        return;
    }
    //good
    cout << doc[1].getString();
}

void good_02(string content) {
    rapidjson::Document doc;
    doc.Parse(content);
    if (doc.HasParseError() || !doc.IsObject()) {
        return;
    }
    //good
    cout << doc["a"].getString();
}