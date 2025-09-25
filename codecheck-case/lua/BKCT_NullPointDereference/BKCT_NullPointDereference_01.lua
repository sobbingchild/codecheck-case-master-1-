local function bad_01()
    local str
    str = nil
    -- bad
    print(#str)

    local tableVar
    tableVar = nil
    -- bad
    local keyCount = #tableVar

    local list = {"element1", "element2"}
    list[1] = nil
    -- bad
    print(list[1]:upper())

    local var
    var = nil
    -- bad
    print(var.someField)
end

local function good_01()
    local str = "Hello"
    -- good
    print(#str)

    local tableVar = {"element1", "element2"}
    -- good
    local keyCount = #tableVar

    local list = {"element1", "element2"}
    list[1] = "Not nil"
    -- good
    print(list[1]:upper())

    local var = {}
    var.someField = 1
    -- good
    print(var.someField)
end
