//
// Created by wadema on 2024/5/16.
//
// define:bkcheck(DirectNullPointer)

void good_01() {
    if (A01->foo() == nullptr) {

    }
    if (A02.Get()->foo() == nullptr) {

    }
    if (F03->ptr != nullptr) {

    }
    if (F04->ptr.Get() != nullptr) {

    }
    if (F05.Get()->ptr != nullptr) {

    }
    if (F06.Get()->ptr.Get() != nullptr) {

    }
    //-------------------------------------
    if (A11->foo()) {

    }
    if (A12.Get()->foo()) {

    }
    if (F13->ptr) {

    }
    if (F14->ptr.Get()) {

    }
    if (F15.Get()->ptr) {

    }
    if (F16.Get()->ptr.Get()) {

    }
    //---------------------------------------
    if (!(A21->foo())) {

    }
    if (!(A22.Get()->foo())) {

    }
    if (!(F23->ptr)) {

    }
    if (!(F24->ptr.Get())) {

    }
    if (!(F25.Get()->ptr)) {

    }
    if (!(F26.Get()->ptr.Get())) {

    }
    //---------------------------------------
    if (A31->foo().IsValid()) {

    }
    if (A32.Get()->foo().IsValid()) {

    }
    if (F33->ptr.IsValid()) {

    }
    if (F34->ptr.Get().IsValid()) {

    }
    if (F35.Get()->ptr.IsValid()) {

    }
    if (F36.Get()->ptr.Get().IsValid()) {

    }
    //---------------------------------------
    if (IsValid(A41->foo())) {

    }
    if (IsValid(A42.Get()->foo())) {

    }
    if (IsValid(F43->ptr)) {

    }
    if (IsValid(F44->ptr.Get())) {

    }
    if (IsValid(F45.Get()->ptr)) {

    }
    if (IsValid(F46.Get()->ptr.Get())) {

    }
    //---------------------------------------




    //---------------------------------------
    // 后文中判空
    if (A51->foo()) {

    }
    if (A52.Get()->foo()) {

    }
    if (F53->ptr) {

    }
    if (F54->ptr.Get()) {

    }
    if (F55.Get()->ptr) {

    }
    if (F56.Get()->ptr.Get()) {

    }
}
