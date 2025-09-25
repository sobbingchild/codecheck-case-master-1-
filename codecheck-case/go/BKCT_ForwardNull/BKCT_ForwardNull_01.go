package BKCT_ForwardNull

import (
	"fmt"
)

func badMethod1() {
	var str *string
	if str == nil {
		// bad
		fmt.Println(len(*str)) // 在为空的分支中使用
	}
}

func badMethod2() {
	var str *string
	if str != nil {
		return
	}
	// bad
	fmt.Println(len(*str)) // 在为空的分支中使用
}

func badMethod3(str *string) {
	if str != nil {
		str = nil
	}
	// bad
	fmt.Println(len(*str)) // 在不再次检查是否为空的情况下使用
}

func badMethod4(str *string) {
	if str == nil {
		// do nothing
	}
	// bad
	fmt.Println(len(*str)) // 在不再次检查是否为空的情况下使用
}

func goodMethod1() {
	var str *string
	if str != nil {
		// good
		fmt.Println(len(*str))
	}
}

func goodMethod2() {
	var str *string
	if str == nil {
		return
	}
	// good
	fmt.Println(len(*str))
}

func goodMethod3(str *string) {
	if str == nil {
		temp := "aaa"
		str = &temp
	}
	// good
	fmt.Println(len(*str))
}

func goodMethod4(str *string) {
	if str == nil {
		return
	}
	// good
	fmt.Println(len(*str))
}
