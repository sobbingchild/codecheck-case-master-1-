//
// Created by wadema on 2024/5/30.
//
// defect:bkcheck(SameEnum)

enum Color {
    RED,       // 默认值为 0
    // bad
    GREEN = 0, // 显式地设为 0
    BLUE       // 在前一个值（GREEN）的基础上递增，值为 1
};
enum Season {
    SPRING = 1,
    SUMMER = 2,
    AUTUMN = 3,
    // bad
    WINTER = 3
};
enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    // bad
    THURSDAY = 2,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
enum Planet {
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN = 7,
    // bad
    URANUS = 7,
    NEPTUNE
};